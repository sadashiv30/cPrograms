/* Bit Masking */
/* Bit masking can be used to switch a character
   between lowercase and uppercase */
#include <stdio.h>
#define BIT_POS(N)            ( 1U << (N) )
#define SET_FLAG(N, F)        ( (N) |= (F) )
#define CLR_FLAG(N, F)        ( (N) &= -(F) )
#define TST_FLAG(N, F)        ( (N) & (F) )
#define BIT_RANGE(N, M)       ( BIT_POS((M)+1 - (N))-1 << (N) )
#define BIT_SHIFTL(B, N)      ( (unsigned)(B) << (N) )
#define BIT_SHIFTR(B, N)      ( (unsigned)(B) >> (N) )
#define SET_MFLAG(N, F, V)    ( CLR_FLAG(N, F), SET_FLAG(N, V) )
#define CLR_MFLAG(N, F)       ( (N) &= ~(F) )
#define GET_MFLAG(N, F)       ( (N) & (F) )
void main()
{
  unsigned char ascii_char = 'A';        /*  char = 8 bits only */
  int test_nbr = 10;
  printf("Starting character = %c\n", ascii_char);
  /*  The 5th bit position determines if the character is
      uppercase or lowercase.
      5th bit = 0  - Uppercase
      5th bit = 1  - Lowercase      */
  printf("\nTurn 5th bit on = %c\n", SET_FLAG(ascii_char, BIT_POS(5)) );
  printf("Turn 5th bit off = %c\n\n", CLR_FLAG(ascii_char, BIT_POS(5)) );
  printf("Look at shifting bits\n");
  printf("=====================\n");
  printf("Current value = %d\n", test_nbr);
  printf("Shifting one position left = %d\n",
         test_nbr = BIT_SHIFTL(test_nbr, 1) );
  printf("Shifting two positions right = %d\n",
         BIT_SHIFTR(test_nbr, 2) );
}
