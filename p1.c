#if 0
Author -- Nafees Noor
Login ID: nn319918
CSI -- 333, Discussion - Friday - 1.40 to 2.35 pm

  This Program takes a decimal  integer number from the user 
  convert the number into the binary form, compute
  the number of one  in the binary representation 
  and then compute the maximum block of length of 
  the binary representation.
#endif

#include <stdio.h>
#define SIZE 31  // size of the array
int main(void)
{
  int array[SIZE];
  int input;   // input variable
  int remainder; // Variable to put converted number into the array
  int i = 0; 
  int j = 0;  // Variables for loop counters
  int h = 0;
  int a = 0;
  int b = 0;
  int count = 0;
  int temp = 0;  // Variable to keep how many time the number  being converted
  int curblock= 0;
  int maxblock =0; // Variables to count the maximum block length

 //Initilizing the array
 for(i = 0;  i <SIZE; i++)
{
  array[i] = 0;
}
 //Taking number from the user
 printf("Please enter one number: ");
 scanf("%d", &input);
 
 // if statement to deal with the negative numbers
 if(input <  0)
{
  printf("Input value is negative.\n");
  return 1;
}

// loop and if number is not zero, keep converting it and put in the array
 while(input != 0)
 { 
  temp++;  // incrementing temp to use to print the converted numbers
  remainder = input %2;
  input = input /2;
  array[j] = remainder;
  j++;
 }

  printf("Converted numbers: "); 

  for(h= temp-1; h >= 0; h--)
 {
   printf("%d",array[h]); //printing out the converted number from the array
 }
 
 printf("\n");


// Loop to count how many one is inside the arary for binary representation
for(a = temp; a >= 0; a--)
{
  if(array[a] == 1)
    {
      count++;  
    }
}

printf("No. of 1's in the binary representation = %d\n ", count);

// for loop to count the maximum block inside the binary representation
for( b = temp; b >= 0; b--)
{
  if(array[b] == 1)
    {
      curblock++;
    }
  if(array[b] == 0)
    {
      curblock = 0;
    }
  if(curblock > maxblock)  
    {
      maxblock = curblock; //setting the maximum block length
    }
}

printf("Maximum block length = %d\n", maxblock); // printing out maximum length

  return 0; 

}  // End of the main method
