/*
 /* stringTests.c
 *
 *  Created on: Jan 11, 2015
 *      Author: antelope
 */


#include <stdio.h>
#include <string.h>



void sort_words(char *x[], int y) {
 int i = 0;
 int j = 0;

 for(i = 0; i < y; ++i)
  for(j = i + 1; j < y; ++j)
   if(strcmp(x[i], x[j]) > 0)
    swap(&x[i], &x[j]);
}

void swap(char **p, char **q) {
 char *tmp;

 tmp = *p;
 *p = *q;
 *q = tmp;
}


int perm(char *s1, char *s2)
{


   /* sort(s2);
    sort(s1);
    if(strcmp(s1,s2)==0)return 1;
    else return 0;
    */
}


int main(void)
{
    char *a="aaabbbbbb\0";
    char *b="tefghif\0";

/*    if(perm(a,b)==1)
     printf("match");
*/
    char *c=stringCompress(a);
    printf("%s", c);

return 0;

}


