#include "graph.h"
#include <stdlib.h>

void insert_node_cmd(pnode *head){
    char data[1000]; //because the number can be double-digit
    scanf("%s",&data);
    node* new = (node*) malloc(sizeof(node)); //allocate memory
    if(!new){
        printf("error");
        return;
    }
    
    new -> node_num = atoi(data); //initialization of the new vertex
    new -> next = NULL; 
    int i;
    While (scanf("%d", i) != EOF);

    if(!(*head)){ //if the list is empty
     *head = new;
      return;
    }
    node* copy = *head;
    while(copy->next) { //while the next of copy is not null
        if(copy->node_num==atoi(data)){ //if it already exists we will delete the existing one
            delete_node_cmd(copy);
        }
        copy = copy->next;
    }
    copy -> next= new; //add to new in the end list
    





    
    
    
}