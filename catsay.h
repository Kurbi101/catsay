#ifndef CATSAY_H
#define CATSAY_H

#include <stdlib.h>

#define TAB_SIZE 4       /* num of spaces \t will be interpreted as      */
#define CHANCE 5         /* once every how many tries will the cat think */
#define MAX_LINES 10     /* maximum number of lines in a poem            */
#define MAX_LEN 25 /* maximum number of characters in a line     */


size_t tabstrlen(const char* str);
void short_catsay(char* poem[], size_t max);
void short_catthink(char* poem[], size_t max);
void catsay(char* poem[], size_t max, int len);
void catthink(char* poem[], size_t max, int len);
void parse_statement(char* input);
void print_cat(void);
char *get_poem(void);
int main(int argc, char* argv[]);

#endif
