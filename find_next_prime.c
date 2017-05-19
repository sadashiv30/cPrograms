/* =====================================================
###    Assignment   ###
#
# Your assignment is to implement the
# following function: `find_next_prime`.
# As the name states, given the number `n` the 
# function should return the next closest prime.
#
# Examples:
#  * `find_next_prime(6)` should return 7.
#  * `find_next_prime(10)` should return 11.
#  * `find_next_prime(11)` should return 13.
#
# You can use whatever you want (data structures,
# language features, etc).
# 
# Unit tests would be a plus.
#
### End Assignment  ###
======================================================= */

/* README
 * Language : C
 * Compiler : gcc
 * make line: gcc find_next_prime.c -o findnextprime -lm 
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_NUM 10000

// Check if the number is prime
int checkifprime(long int num)
{ long int i;

    // Brute force division from 2 to sqrt(num)
    for(i=2;i<=sqrt(num);i++)
    {
	if(num%i == 0)
	    return 0;
    }
    return 1;
}

// Function to find the next prime
long int find_next_prime(long int n)
{
    long int prime;

    // 0 and 1 is special case
    if(n<2)
	return 2;

    // Check one by one
    for(prime=n+1;;prime++)
    {
	if(checkifprime(prime))
	    return prime;
    }
}


int  main()
{
    int i,j;

    // Check for 20 random numbers
    for(i=0;i<20;i++)
    {
	j= rand() % MAX_NUM;
	printf("n=%5d, next prime= %5ld\n",j,find_next_prime(j));
    }
    return 0;
}


