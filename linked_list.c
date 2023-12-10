#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define AIV_LIST(x) &(x.list_item)

typedef struct aiv_list_item  list_item;
typedef struct aiv_int_item  list_int;

struct aiv_list_item
{
    struct aiv_list_item *next;
    unsigned int count;
};

struct aiv_int_item
{
    struct aiv_list_item list_item;
    int value;
};



list_item * aiv_list_get_tail(list_item* head)
{
    if(!head)
    {
        return NULL;
    }

    list_item* current_item = head;
    list_item* last_item = head;
    while(current_item)
    {
        last_item = current_item;
        current_item = current_item->next;

    }

    return last_item;
};

list_item* aiv_list_append(list_item** head, list_item* item)
{
    list_item* tail = aiv_list_get_tail(*head);

    if(!tail)
    {
        *head = item;
        (*head)->count = 1;
         
    }
    else
    {
         tail->next = item;
         (*head)->count++;
         
    }
    item->next = NULL;
    return item;


    
};

unsigned int  aiv_list_lenght(list_item* head)
{
    return head->count;
};

list_item* aiv_list_pop(list_item** head)
{
    if(!(*head))
    {
        return NULL;
    }

    list_item* current_head = *head;
    const unsigned int current_count = current_head->count;
    *head = (*head)->next;
    if(*head)
    {
        (*head)->count = current_count - 1;
    }
    

    current_head->next = NULL;
    return current_head;

};



list_item* aiv_list_remove(list_item** head, list_item* item)
{
    list_item* current;
    list_item* element_to_remove;

    if(!(*head))
    {
        return NULL;
    }

    if(*head == item)
    {
        element_to_remove = *head;
        printf("Removed Item : %d\n", ((list_int*)element_to_remove)->value);
        *head = (*head)->next;
    }
    else
    {
        for(current = *head; current != NULL; current = current->next)
        {
            if(current->next == item)
            {
                element_to_remove = current->next;
                printf("Removed Item : %d\n", ((list_int*)element_to_remove)->value);
                current->next = current->next->next;
                
            }
        
        }
    
    }
    
    return current;
}

void aiv_reverse_list(list_item** head)
{
    /*I WILL START THE FUNCTION DECLARING 3 VARIABLES: PREVIOUS, CURRENT AND NEXT
    AND INITIALIZE THE CURRENT VARIABLE WITH THE HEAD OF OUR LINKED LIST*/
    list_item* prev = NULL;
    list_item* curr = *head;
    list_item* next = NULL;

    /*WE CYCLE THE LIST UNTIL THE CURRENT VALUE IS NULL*/
    while(curr != NULL)
    {
        next  = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;

}

void aiv_print_list(list_item** head)
{
    list_item* current;

    printf("LIST:\n");
    for(current = *head; current!= NULL; current = current->next)
    {
        printf("[%d] ",((list_int*)current)->value);
        
    }
    printf("\n");

}

int main(int argc, char** argv)
{

    list_item* head = NULL; //value = 0 - address = 0xaddress

    list_int int_item;
    int_item.value = 100;
    aiv_list_append(&head,AIV_LIST(int_item));
    list_int int_item2;
    int_item2.value = 200;
    aiv_list_append(&head,AIV_LIST(int_item2));
    list_int int_item3;
    int_item3.value = 300;
    aiv_list_append(&head,AIV_LIST(int_item3));
    list_int int_item4;
    int_item4.value = 400;
    aiv_list_append(&head,AIV_LIST(int_item4));
    printf("NOW I WILL PRINT THE LINKED LIST.\n");
    aiv_print_list(&head);

    printf("NOW I WILL REVERSE THE LINKED LIST\n");
    aiv_reverse_list(&head);
    aiv_print_list(&head);

    printf("NOW I WILL REMOVE AN ELEMENT.\n");
    aiv_list_remove(&head,AIV_LIST(int_item2));
    aiv_print_list(&head);

   

    return 0;
}