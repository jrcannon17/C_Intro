/*Filename: A4.c *
 *Part of: A590 Assignment 4 (Criket Mini Game and Linked Nodes) *
 *Created by: Joshua Cannon *
 *Created on: 10/08/2018 *
 *Last Modified by: Joshua Cannon *
 *Last Modified on: 10/12/2018 *not complete| Cricket output, Linked List Functions
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/*since this is a big program, I will not be commenting unless necessary (e.g. function logic, incomplete, errors etc.*/

void menu();

struct cricket
{
  char firstname[32];
  char teamname[32];
  double ba;
};

void Cricket();

void Displaystats(struct cricket *arr,/*char *arr2,*/int num/*,int total*/);/*team display incomplete*/


struct Node 
{ 
  int data; 
  struct Node *next; 
};
 
/*pointer functions and linked lists HIGHLY influenced by the Stanford reference on the website. Thank you Jeff for the source doc. Other help offerred: cohort Nicolas Serrara, Asia, and Laura Calloway */

int linkfunc();
void printList(struct Node* head); 
void insert_beginning(struct Node** head_ref, int new_data);
void insert_end(struct Node** head_ref, int new_data);  
int delete_last(struct Node* head_ref); 
int delete_beginning(struct Node** head_ref);
void insert_middle(struct Node** head_ref,int new_data);
void modify(struct Node* head_ref,int replace, int new_data);
void position(struct Node* head_ref, int position);

/*main starts here*/

int main(void) 
{ 

  menu(); 
  return(0); 
}
/* MAIN ENDS */

void menu()
{
  int input;
  printf("\nWelcome!\n");
  printf("Select Which Program You Would Like to Try\n");
  printf("\n-- Menu Selection --\n");

printf("Press 1 for Cricket Player List Setup\n");
printf("Press 2 for Link List Manipulation with Nodes\n");
printf("Press 3 to Exit The Program Entirely\n");
scanf("%d",&input);

 switch(input)
   {
   case 1:
     Cricket();
     break;

   case 2:
     linkfunc();
     break;
      
   case 3:
     printf("Thank You and Goodbye\n");
     break;

   default:
  printf("Select 1,2, or 3 please\n");
  break;
      }
}
void Cricket()
{
  
    int i,num;
    int total;
    char ch;

    struct cricket members[100]; /*this number is exageratted. It was supposed to be that int Total would determine how big members was going to be*/

    printf("Enter the number of teams you wish to record: ");
    scanf("%d",&num); /*a 2D array to hold teams for later use*/
    char teamname[num][32];

    for (i=0;i<num;i++)
      {
	printf("Enter the name(s) of the teams: \n");
	scanf("%s",teamname[i]);
      }
    printf("Enter the TOTAL number of players for all teams: ");
    scanf("%d",&total);

    for (i=0;i<total;i++)
      {/*it is a weighted coin toss but typing anything outside these parameters WILL most likely give a seg fault*/
	printf("Enter Player %d name, Team name, and batting average (spaces in between each entry): ",i+1);
	scanf("%s%s%s",members[i].firstname,members[i].teamname,members[i].ba);
      }
    printf("Listing of players and batting average according to team names: ");
    Displaystats(members,/*teamname,num,*/total);

  }
  void Displaystats(struct cricket *arr,/*char *arr2,int num,*/int total) 

/*could not find a way to compare a 2D array with one array struct to compare a single element. That element is teamname
if teamname[i] == arr2[i].teamname
then true
else false

I also did not want someone to just enter any team they wanted when being asked to put the players in the teams*/

{
    int i,j;
    printf("\n");


    /*   for(j=0;j<total;j++)
	 if (arr[j].teamname==arr2[j])
	{printf("%s\n",arr[i].teamname);
	}*/

    for(i=0;i<total;i++)
      {
	printf("Team:%s\nPlayer:  %s    Batting Average %lf\n",arr[i].teamname, arr[i].firstname, arr[i].ba);
      }
  }

/*INTRO TO LINK LIST FUNCS*/

/*My familiarity with link lists is very green. The entire reason Cricket was never completed was because I quickly realized this portion would take up the majority of my time. Ironically, writing comments did help with cognitive learning of linked list however

The Stanford reference got me started with adding nodes, but it quickly went downhill from there. I now see the logic behind each activity in a link list can be extremely different from the last, but I chose to run with it anyways due to the time constrainst against me. I do not know why I use double ** in some funcs and in others, I don't. I don't know why I need to use an & for my head node to work to display in a function and neither do I know why malloc in Linkfunc shuts it down completely. I had to brute force my way to get even the most simple functions to work (i.e. printList). AI's from other labs introduced different concepts and methods to make this work but that only made it more difficult*/

int linkfunc() 
{ 
  int num,pos,replace; 
  int input; 
  struct Node* head = NULL;
   
  /* head = malloc(sizeof(struct Node));*/
  
  printf("This program initializes a linked list\n");
  printf("It starts out empty, so the first thing you probably want to do is insert a node.\n"); 
 
 
   while(input != 8) { 
     printf("\nPlease enter your choice\n"); 
     printf("1. INSERT a node at the BEGINNING of linklist\n"); 
     printf("2. INSERT a node at the END of linklist\n"); 
     printf("3. DELETE a node at the BEGINNING of linklist\n"); 
     printf("4. DELETE a node from the END of linklist\n"); 
     printf("5. INSERT a node in the MIDDLE of linklist\n");
     printf("6. DELETE a node from the MIDDLE of linklist\n"); 
     printf("7. MODIFY any node in linklist\n"); 
     printf("8) EXIT\n"); 
     scanf("%d", &input); 
     switch(input) { 
     case 1: 
       printf("Enter the value for the node you want to insert at the beginning\n"); 
       scanf("%d", &num); 
       insert_beginning(&head,num);
       printList(head);
       break; 
     case 2:
       printf("Enter your node in the list\n");
       scanf("%d", &num);
       insert_end(&head,num);
       printList(head);
       break; 
     case 3:
       delete_beginning(&head);
       printList(head);
       break; 
     case 4:
       delete_last(head);/*gives seg fault if used first*/
       printList(head);
       break; 
     case 5:
       printf("Enter the value of the nodeafter which you want to insert a new node\n");
       scanf("%d",&pos);/*finds position of node entered to determine where the middle is*/
       printf("Enter value of new node\n");
       scanf("%d",&num);
       /*insert_middle(&head,pos,num);*/
       printList(head); 
       break; 
     case 6:
       printf("Not Available at this time"); 
       break; 
     case 7:
       printf("Enter the value of the node you want to modify\n");
       scanf("%d",&replace);
       printf("Enter the value for this node\n");
       scanf("%d",&num);
       /* modify(head,replace,num);*/
       printList(head); 
       break; 
     case 8: 
       printf("Goodbye...\n"); 
       input = 8; 
       break; 
     default: 
       printf("That is not a valid menu option\n"); 
       break; 
     } 
   }free(head); 
 }


void insert_beginning(struct Node** head_ref, int new_data)  
 {  
   /*creates a new node and frees up the space for it*/						\
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));  
  /* convert data into new_data */
   new_node->data = new_data;  
  /*next_node becomes new head*/
   new_node->next = *head_ref;  
  /*establishd as new node */  
   *head_ref= new_node;  
}  

void insert_end(struct Node** head_ref,int new_data)  
 {  

   struct Node* current = *head_ref; /*places head as current in list*/
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); /*make new node to insert*/
   /*new_node becomes part of new int data in lisk*/
   new_node->data = new_data;
   /*end NODE has NULL after it, making it the last node*/
   new_node->next = NULL;
   
   if (current == NULL) {
     *head_ref = new_node;
   }
   else {
     // Locate the last node
     while (current->next != NULL) {
       current = current->next;
     }
     current->next = new_node;
   }
 }
  
int delete_beginning(struct Node** head_ref)
{
  /*why is this negative one? I saw it in Program4 dealing with deletion so I used it here*/
  int retval = -1;
  struct Node* next_node = NULL;

  if (*head_ref == NULL)
    {
      return -1;
    }
  next_node = (*head_ref)->next;
  free(*head_ref);/*free space after deletion*/
  *head_ref = next_node;
  return retval;
}
int delete_last(struct Node* head_ref)
{
  int retval = 0;
  /* if there is only one item in the list, remove it */
  if (head_ref->next == NULL) {
    retval = head_ref->data;
    free(head_ref);
    return retval;
  }

  /* place head in current while reaching outwards two places to delete last node */
  struct Node* current = head_ref;
  while (current->next->next != NULL) {
    current = current->next;
  }

  /*have to now put current value back */
  retval = current->next->data;
  free(current->next);/*free space*/
  current->next = NULL;
  return retval;
}
void printList(struct Node *head) 
{ 
  printf("\nThe link list currently has these nodes:\n"); 
  while (head != NULL) 
    { 
      printf(" %d->", head->data); /*keep jumping header so every node is read*/
      head = head->next; 
    }
} 


/*void insert_middle(struct Node** head_ref,int position(), int new_data)
{

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  struct Node* after = (*head_ref)->next;

  while (after && after->next)
    {
      pre=pre->next;
      after=after->next->next;
    }
  new_node->next = pre->next;
  pre-> = new_node;

  }
*/
/*void modify(struct Node* head_ref,int replace, int new_data)
{
  
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* current = head_ref;
  
   
  if(head_ref==NULL) {
    printf("There are no nodes to modify");
    return;
  } 

  current = head_ref;
  while(current->next!=NULL) {
    if(current->data == replace) {
      current->data = new_data;
      return;
    }
      
    current = current->next;
    
  }
    
}
*/

