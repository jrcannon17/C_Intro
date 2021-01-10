/*Filename: A1harmonic.c *
 *Part of: Harmonic  A590 program assignment *
 *Created by: Joshua Cannon *
 *Created on: 9/7/2018 *
 *Last Modified by: Joshua Cannon *
 *Last Modified on: 9/10/2018 *NOT COMPLETE
 */
#include <stdio.h>

int main()
{
  /*since answer will be a decimal, decided isum will be a float number*/
int num,i;
float isum = 0.0;

printf("Enter a positive number: ");

scanf("%d",&num);

/*based on the prime.c; catch value could not be figured out in time to include it in this problem*/

 for(i=1;i<=num;i++)
  {
    /*did not know how to combine isum w/o the use a nested if statement */   
 if(i<num)
   /*i becomes looped until hitting the num input, where it is turned into isum*/
      {
	isum=1/(float)i;
      }
    if(i==num);
    {
      isum=1/(float)i; 
 }
}
    printf("the value for the series is %f ", isum);
return(0);
       
} 

