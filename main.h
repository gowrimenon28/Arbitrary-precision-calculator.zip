#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1


typedef struct node
{
    int num;
    struct node *prev;
    struct node *next;
}List;

typedef struct node2
{

    int num;
    struct node2 *prev;
    struct node2 *next;
}List2;

typedef struct node3
{
    int num;
    struct node3 *prev;
    struct node3 *next;
} RList;






void store_num1(List **head, List **tail, char str1[]);
void store_num2(List2 **head2, List2 **tail2, char str2[]);
void print_list(List *head);
void print_list2(List2 *head2);
void print_list3(RList *head);
void print_list4(RList *head);
 void print_list8(RList *head);

void add_num(List **head, List **tail, List2 **head2, List2 **tail2, RList **head3, RList **tail3);
void sub_num(List **head, List **tail, List2 **head2, List2 **tail2, RList **head3, RList **tail3);
void multi_num(List **head, List **tail, List2 **head2, List2 **tail2, RList **head3, RList **tail3);
void div_num(List **head, List **tail, List2 **head2, List2 **tail2, RList **head3, RList **tail3);
