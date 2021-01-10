/*Filename: A3.c *
 *Part of: Program 3 A590 assignment *
 *Created by: Joshua Cannon *
 *Created on: 10/02/2018 *
 *Last Modified by: Joshua Cannon *
 *Last Modified on: 10/04/2018 NOTE formatting may need adjustment
 */

#include<stdio.h>
#include<math.h>
#include<string.h>

int showbits(int num);

int bitops();

int main(void)

{
      bitops();
  return(0);

}
int bitops()
{ 

  int input;
  unsigned int value, value2, shift;
  char space;
 
  while(input!=7)
    {
      printf("\n\t\tMain Menu\n");
      printf("\t\t---------\n");
      printf("1. Perfrom Left Bit Shift Operation (one value)\n");
      printf("2. Perfrom Right Bit Shift Operation (one value)\n");
      printf("3. Perform Binary AND Operation (two values)\n");
      printf("4. Perorm Binary OR Operation (two values)\n");
      printf("5. Perorm Binary One's complement (~) Operation (one value)\n");
      printf("6. Perorm Binary XOR Operation (two values)\n");
      printf("7. Quit\n");
      /*input is an int value, but it is designed to determine a letter input */
      
      scanf("%d", &input);

      switch (input) 
	{
	case 1:
	  printf ("\nEnter a base 10 integer: ");
	  scanf("%d", &value);
	  printf("\nEnter number of places to shift bit: ");
	  scanf("%d", &shift);
	  printf("\n\n\tEntered Integer: "); showbits(value);printf("(Base 10 %d )\n", value);
	  value=value<<shift;
          printf("\tLift Shifted: "); showbits(value);printf("(Base 10 %d )\n", value);
	  break;
	
	case 2:	  
	  printf ("\nEnter a base 10 integer: ");
	  scanf("%d", &value);
	  printf("\nEnter number of places to shift bit: ");
	  scanf("%d", &shift);
	  printf("\n\n\tEntered Integer: "); showbits(value);printf("(Base 10 %d )\n", value);
	  value=value>>shift;
          printf("\tLift Shifted       : "); showbits(value);printf("(Base 10 %d )\n", value);	 
	  break;
	 
	case 3:
	  printf ("\nEnter two base 10 Integers, seperated by a space: ");
          scanf("%d %d", &value,&value2);
          printf("\n\n\tEntered Integer 1: "); showbits(value);printf("(Base 10 %d )\n", value);
	  printf("\tEntered Integer 2    : "); showbits(value2);printf("(Base 10 %d )\n", value2);
	  value=value&value2;
	  printf("\tAND'ed               : "); showbits(value);printf("(Base 10 %d )\n", value);
	  break; 
	  case 4:
	    printf ("\nEnter two base 10 Integers, seperated by a space: ");
	    scanf("%d %d", &value,&value2);
	    printf("\n\n\tEntered Integer 1: "); showbits(value);printf("(Base 10 %d )\n", value);
            printf("\tEntered Integer 2    : "); 
	    showbits(value2);printf("(Base 10 %d )\n", value2);
	    value=value | value2;
	    printf("\tOR'ed                :"); showbits(value);printf("(Base 10 %d )\n", value);
	    break; 
	case 5:
	  printf ("\nEnter a base 10 integer: ");
          scanf("%d", &value);
	  printf("\n\n\tEntered Integer: "); showbits(value);printf("(Base 10 %d )\n", value);
	  value=~value;
	  printf("\t~'ed               :"); showbits(value);printf ("Base 10 %d )\n",value);
      
	   break;	
	 
	case 6:
	  printf ("\nEnter two base 10 Integers, seperated by a space: ");
          scanf("%d %d", &value,&value2);
          printf("\n\n\tEntered Integer 1: "); showbits(value);printf("(Base 10 %d )\n", value);
	  printf("\tEntered Integer 2: "); 
	  showbits(value2);printf("(Base 10 %d )\n", value2);
	  value=value^value2;
	  printf("\tXOR'ed           : "); showbits(value);printf("(Base 10 %d )\n",value);
	case 7:
	
	  break;
	default:
	  printf ("Please enter 1-7 as indicated by the menu.\n");
	}
    }
}
int showbits(int num)
{
  int i;
 
  
   
  for (i = 31; i >= 0; i--)
    {
      printf("%d",(num&(1<<i)) >> i); /* read i'th bit */
    }
  
}
