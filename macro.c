#include <stdio.h>

#define CUBE(x) ((x)*(x)*(x))
#define DEBUG_VALUE(v) printf(#v " is equal to %d.\n", v)
#define SORT(x) sort_function ## x

void print_version_info(void)
{
     printf("Date Compiled: %s\n", __DATE__);
     printf("Time Compiled: %s\n", __TIME__);
}

int sort_function3(char *array, int elements, int element_size){
    printf("Sort 3\n");
    return 0;
}

int sort_function2(int elements, int element_size){
    printf("Sort 2\n");
    return 0;
}


void main(void)
{
     int x, y;
     x = 5;
     y = CUBE(++x);
     printf("y is %d\n", y);
     DEBUG_VALUE(y); 
     print_version_info();

     char* array;
     int   elements, element_size;
     SORT(3)(array, elements, element_size);

}

