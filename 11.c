#include <stdio.h>
#include <stdlib.h>
typedef struct node	{
	int data;
	struct node *next;
	}node;
	node *list = NULL;
	
void ins_beg()	{
	int x;
	scanf("%d",&x);
	node *p;
	p = (node *)malloc(sizeof(node));
	p->data = x;
	p->next = list;
	list = p;
}
void ins_end()	{
	int x;
	scanf("%d",&x);
	node *p,*q;
	p = list;
	while(p->next != NULL)
		p = p->next;
	q = (node *)malloc(sizeof(node));
	q->data = x;
	q->next = NULL;
	p->next = q;
}

void del_beg()	{
	node *p;
	p = list;
	int x = p->data;
	printf("%d is deleted\n",x);
	list = p->next;
	free(p);
}
void del_end()	{
	node *p = list;
	node *q = p->next;
	while(q->next != NULL)	{
		p = q;
		q = q->next;
	}
	int x = q->data;
	printf("%d is deleted\n",x);
	p->next = NULL;
	free(q);
}

void display()	{
	int c = 0;
	node *p = list;
	while(p != NULL)	{
		c++;
		int y = p->data;
		printf("%d ",y);
		p = p->next;
	}
	printf("\n");
}
int main()	{
	int n;
	int choice;
	do	{
		printf("1)Insert at begining\n2)Insert at end\n4)Delete at beginging\n5)Delete at end\n7)Display\n8)Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			ins_beg();
			break;
			case 2:
			ins_end();
			break;
			break;
			case 4:
			del_beg();
			break;
			case 5:
			del_end();
			break;
			case 7:
			display();
			break;
			case 8:
			exit(0);
		}
	}while(choice!=8);
	return 0;
}
