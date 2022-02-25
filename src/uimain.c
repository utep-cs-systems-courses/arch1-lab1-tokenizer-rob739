#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"


int main()
{
  char input[100]; 
  List *history = init_history();

  
  while(1){
    printf("Ready to tokenize\n---------------\n");
    printf(">");
    fgets(input,sizeof(input),stdin);
    if(input[0] == '@'){
      break;
    }
    char* temp = &input[0];
    char** tokens = tokenize(temp);
    print_tokens(tokens);
    free_tokens(tokens);
    add_history(history,temp);
  }
  
  while(1){
    printf("Tokenized History\n-------------------\n");
    print_history(history);
    printf("enter ref. number of str you want to tokenize\n>");
    fgets(input,sizeof(input),stdin);
    if(input[0] == '@'){
      break;
    }
    int id = atoi(input);
    printf("Fetching str[%d]...\n",id);
    char* temp = get_history(history,id);
    char** tokens = tokenize(temp);
    print_tokens(tokens);
    free_tokens(tokens);
    add_history(history,temp);
  }

  free_history(history);

  return 0;
}
