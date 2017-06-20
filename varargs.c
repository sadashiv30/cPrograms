#include <stdarg.h>
#include <stdio.h>
#include <string.h>
int myfunction(char *first_argument, ...) {
  int length;
  va_list argp;
  va_start(argp, first_argument);
  char *p;
  length = strlen(first_argument);
  while ((p = va_arg(argp, char *)) != NULL) {
    length = length + strlen(p);
  }
  va_end(argp);
  return (length);
}
int main() {
  int length;
  length = myfunction("Hello", "Hi", "Hey!", (char *)NULL);
  printf("Length of the strings:%d\n", length);
  return (0);
}