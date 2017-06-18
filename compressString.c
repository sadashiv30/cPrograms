/*
 * compressString.c
 *
 *  Created on: Jan 11, 2015
 *      Author: antelope
 */

/*
 *  Implement a method to perform basic string compression using the counts of
repeated characters. For example, the string aabcccccaaa would become
a2blc5a3. If the "compressed" string would not become smaller than the original
string, your method should return the original string.
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *stringCompress(char *s)
{
	int len = strlen(s);
	char *buf = (char *)malloc(len*2);
	char *ptr ,*tmp;
	ptr=tmp=s;
	int count=0;
	if(len==0)
		return NULL;

	while(ptr!=NULL)
	{
		count=0;
		while(strncmp(ptr,tmp,1)==0)
		{
			count++;
			tmp++;
		}
		*buf=*ptr;
		//itoa(count,++buf,10);
		//sprintf(++buf,co)
		ptr+=count;
	}
	return buf;
}

int main(){

	return 0;
}