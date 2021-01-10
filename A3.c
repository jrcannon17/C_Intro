/*Filename: A3.c *
 *Part of: Assignment 3 A590 *
 *Created by: Joshua Cannon *
 *Created on: 10/02/2018 *
 *Last Modified by: Joshua Cannon *
 *Last Modified on: 10/04/2018 NOTE formatting may need adjustment
 */

#include<stdio.h>
#include<math.h>
#include<string.h>

/*function prototypes declared*/
int showbits(int num);

int bitops();

int main(void)

{
      bitops();
  return(0);

}

int bitops()
{ 
  /*variables declared including a blank space value during user input per A2 solutions*/
  int input;
  unsigned int value, value2, shift;
  char space;
  /*much like the calculator assignment, a switch-case was used inside the While loop*/
  while(input!=7)
    {
      printf("\n\t\tMain Menu\n"); /*\n and \t used for formatting*/
      printf("\t\t---------\n");
      printf("1. Perfrom Left Bit Shift Operation (one value)\n");
      printf("2. Perfrom Right Bit Shift Operation (one value)\n");
      printf("3. Perform Binary AND Operation (two values)\n");
      printf("4. Perform Binary OR Operation (two values)\n");
      printf("5. Perform Binary One's complement (~) Operation (one value)\n");
      printf("6. Perform Binary XOR Operation (two values)\n");
      printf("7. Quit\n");
      
      /*scan only the input in the While loop. The rest of the values will be scanned during each case scenerio*/
      scanf("%d", &input);
     
 /*for all cases except 7, scan values entered, use showbit function to convert to binary, do case operation, reprint using showbits */
      
      switch (input) 
	{
	case 1:
	  printf ("\nEnter a base 10 integer: ");
	  scanf("%d", &value);
	  printf("\nEnter number of places to shift bit: ");
	  scanf("%d", &shift);
	  printf("\n\n\tEntered Integer: "); showbits(value);printf(" (Base 10 %d)\n", value);
	  value=value<<shift; /*could have done this was pointers as well, try to recreate this using pointers to see how well the program works*/
          printf("\tLeft Shifted   : "); showbits(value);printf(" (Base 10 %d)\n", value);
	  break; /*the spaces do get tedious. I have not yet looked at a method to use arithmetic to auto calculate the white space required to align each colon*/
	
	case 2:	  
	  printf ("\nEnter a base 10 integer: ");
	  scanf("%d", &value);
	  printf("\nEnter number of places to shift bit: ");
	  scanf("%d", &shift);
	  printf("\n\n\tEntered Integer: "); showbits(value);printf(" (Base 10 %d)\n", value);
	  value=value>>shift;
          printf("\tRight Shifted  : "); showbits(value);printf(" (Base 10 %d)\n", value);	 
	  break;
	 
	case 3:
	  printf ("\nEnter two base 10 Integers, seperated by a space: ");
          scanf("%d %d", &value,&value2);
          printf("\n\n\tEntered Integer 1: "); showbits(value);printf(" (Base 10 %d)\n", value);
	  printf("\tEntered Integer 2: "); showbits(value2);printf(" (Base 10 %d)\n", value2);
	  value=value&value2;
	  printf("\tAND'ed           : "); showbits(value);printf(" (Base 10 %d)\n", value);
	  break; 
	  
	case 4:
	    printf ("\nEnter two base 10 Integers, seperated by a space: ");
	    scanf("%d %d", &value,&value2);
	    printf("\n\n\tEntered Integer 1: "); 
	    showbits(value);printf(" (Base 10 %d)\n", value);
            printf("\tEntered Integer 2: "); 
	    showbits(value2);printf("(Base 10 %d)\n", value2);
	    value=value | value2;
	    printf("\tOR'ed            : "); showbits(value);printf(" (Base 10 %d)\n", value);
	    break; 
	
	case 5:
	  printf ("\nEnter a base 10 integer: ");
          scanf("%d", &value);
	  printf("\n\n\tEntered Integer: "); showbits(value);printf(" (Base 10 %d)\n", value);
	  value=~value;
	  printf("\t~'ed           :"); showbits(value);printf (" (Base 10 %d)\n",value);
      
	   break;	
	 
	case 6:
	  printf ("\nEnter two base 10 Integers, seperated by a space: ");
          scanf("%d %d", &value,&value2);
          printf("\n\n\tEntered Integer 1: "); showbits(value);printf(" (Base 10 %d)\n", value);
	  printf("\tEntered Integer 2: "); 
	  showbits(value2);printf(" (Base 10 %d)\n", value2);
	  value=value^value2; /*not sure if ^ can also be used to declare exponents. If so, how does the program decipher this information?*/
	  printf("\tXOR'ed           : "); showbits(value);printf("(Base 10 %d)\n",value);
	
	case 7:
	  /*originally used an if statement if input == 7 but this does not work and there is really no need.*/
	  break;
	
	default: /*I've broken this before using Ctrl-X on accident. I don't know why this happened but for normal key commands, the default catches the input */
	  printf ("Please enter 1-7 as indicated by the menu.\n");
	}
    }
}

int showbits(int num) /*takes an arguement. In our case, the arguement will be the values from the switch case. Because of this, there is no reason to put this in main. Doing so w/o a value declared in main would most likely give an error anyways*/
{
  int i;
  /*since num is already declared as an int type in the arguement, I found no reason to do this again within the function. Doing so may produce an error */
  
  /*I found another way to do this, but this example from the P2 assignment is much more cleaner and easier to read */

  for (i = 31; i >= 0; i--) /*maximum len is 32 bits*/
    {
      printf("%d",(num&(1<<i)) >> i); /* read i'th bit */
    }
  
}
