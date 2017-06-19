#include <stdio.h>

int myatoi(const char *string);
int myatoi2(const char *string);
int main(int argc, char *argv[]) {
  printf("%d\n", myatoi("0250999"));
  printf("%d\n", myatoi2("0250999"));

  return (0);
}
int myatoi(const char *string) {
  int ivalue;
  ivalue = 0;
  while (*string) {
    ivalue = (ivalue << 1) + (ivalue << 3) +
             (*string - '0'); // ivalue <<3 + ivalue <<1 = 8 + 2
    string++;
  }
  // Dont increment ivalue!

  return (ivalue);
}

int myatoi2(const char *string) {
  int value = 0;
  if (string) {
    while (*string && (*string <= '9' && *string >= '0')) {
      value = (value * 10) + (*string - '0');
      string++;
    }
  }
  return value;
}
