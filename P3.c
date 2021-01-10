/*Filename: P3.c *
 *Part of: Program 3 A590 assignment *
 *Created by: Joshua Cannon *
 *Created on: 9/26/2018 *
 *Last Modified by: Joshua Cannon *
 *Last Modified on: 9/29/2018
 */

#include<stdio.h>
#include<math.h>
#include<string.h>

int bitmodels();
int pointers();
int morepointers();
int pointerfunc(int numerator, int denominator, int *dividend, int *remainder);
int pointerarithmetic();
int pointerarray();

int main(void)
{

  /*data types and values for pointerfunc function*/
  int x,y,d,r;
  x=9;
  y=2;

  /*functions beging being called in order here and beyond in main()*/
  printf("\nBIT MODELS FUNCTION\n");
  bitmodels();

 printf("\nPOINTERS FUNCTION");
 pointers();

 printf("\nMORE POINTERS FUNCTIONS\n");
 morepointers();

 /*print statements for pointerfunc */
printf("\nPointer Used in A Function With an Aguement");

printf("\naddress of d: %u\n",&d); /*address where dividend in function should point*/
printf("address of r: %u\n",&r); /*address where remainder in function should point*/

pointerfunc(x,y,&d,&r);
/*results from printer func wit arguements*/
printf("\n%d/%d = %d with %d remainder\n",x,y,d,r);
printf("\nx=%d\n",x); 
  
printf("\nPOINTER ARITHMETIC FUNCTION\n"); 
 pointerarithmetic();

printf("\nPOINTER ARRAY FUNCTION BEGINS HERE\n");
 pointerarray();

 return(0);

}

int bitmodels()

{
  /*Declaring some variables of different types never used before.
   unsigned are only positive and for characters, it is 1 byte with
   a value range of 0-255*/
  unsigned char a;
  unsigned char b,c;
  unsigned char d,e;
  char f;
  int i;
  /*Various bitwise operations*/
a=17;
/*~ operator: creates compliment of original value in bitwise operations. Also a   NOT bitwise operation*/
a=~a;
  
printf("\nbitwise NOT of 17\n");
printf("%d\n",a);

b=17;
c=22;

 b=b & c; /*bitwise & operator: result is 1 only if both bits are 1*/
printf("bitwise AND of 17 and 22\n");
printf("%d\n",b);
  
d=17;
e=22;

/*bitwise OR operator: same principles as AND except in an OR construct */
d=d | e;
printf("bitwise OR of 17 and 22\n");
printf("%d\n",d);
  
f=17;
f=f | (1 << 3); /* set bit #3. Left shift the bits of first operand
		 and the second operand decides the number of places
		 to shift*/
printf("Sets bit #3 in 17, new value is 17+8=25\n");
  
printf("%d\n",f);

f=f & (~(1<<4)); /* clear bit 4 */
printf("Clears bit #4 in 25, new value is 25-16=9\n");
printf("%d\n",f);

printf("Reads i-th bit in current value of f (which is the base10 number 9),\nplus a loop that prints every bit in 8-bit space\n");

/*if i is greater than 0, decrease i by one increment*/

/*every for loops to the i'th bit and displays the current value */
for (i=7; i>=0; i--)

printf("%d ",(f&(1<<i)) >> i); 
printf("\n");
printf("Current value of a\n");

for (i=7; i>=0; i--)
printf("%d ",(a&(1<<i)) >> i); 
printf("\n");
printf("Current value of d\n");
  
for (i=7; i>=0; i--)
    printf("%d ",(d&(1<<i)) >> i); 
  printf("\n");
  printf("Current value of e\n");

for (i=7; i>=0; i--)
    printf("%d ",(e&(1<<i)) >> i); 
  printf("\n");
  
}


int pointers()

{
  /*Declaring variables and pointers to different data types*/
  int count, x;
  int *count_p;
  char letter;
  char *letter_p = &letter; /*pointer points to letter address*/
  /*Assigning specific values to the declared variables */
  count=10;
  count_p=&count;
 
  /*print the contents of count and x*/
  x=*count_p;
  letter = 'Q';
  
  printf("\nHere's is the step-by-step output from the integer pointer example\n");
  /*printing contents of count and x */
  printf("count = %i and x = %i\n", count, x);
 
 /*the rest of this guide has not been changed per the instructors version */
 
  *count_p = 42;
  /*Let's print the contents of count and x again*/
  printf("count = %i and x = %i\n", count, x);
  /*Let's change count to the value of x*/
  count = x;
  /*Let's print the contents of count and x again*/
  printf("count = %i and x = %i\n", count, x);
  printf("\nHere's is the step-by-step output from the character pointer example\n");
  /*Let's confirm the values of letter and letter_p*/
 
  printf("letter = %c and letter_p = %c\n", letter, *letter_p);
  /*Let's change letter but not letter_p*/
  letter = '/';
  /*Let's print the contents of letter and letter_p again*/
  printf("letter = %c and letter_p = %c\n", letter, *letter_p);
  /*Let's change letter_p but not letter*/
  *letter_p = '!';
 
  /*Let's print the contents of letter and letter_p again*/
  printf("letter = %c and letter_p = %c\n", letter, *letter_p);/*Declaring some variables of different types */

}

int morepointers()
{
  /*making int types with pointers assigned to those addresses*/
  int firsti, secondi;
  int *firsti_p, *secondi_p;
  /*IMPORTANT! Do NOT forget about data types in the sense of whole numbers.
   We declare values to the data types.*/
  firsti=5;
  firsti_p=&firsti;
  secondi = *firsti_p / 2 + 10; /*BUT this will not give us what we think it will
			        and a FLOAT will NOT be th output*/
  secondi_p = firsti_p;
  /*printing outcome of first int with pointer*/
  printf("\nHere the output from the first integer pointer example\n");
  /*confirming the values*/
  
printf("firsti = %i, secondi = %i, value of firsti_p = %i and value of secondi_p = %i\n", firsti, secondi, *firsti_p, *secondi_p);

}

/*first function that takes in arguements*/
int pointerfunc(int numerator, int denominator, int *dividend, int *remainder)
{

  printf("address stored in dividend: %u\n",dividend);
  printf("address stored in remainder: %u\n",remainder);
  if (denominator < 1)
    return(0);
  *dividend=numerator/denominator; /*pointer is now the result of arithmetic*/
  *remainder=numerator%denominator;
  numerator=7;

}
int pointerarithmetic()
{
  /*introducing arrays with pointers */
  char ca[3],*cp;
  int ia[3],*ip;
 
 /*Assign values to array cells*/
  ca[0]='A';
  ca[1]='B';
  ca[2]='c';
  cp=&(ca[0]);
  ia[0]=1234;
  ia[1]=5678;
  ia[2]=9999;
  ip=&(ia[0]);

  /* print standard output, then use pointers, then show output again. */
  printf("\nchar pointer cp points to value = %c\n",*cp);
  printf("ca[2] = %c\n", ca[2]);
  printf("int pointer ip points to value = %i\n", *ip);
  printf("ia[2] = %i\n",ia[2]);
  *(cp+2) = 'Q'; /*moving right two times and changing value to Q */
 
  *(ip+2) = 33;
  printf("\nResults after we apply pointer arithmetic.\n");
  printf("ca[2] = %c\n",ca[2]);
  printf("ia[2] = %i\n",ia[2]);

}

int pointerarray()

{
  double array[10]; /*declaring data types along with pointers */
  double *d_ptr;
  double value;
  int i,offset;

  for (i=0; i<10; i++)
    array[i]=(double)i+10.0; /* access memory using array index and fill cells with #s*/
  d_ptr=&(array[0]); /* access memory location of first array cell using pointer
		      */
  while (1)
    {
      printf("\nAddress(hex)\tAddress(base10)\tValue\n");
      for (i=0; i<10; i++)
	/*%p is pointer adress assigned to pointer,%u is unsigned decimal %lf for           long float */
	printf("%p\t%u\t%lf\n",&(array[i]),&(array[i]),array[i]);
      printf("\nEnter offset value (0 0 to quit): ");
      scanf("%d %lf",&offset,&value);
      if (offset == 0 && value == 0.0)
	break; /* break out of loop */
      if (offset < 0 || offset > 9)
	{
	  printf("Offset out of bounds\n");
	  continue; /* go back to start of loop */
	}
      /* Three ways to do the same thing */
      /*NOTE FROM JEFF(thanks Jeff!): First one listed will be the one used at com        pile time
	To test each one, change order, or comment out all but one*/
      array[offset]=value; /* using array syntax */
      /* *(d_ptr+offset)=value; using pointer syntax */
      /* *(array+offset)=value; using mixed syntax */
}
}
