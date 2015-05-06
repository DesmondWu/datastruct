
#include "stdio.h"
#include "stdlib.h"
typedef struct
{
    int data;
    struct link *next;
}link;

//add new link with data to select_link
int add(link *pSelect_link,int idata)
{
	link *plnew,*pcur;

	if(pSelect_link==NULL) return -1;

	if(pSelect_link->next==NULL)
	{
		pcur=pSelect_link;
	}
	else
	{
		for(pcur=pSelect_link->next;pcur->next!=NULL;pcur=pcur->next);
	}

	plnew = (link*)malloc(sizeof(link));
	if(plnew==NULL) return -1; //create memory fail

	pcur->next=plnew;
	plnew->next=NULL;
	plnew->data=idata;
	return 0;
}
//delete next link of select_link 
int del(link *pSelect_link)
{
	if(pSelect_link->next == NULL)
		return -1; //Already delete ;

	pSelect_link->next=NULL;
	return 0;
}
//cat link
void linkcat(link *pselect_link)
{
	link *cur;
	int i;
	for(cur=pselect_link,i=0;cur!=NULL;cur=cur->next,i++)
	{				
		printf("idx[%d]=%d \n",i,cur->data);	
	}
}
//set trap to connect select_link 
void trap(link *pselect_link,int count)
{
	int i;
	link *pcur,*ptrap;
	for(pcur=pselect_link,i=0;pcur!=NULL;pcur=pcur->next,i++)
	{				
		if(count==i)
			ptrap=pcur;
		if(pcur->next==NULL)
		{
			pcur->next=ptrap;
			return;
		}
	}
}
//select_link loop checker hash with pRecord_link
int hash(link *pSelect_link,link *pRecord_link)
{
/*	sample code
  HashSet nodesSeen = new HashSet();
  Node currentNode = startNode;
  do {
    if (nodesSeen.contains(currentNode)) return true;
    nodesSeen.add(currentNode);
  } while (currentNode = currentNode.next());
  return false;
*/  
}
//select_link loop checker nlogn(btree) with pRecord_link
int btree(link *pSelect_link,link *pRecord_link)
{
	
}
//select_link loop checker n^2(doubly) with pRecord_link
int doubly(link *pSelect_link,link *pRecord_link)
{
	
}
int checkloop(link *pSelect_link)
{
	link *plnew,*pcur;
	link record={0,NULL};
	if(pSelect_link==NULL) return -1;//no link data

	if(pSelect_link->next==NULL) return 0; //no loop
	record.data=pSelect_link;
	for(pcur=pSelect_link->next;pcur->next!=NULL;pcur=pcur->next)
	{
		add(&record,pcur);
		doubly(pcur,&record);
	}
		
}
int main()
{
	link head={0,NULL};
	add(&head,1);
	add(&head,2);
	add(&head,3);
	add(&head,4);
	linkcat(&head);
	trap(&head,2);
	linkcat(&head);
	return 0;
}