#define _POSIX_C_SOURCE 200809L
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "list.h"
bool linkList_exists = false;
list *create_list()
{
    list *ll = (list *)malloc(sizeof(list));
    if (ll == NULL){
        printf("Not happeening my man");
        return NULL;
    }
        linkList_exists = true;
         ll->head = NULL;
        printf("The linked list has been created.\n");
        return ll;
        // printf("linked list has been created\n");
        // printf("entered the fucntion of the create list function");
    };
int add_to_list(list *ll, char *item) {
    if (ll == NULL || !linkList_exists) {
        printf("List doesn't exist. Create a list first.\n");
        return 0;
    }

    node *new = (node *)malloc(sizeof(node));
    if (new == NULL) {
        printf("Memory allocation failed. Unable to add item to the list.\n");
        return 0;
    }

    new->item = strdup(item);
    new->next = NULL;

    if (ll->head == NULL) {
        ll->head = new;
    } else {
        node *finding_last = ll->head;
        while (finding_last->next != NULL) {
            finding_last = finding_last->next;
        }
        finding_last->next = new;
    }

    return 1;
}
void print_list(list *ll){
    if(ll->head ==NULL || !linkList_exists) {
        printf("List is empty or Non-Existent\n");
        return;
    }
    node *temp = ll->head;
    printf("\n");
    while(temp->next != NULL){
        printf("%s\n",temp->item);
        temp = temp->next;
    }printf("%s\n\n",temp->item);
}
char* remove_from_list(list *ll){
    if(ll->head==NULL||ll==NULL){
        printf("No list has been created=, Create a list first");
        return strdup("");
    }node *current=ll->head;
    char *item = strdup(current->item);
    ll->head=current->next;
    free(current->item);
    free(current);
    return item;
}
void flush_list(list *ll)
{
    if(ll == NULL){
        printf("No list found to flush");
        return;
    } node *temp=ll->head;
    while(temp!=NULL){
        node *temp1 =temp;
        temp = temp->next;
        free(temp1->item);
        free(temp1);
    }
    ll->head = NULL;
}
void free_list(list **ll){
    if(*ll==NULL || *ll==NULL){
        printf("Target list not found, either flushed or not initiated");
        return;
    }flush_list(*ll);
    free(*ll);
    *ll = NULL;
    linkList_exists = false;
    printf("Link list has been freed from memory, no more operations permitted after this point");
}