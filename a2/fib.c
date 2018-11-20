// CMPT 214 Assignment 2 Question 2 - Fibbonacci Sequence
// Tyrel Kostyk, tck290, 11216033
#include <stdio.h>
#include <limits.h>
#include <math.h>

int fib(int n) {
  int prev1, prev2;
  int MAX_VAL = pow(2, 8*sizeof(typeof(n))) - 1;  // Calculate max val before overflow
  int MIN_VAL = ( pow(2, 8*sizeof(typeof(n))) ) * (-1);  // Calculate min val before overflow

  // Base Cases - n = 0 or n = 1; just return n
  if ((n == 0) || (n == 1)) {
    return n;
  }

  // case of positive n - F(n) = F(n-2) + F(n-1)
  else if (n > 1) {
    prev1 = fib(n-1);
    prev2 = fib(n-2);
    if ((prev1 == 4) || (prev2 == 4)) { return 4; }  // Checks for previous Int Overflow (see below)

    // Check for Positive Int Overflow:
    if (prev1 <= MAX_VAL - prev2) {
      return prev1 + prev2;
    } else {
      // Flag to indicate Overflow - Chosen b/c 4 does not show up in the Fibbonacci Sequence
      return 4;
    }
  }

  else {
    prev2 = fib(n+2);
    prev1 = fib(n+1);
    if ((prev1 == 4) || (prev2 == 4)) { return 4; }  // Checks for previous Int Overflow (see below)

    // If prev1 negative, prev2 positive; check for Pos Int Overflow
    if (prev1 <= 0) {
      if (prev2 <= MAX_VAL + prev1) {
        return prev2 - prev1;
      } else {
        // Flag to indicate Overflow - Chosen b/c 4 does not show up in the Fibbonacci Sequence
        return 4;
      }
    // Check for Negative Int Overflow if prev1 > 0:
    } else if (prev2 >= MIN_VAL + prev1) {
        return prev2 - prev1;
    } else {
      // Flag to indicate Overflow - Chosen b/c 4 does not show up in the Fibbonacci Sequence
      return 4;
    }
  }
}

int main() {
  int n, fib_result;
  printf("Enter an integer: ");
  scanf("%d", &n);
  fib_result = fib(n);

  if (fib_result == 4) {
    printf("Error: Int Overflow when n = %d!\n", n);
  } else {
    printf("Fibbonacci Result: %d\n", fib_result);
  }
}
