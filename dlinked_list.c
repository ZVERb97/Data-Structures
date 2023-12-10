#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define AIV_LIST(x) &(x.item)

typedef struct aiv_list_node Node;
typedef struct aiv_list_item Item;

struct aiv_list_node
{
    struct aiv_list_node* prev;
    struct aiv_list_node* next;
};

struct aiv_list_item
{
    Node item;
    int value;

};

Node* list_get_tail(Node *head)
{
    if(!head)
    {
        return NULL;
    }

    Node* current_item = head;
    Node* last_item = head;

    while(current_item)
    {
        last_item = current_item;
        current_item = current_item->next;

    }

    return last_item;
}

Node* list_append (Node **head, Node* item)
{
    Node* tail = list_get_tail(*head);

    if(!tail)
    {
        *head = item;
    }
    else
    {
        tail->next = item;
    }

    item->prev = tail;
    item->next = NULL;

    return item;
}

Node* aiv_list_remove(Node** head, Node* item)
{
    Node* current;
    Node* element_to_remove;

    if(!(*head))
    {
        return NULL;
    }

    if(*head == item)
    {
        element_to_remove = *head;
        printf("Removed Item : %d\n", ((Item*)element_to_remove)->value);
        *head = (*head)->next;
    }
    else
    {
        for(current = *head; current != NULL; current = current->next)
        {
            if(current->next == item)
            {
                element_to_remove = current->next;
                printf("Removed Item : %d\n", ((Item*)element_to_remove)->value);
                current->next = current->next->next;
                current->prev = current->prev->prev;
                
            }
        
        }
    
    }
    
    return current;
}

void list_insert_before(Node** head, Node* list_index, Node* element_to_add)
{
    element_to_add->next = list_index;
    element_to_add->prev= list_index->prev;

    if(element_to_add->prev == NULL)
    {
       *head = element_to_add;  
    }
    else
    {
        list_index->prev->next = element_to_add;
    }

    printf("%d <- %d\n",((Item*)element_to_add)->value,((Item*)list_index)->value);
}

void list_insert_after(Node** head, Node* list_index, Node* element_to_add)
{
    element_to_add->next = list_index->next;
    element_to_add->prev = list_index;


    if(list_index->next == NULL)
    {
        list_append(head,element_to_add);
    }
    else
    {
      list_index->next->prev = element_to_add;
    }

    list_index->next = element_to_add;
   

    printf("%d -> %d\n",((Item*)list_index)->value,((Item*)element_to_add)->value);
}

void aiv_print_list(Node** head)
{
    Node* current;

    printf("LIST:\n");
    for(current = *head; current!= NULL; current = current->next)
    {
        printf("[%d] ",((Item*)current)->value);
        
    }
    printf("\n");

}

int main(int argc, char** argv)
{
    Node *head = NULL;

    Item element0, element1, element2, element3, element4,element5,element6;
    element0.value = 100;
    element1.value = 200;
    element2.value = 300;
    element3.value = 400;
    element4.value = 500;
    element5.value = 10000;
    element6.value = 2000;
    list_append(&head,AIV_LIST(element0));
    list_append(&head,AIV_LIST(element1));
    list_append(&head,AIV_LIST(element2));
    list_append(&head,AIV_LIST(element3));
    list_append(&head,AIV_LIST(element4));
    aiv_print_list(&head);

    list_insert_before(&head,AIV_LIST(element2),AIV_LIST(element5));
    aiv_print_list(&head);
    list_insert_after(&head,AIV_LIST(element4),AIV_LIST(element6));
    aiv_print_list(&head);

    aiv_list_remove(&head,AIV_LIST(element2));
    aiv_print_list(&head);
    aiv_list_remove(&head,AIV_LIST(element6));
    aiv_print_list(&head);

    

    return 0;
}

