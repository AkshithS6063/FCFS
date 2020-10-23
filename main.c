#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int queue[20],a,b,n,head,end,i,j;
void sort()
{
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(queue[j]>queue[j+1])
      {
        int temp=queue[j];
        queue[j]=queue[j+1];
        queue[j+1]=temp;
      }
    }
  }
}

void fcfs()
{
  int seektime=0,s;
  printf("\tFCFS\n\n");
  for(i=0;i<n;i++)
  {
    s=abs(queue[i]-head);
    seektime+=s;
  }
  printf("Seek time = %d\n",seektime);
  printf("The Squence is\n%d\t",head);
  for(i=0;i<n;i++)
  {
    printf("%d\t",queue[i]);
  }
  printf("\n");
}

void scan()
{
  int k[20],seek=0,diff,size;
  sort();
  printf("The order is:\n%d->",head);
  int i=0,temp=-1;
  while(queue[i]<head)
    i++;
  temp=i;
  while(i!=n)
  {
    printf("%d->",queue[i]);
    i++;
  }
  printf("%d->",end);
  i=temp;
  if(temp-1>=0)
      i=temp-1;
  while(i>=0)
  {
    printf("%d->",queue[i]);
    i--;
  }
  if(i==-1)
  {
    printf("END\n");
  }
  for(i=0;i<n;i++)
  {
    if(i==0)
    {
      a=queue[i];
    }      
  }
  seek=abs((end-head)+(end-a));
  printf("\nSeek Time is %d\n",seek);
}

void cscan()
{
  sort();
  int seek;
  printf("The order is\n%d->",head);
  int i=0,temp=-1;
  while(queue[i]<head)
    i++;
  while(i!=n)
  {
    printf("%d->",queue[i]);
    i++;
  }
  printf("%d->0->",end);
  i=0;
  while(queue[i]<head)
  {
    printf("%d->",queue[i]);
    i++;
  }
  printf("END\n");
  j=0;
  while (queue[j]<head)
  {
    j++;
    b=queue[j-1];
  }
  printf("%d\n",b);
  seek=abs((end-head)+(end-0)+(b-0));
  printf("%d",seek);
}

int main()
{
  int x;
  int ch;
  printf("Enter head\n");
  scanf("%d",&head);
  printf("Enter the end position of the disk\n");
  scanf("%d",&end);
  printf("Enter the number of disk scheduling needed\n");
  scanf("%d",&n);
  printf("Enter the positions\n");
  for(i=0;i<n;i++)
  {
    printf("Position %d\n",i);
    scanf("%d",&queue[i]);
    printf("\n");
  }
  do
  {
    printf("Choose the disk scheduling algorithm\n");
    printf("\n1.FCFS\n2.SCAN\n3.CSCAN\n");
    scanf("%d",&x);
    
    switch(x)
    {
      case 1: fcfs();
      break;
      case 2: scan();
      break;
      case 3: cscan();
      break;
    }
    printf("\n");
    printf("\nDo you wish to continue?\n\t(1 or 0)\n");
    scanf("%d",&ch);
    printf("%d\n",ch);
  } 
  while (ch ==1);  
}