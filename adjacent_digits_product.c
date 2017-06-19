/*

   Below this line you'll see a 1000-digit number. The four adjacent digits
contained in that number that have the greatest product are 9 × 9 × 8 × 9 = 5832
(highlighted in the picture at the end).

   73167176531330624919225119674426574742355349194934
   96983520312774506326239578318016984801869478851843
   85861560789112949495459501737958331952853208805511
   12540698747158523863050715693290963295227443043557
   66896648950445244523161731856403098711121722383113
   62229893423380308135336276614282806444486645238749
   30358907296290491560440772390713810515859307960866
   70172427121883998797908792274921901699720888093776
   65727333001053367881220235421809751254540594752243
   52584907711670556013604839586446706324415722155397
   53697817977846174064955149290862569321978468622482
   83972241375657056057490261407972968652414535100474
   82166370484403199890008895243450658541227588666881
   16427171479924442928230863465674813919123162824586
   17866458359124566529476545682848912883142607690042
   24219022671055626321111109370544217506941658960408
   07198403850962455444362981230987879927244284909188
   84580156166097919133875499200524063689912560717606
   05886116467109405077541002256983155200055935729725
   71636269561882670428252483600823257530420752963450
   Write a function that will receive a big number as a string and a number of
digits to multiply and will return the biggest product contained in the number.
Example:

   adjacent_digits_product(NUMB, 4)  # Should return 5832
   adjacent_digits_product(NUMB, 5)  # Should return 40824
   Please include the unit tests required to match at least 5 sample digit
counts (ex: 4, 13, 17, 25, 50).

   Use the example in the file below in order to submit your exercise.

*******************************************************************************************


/* README
 * Language : C
 * Compiler : gcc
 * make line: gcc adjacent_digits_product.c -o adjacent_digits_product -lm
 */

#include <limits.h>
#include <stdio.h>
#include <string.h>

// Brute force method to find the MSB 1
int highestOneBitPosition(unsigned long long int a) {
  int bits = 0;
  while (a != 0) {
    ++bits;
    a >>= 1;
  };
  return bits;
}

// The product will have the MSB at sum of MSB position of the inputs
int multiplication_is_safe(unsigned long long int a, unsigned long long int b) {
  int a_bits = highestOneBitPosition(a), b_bits = highestOneBitPosition(b);
  return (a_bits + b_bits <= 64);
}

unsigned long long int adjacent_digits_product(const char *input,
                                               int num_digits) {
  int len, i, j;
  len = strlen(input);

  long long int prod, max;
  max = 0;

  // Loop through all digits
  for (i = 0; i < len - num_digits; i++) {
    prod = 1;
    // Find the product in the window from i to i+num_digits
    for (j = i; j < i + num_digits; j++) {
      // Check if overflow will occur, if so return the ULONG LONG MAX supported
      // by the system
      if (!multiplication_is_safe(prod, input[j] - '0'))
        return ULLONG_MAX;
      prod *= (input[j] - '0');
    }
    // Update the max
    if (prod > max)
      max = prod;
  }
  return max;
}

void main() {
  char NUMB[1001];
  strcpy(NUMB, "731671765313306249192251196744265747423553491949349698352031277"
               "450632623957831801698480186947885184385861560789112949495459501"
               "737958331952853208805511125406987471585238630507156932909632952"
               "274430435576689664895044524452316173185640309871112172238311362"
               "229893423380308135336276614282806444486645238749303589072962904"
               "915604407723907138105158593079608667017242712188399879790879227"
               "492190169972088809377665727333001053367881220235421809751254540"
               "594752243525849077116705560136048395864467063244157221553975369"
               "781797784617406495514929086256932197846862248283972241375657056"
               "057490261407972968652414535100474821663704844031998900088952434"
               "506585412275886668811642717147992444292823086346567481391912316"
               "282458617866458359124566529476545682848912883142607690042242190"
               "226710556263211111093705442175069416589604080719840385096245544"
               "436298123098787992724428490918884580156166097919133875499200524"
               "063689912560717606058861164671094050775410022569831552000559357"
               "2972571636269561882670428252483600823257530420752963450");

  printf("Adj digits 4  : %20llu Expected Value: 5832\n",
         adjacent_digits_product(NUMB, 4)); // Should return 5832
  printf("Adj digits 5  : %20llu Expected Value: 40824\n",
         adjacent_digits_product(NUMB, 5)); // Should return 40824
  printf("Adj digits 10 : %20llu Expected Value: 493807104\n",
         adjacent_digits_product(NUMB, 10));
  printf("Adj digits 13 : %20llu Expected Value: 23514624000\n",
         adjacent_digits_product(NUMB, 13));
  printf("Adj digits 17 : %20llu Expected Value: 5292994896000\n",
         adjacent_digits_product(NUMB, 17));
  printf("Adj digits 25 : %20llu Expected Value: 94810963968000000\n",
         adjacent_digits_product(NUMB, 25));
  printf("Adj digits 50 : %20llu Expected Value: Overflow\n",
         adjacent_digits_product(NUMB, 50));
}
