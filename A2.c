/*Filename: A2.c *
 *Part of: Assignment 2 A590 program *
 *Created by: Joshua Cannon *
 *Created on: 9/17/2018 *
 *Last Modified by: Joshua Cannon *
 *Last Modified on: 9/20/2018 |NOTE* array duplicate notice does not stop array function from proceeding*
 */


#include <stdio.h>

void arrays()
{


  int i,j,size;
 
  /*the variables below find the intersection. Finding the Union is done with a While loop and simple compare math operators.
the intersection logic was used from a friend  who tried to solve the problem but could not. His logic proved nice but was too compplicated for me to implemenent in the end. I keep this here so I can solve on my own in the future. */
 
  /* int intersection[2*size];

     int indexs =-1; */

   
printf("Enter the size of the arrays:\n ");
scanf("%d",&size);

int a[size]; 
int b[size];
  
 printf("Enter elements of first array:\n ");

 /*scans the input value and adds to the  first array, named 'a'. Asia helped me with this...however....  */
 for (i=0; i<size; i++)
   {
     scanf("%d",&a[i]);
    }

 /*duplicate notification for-loop. I did not have the time to figure out how this could be used with scanf to prompt the user to start over   again. However, I would like to know how to do so in the future. This is in both the a and b arrays  */


 for(i=0; i<size; i++)
   {
     for(j=i+1;j<size;j++)
       {
	 if(a[i]==a[j])/*I've also tested if a[i]==a[i+1] as well and this seems to work.  */
	   {
	     printf("There should be no duplicates in the program in your input...\n");
		    }
	   }
       }

   
 printf("\nEnter elements of second array:\n ");
 
    for (j=0; j<size; j++)
      { scanf("%d",&b[j]);
           
 }
    /*check for duplicates in array b */
    for(j=0; j<size; j++)
      {
	for(i=j+1;i<size;i++)
	  {
	    if(b[j]==b[i])
	      {
		printf("\nThere should be no duplicates in the program in your input...\n\n");
		       }
	      }
	  }
       
    /*beginning problem to solve for intersection  */
     

    printf("\nthe intersection of the two arrays is: ");
   
 /*not sure if i and j need to be redclared but I wanted to be on the safe side since the next while loop will also be using i and j to find the union and I need them to start back to 0 */

    i = 0;
    j = 0;

    /*a loop that searches for the common integer in both arrays*/

    while(i < size && j < size)
      {
        if(a[i] < b[j])  
	  i++; /*moves i to the next cell */
        else if(b[j] < a[i]) /*moves j to the next cell */
	  j++;
        else /*could be also be read as a[i]==b[j] */
	  {
            printf("%d", a[i]);
            i++; j++; /*since that number is in common, both i and j are incremented to move to the next cell. Of course, this will also catch duplicates since the last for loop let duplicates pass through the function */
	  }
      }
 
    printf("\n");
    
    /*While loop to find the union begins here */

printf("the union of the two arrays is: ");

/*see comment about i and j for intersection. Re-declaring the numeral values for i and j to make the while loop work */
    i = 0;
    j = 0;


    while(i < size && j < size)
      {
	/*like the intersection while, both i and j are compared to size */
	if(a[i] < b[j]) /*step 1: find and print all i cells smaller than j's */
	  printf("%d", a[i++]); /*step 2: print all j cells smaller than i*/
	else if(b[j] < a[i])
	  printf("%d", b[j++]); 
	else
	  {
	    printf("%d", a[i]); /*step 3: like intersection, if they are the same int, then both get incremented */
	    i++; j++; /*the difference between the two I found are in this, we print everything instead of only what they have in common */
	  }
      }
   

 /*all the rest of the elements from each array are then printed out here */
    /*again, this is why it's important to declare i and j in previous loop. If i and j were changed back to 0, this would not work and instead, every element of both would be printed out.*/
  
    while(i < size)
      printf("%d", a[i++]);
    while(j < size )
      printf("%d", b[j++]);
   
    printf("\n");

    /*test to see how large the array size is TESTING ONLY */
 /*int lena = sizeof(a)/sizeof(a[0]);
   printf("\nsize of array a is %d and b is %d\n",lena,sizeof(b));*/

}

void matrixtranspose(int matrixa[4][5],int matrixb[5][4])
{
  /*my arguement is manually entered in main. For the function, I have the regualar matrix and the inversed or transposed one. After manual imput, code should do the rest. */
  int i,j;

  printf("\nThe Original Matrix: \n\n");

  /*displays matrix entered by loops through each index, row, and column */
  for (i = 0; i < 4; i++)
    {
      for (j = 0; j < 5; j++)
        {
	  /*had to look up how to pad spaces in C. 3d puts three spaces and then the next number */
	  printf("%3d", matrixa[i][j]);
        }
      printf("\n");
    }
 

 /*this flips the two matrixes. */

  for (i=0; i<4; i++)
    {
 for (j=0; j<5; j++)
      matrixb[j][i] = matrixa[i][j];
    }
 

printf("\nThe Transposed Matrix is: \n\n");
/*same concept for displaying the original matrix with padding */
  for (i = 0; i < 5; i++)
    {
      for (j = 0; j < 4; j++)
        {
	  printf("%3d", matrixb[i][j]);
        }
  printf("\n");
}
}

/*calculatot function begins here */
void calculator()
{
 
  /*decided to use doubles instead of floats just in case the input is exceptionally strong numbered. Have not tested to see what float*/
  double accumulator, value;
  char operator;
  /*operator also has to be scanned as input. a char works in this case */
  printf("Begin Calculations\n\n");

  printf("Initialize your Accumulator with the data of the form 'number' 'S' which sets\n the Accumulator to the value of your number\n ");

  
  /*while loop should stop ONLY if E is selected. A do while could be better in this case but a while loop still gets the job done */

while(operator!= 'E')
    
 {
  
   /*was going to include accumulator in scan as well but since accumulator equals value and value is scanned, I figured it'd be best not too. Scanning accumulator outside the loop as input seemed to crash the while loop/ */  
   scanf("%lf %c", &value,&operator);

 switch(operator)
    {
     

 /*the value is officially set in the S case */ 
   

     case 'S':  /*declare the equations outside the printf statement then print the accumulator */
      accumulator = value;
      printf("Value in the accumulator =  %.6lf\n ", accumulator); /*scanning as lf needs to be consistent. Scanning the value/accumulator otherwise could have unintended results */
      break;
      
     case '+':
       accumulator =  accumulator + value;

       printf("Value in the Accumulator = %.6lf\n ",accumulator); 
       break; 

    case '-':
      accumulator =  accumulator - value; 
      printf("Value in the Accumulator = %.6lf\n ",accumulator); 
      break;  


    case '*':
      accumulator =  accumulator * value; 
      printf("Value in the Accumulator = %.6lf\n ",accumulator = accumulator * value); 
      break;
 
      /*code to find 0 stated here. W/o brackets, the if and else would crash the code. They are now set in place and seem to work without disrupting the while loop  */

    case '/':  
      if (value == 0)
	{ 
	printf("cannot divide by 0\n"); 
	}
      else
	{
	  accumulator =  (accumulator/value); /*was not sure if accumulator needed to be set above the if or in the else. It seems to work in the else and this was the intended logic.*/
	printf("Value in the Accumulator = %.6lf\n ", accumulator); 
	}
      break; 

    case 'E': /*number HAS to be entered. If an E is entered alone, the entire program crashes*/
      printf("Value in the Accumulator = %.6lf\n ",accumulator = accumulator - value); 
      printf("\nEnd of calculations\n"); 
      break; 

      /* operator doesn't match case inside loop default case */

     default: 
       printf("Error! operator is not correct\n"); 
     } 

 } 

 } 


 int main() 

 { 
    printf("array function\n");
      arrays();
      

  int x,y;
  /*matrix established here without user input */
  int mainmatrix[4][5] = {
    {1,2,3,4,5},
    {6,7,8,9,10},
    {10,9,8,7,6},
    {5,4,3,2,1} };
 
 /*transpose matrix indice declared */
  int transposematrix[5][4];
 
  printf("\nMatrix Tranpose Function\n ");
  matrixtranspose(mainmatrix,transposematrix);
  printf("\n\n");
 
 /*calc function*/ 
 calculator(); 
  
  return(0);
  }
