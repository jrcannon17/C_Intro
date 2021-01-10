#include <stdio.h>

void arrays()
{
  int i,n,j;
  printf("Enter the size of the arrays:\n");
  scanf("%d",&n);

  int a1[n];
  int a2[n];
  int intersection[2*n], unions[n];
  printf("Enter elements of the first array:\n");

  for (i = 0; i < n; i++)
    {
      scanf("%d",&a1[i]);
    }

  for(i=0; i<n; i++)
    {
      for(j=i+1;j<n;j++)
	{
	  if(a1[i]==a1[j])
	    {
	      printf("%d is a duplicate number",a1[i]);
	    }
	}
    }

  printf("Enter elements of the second array:\n");
  for (j = 0; j < n; j++)
    {
      scanf("%d",&a2[j]);
    }
  int indexs = -1;
   
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        {
	  if(a1[i] == a2[j])
            {
	      intersection[++indexs] = a2[j];
	      	                 
 }
        }
    }


printf("Intersection:\n");
for(i = 0; i <= indexs; i++)
  printf("%d",intersection[i]);
printf("\n");
 printf("the union of the two arrays is: ");

 i = 0;
 j = 0;

 
 while(i < n && j < n)
   {
     if(a1[i] < a2[j])
       printf("%d", a1[i++]);
     else if(a2[j] < a1[i])
       printf("%d", a2[j++]);
     else
       {
	 printf("%d", a1[i]);
	 i++; j++;
       }
   }
 
 /* Print remaining elements of the larger array */
 
 while(i < n)
   printf("%d", a1[i++]);
 while(j < n )
   printf("%d", a2[j++]);

 printf("\n");
}



int main()
{
  arrays();
  return(0);
}
