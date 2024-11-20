#include<stdio.h>
#include"main.h"



void div_num(List **head, List **tail, List2 **head2, List2 **tail2, RList **head3, RList **tail3)
{
    List *temp1 = *head;
    List2 *temp2 = *head2;
    RList *temp3 = *head3;
    int len1=0;
    int len2 = 0;
    while (temp1 != NULL)
    {
	len1++;
	temp1 = temp1 -> next;

    }
    temp1 = *tail;
    while (temp2 != NULL)
    {
	len2++;
	temp2 = temp2 -> next;
    }
    temp2 = *tail2;
    
    //checking if 2nd operand is greater then printing zero directly
    if ((len1 < len2) || ( (*head) -> num > (*head2) -> num ))
    {
	printf("0\n");
	return;
    }
    else if (len1 >= len2)
    {
	// Convert divisor linked list to an integer
	List2 *current = *head2;
	long int divisor = 0;
	while (current) {
	    divisor = divisor * 10000 + (long int )current->num;
	    current = current->next;
	}

	// Process the dividend linked list
	List *current0 = *head;
	long int current_value = 0;
	RList *dummy_head = (RList *)malloc(sizeof(RList));
	dummy_head->num = 0;
	dummy_head->next = NULL;
	dummy_head->prev = NULL;
	*head3 = dummy_head;
	*tail3 = dummy_head;

	int has_significant_digit = 0; // To track leading zeros

	while (current0) {
	    current_value = current_value * 10000 + (long int)current0->num;
	    long int quotient_digit = current_value / divisor;
	    current_value = current_value % divisor;

	    // Add the quotient digit to the result list
	    if ( has_significant_digit != 0 || quotient_digit > 0 ) {
		has_significant_digit = 1;
		RList *new_node = (RList *)malloc(sizeof(RList));
		new_node->num = quotient_digit;
		new_node->next = NULL;
		new_node->prev = *tail3;
		(*tail3)->next = new_node;
		*tail3 = new_node;
	    }

	    current0 = current0 ->next;
	}

    //print_list4(*head3);
	if ((*head3) -> num == 0)
	{
	    *head3 = (*head3) -> next;
	    free((*head3) -> prev);
	    (*head3) -> prev = NULL;
	}
	else if ("")

	if (*tail3 == dummy_head) {
	    *head3 = dummy_head->next;
	    if (*head3) {
		(*head3)->prev = NULL;
	    }
	    free(dummy_head);
	}
    }
    //print_list4(*head3);
    print_list8(*head3);

}


void print_list8(RList *head) {
    if (!head) {
	printf("0\n");
	return;
    }

    // Create a string buffer to store the result
    char buffer[1000];
    char *ptr = buffer;
    int first = 1;

    while (head) {
	if (first) {
	    // Print the first segment without leading zeros
	    ptr += sprintf(ptr, "%d", head->num);
	    first = 0;
	} else {
	    // Print subsequent segments with leading zeros
	    ptr += sprintf(ptr, "%04d", head->num);
	}
	head = head->next;
    }
    printf("%s\n", buffer);
}



