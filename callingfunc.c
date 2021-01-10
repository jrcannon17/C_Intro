/*Filename: callingfunc.c *
 *Part of: Program 2 A590 assignment *
 *Created by: Joshua Cannon *
 *Created on: 9/10/2018 *
 *Last Modified by: Joshua Cannon *
 *Last Modified on: 9/14/2018 
 */
 
#include <stdio.h>
/*this program includes the following: */
/*Precise and detaild COMMENT explaining what array function actually does */
/*function from meeting 4 loops function */
/*function called conditionals  */
/*function called firstswap displayed output mimic meeting 5 (page 5) guide */
/*calling function to call all functions to run in order with single command after compilation */

void loops()



{
  int i,x;
  x=0; 

  printf("This is a  \"for\" loop\n");

  for (i=0; i<4; i++)
    {
      x=x+i;
      /*prints the values of x until the loop finishes with i */
      printf("%d\n",x);
    }

  printf("This is a \"while\" loop\n");

  while (i<7) /*the end condition is the only thing needed for the while loop to run*/
    {
      x=x+i;
      /*as with the for loop, we have to increment i within the loop instead of as an arguement to reach the end condition i<7 */
      i++;
      printf("%d\n",x);
    }

  /*do-while loop runs until i is less than 9, but runs at least once. Figuring out the starting value of each loop is key*/

  printf("This is a 'do-while' loop\n");

  do 
    {
      /*will run the same criteria as before but will run at least once even if something is wrong within our statement */
      x=x+i;
      i++;
      printf("%d\n",x);
    }
  while (i<9);
 
}
/*end of loops() function */


 void conditionals()
  /*Now a review of conditionals and blocks ran in C */
 {
  int i,x;
x=0;  

  for (i=0; i<5; i++)
    {
      /*this is not a regualr OR statement. It is a logical one. */
      if (i%2 == 0 || i == 1)
      /*if any of these conditions are met, x is added. If not, x is subtracted and the loop will repeat itself over         again if the parameter 5 was not included */
	x=x+i;
      else 
	x=x-i;
      printf("%d\n",x);
    }

  /*An example of switch-case. Grades are cases that have int values */

  printf("This is a \"switch-case\" conditional\n");

  int grade; 
  /*grade is an int value, but it is designed to determine a letter grade */
  printf("Input Grade: \n");
  scanf("%d", &grade);

  switch (grade) {

  case 1:
    printf ("Fail (F)\n");break;
  case 2:
    printf ("Not Good (D)\n");break;
  case 3: 
    printf ("Good (C)\n");break;
  case 4:
    printf ("Very Good (B)\n");break;
  case 5:
    printf ("Excellent (A)\n");break;
    /*anything outside the 1-5 scale will get this default value, even if the actual grade is put in. */
  default:
    printf ("You have not input a valid grade value.\n");break;
  
  }
 }
/*end of conditional function */

/*beginning of array function */
void firstswap()
{
  /*re-arranges content within the cells of an array */

  int i,j,k,swap;
  /*this char array has 8 cells assigned to it, with each cell being 8 bits */
  char c[8];

  c[0]='f'; c[1]='r'; c[2]='o'; c[3]='g'; c[4]=0;

  printf("Initial values for first 5 cells: %c%c%c%c%c\n",c[0],c[1],c[2],c[3],c[4]);

  for (i=0; i<4; i++)
    {
      /*K will always be the same as incremental i */
      k=i;
      /*j will always be one over i and k */
      for (j=i+1; j<4; j++)

	if (c[j]-c[k] < 10) /*this determines what cell swap will inherit. When printing what values c[j] and c[k] are during the loop, there are a few instances that the differences are above 10. I have yet to find out why 10 and not another number (such as 6 for instance) is the chosen integer for this code. Also, it is not clear why ints are small but displayed as c[int], they are very high numbers. My first thought was 10 was the cell space these two could play around in to determine what position swap would be. I tried. */
	  k=j;
      swap=c[i];
      

      c[i]=c[k];
      c[k]=swap;
    }
 

 printf("Final values: i: %d, j: %d, k: %d, swap: %d\n",i,j,k,swap);

 printf("Final values for first 5 cells after we swap: %c%c%c%c%c\n",
	 c[0],c[1],c[2],c[3],c[4]);

}

int main(void)

{
  /*declaration of previous functions after print statement enumerated said functions*/
  printf("THIS IS MY LOOPS FUNCTION.\n\n");
  loops();
  printf("\nTHIS IS MY FIRST ARRAY FUNCTION.\n\n");
  firstswap(); 
 printf("\nTHIS IS MY CONDITIONALS FUNCTION.\n\n");
conditionals(); 
  
  return(0);
}
