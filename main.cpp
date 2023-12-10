/* Authors: Tyler Burkett, Dr. Jerzy Jaromczyk
 *          Part of the handout for project 4 of CS441 Fall 2022
 */
#include "Parser.hpp"
#include "AST.hpp"
#include "ScannerShim.hpp"
#include "SemanticAnalyzer.hpp"
#include "CodeGenerator.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>

constexpr int MIN_ARGC = 2;
constexpr int PARSE_SUCCESS = 0;
constexpr bool SEMANTICS_GOOD = true;

constexpr int GENERIC_ERROR = -1;
constexpr int PARSE_ERROR = -2;
constexpr int SEMANTIC_ERROR = -3;


auto main(int argc, char *argv[]) -> int {

    // Construct vector for program arguments
    std::vector<char *> arg(argv, argv+argc);

    if (argc < MIN_ARGC) {
        std::cerr << "Expected an argument; the name of a file to parse" << std::endl;
        return GENERIC_ERROR;
    }

    // Open the file to scan and file to output HTML to
    std::ifstream bminorFile;
    bminorFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        bminorFile.open(arg[1]);
    }
    catch (std::ifstream::failure&) {
        std::cerr << "Unable to open file \"" << arg[1] << "\"\n";
        return GENERIC_ERROR;
    }


    // Create the scanner & parser and begin parsing
    B_Sharp::Scanner scanner(bminorFile, std::cout);
    B_Sharp::AST::TranslationUnit* parse_tree = nullptr;
    B_Sharp::Parser parser(scanner, &parse_tree);

    try {
      if (parser() != PARSE_SUCCESS) {
        std::cerr << "Failed to parse \"" << arg[1] << "\"\n";
        return PARSE_ERROR;
      }
    }
    catch (std::ifstream::failure&) {
        std::cerr << "Error while reading file \"" << arg[1] << "\"\n";
        return GENERIC_ERROR;
    }


    // Check that the semantics of the tree are correct
    B_Sharp::AST::SemanticAnalyzer analyzer(std::cout);
    if(analyzer(parse_tree) != SEMANTICS_GOOD) {
      return SEMANTIC_ERROR;
    }
    else {
      // Perform code generation
      std::filesystem::path original_path(argv[1]);
      std::string file_name = std::string(original_path.filename());
      std::string file_stem = std::string(original_path.stem());
      B_Sharp::AST::CodeGenerator generator(file_name);
      generator(parse_tree);

      // Write the results to a file
      std::string IRText = generator.extractIR();
      std::fstream outLLVM(file_stem + ".ll", std::fstream::out);
      outLLVM.exceptions(std::ifstream::failbit | std::ifstream::badbit);
      try {
        outLLVM << IRText;
        outLLVM.close();
      }
      catch (std::ifstream::failure&) {
          std::cerr << "Unable to write LLVM IR to file\n";
          return GENERIC_ERROR;
      }
    }

    // Close files
    try {
        bminorFile.close();
    } catch (std::ifstream::failure&) {
        std::cerr << "Error while closing file \"" << arg[1] << "\"\n";
        return GENERIC_ERROR;
    }

    return 0;
}
