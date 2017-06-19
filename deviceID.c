/*
What was the bug in the firmware?
The bug is that the deviceID function was ignoring the '0's somehow, may be in
the comparison of character bounds ">'0'" instead of ">='0'"
Why did it only impact a small percentage of units?
The issue occurs when there are more than one 0 in the device ID. I guess that
number was small.

*/
#include <stdio.h>

int deviceIDMatch(char *deviceID1, char *deviceID2) {
  short int countZ1, countZ2; // vars to count number of 0s
  countZ1 = countZ2 = 0;

  // Loop through all chars
  while (*deviceID1 != '\0' || *deviceID2 != '\0') {
    // Find the first non zero char, count the num of 0's
    while (*deviceID1 == '0') {
      countZ1++;
      deviceID1++;
    }
    while (*deviceID2 == '0') {
      countZ2++;
      deviceID2++;
    }
    // Now we have the non 0s in the front, check if they are equal
    if (*deviceID1 == *deviceID2) {
      deviceID1++;
      deviceID2++;
    } else {
      return 0;
    }
  }
  if (countZ1 == countZ2)
    return 1;
  else
    return 0;
}

int main() {

  printf("Ret %d\n",
         deviceIDMatch("04E8FFE8000342120000FED3", "04E8FFE8000342120000FED3"));
  printf("Ret %d\n",
         deviceIDMatch("000000004E8FFE834212FED3", "04E8FFE8000342120000FED3"));
  printf("Ret %d\n",
         deviceIDMatch("234234123412341234123434", "545454535435345345345345"));
  printf("Ret %d\n",
         deviceIDMatch("0000004E8FFE834212FED3", "04E8FFE8000342120000FED3"));
  return 0;
}
