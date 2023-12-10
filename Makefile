SHELL:=/bin/bash -O globstar
BISON_FILE=B-Sharp.y
BFLAGS=
FLEX_FILE=B-Sharp.lex
FFLAGS=
CFLAGS=-Wall -g --std=c++17 `llvm-config-12 --cppflags --ldflags --system-libs --libs all`
IN=
LINTFILES= main.cpp util.cpp util.cpp token.hpp ScannerShim.hpp AST.cpp AST.hpp
LINTFILES+= SemanticAnalyzer.cpp SemanticAnalyzer.hpp SymbolTable.cpp SymbolTable.hpp
LINTFILES+= TypeInfo.cpp TypeInfo.hpp CodeGenerator.cpp CodeGenerator.hpp
LINTFLAGS=

bsc.exe: util.o Scanner.o Parser.o AST.o SymbolTable.o TypeInfo.o SemanticAnalyzer.o CodeGenerator.o main.o
	g++ $^ $(CFLAGS) -o $@

%.o:%.cpp
	g++ -c $^ $(CFLAGS) -o $@

Parser.cpp: $(BISON_FILE)
	bison $(BFLAGS) $<

Scanner.cpp: $(FLEX_FILE) Parser.cpp
	flex $(FFLAGS) $<

.PHONY: clean
clean:
	rm -f $$(find . -name "*.o" ! -name "SemanticAnalyzer.o") Scanner.cpp Parser.* *.exe *.ll

.PHONY: run
run: bsc.exe
	./$< $(IN)
	llc-12 -relocation-model=pic --filetype=obj $(basename $(notdir $(IN))).ll -o $(basename $(notdir $(IN))).o
	g++ $(basename $(notdir $(IN))).o -o $(basename $(notdir $(IN))).exe

.PHONY: llvm-compile
llvm-compile:
	llc-12 -relocation-model=pic --filetype=obj $(basename $(notdir $(IN))).ll -o $(basename $(notdir $(IN))).o
	g++ $(basename $(notdir $(IN))).o -o $(basename $(notdir $(IN))).exe

.PHONY: lint
lint: Parser.cpp
	for FILE in $(LINTFILES) ; \
	do \
		clang-tidy $(LINTFLAGS) $$FILE --; \
	done;
