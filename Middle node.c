//C code to find the number of nodes in a linklist also find the middle node of the linklist.

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *next;
};
 
void create(struct node **);
void middlenode(struct node *);
void release(struct node **);
 
int main()
{
    struct node *p = NULL;
 
    printf("----Create list by entering data----\n");
    create(&p);
    middlenode(p);
    release (&p);
 
    return 0;
}
 void middlenode(struct node *head)
{
    struct node *p, *q;
    int flag = 0;
 
    q = p = head;
    
    while (q->next != NULL)
    {
        q = q->next;
        if (flag)
        {
            p = p->next;
        }
        flag = !flag;
    }
    if (flag)
    {
        printf("List contains even number of nodes\nThe middle two node's values are: %d  %d\n", p->next->data, p->data);
    }
    else
    {
        printf("Element present in the middle of the list: %d\n", p->data);
    }
}
void create(struct node **head)
{
    int c, ch,no;
    struct node *temp;
  printf("enter the no of nodes:");
  scanf("%d",&no);
  for(int i=0;i<no;i++)
    {
        printf("Enter no: ");
        scanf("%d", &c);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data= c;
        temp->next = *head;
        *head = temp;
        } 
    printf("\n");
}
void release(struct node **head)
{
    struct node *temp = *head;
    *head = (*head)->next;
    while ((*head) != NULL)
    {
        free(temp);
        temp = *head;
        (*head) = (*head)->next;
    }
}
