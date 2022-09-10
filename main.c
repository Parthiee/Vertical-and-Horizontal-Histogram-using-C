#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int throw_die();
int* frequency_array(int arr[],int size);
void print_horizontal_histogram(int* frequency);
void print_vertical_histogram(int* frequency);

int main()  
 {
   
   int i,value[100],input;
   int* frequency;
   int* frequency_dummy = calloc(6,sizeof(int));
   time_t t;
   srand((unsigned) time(&t));
   while(1) {
   printf("\nSelect 1 to throw the die\n"
   	  "Select 2 for horizontal histogram\n"
   	  "Select 3 for vertical histogram\n"
   	  "Select 4 to print the frequency\n"
   	  "Select 5 to quit\n");
   scanf("%d",&input);
   if(input==1) 
     {
      for(i=0;i<100;++i) 
   	{
   	 value[i]=throw_die();
   	}
   frequency=frequency_array(value,100);
   frequency_dummy=frequency_array(value,100);
    }
   else if(input==3) print_vertical_histogram(frequency);
   else if(input==4)
    {
     for(int i=0;i<6;++i)
      {
       printf("%d ",frequency_dummy[i]);
      }
    }
    else if(input==5) exit(1);
    else if(input==2) print_horizontal_histogram(frequency);  
    else printf("Choose valid numbers\n");
 }	
}

  
int* frequency_array(int arr[],int size)
 {
 int* frequency;
 frequency=(int*)calloc(6,sizeof(int));
    for(int i=0;i<size;++i) 
      {
      	if(arr[i+1]==1) frequency[0]++;
      	else if(arr[i+1]==2) frequency[1]++;
      	else if(arr[i+1]==3) frequency[2]++;
      	else if(arr[i+1]==4) frequency[3]++;
      	else if(arr[i+1]==5) frequency[4]++;
      	else if(arr[i+1]==6) frequency[5]++;
      }
      return frequency;
 }
     	
void print_horizontal_histogram(int* frequency) 
 {
  printf("\t\t\t Horizontal Histogram\n\n");
  for(int i=0;i<6;++i) 
   	{
    	 printf("%d |",i+1);
     	 for(int j=0;j<frequency[i];++j)
      		{
      		  printf("*");
      		 }
      	 printf("\n");
      	}
 }
        
int throw_die() 
 {
  int value=rand()%6+1;
  return value;
 }
 
void print_vertical_histogram(int* frequency)
 {
  int max=-1;
  printf("\t\t\t Vertical Histogram\n\n");
  for(int i=0;i<6;++i)
   {
     if(frequency[i]>max) max=frequency[i]; //finds the maximum
   } 
   for(int i=max;i>0;--i) 
    {
     for(int j=0;j<6;++j)
      {
       if(frequency[j]==i)
        { 
          printf("* "); 
          frequency[j]--;
        }
       else printf("  ");
      }
      printf("\n");
    }
   for(int i=0;i<6;++i) printf("- ");
   printf("\n");
   for(int i=0;i<6;++i) printf("%d ",i+1);
    
 }   
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

 
