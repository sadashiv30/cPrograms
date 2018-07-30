#include <stdio.h>
#include <string.h>

void shiftLeftString(char *str, int pos) {
  int len = strlen(str);
  for (int j = pos; j < len - 1; j++) {
    str[j] = str[j + 1];
  }
  str[len - 1] = '\0';
}

void removeDuplicates(char *str) {
  if (!str)
    return;
  int len = strlen(str);
  if (len < 2)
    return;

  for (int i = 0; i < strlen(str); ++i) {
    for (int j = i + 1; j < strlen(str); j++) {
      while (str[i] == str[j]) {
        shiftLeftString(str, j);
      }
    }
  }
}
char strng[40][40] = {"abadefabbd", "abababababab", "aa", ""};
int main() {
  for (int i = 0; i < 4; i++) {
    printf("%d: %s\n", i, strng[i]);
    removeDuplicates(strng[i]);
    printf("%d: %s\n", i, strng[i]);
  }
  return 0;
}