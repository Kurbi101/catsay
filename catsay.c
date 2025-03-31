#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "heinebase.h"
#include "catsay.h"

/* strlen equivelent but doesnt screw up with tabs */
size_t tabstrlen(const char* str) {
    size_t length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\t') {
            length += (TAB_SIZE - (length % TAB_SIZE));   
        } else {
            length++;  
        }
    }
    return length;
}

/*simple case of a one line sentance*/
void short_catsay(char* poem[], size_t max){
    printf(" ");
    for(size_t i = 0; i < max + 1; i++) printf("_");
    printf("\n");
    printf("< %s >\n", poem[0]);
    printf(" ");
    for(size_t i = 0; i < max + 1; i++) printf("-");
    printf("\n");
    printf("        \\\n");
    printf("         \\\n");
}

void short_catthink(char* poem[], size_t max){
    printf(" ");
    for(size_t i = 0; i < max + 1; i++) printf("_");
    printf("\n");
    printf("( %s )\n", poem[0]);
    printf(" ");
    for(size_t i = 0; i < max + 1; i++) printf("-");
    printf("\n");
    printf("        \\\n");
    printf("         \\\n");
}


void catsay(char* poem[], size_t max, int len){
    printf(" ");
    for(size_t i = 0; i < max + 1; i++) printf("_");
    printf("\n");
    printf("/ %s", poem[0]);
    size_t padding = max - tabstrlen(poem[0]) > 0 ? (max - tabstrlen(poem[0])) : 0;
    for(size_t j = 0; j < padding; j++) printf(" ");
    printf("\\\n");
    for(int i = 1; i < len - 1; i++){
        printf("| %s", poem[i]);
        padding = max - tabstrlen(poem[i]) > 0 ? (max - tabstrlen(poem[i])) : 0;
        for(size_t j = 0; j < padding; j++) printf(" ");
        printf("|\n");
    }
    printf("\\ %s", poem[len - 1]);
    padding = max - tabstrlen(poem[len-1]) > 0 ? (max - tabstrlen(poem[len-1])) : 0;
    for(size_t j = 0; j < padding; j++) printf(" ");
    printf("/\n ");

    for(size_t i = 0; i < max + 1; i++) printf("-");
    printf("\n");
    printf("        \\\n");
    printf("         \\\n");
}

void catthink(char* poem[], size_t max, int len){
    printf(" ");
    for(size_t i = 0; i < max + 1; i++) printf("_");
    printf("\n");
    printf("( %s", poem[0]);
    size_t padding = max - tabstrlen(poem[0]) > 0 ? (max - tabstrlen(poem[0])) : 0;
    for(size_t j = 0; j < padding; j++) printf(" ");
    printf(")\n");
    for(int i = 1; i < len - 1; i++){
        printf("( %s", poem[i]);
        padding = max - tabstrlen(poem[i]) > 0 ? (max - tabstrlen(poem[i])) : 0;
        for(size_t j = 0; j < padding; j++) printf(" ");
        printf(")\n");
    }
    printf("( %s", poem[len - 1]);
    padding = max - tabstrlen(poem[len-1]) > 0 ? (max - tabstrlen(poem[len-1])) : 0;
    for(size_t j = 0; j < padding; j++) printf(" ");
    printf(")\n ");

    for(size_t i = 0; i < max + 1; i++) printf("-");
    printf("\n");
    printf("        O\n");
    printf("         o\n");
}


void parse_statement(char* input){
    char buffer[strlen(input) * tabstrlen(input)];
    strcpy(buffer, input);   
    
    char* line;
    line  = strtok(buffer, "\n");
    size_t max = tabstrlen(line);
    char* poem[MAX_LINES];
    int len = 0;
    while(line != NULL){
        poem[len] = malloc(tabstrlen(line) + 1); 
        strcpy(poem[len++], line);
        if(tabstrlen(line) > max) max = tabstrlen(line);
        line = strtok(NULL, "\n");
    }
    int lottery = rand() % CHANCE;
    switch(len){
        case 0:
            printf("ERROR! - poem of length zero, asses immideatly");
            break;
        case 1:
            if(lottery == CHANCE) short_catthink(poem, max);
            else short_catsay(poem, max); 
            break;
        default:
            if(lottery == CHANCE - 1) catthink(poem, max, len);
            else catsay(poem, max, len);
            break;
    }
    for(int i = 0; i < len; i++) free(poem[i]); 

}

void print_cat(void){
    printf("\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀\n");
    printf("\t⠀⠀⠀⠀⢀⡴⣆⠀⠀⠀⠀⠀⣠⡀⠀⠀⠀⠀⠀⠀⣼⣿⡗⠀⠀⠀⠀\n");
    printf("\t⠀⠀⠀⣠⠟⠀⠘⠷⠶⠶⠶⠾⠉⢳⡄⠀⠀⠀⠀⠀⣧⣿⠀⠀⠀⠀⠀\n");
    printf("\t⠀⠀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣤⣤⣤⣤⣤⣿⢿⣄⠀⠀⠀⠀\n");
    printf("\t⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣧⠀⠀⠀⠀⠀⠀⠙⣷⡴⠶⣦\n");
    printf("\t⠀⠀⢱⡀⠀⠉⠉⠀⠀⠀⠀⠛⠃⠀⢠⡟⠀⠀⠀⢀⣀⣠⣤⠿⠞⠛⠋\n");
    printf("\t⣠⠾⠋⠙⣶⣤⣤⣤⣤⣤⣀⣠⣤⣾⣿⠴⠶⠚⠋⠉⠁⠀⠀⠀⠀⠀⠀\n");
    printf("\t⠛⠒⠛⠉⠉⠀⠀⠀⣴⠟⢃⡴⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("\t⠀⠀⠀⠀⠀⠀⠀⠀⠛⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
}

char* get_poem(void){
    srand(time(NULL));
    int random = rand() % NUM_POEMS;
    return heine_db[random];
}

int main(int argc, char* argv[]) {
    if(argc > 1){
        size_t input_len = strlen(argv[1]);
        for(size_t i = 1; i < argc; i++){
            input_len += strlen(argv[i]) + 1;
        }
        char* input = malloc(input_len);
        input[0] = '\0';
        for(size_t i = 1; i < argc; i++){
            strcat(input, argv[i]);
            if(i != argc - 1) strcat(input, " ");
        }
        parse_statement(input);
        print_cat();
        free(input);
        return 0;
    } else{
    char* poem = get_poem();
    parse_statement(poem);    
    print_cat();
    }
    return 0;
}
