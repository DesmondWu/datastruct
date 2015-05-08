/*
; Copyright (C) 2015 Desmond Wu <wkunhui@gmail.com>
;
; This software is licensed under the terms of the GNU General Public
; License version 2, as published by the Free Software Foundation, and
; may be copied, distributed, and modified under those terms.
;
; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.
; reference doc:http://blog.ostermiller.org/find-loop-singly-linked-list
*/
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
	if(checkloop(pselect_link)!=0)
	{
		printf("loop detected!!\n");
		return;
	}
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
//select_link loop checker hash 
int hash(link *pSelect_link)
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
//select_link loop checker nlogn(tree)
int tree(link *pSelect_link)
{
/*
sample code
http://web.mit.edu/~emin/www.old/source_code/red_black_tree/red_black_tree.c	
*/
}
//select_link loop checker n^2(doubly) 
int doubly(link *pSelect_link)
{
	link *pcur,*prec;
	link record={0,NULL};
	if(pSelect_link==NULL) return -1;//no link data
	if(pSelect_link->next==NULL) return 0; //no loop
	record.data=pSelect_link;
	for(pcur=pSelect_link->next;pcur!=NULL;pcur=pcur->next)
	{	
		for(prec=&record;prec!=NULL;prec=prec->next)
		{
			if(prec->data==pcur)
			{	
				return -1;
			}
		}
		add(&record,pcur);
	}
	return 0;	
}
int checkloop(link *pSelect_link)
{
	if(pSelect_link==NULL) return -1;//no link data

	if(pSelect_link->next==NULL) return 0; //no loop
	if(doubly(pSelect_link)) return -1;

	return 0;
		
}
int main()
{
	link head={0,NULL};
	int i;
	for(i=1;i<10;i++) add(&head,i);
	linkcat(&head);
	trap(&head,2);
	linkcat(&head);
	return 0;
}
