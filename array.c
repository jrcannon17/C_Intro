#include <stdio.h>

int main()
{

  int i,j,size;
  int av,bv;

  printf("Enter the size of the arrays: ");
  scanf("%d",&size);

  int a[size];
  int b[size];
  int arrayReturn[sizeof(a) + sizeof(b)];
  int count = 0;
  printf("Enter elements of first array: ");


  for (i=0; i<size; i++)
    { scanf("%d",&av);
      a[i]=av;
      /* printf("array a %d",a[i]);*/

      printf("Enter elements of second array: ");

      for (j=0; j<size; j++)
	{ scanf("%d",&bv);
	  b[j]=bv;
	  if(a[i]==b[j])
	    count = count + 1;
	  printf("count%d",count);
	  arrayReturn[count] = a[i];
	}
      printf("intersection %d",arrayReturn);
    }
  return(0);
}
