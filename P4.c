/*Filename: P4.c *
 *Part of: Program 4 A590 assignment(linked list and structures) *
 *Created by: Joshua Cannon *
 *Created on: 10/07/2018 *
 *Last Modified by: Joshua Cannon *
 *Last Modified on: 10/08/2018
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
 
int demo_function();

void DisplayStats(); /*if I put the arguments in right here, it displays all kinds of warnings and errors.
                      Since time is of essence, I have just left it the way it is; blank*/

struct person { /* "structure type name */
  char first[32]; 
  char last[32];
  int year; 
  double ppg; 
}; /* ; means end of structure type definition but could add additional var name for struture. right before       ; */

/*linked list structure per meeting 12*/

struct NODE {
  int number;
  struct NODE *next; /*establish pointer for linked list*/
};

/*prototypes specifically for the linked list */

void append_node(struct NODE *llist, int num);
void delete_node(struct NODE *llist, int num);
int search_value(struct NODE *llist, int num);
void display_list(struct NODE *llist);
int linkfunc();

/*main*/ 
int main(void)

{

demo_function();
linkfunc();
  
  return(0);

}

int linkfunc()
{
  int num = 0;
  int input = 1;
  int retval = 0;
  struct NODE *llist;

  /*call malloc to allocate size in bytes when function calls on it. Establishing the NULL node but also all    owing us to create new nodes */
  llist = (struct NODE *)malloc(sizeof(struct NODE));
  llist->number = 0;
  llist->next = NULL;
  
  /*establishing switch case for our menu*/
while(input != 0) {
    printf("\n-- Menu Selection --\n");
    printf("0) Quit\n");
    printf("1) Insert\n");
    printf("2) Delete\n");
    printf("3) Search\n");
    printf("4) Display\n");
    scanf("%d", &input);
    switch(input) {
 
      
    case 0:
      printf("Goodbye ...\n");
      input = 0;
      break;
      /*outside of case 0, none of these will work until the function is created so create the functions first, otherwise, there will be no reference for the case to refer too*/
    case 1:
      printf("Your choice: 'Insertion'\n");
      printf("Enter the value which should be inserted: ");
      scanf("%d", &num);
      append_node(llist, num);
      break;
 
    case 2:
      printf("Your choice: 'Deletion'\n");
      printf("Enter the value which should be deleted: ");
      scanf("%d", &num);
      if((retval = search_value(llist, num)) == -1) /*check to see if number is in the list, if it is, then delete*/
	printf("Value '%d' not found\n", num);
      else
	delete_node(llist, num);
      break;
 
    case 3:
      printf("Your choice: 'Search'\n");
      printf("Enter the value you want to find: ");
      scanf("%d", &num);
      if((retval = search_value(llist, num)) == -1)
	printf("Value '%d' not found\n", num);
      else
	printf("Value '%d' located at position '%d'\n", num, retval);
      break;
 
    case 4:
      printf("You choice: 'Display'\n");
      display_list(llist);
      break;
      
    default:
      printf("That is not a valid menu option\n");
      break;
    } /*exit switch case*/
 }   /*exit while loop*/
 free(llist); /*free up space malloc has not used*/
}

void append_node(struct NODE *llist, int num) 

{
  /*using malloc to move pointers for new appending nodes*/
  while(llist->next != NULL)
  llist = llist->next;
  llist->next = (struct NODE *)malloc(sizeof(struct NODE));
  llist->next->number = num;
  llist->next->next = NULL;
}

void delete_node(struct NODE *llist, int num) {
  
/*we have to do this in different ways depending on the position of the node. Mainly because this is in sequence and not in a double linked list */ 
 
  struct NODE *temp; /*use temp to store pointer if node found. Remember, pointers are the chains that connect the list. If we lose the pointer, the list is broken and thus, no more link */
  temp = (struct NODE *)malloc(sizeof(struct NODE));
  if(llist->number == num) 

    {
    /* remove the node */
    temp = llist->next;
    free(llist); /*free memory of deleted node */
    llist = temp; /*pointer is no longer in temp*/
  } 
  else {
    while(llist->next->number != num)
      llist = llist->next;
    temp = llist->next->next;
    free(llist->next); /*again, free up the memory for removed node */
    llist->next = temp;
  }
}

int search_value(struct NODE *llist, int num) 
{
  int retval = -1; /*return value -1*/
  int i = 1;
  while(llist->next != NULL) /*while the node searched is not the NULL node*/

{
    if(llist->next->number == num)
      return i;
    else
      i++;
    llist = llist->next;
  }
  return retval;
}


void display_list(struct NODE *llist) 
{
  while(llist->next != NULL) {
    printf("%d ", llist->number);
    llist = llist->next;
  }
  printf("%d", llist->number);
}

int demo_function()
{

  /*initializing class strucutre like an array. MUCH more easier and cleaner*/
  struct person class[10] = {
    {"Jane","Doe", 2004, 5.2},
    {"Brian","Smith",2005,4.9},
    {"Jamie","Fox",2005,3.0},
    {"Trish","Underwood",2004,3.3},
    {"Malice","Hardhitter",2006,6.0},
    {"McGregor","Lost",2018, 0.0},
    {"Connell","StillLost",2018,0.0}
  };

  /*second method. Much more tedious but it is here for future reference*/

  /*  class[0].year=2004; 
  class[0].ppg=5.2;
  strcpy(class[0].first,"Jane");
  strcpy(class[0].last,"Doe");

  class[1].year=2005; 
  class[1].ppg=4.9;
  strcpy(class[1].first,"Brian");
  strcpy(class[1].last,"Smith");

  class[2].year=2004; 
  class[2].ppg=3.2; 
  strcpy(class[2].first,"Jamie");
  strcpy(class[2].last,"Fox");

  ----END OF SECOND REFERENCE---- */

  /*call the display stats function*/
   DisplayStats(class);
}

/*there is another way I found, and it uses sizeof/sizeof with pointers. I want to include this to test but limited on time for the assignment. Since I've declared the size of the array, the compiler doesn't have an issue with DisplayStats. */

void DisplayStats(struct person *arr) /*two ways I tried to do this: one is with arr[] and the other is with arr pointer */
{
  int i;
  printf("\n");

  for(i=0;i<7;i++) /*set i less than size of array*/
    { printf("%s, %s:  %lf PPG in %d\n",arr[i].last, arr[i].first, arr[i].ppg, arr[i].year); /*this setup is per Hoover */
    }

}
