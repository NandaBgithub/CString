#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *concat(char *s1, char *s2);
void join(char *s1, char *s2, int n1, int n2);

int main(){
    char s1[] = "ab";
    char s2[] = "cd";

    // char *res = concat(s1, s2);
    // printf("%s \n", res);
}

/*
    concat() takes in pointers to two strings and returns
    a pointer to a string that is a combination of s1 + s2 in that
    order. 
*/
char *concat(char *s1, char *s2){
    int len1 = 0, len2 = 0, i = 0;
    char *res;

    do {
        len1++;
        i++;
    }while (s1[i] != '\0');

    do {
        len2++;
        i++;
    }while (s2[i] != '\0');

    res = (char *)malloc(sizeof(char) * (len1 + len2 - 1));
    memcpy(res, s1, len1);
    memcpy(res+len1, s2, len2);
    return res;
}

/*
    join() takes strings and their sizes including the terminating null byte
*/
void join(char *s1, char *s2, int n1, int n2){
    s1 = realloc(s1, sizeof(char) * (n1+n2-1));
    memcpy(s1+(n1-1), s2, n2);
}


