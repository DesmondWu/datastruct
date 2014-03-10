#include "stdio.h"
typedef struct 
{
  int value;
  struct data *next;
}data;
int list(data *input)
{
   static data *start=-1;
   data *point,*last=-1;
   for(point=start;start!=-1;point=point->next)
   {
      if(point->value ==input->value)
      {
        printf("input can't be same value!!");
        return -1;
      }
      if(point->next==-1) break;
   }

   if(start==-1)
    {
      start=input;
    }
    else
    {
      for(point=start;;last=point,point=point->next)
      {
        if(point->value < input->value)
        {
          if(last==-1)
          {
            start=input;
          }
          else
          {
            last->next=input;
          }
          input->next=point;
          break;
        }
        if(point->next==-1) break;
      }
      if(input->next ==-1)
      {
        point->next=input;
      }
      printf("your list:\n");
      for(point=start;;point=point->next)
      {
        printf("%d ",point->value);
        if(point->next==-1) break;
      }
    }
    return 0;
}
int main()
{
  data *start=-1,*input,*point,*last=-1;

  while(1)
  {
    input=(data*)malloc(sizeof(data));
    printf("\nplz input:");
    scanf("%d",&input->value);
    input->next=-1;
    printf("your input:%d\n",input->value);
    list(input);
  }
}

