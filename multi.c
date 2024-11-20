#include<stdio.h>
#include"main.h"



void multi_num(List **head, List **tail, List2 **head2, List2 **tail2, RList **head3, RList **tail3)
{
    List *temp1 = *head;
    List2 *temp2 = *head2;
    RList *temp3 = *tail3;
    if ((*tail) -> num == 0 || (*tail2) -> num == 0) {
	printf("0\n");
	return;
    }
    int len1 = 0;
    int len2 = 0;
    while (temp1 != NULL)
    {
	len1++;
	temp1 = temp1->next;
    }
    temp1 = *tail;
    while (temp2 != NULL) {
	len2++;
	temp2 = temp2->next;
    }
    temp2 = *tail2;

    // Create a result array to store intermediate results
    int result_size = len1 + len2;
    int *result_array = (int *)calloc(result_size, sizeof(int));
    int i=0;
    int j;
    while (temp1 != NULL)
    {
	j = i;
	temp2 = *tail2;
	while (temp2 != NULL)
	{
	    result_array[j] = result_array[j] + (temp1->num * temp2->num);
	    temp2 = temp2 -> prev;
	    j++;
	}
	temp1 = temp1 -> prev;
	i++;
    }
    /*
    for (int i = 0; i<result_size; i++)
    {
	printf("%d  ", result_array[i]);
    }
    printf("\n");
    */
    int carry = 0;
    for (int i =0; i<result_size; i++)
    {
	result_array[i] = result_array[i] + carry;
	if (result_array[i] > 10000)
	{
	    carry = result_array[i] / 10000;
	    result_array[i] %= 10000;
	}
	if (result_array[i] != 0)
	{
	    RList *new = malloc(sizeof(RList));
	    if (*head3 == NULL)
	    {
		new -> num = result_array[i];
		new -> prev = NULL;
		new -> next = NULL;
		*head3 = new;
		*tail3 = new;
	    }
	    else
	    {
		new -> num = result_array[i];
		new -> prev = NULL;
		new -> next = *head3;
		(*head3) -> prev = new;
		*head3 = new;
	    }
	}

    }
    free(result_array);
    print_list3(*head3);



}
