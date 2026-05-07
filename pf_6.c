#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { TOK_WORD, TOK_PIPE, TOK_IN, TOK_OUT, TOK_APP } TType;

typedef struct buffer{
    TType type;
    char *val;
    struct buffer *next;

} buffer;

typedef struct Token { TType type; char *val; } Token;

buffer *addnode(Token *token, buffer *prev){
    buffer *node = malloc(sizeof(buffer));
    node->type = token->type;
    node->val = NULL;
    if (token->type == TOK_WORD) {node->val = token->val;}
    node->next = NULL;
    if(prev != NULL) {prev->next = node;}
    return node;
}
Token *tokenize(const char *input, int *n){
    Token *toks = malloc(strlen(input) * sizeof(Token));
    size_t start=0;
    for(size_t i=0; i<strlen(input); i++){
        switch (input[i])
        {
        case ('|'):
        if(i>start){
            size_t wlen = i-start;
            char *word = malloc(wlen + 1);
            memcpy(word, input + start, wlen);
            word[wlen] = '\0';
            toks[*n].val  = word;
            toks[*n].type = TOK_WORD;
            (*n)++;
            
        }
        toks[*n].val  = NULL;
        toks[*n].type = TOK_PIPE;
        (*n)++;
        start = i+1;
            break;
        
        case ('>'):
        if(i>start){
            size_t wlen = i-start;
            char *word = malloc(wlen + 1);
            memcpy(word, input + start, wlen);
            word[wlen] = '\0';
            toks[*n].val  = word;
            toks[*n].type = TOK_WORD;
            (*n)++;
        }
            if (i+1 < strlen(input) && input[i+1] == '>'){
                toks[*n].val  = NULL;
                toks[*n].type = TOK_APP;
                i++;
            }
            else {
                toks[*n].val  = NULL;
                toks[*n].type = TOK_OUT;
            }
        (*n)++;
        start = i+1;
            break;

        case('<'):
            if(i>start){
            size_t wlen = i-start;
            char *word = malloc(wlen + 1);
            memcpy(word, input + start, wlen);
            word[wlen] = '\0';
            toks[*n].val  = word;
            toks[*n].type = TOK_WORD;
            (*n)++;
        }
        toks[*n].val  = NULL;
        toks[*n].type = TOK_IN;
        (*n)++;
        start = i+1;
            break;
        case(' '):
        if(i>start){
            size_t wlen = i-start;
            char *word = malloc(wlen + 1);
            memcpy(word, input + start, wlen);
            word[wlen] = '\0';
            toks[*n].val  = word;
            toks[*n].type = TOK_WORD;
            (*n)++;
            
        }
        start = i+1;
        
            break;

        default:
            break;

        }
    }
    if(strlen(input)>start){
        size_t wlen = strlen(input)-start;
        char *word = malloc(wlen + 1);
        memcpy(word, input + start, wlen);
        word[wlen] = '\0';
        toks[*n].val  = word;
        toks[*n].type = TOK_WORD;
        (*n)++;
    }
    return toks;
}

int main(){
int n=0;
//const char *nomi[] = {"WORD", "PIPE", "IN", "OUT", "APP"};
 Token *toks = tokenize("ls -la | grep .c", &n);
 buffer *temp_node=NULL;
 buffer *head;
 for (int i=0; i<n; i++){
    temp_node = addnode(&toks[i], temp_node);
    if (i==0) { head = temp_node;} //per la stampa
 //   printf("%s %s\n", nomi[toks[i].type], toks[i].val ? toks[i].val : "");
 }
 while(head != NULL){
    printf("%s\n", head->val ? head->val : "");
    head = head->next;
 }

 return 0;
}