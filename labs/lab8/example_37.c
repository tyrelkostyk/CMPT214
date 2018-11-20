/* 
        String constants 
        Illustrates: string constants, pointers to strings, and array of chars 
*/ 

#include <stdio.h> 

int main() 
{ 
        char *a = "I am a constant";   // a pointer initialized to point to
                                       //  a string constant; value of a can
                                       //  be changed; content of string cannot
                                       //  be changed 
        char b[] = "Hello";            // an array of characters (i.e. a string)
                                       //  initialized to "Hello"; value of
                                       //  b cannot be changed; content of
                                       //  string can be changed
                                       // since dimension is not given, string
                                       //  is made just big enough to contain
                                       //  all the specified characters
        char c[] = {'H', 'e', 'l', 'l', 'o', '\0'}; 
                                       // equivalent to definition of b
        printf("%s\n%s\n%s\n", a, b, c); 
        return 0; 
} 
