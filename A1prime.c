/*Filename: A1prime.c *
 *Part of: Finding prime A590 program assignment *
 *Created by: Joshua Cannon *
 *Created on: 9/7/2018 *
 *Last Modified by: Joshua Cannon *
 *Last Modified on: 9/10/2018 
 */

#include <stdio.h>

int main()


{
  /*the flag concept was introduced in a stackoverflow comment. Please see for loop comments for further explanation */
  int i, num, flag;

  printf("Enter a positive number to check if it is a prime number: ");
  scanf("%d",&num);

  /*though not required, I wanted a catch if someone entered a 0. The problem is getting the while to stop. I did not want to use break because then it will not prompt to ask for another input.  I'm not sure if I needed a if/else to outside or inside the while loop to catch this */
    while (num<=1)
      {

	printf("Zero is not a prime number for obvious reasons. Try again with a positive number: ");
	break;
}
    /*the original code was supposed to be if num%i==0, then the condition for prime is met. However, it only catches the first if and not the else statement. But when a flag is introduced, it works but only outside of the for loop */
  for (i=2; i<=num/2; i++)
    {
      if (num%i==0)
	{
	  flag=1;
	  /*if the break is not set, I havent tested what would occur */
	  /* break;*/
}
    }     
 if (flag==0)
	printf("The number %d is a prime number",num);
     else 
	  printf("The number %d is NOT a prime number",num);

 /* break;*/
    


  return(0);

}
