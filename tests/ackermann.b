/*
   File:   ackermann.b
   Author: Tyler Burkett
   Date:   08-11-2022
*/

// The Ackermann function. This function cannot be written with loops; it has to be recursive
ackermann: function integer (m: integer, n: integer) = {
    answer: integer;

    if (m == 0)       answer = n+1;
    else if (n == 0)  answer = ackermann(m-1, 1);
    else              answer = ackermann(m-1, ackermann(m, n-1));

   return answer;
}

main: function integer () = {
    print ackermann(0,0), "\n";    // Should be 1
    print ackermann(0,1), "\n";    // Should be 2
    print ackermann(1,0), "\n";    // Should be 2
    print ackermann(1,1), "\n";    // Should be 3
    print ackermann(2,2), "\n";    // Should be 7
    print ackermann(3,3), "\n";    // Should be 61
    //  print ackermann(4,1), "\n"; // Should be 65533; this takes a few minutes to compute!
    //  print ackermann(4,2), "\n"; // don't even try; this number will have 19,729 digits!

    return 0;
}
