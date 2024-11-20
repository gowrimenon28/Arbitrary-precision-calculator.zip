#include<stdio.h>
#include"main.h"

extern int neg1;
extern int neg2;
void sub_num(List **head, List **tail, List2 **head2, List2 **tail2, RList **head3, RList **tail3)
{
    List *temp1 = *head;
    List2 *temp2 = *head2;
    RList *temp3 = *tail3;
    int borrow = 0;
    int num1_neg = 0;
    int count1 = 0;
    int count2 = 0;
    while (temp1 != NULL)
    {
	count1++;
	temp1 = temp1 -> next;
    }
    temp1 = *tail;
    while (temp2 != NULL)

    {
	count2++;
	temp2 = temp2 ->next;
    }
    temp2 = *tail2;
    if (count1 > count2)
    {
	num1_neg = 0;
    }
    else if (count1 < count2)
    {
	num1_neg = 1;
    }
    else if ((*head) -> num > (*head2) -> num)
    {
	num1_neg = 0;
	//diff = num1 - num2 - borrow;
    }
    else
    {
	num1_neg = 1;
	if ((*head) -> next != NULL && (*head2) -> next != NULL)
	{
	    List *temp4 = (*head)->next;
	    List2 *temp5 = (*head2) -> next;
	    while (temp4 != NULL ||temp5 != NULL)
	    {
		if (temp4 -> num > temp5 -> num)
		{
		    num1_neg = 0;
		    //diff = num1 - num2 - borrow;
		    break;
		}
		else if (temp4 -> num < temp5 -> num)
		{
		    temp4 = temp4 -> next;
		    temp5 = temp5 -> next;
		}
		if (temp4 == NULL || temp5 == NULL)
		{
		    num1_neg = 1;
		    break;
		}
	    }
	}
    }

    while (temp1 != NULL || temp2 != NULL || borrow > 0)
    {
	int num1 = temp1 ? temp1->num : 0;
	int num2 = temp2 ? temp2->num : 0;
	int diff=0;
	if (num1_neg == 0)
	{
	    diff = num1 - num2 - borrow;
	}
	else
	{

	    diff = num2 - num1 - borrow;
	}

	if (diff < 0)
	{
	    diff = diff + 10000;
	    borrow = 1;
	}
	else
	{
	    borrow = 0;
	}
	RList *new = malloc(sizeof(RList));
	if (*head3 == NULL)
	{
	    new -> num = diff;
	    new -> prev = NULL;
	    new -> next = NULL;
	    *head3 = new;
	    *tail3 = new;
	}
	else
	{
	    new -> num = diff;
	    new -> prev = NULL;
	    new -> next = *head3;
	    (*head3) -> prev = new;
	    *head3 = new;
	}
	if (temp1)
	{
	    temp1 = temp1->prev;
	}
	if (temp2)
	{
	    temp2 = temp2->prev;
	}
	diff =0;

    }
    //print_list4(*head3);
    if ((*tail3) -> num == 0 && (*head3) -> num == 0)
    {
	printf("0\n");
	return;
    }
    else 
    {
	while ((*head3) -> num == 0)
	{
	    RList *temp = *head3;
	    *head3 = (*head3) -> next;
	    (*head3) -> prev = NULL;
	    free(temp);
	}
    }

    if (num1_neg || neg1)
    {
	printf("-");
	print_list3(*head3);
    }
    else
    {
	print_list3(*head3);
    }


}

