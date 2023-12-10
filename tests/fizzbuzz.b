/*
   File:   fizzbuzz.b
   Author: Tyler Burkett
   Date:   08-11-2022
*/

// FizzBuzz game:
// Print Fizz for a number divisible by 3
// Print Buzz for a number divisible by 5
// Print FizzBuzz for a number divisible by 3 and 5
// Print the number otherwise
main: function integer () = {
    x: integer;
    is_fizz:  boolean = false;
    is_buzz:  boolean = false;

    for (x = 1; x <= 100; x++) {
        is_fizz = (x % 3) == 0;
        is_buzz = (x % 5) == 0;

        if (is_fizz)                    print "Fizz";
        if (is_buzz)                    print "Buzz";
        if (!is_fizz && !is_buzz)       print x;
        print '\n';
    }

    // Output should be
    // "1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz ..."
    return 0;
}
