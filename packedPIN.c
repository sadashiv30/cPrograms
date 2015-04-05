/*
	a) How might we use the existing 32bit storage scheme in place for the	6 numeric digit to store the alpha-numeric PIN?
	Since there are 30 symbols to be represented, and we have only 6 symbols to be packed in 32 bits, each symbol should be represented in 5 bits. I am choosing the simplest notation of A=1, C=2,.... and 2=24, 3=25, 9=30 as the encoding scheme.
	 	
	b) Write a	piece of code to encode	OR	decode your encoding scheme:
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN_PIN 6
#define FIVEBIT_MASK 0x1F
#define ALPHA_BEGIN 1
#define NUM_BEGIN 24
#define NUM_BITS_PER_SYMBOL 5

// Globals
int LUT[128]; // Look up table for codes
char rLUT[32]; // Reverse look up table for decodes

// Populate the tables
int fillLUT()
{
    char i;
	for(i='0' ; i<='Z' ; i++)
	{ 
		LUT[i] = 0;  // 0 is an invalid code
		// Process the numerals
		if(i>='0' && i <='9')
		{ 
		    int count = 0;
			if(i == '0' || i == '1' || i == '8') 
			{
			    continue;  // Skip
			}
			if(i>'0') ++count;
			if(i>'1') ++count;
			if(i>'8') ++count;
			LUT[i] = NUM_BEGIN + i-'0'- count; // Store the code at the index
			rLUT[LUT[i]] = i ; // Store the rerver look up index
			continue;  // skip the rest
		}
		// Process the alphabets
		if(i>='A' && i <='Z')
		{   int count;
		    count =0;
			if(i == 'B' || i == 'I' || i == 'O') // Skip B , I , 0
			{
				continue;  
			}
			if(i>'B') count++;
			if(i>'I') count++;
			if(i>'O') count++;
			LUT[i] = ALPHA_BEGIN + i-'A' -count; // Store the code at the index
			rLUT[LUT[i]] = i;
		}
	}
	return 0;
}


int encodeAlphaPin(char *alphaNumericPin)
{
	int i,intR = 0;
	//Start from LSB
	for(i= 0 ; i< LEN_PIN ; i++)
	{
		int temp = LUT[alphaNumericPin[i]] ;
		if(temp == 0)  // If invalid alphanumeric is sent, ret 0
		return 0;
		intR|= temp<< (i * NUM_BITS_PER_SYMBOL);
	}
	return intR;
}


char * decodePackedPin(int packedPIN)
{
    int i;
    char *c = (char *) malloc(LEN_PIN+1);
    for(i= 0 ; i< LEN_PIN ; i++)
	{
		int temp = packedPIN & (FIVEBIT_MASK << (i* NUM_BITS_PER_SYMBOL));
		c[i] = rLUT[temp>>(i*NUM_BITS_PER_SYMBOL)];
	}
	c[i] = '\0';
	return c;
}

int main()
{
	char s[][7] = { "ER9324", "6R493K", "I1O0B8", "AAAAAA", "999999"};
	int test,i;
	
	fillLUT();  // Fillup the look up tables
	
	printf("  Encode        Integer   Decode\n");
	for(i=0;i<5;i++)
	{
		test = encodeAlphaPin(s[i]);
		printf("%d %s  %12d ",i+1, s[i], test);
		printf("   %s\n", decodePackedPin(test));
	}
    return 0;
}
