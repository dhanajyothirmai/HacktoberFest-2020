#include<stdio.h>
#include<malloc.h>
struct circular_node
{
 int data;
 struct circular_node * next;
};
typedef struct circular_node CIRC_NODE;
typedef CIRC_NODE * CIRC_NODE_PTR;
CIRC_NODE_PTR insertNode(int num, CIRC_NODE_PTR start)
{
 CIRC_NODE_PTR newnode, tptr, prev, minNode;
 int minval;
 newnode = (CIRC_NODE_PTR) malloc(sizeof(CIRC_NODE));
 newnode->data = num;
 newnode->next = NULL;
 if(start == NULL)
 {
 newnode->next = newnode;
 return newnode;
 }
 if(start==start->next)
 {

 newnode->next =start;
 start->next = newnode;
 return newnode;
 }
 // find the start
 minval = start->data;
 minNode = start;
 tptr = start;
 do
 {
 if(tptr->data < minNode->data)
 {
 minNode = tptr;
 minval = tptr->data;
 }
 tptr = tptr->next;
 }while(tptr != start);
 if(newnode->data < minNode->data)
 {
 tptr = minNode->next;
 while(tptr!=minNode)
 {
 prev = tptr;
 tptr = tptr->next;
 }
 } //
 else
 {
 prev = minNode;
 tptr = minNode->next;
 while(tptr!=minNode && newnode->data > tptr->data)
 {
 prev = tptr;
 tptr = tptr->next;
 }
 }
 prev->next = newnode;
 newnode->next = tptr;
 return newnode;
}
void print_Circular(CIRC_NODE_PTR start)
{
 CIRC_NODE_PTR tptr;
 if(!start) return;
 tptr= start;
 do
 {
 printf("%d ", tptr->data);
 tptr= tptr->next;
 }while(tptr!=start);
}
int main()

{
 CIRC_NODE_PTR start= NULL;
 int input;
 do
 {
 scanf("%d",&input);
 if( input == -1) break;


 start = insertNode(input, start);
 }while(1);
 /*start = insertNode(16, start);
 start = insertNode(1, start);
 start = insertNode(5, start);
 start = insertNode(9, start);
 start = insertNode(4, start);
*/
 print_Circular(start);
}

