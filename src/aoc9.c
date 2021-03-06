#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char fname[] = "inputs/aoc9.txt";
static FILE * fp;

unsigned long list[1000];
unsigned long  * ptr;

// Validate the by finding a+b=number from 25 previous val's in the list
// ret 1 for valid and 0 for invalid number
static int validate(unsigned long * test_val, unsigned long * list)
{
    int i,j;
    for(i = 0; i < 25 ; i++)
        for(j = i; j < 25; j++)
            if(*test_val == list[i]+list[j]) return 1;

    return 0;
}

// Task 2/2
static void task2()
{

    int a, b, ind;
    unsigned long temp_sum, min, max;

    temp_sum = ind = 0;

    // Find ind sequential numbers summing to the invalid number
    for(a=0; list+a < ptr; a++)
    {
        while(temp_sum <= *ptr)
        {
            temp_sum += list[a+ind];
            ind++;
            if(temp_sum == *ptr) goto end;
        }
        ind = temp_sum = 0;
    }

    // Find the min & max of the list, compute the sum
end:
    min = *ptr;
    max = b = 0;
    while(b < ind){
        if(list[a+b] < min) min = list[a+b];
        if(list[a+b] > max) max = list[a+b];
        b++;
    }

printf("Sum: %lu \n", max+min);

}

// Task 1/2
static void task1()
{
	int a;
    ptr = &list[0];

    memset(list, 0, 1000*sizeof(unsigned long));

    if(NULL == ( fp = fopen(fname, "r")))
    {
        printf("File not found..\n");
        exit(0);
    }

    // Read the preamble
    while(ptr != &list[25])
        fscanf(fp, "%lu", ptr++);

    // Scan + validate
    while(EOF != fscanf(fp, "%lu", ptr))
    {
        a = validate(ptr, ptr-25);
        if(!a)
        {
            printf("Invalid number: %lu\n", *ptr);
            break;
        }
        ptr++;
    }

    fclose(fp);

}

void aoc9()
{

	task1();
	task2();
}
