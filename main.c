/* # Arbitrary-Precision-Calculator

NAME:Gowri Menon
Date:18-09-24

1. Addition: Perform addition on arbitrarily large numbers.
2. Subtraction: Subtract one arbitrarily large number from another.
3. Multiplication: Multiply large numbers with precise results.
4. Division: Divide large numbers and obtain both quotient and remainder.

DATA STRUCTURES

Double Linked List

We use a double linked list to store each digit of the large numbers. This allows efficient insertion, deletion, and traversal of digits, which is crucial for performing arithmetic operations on numbers with many digits.
1. Node: Each node in the list represents a four digit.
2. List: The list can grow dynamically to accommodate numbers of any length.

ADVANCED C TECHNIQUES

This project utilizes several advanced features of C to manage memory and optimize performance:
1. Dynamic Memory Allocation: To handle numbers of varying lengths.
2. Pointer Manipulation: For efficient traversal and modification of the linked list.
3. Custom Data Structures: Implementation of the double linked list for digit storage.
4. Error Handling: Robust handling of edge cases and invalid input.


EXAMPLE EXECUTION

To compile and run this project, you need a C compiler (GCC recommended)

./a.out

Enter input (num1 operator num2) : 6464667478339292928272 + 7774747746363637383393030

Result : 7781212413841976676321302

Do you want to continue (y/n) : y

Enter input (num1 operator num2) : -65464646467438383833847474 - 676733373738352424353

Result : -6546532320812122186271827

Do you want to continue (y/n) : y

Enter input (num1 operator num2) : 63535435363894242584849 * 53434353678333

Result : 339497492434119088964292717305376717

Do you want to continue (y/n) : y

Enter input (num1 operator num2) : 6464647484838625363737 / 6363633

Result : 1015873713150746

Do you want to continue (y/n) : n */





#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"



int neg1 = 0;
int neg2 = 0;
int both_neg = 0;

int main(int argc, char *argv[]) 
{
    char condition = 'y';
    while (condition == 'y')
    { 
	// Define two strings to store the numbers
	char str1[100], str2[100];
	// Define a character to store the operator
	char operator;

	//duplicate string to storing the operator
	//char dup_op[2];
	char input[200];


	//enter user input eg : 23421111111144 + 343641414411444
	printf("Enter input (num1 operator num2) : ");
	scanf(" %[^\n]", input);

	sscanf(input, "%[0-9-]%*c%c%*c%[0-9-]", str1, &operator, str2);


	if (str1[0] == '-' && str2[0] == '-')
	{
	    both_neg = 1;
	}
	if (str1[0] == '-')
	{
	    neg1 = 1;
	    int i =0;
	    while(str1[i] != '\0')
	    {
		str1[i] = str1[i+1];
		i++;
	    }
	}
	if (str2[0] == '-')
	{
	    neg2 = 1;
	    int i =0;
	    while(str2[i] != '\0')
	    {
		str2[i] = str2[i+1];
		i++;
	    }
	}
	List *head = NULL;
	List *tail= NULL;
	store_num1(&head,&tail,str1);
	//print_list(head);
	List2 *head2 = NULL;
	List2 *tail2 = NULL;
	store_num2(&head2, &tail2, str2);
	//print_list2(head2);
	RList *head3 = NULL;
	RList *tail3 = NULL; 
	switch (operator)
	{ 
	    case '+':
		{	    
		    if (head == NULL || head2 == NULL)
		    {
			printf("Syntax error pass 2 operands\n");
			return 0;
		    }
		    printf("Result : ");
		    if (both_neg == 1)
		    {
			printf("-");
			add_num(&head,&tail,&head2,&tail2,&head3,&tail3);
		    }
		    else if (neg1)
		    {
			sub_num(&head,&tail,&head2,&tail2,&head3,&tail3);
		    }
		    else if (neg2)
		    {
			sub_num(&head,&tail,&head2,&tail2,&head3,&tail3);
		    }
		    else
		    {
			add_num(&head,&tail,&head2,&tail2,&head3,&tail3);

		    }
		    break;
		}
	    case '-':
		{
		    if (head == NULL || head2 == NULL)
		    {
			printf("Syntax error pass 2 operands\n");
			return 0;
		    }
		    printf("Result : ");
		    if (neg1 == 1)
		    {
			printf("-");
			add_num(&head,&tail,&head2,&tail2,&head3,&tail3);
		    }
		    else 
		    {
			sub_num(&head,&tail,&head2,&tail2,&head3,&tail3);
		    }
		    break;
		}
	    case '*' :
		{
		    if (head == NULL || head2 == NULL)
		    {
			printf("Syntax error pass 2 operands\n");
			return 0;
		    }
		    printf("Result : ");
		    if (head2 == NULL)
		    {
			return 0;
		    }
		    if( (neg1 == 1 && neg2 == 0) || (neg1 == 0 && neg2 == 1) )
		    {
			printf("-");
			multi_num(&head,&tail,&head2,&tail2,&head3,&tail3);
		    }
		    else
		    {
			multi_num(&head,&tail,&head2,&tail2,&head3,&tail3);
		    }
		    break;
		}
	    case '/' :
		{
		    if (head == NULL || head2 == NULL)
		    {
			printf("Syntax error pass 2 operands\n");
			return 0;
		    }
		    printf("Result : ");
		    if (head2 == NULL)
		    {
			printf("num1\n");
			return 0;
		    }
		    if ((neg1 == 1 && neg2 == 0) || (neg1 == 0 && neg2 == 1))
		    {
			printf("-");
			div_num(&head,&tail,&head2,&tail2,&head3,&tail3);
			neg1 = 0;
			neg2 = 0;
		    }
		    else
		    {
			div_num(&head,&tail,&head2,&tail2,&head3,&tail3);
			both_neg = 0;
		    }
		    break;
		}
	    default:
		{
		    printf("Pass correct operator\n");
		}

	}
	neg1 = 0;
	neg2 = 0;
	both_neg = 0;
	printf("Do you want to continue (y/n) : ");
	scanf(" %c", &condition);
    }

    return 0;
}



void store_num1(List **head, List **tail, char str1[])
{
    int len1 = strlen(str1);
    int j = strlen(str1) -1;
    char str3[5];
    /*for (int i=0; i<len1/4 ; i++)
      {
      for (int k = 0; k<4; k++)
      {
      str3[3-k] = str1[j-k];
      }
      j = j - 4;
      str3[4] = '\0';*/
    while (j >= 0)
    {
	int k;
	for (k = 0; k < 4 && j >= 0; k++, j--)
	{
	    str3[3 - k] = str1[j];
	}
	while (k < 4) {
	    str3[3 - k] = '0';
	    k++;
	}
	str3[4] = '\0';
	int num1 = atoi(str3);
	List *new = malloc(sizeof(List));
	if (new == NULL)
	{
	    printf("Memory allocation failed.\n");
	    exit(1);
	}

	new->num = num1;
	new->prev = NULL;
	if (*head == NULL)
	{
	    *head = new;
	    *tail = new;
	} 
	else 
	{
	    new->next = *head;
	    (*head)->prev = new;
	    *head = new;
	}
    }

}



void store_num2(List2 **head2, List2 **tail2, char str2[])
{
    int len2 = strlen(str2);
    int j = strlen(str2) -1;
    char str3[5];
    /*for (int i=0; i<len2/4; i++)
      {
      for (int k = 0; k<4; k++)
      {
      str3[3-k] = str2[j-k];
      }
      j = j - 4;
      str3[4] = '\0'*/
    while (j >= 0) {
	int k;
	for (k = 0; k < 4 && j >= 0; k++, j--)
	{
	    str3[3 - k] = str2[j];
	}
	while (k < 4) {
	    str3[3 - k] = '0';
	    k++;
	}
	str3[4] = '\0';
	int num2 = atoi(str3);
	List2 *new = malloc(sizeof(List));
	if (new == NULL) {
	    printf("Memory allocation failed.\n");
	    exit(1);
	}

	new->num = num2;
	new->prev = NULL;

	if (*head2 == NULL)
	{
	    *head2 = new;
	    *tail2 = new;
	}
	else
	{
	    new->next = *head2;
	    (*head2)->prev = new;
	    *head2 = new;
	}
    }

}


void print_list(List *head)
{
    /* Cheking the list is empty or not */
    if (head == NULL)
    {
	printf("INFO : List is empty\n");
    }
    else
    {
	printf("Head -> ");
	while (head)		
	{
	    /* Printing the list */
	    printf("%d <-", head -> num);

	    /* Travering in forward direction */
	    head = head -> next;
	    if (head)
		printf("> ");
	}
	printf(" Tail\n");
    }
}


void print_list2(List2 *head)
{
    /* Cheking the list is empty or not */
    if (head == NULL)
    {
	printf("INFO : List is empty\n");
    }
    else
    {
	printf("Head -> ");
	while (head)		
	{
	    /* Printing the list */
	    printf("%d <-", head -> num);

	    /* Travering in forward direction */
	    head = head -> next;
	    if (head)
		printf("> ");
	}
	printf(" Tail\n");
    }
}

void print_list3(RList *head)
{
    /* Cheking the list is empty or not */
    if (head == NULL)
    {
	printf("INFO : List is empty\n");
    }
    else
    {
	//printf("Head -> ");
	while (head)		
	{
	    if (head->num == 0)
	    {
		printf("000");
	    }
	    /* Printing the list */
	    printf("%d", head -> num);

	    /* Travering in forward direction */
	    head = head -> next;
	    //if (head)
	    //printf("> ");
	}
	//printf(" Tail\n");
    }
    printf("\n");
}











void print_list4(RList *head)
{
    /* Cheking the list is empty or not */
    if (head == NULL)
    {
	printf("INFO : List is empty\n");
    }
    else
    {
	printf("Head -> ");
	while (head)		
	{
	    /* Printing the list */
	    printf("%d <-", head -> num);

	    /* Travering in forward direction */
	    head = head -> next;
	    if (head)
		printf("> ");
	}
	printf(" Tail\n");
    }
}
