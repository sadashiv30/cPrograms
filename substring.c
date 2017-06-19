#include <stdio.h>
#include <string.h>
void BruteForce(char *x /* pattern */, int m /* length of the pattern */,
                char *y /* actual string being searched */,
                int n /* length of this string */) {
  int i, j;
  printf("\nstring : [%s]"
         "\nlength : [%d]"
         "\npattern : [%s]"
         "\nlength : [%d]\n\n",
         y, n, x, m);
  /* Searching */
  for (j = 0; j <= (n - m); ++j) {
    for (i = 0; i < m && x[i] == y[i + j]; ++i)
      ;
    if (i >= m) {
      printf("\nMatch found at\n\n->[%d]\n->[%s]\n", j, y + j);
    }
  }
}

void preComputeData(char *x, int m, int Next[]) {
  int i, j;
  i = 0;
  j = Next[0] = -1;
  while (i < m) {
    while (j > -1 && x[i] != x[j])
      j = Next[j];
    Next[++i] = ++j;
  }
}
void MorrisPrat(char *x, int m, char *y, int n) {
  int i, j, Next[1000];
  /* Preprocessing */
  preComputeData(x, m, Next);
  /* Searching */
  i = j = 0;
  while (j < n) {
    while (i > -1 && x[i] != y[j])
      i = Next[i];
    i++;
    j++;
    if (i >= m) {
      printf("\nMatch found at : [%d]\n", j - i);
      i = Next[i];
    }
  }
}

int main() {
  char *string = "hereroheroero";
  char *pattern = "hero";
  BruteForce(pattern, strlen(pattern), string, strlen(string));
  printf("------------\n\n");

  MorrisPrat(pattern, strlen(pattern), string, strlen(string));

  printf("------------\n\n");
  return (0);
}
