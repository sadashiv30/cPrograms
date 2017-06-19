#include <stdio.h>
#include <string.h>
static char str[] = "STRING TO REVERSE";
void ReverseStr(char *buff, int start, int end) {
  char tmp;
  if (start >= end) {
    printf("\n%s\n", buff);
    return;
  }
  tmp = *(buff + start);
  *(buff + start) = *(buff + end);
  *(buff + end) = tmp;
  ReverseStr(buff, ++start, --end);
}

int main(int argc, char *argv) {
  printf("\nOriginal string : [%s]", str);
  // Call the recursion function
  ReverseStr(str, 0, strlen(str) - 1);
  printf("\nReversed string : [%s]\n", str);
  return (0);
}
