
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if(c == '\t' || c == ' '){
    return 1;
  }
  else{
    return 0;
  }
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  if(c =='\t' || c == ' ' || c == '\0'){
    return 0;
  }
  else{
    return 1;
  }
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str){
  while(space_char(*str)){
    str++;
  }
  return str;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
  while(non_space_char(*word)){
    word++;
  }
  return word;
}
/* Counts the number of words in the string argument. */
int count_words(char *str){
  int tally = 0;
  while(*str != '\0'){
    str = word_start(str);
    tally++;
    str = word_terminator(str);
  }
  return tally;
}
    

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *copy = (char*)malloc((sizeof(char))*(len+1));
  int i = 0;
  while(i<len){
    *(copy+i) = *(inStr+i);
    i++;
  }
  *(copy+len) = '\0';
  return copy;		     
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  int num_of_tokens = count_words(str);
  char **tokens = (char**)malloc(sizeof(char*) * (num_of_tokens+1));
  char *start_of_token;
  char *end_of_token = str;
  int token_size;

  for(int i = 0; i < num_of_tokens;i++)
  {
    start_of_token = word_start(end_of_token);
    end_of_token = word_terminator(start_of_token);
    token_size = end_of_token - start_of_token;   
    *(tokens+i) = copy_str(start_of_token,token_size);
  }
  *(tokens+num_of_tokens)='\0';
  return tokens;
}



/* Prints all tokens. */
void print_tokens(char **tokens){
  char **temp = tokens;
  while(*tokens){
    printf("%s\n",*tokens);
    tokens++;
  }
  free(temp);
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  while(*tokens){
    free(*tokens);
    tokens++;
  }//read 7.8.5 to free double pointer
}

/* helper function*/
int string_length(char *str){
  int tally= 0;
  while(*str != '\0'){
    str++,tally++;
  }
  return tally;
}
