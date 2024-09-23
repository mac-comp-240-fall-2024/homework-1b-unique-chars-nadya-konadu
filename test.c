/*
* Name: Nadya K.
 * This file contains test cases for the hasUniqueChars function.
 * It verifies correct behavior with various input strings.
 */

#include <stdio.h>    // printf
#include <stdbool.h>  // to define a boolean type and true, false
#include <string.h>   // strcpy  to copy a string
#include <assert.h>

// declaration of function from hasUniqueChars.c
bool hasUniqueChars(char * inputStr);

int main() {
    bool ok;    // holds the result of hasUniqueChars(); used in asserts
    char string3[128];   // buffer for test strings

    // Test 1: Duplicates (should return false)
    strcpy(string3, "This should fail (l and s and i and h)");
    ok = hasUniqueChars(string3);
    printf("Test 1: Expecting false for \"%s\"... ", string3);
    assert(!(ok));
    printf("Passed!\n");

    // Test 2: Unique lowercase characters (should return true)
    strcpy(string3, "abcdefghij");
    ok = hasUniqueChars(string3);
    printf("Test 2: Expecting true for \"%s\"... ", string3);
    assert(ok);
    printf("Passed!\n");

    // Test 3: Uppercase and lowercase unique (should return true)
    strcpy(string3, "AaBbCcDdEeFfGg");
    ok = hasUniqueChars(string3);
    printf("Test 3: Expecting true for \"%s\"... ", string3);
    assert(ok);
    printf("Passed!\n");

    // Test 4: Unique characters (should return true)
    strcpy(string3, "xyz");  
    ok = hasUniqueChars(string3);
    printf("Test 4: Expecting true for \"%s\"... ", string3);
    assert(ok);
    printf("Passed!\n");

    // Test 5: Duplicates (should return false)
    strcpy(string3, "aabbcc");  
    ok = hasUniqueChars(string3);
    printf("Test 5: Expecting false for \"%s\"... ", string3);
    assert(!(ok));
    printf("Passed!\n");

    // Test 6: More duplicates (should return false)
    strcpy(string3, "abcdefga");  
    ok = hasUniqueChars(string3);
    printf("Test 6: Expecting false for \"%s\"... ", string3);
    assert(!(ok));
    printf("Passed!\n");

    // Test 7: String with multiple spaces (should return true)
    strcpy(string3, "a b c d e");
    ok = hasUniqueChars(string3);
    printf("Test 7: Expecting true for \"%s\"... ", string3);
    assert(ok);
    printf("Passed!\n");

    // Test 8: Edge case - empty string (should return true)
    strcpy(string3, "");
    ok = hasUniqueChars(string3);
    printf("Test 8: Expecting true for \"%s\"... ", string3);
    assert(ok);
    printf("Passed!\n");

    // Test 9: Edge case - string with only one character (should return true)
    strcpy(string3, "A");
    ok = hasUniqueChars(string3);
    printf("Test 9: Expecting true for \"%s\"... ", string3);
    assert(ok);
    printf("Passed!\n");

    // Test 10: All printable characters without duplicates (should return true)
    strcpy(string3, "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
    ok = hasUniqueChars(string3);
    printf("Test 10: Expecting true for all printable characters... ");
    assert(ok);
    printf("Passed!\n");

    // Test 11: Non-printing character (should cause exit)
    strcpy(string3, "Hello\0World");
    ok = hasUniqueChars(string3);
    printf("Test 11: Expecting to fail for \"%s\"... ", string3);
    assert(!(ok)); 
    printf("Passed!\n");

    // Test 12: String with tab character (should cause exit)
    strcpy(string3, "abc\tdef");
    ok = hasUniqueChars(string3);
    printf("Test 12: Expecting to fail for \"%s\"... ", string3);
    assert(!(ok)); 
    printf("Passed!\n");

    // Test 13: String with newline character (should cause exit)
    strcpy(string3, "abc\ndef");
    ok = hasUniqueChars(string3);
    printf("Test 13: Expecting to fail for \"%s\"... ", string3);
    assert(!(ok)); 
    printf("Passed!\n");


  // NOTE: if you add a \n to any tests, this should cause the
  //       exit failure given. Keep this test last so you can check 
  //       that others pass or fail as you expect them to.
  strcpy(string3, "a b cc\n");
  ok = hasUniqueChars(string3);
  // other examples that should fail that you can place in strings
  // are \0 or \t or \r
  // See problem description for more details about escape sequences
  
  return 0;
}