// Jennifer Hälgh & Sadhana Anandan, group: 25 (2023) 
// Work package 2 
// Exercise 2
// Submission code: 180DC4E
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #### Constants #####
#define MAX 5

// ##### typedefs          ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations   #####

REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);

// ###### Main program #######
int main(int argc, char *argv[])
{
    int nr = 0;

    REGTYPE *act_post, *head = NULL;

    srand(time(0)); //   Random seed
    head = random_list();
    act_post = head;
    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }
    printf("\n -------------");
    head = add_first(head, 5); //call the add_first function and assign the return value to head
    nr = 0; //set nr back 0
    act_post = head; //set act_post to head
    //while act_post is not null
    while (act_post != NULL)
    {
        //print the linked list
        printf("\n Post nr %d : %d", nr++, act_post->number);
        //sets the act_post to next value its pointing to
        act_post = act_post->next;
    }

    // --- Free the allocated memory  ---

    while ((act_post = head) != NULL)
    {
        head = act_post->next;
        free(act_post);
    }

    return 0;
}

// ====     End of main   ======================================

REGTYPE *random_list(void)
{
    int nr, i = 0; //Declare nr and initialize i
    REGTYPE *top, *old, *item; //Declare top, old and item
   
   //while i is less than MAX
    while (i < MAX)
    {
        //generate a random number
        nr = rand() % 100;
        //if i==0, i.e its the first node in the linked list
        if(i==0){
        //allocate memory for the head node
        top = (REGTYPE *)malloc(sizeof(REGTYPE)); //allocate memory for the head node
        //set the top's number as nr
        top->number = nr; //set the tops number to nr
        //set the top's next to NULL
        top->next = NULL;
        //set the top's prev to NULL
        top->prev = NULL;
        //set old as top
        old = top;
        } else {
        //allocate memory for item
        item = (REGTYPE *)malloc(sizeof(REGTYPE));
        //set the item's number to nr
        item->number = nr;
        //set the item's next to NULL
        item->next = NULL;
        //set the item's prev to old
        item->prev = old;
        //set the old's next to item
        old->next = item;
        //set old to item
        old = item;
        }
        //increse i by 1
        i++; 
    }

    return (top);
}

//==========================================================

REGTYPE *add_first(REGTYPE *head, int data)
{
    //allocate memory for the newItem
    REGTYPE *newItem = malloc(sizeof(REGTYPE));
    // if head is null, i.e the linked list if empty
    if (head == NULL)
    {
        newItem->next = NULL;
        //set newItem's number to data
        newItem->number = data;
    }
    else// If the linked list is not empty
    {
        //set newItem's next to head
        newItem->next = head;
        //set newItem's number to data
        newItem->number = data;
        
    }
    //set newItem's prev to NULL
    newItem->prev = NULL;
    //newItem is the new head
    head = newItem;
    return head;
}