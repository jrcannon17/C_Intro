/*Filename: buffet.c *
 *Part of: First A590 program *
 *Created by: Joshua Cannon *
 *Created on: 8/22/2018 *
 *Last Modified by: Joshua Cannon *
 *Last Modified on: 9/2/2018 * Hoover sqaure problem revised
 */


#include <stdio.h>

int main()

{

 /*defining data types. We have four types and 6 variables: x,y,a,f,e, and d */

 int x,y;
 char a;
 float f,e;
 double d;


 /*additional variables 'i','j', and 'number' included for Hoover code near
the bottom of the script */ 

 int i,j,number; 

 /*variable d is a double type and e is a floating type just to clarify
 again  :)*/

 x=4;
 y=7;
 a='H';
 f=-3.4;
 d= 54.123456789;
 e=54.123456789;

 /* 'sizeof' print statements that tell us each data types storage size
   --- note: this is in bytes, not bits */

printf("sizeof(char) ==  %d\n", sizeof(char));
printf("sizeof(short) == %d\n", sizeof(short));
printf("sizeof(int) == %d\n", sizeof(int));
printf("sizeof(long) == %d\n", sizeof(long));
printf("sizeof(float) == %d\n", sizeof(float));
printf("sizeof(double) == %d\n", sizeof(double));
printf("sizeof(long double) == %d\n", sizeof(long double));
printf("sizeof(long long) == %d\n", sizeof(long long));


/*prints how the values given to variables are computed by the data types
 assigned to them. lf is for long float and .9 is the number of spaces to round too */
printf("%d %c %f %lf\n",x,a,e,d);
printf("%d %c %.9f %.9lf\n",x,a,e,d);

/*r variables for arithmetic statements*/

int r1,r2,r3,r4,r5;

 r1=x+y;
 r2=x-y;
 r3=x/y;
 r4=x*y;
 printf("%d %d %d %d\n",r1,r2,r3,r4);

 /*some modications to these expressions. IMPORTANT: w/o {bracket} use, these 
 values will be changed permanently until otherwise modified again */
 r3++;
 r4--;
 r5=r4%r1;
 printf("%d %d %d\n",r3,r4,r5);

 /*beginning of Hoover square problem*/

 printf("Enter a number: ");

 /*scanf for converting number input as actual number user sees on keyboard.
notice there is not catch error to put if the user puts in anything other than an int type*/

 scanf("%d",&number);

 i=1;/*we exclude any values of 0 to determine squares. This is debated but for this assignment, we will begin with 1. We do the same for the second int after i has passed the first while condition*/

 while (i*i<= number)
   {
     j=1;
     while (j<=i)/*to get all solutions, j must equal or be less of i*/
       {
         if (i*i + j*j == number)
           printf("Found: %d + %d\n",i*i,j*j);
         j++;
       }
     i=i+1; /*until problem is solved, we increase i by 1 and repeat the loop*/
   } 

 /* Exit status for program. Do not delete return value */

return(0);

}
