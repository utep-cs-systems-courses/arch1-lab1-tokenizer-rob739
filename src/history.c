#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
/*
typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;
*/

/* Initialize the linked list to keep the history. */
List* init_history(){
  List* history = (List*)malloc(sizeof(Item)*50);
  return history;
}


/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/

void add_history(List *list, char *str){
  Item *iterator_node = list->root;

  if(iterator_node == NULL){
    Item *new_node = (Item*)malloc(sizeof(Item));
    char *new_str = copy_str(str,string_length(str));
    new_node->id= 1, new_node->str= new_str, new_node->next= NULL;
    list->root = new_node;
  }

  else{
    int pos = 2;
    while(iterator_node->next != NULL){
      iterator_node = iterator_node->next;
      pos++;
    }
    iterator_node->next= (Item*)malloc(sizeof(Item));
    iterator_node->next->id= pos;
    iterator_node->next->str= copy_str(str,string_length(str));
  }
}



/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */

char *get_history(List *list, int id){
  Item* iterator_node= list->root;
  
  while(iterator_node != NULL){
    if(iterator_node->id == id){
      return iterator_node->str;
    }
    else{
      iterator_node = iterator_node->next;
    }
  }
  printf("id not valid for memory pos.");
  return 0;
}



/*Print the entire contents of the list. */

void print_history(List *list){
  Item *iter = list->root;
  while(iter != NULL){
    printf("[%d] %s\n",iter->id,iter->str);
    iter = iter->next;
  }
}


/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *iter = list->root;

  while (iter != NULL){
    free(iter);
    iter = iter->next;
  }
  free(list);
}


