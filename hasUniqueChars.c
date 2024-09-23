/*
 * hasUniqueChars.c
 * 
 * This file contains the implementation of the hasUniqueChars function, 
 * which checks if all characters in an input string are unique. It 
 * handles printable characters and reports any non-printing characters 
 * by exiting the program with an error message.
 * 
 * Name: Nadya K.
 */

#include <stdio.h>  // fprintf, printf
#include <stdlib.h> // exit() defined here
#include <string.h> // useful string operations
#include <ctype.h>  // useful character operations
#include <stdbool.h>  // to define a boolean type and true, false

#include "binary_convert.h"

/*
 * This function is for debugging by printing out the value
 * of an input unsigned long as a binary string.
 */
void seeBits(unsigned long value, char *debug_text) {
  
  // string to represent binary value of variable value
  char *bin_str;

  bin_str = ulong_to_bin_str(value);
  printf("%s%s\n", debug_text, bin_str);
  free(bin_str);
}

/*
 * Given an input string of chars, check for any non-printing
 * characters and print an error and exit if the string has any.
 */
void checkInvalid(char *inputStr) {
  char nextChar;
  int i;
  
  for (i = 0; i < strlen(inputStr); i++) {
    nextChar = inputStr[i];

    // if nextChar is invalid (31 or less or 127 as an ASCII char code), then bail out
    if ((nextChar <= 31) || (nextChar == 127)) {
      fprintf(stderr, "invalid character in string\n");
      exit(EXIT_FAILURE);
    }
  }
}

/*
 * This function checks if all characters in the input string are unique.
 * It uses bit manipulation to track which characters have been seen.
 * 
 * Parameters:
 *   char *inputStr: The string to check for unique characters.
 * 
 * Returns:
 *   true if all characters are unique, false otherwise.
 * 
 * This function will exit if the input string contains any non-printing characters.
 */
bool hasUniqueChars(char *inputStr) {
  // bail out quickly if any invalid characters
  checkInvalid(inputStr);
  
  int i; // loop counter
  
  // unsigned long can handle 64 different chars in a string
  unsigned long checkBitsA_z = 0;   // for checking A through z
  unsigned long checkBitsexcl_amp = 0; // for checking ! through @ 

  char nextChar; // next character in string to check

  unsigned long bitMask = 1; // bit mask for setting bits

  for (i = 0; i < strlen(inputStr); i++) {
    nextChar = inputStr[i];

    if (nextChar >= 'A' && nextChar <= 'Z') {
      int bit_position = nextChar - 'A';
      if (checkBitsA_z & (bitMask << bit_position)) {
        return false; // duplicate found
      }
      checkBitsA_z |= (bitMask << bit_position); // set the bit
    } else if (nextChar >= 'a' && nextChar <= 'z') {
      int bit_position = nextChar - 'a' + 26; // 26-51 for a-z
      if (checkBitsA_z & (bitMask << bit_position)) {
        return false; // duplicate found
      }
      checkBitsA_z |= (bitMask << bit_position); // set the bit
    } else if (nextChar >= '!' && nextChar <= '@') {
      int bit_position = nextChar - '!'; // 0-32 for special characters
      if (checkBitsexcl_amp & (bitMask << bit_position)) {
        return false; // duplicate found
      }
      checkBitsexcl_amp |= (bitMask << bit_position); // set the bit
    }
  }

  // if through all the characters, then no duplicates found
  return true;
}