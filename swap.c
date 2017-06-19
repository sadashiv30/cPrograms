#include <stdio.h>

void swapXOR(int *a, int *b) {
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void swapAdd(int *a, int *b) {
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

int main(void) {
  int a = 7, b = 6;
  int p = 7, q = 7;
  printf("Before Swap %d, %d\n", a, b);
  swapAdd(&a, &b);
  printf("After Swap %d, %d\n", a, b);
  printf("Before Swap %d, %d\n", p, q);
  swapXOR(&p, &q);
  printf("After Swap %d, %d\n", p, q);
}