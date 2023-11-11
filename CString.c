#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "CString.h"

/*
    Assigns a string into the String stuct
    Assigns len to string in String struct
*/
void CSassign(String *destination, char *string){
    int stringSize = 1;
    int i = 0;

    while (string[i] != '\0'){
        stringSize++;
        i++;
    }
    
    i = 0;
    destination->len = stringSize;
    destination->content = (char *)malloc(sizeof(char) * stringSize);
    while (string[i] != '\0'){
        destination->content[i] = string[i];
        i++;
    }
    destination->content[i] = '\0';
}

/*
    Creates new string that is a concatenated version of arg1 and arg2
*/
String *CSconcat(String *s1, String *s2){
    int size = s1->len + s2->len - 1; 
    int i = 0, j = 0;                      
    String *res = (String *)malloc(sizeof(String) * size);
    res->len = size;

    while (s1->content[i] != '\0'){
        res->content[i] = s1->content[i];
        i++;
    }
    
    while (s2->content[j] != '\0'){
        res->content[i] = s2->content[j];
        i++;
        j++;
    }

    res->content[i] = '\0';
    return res;
}

/*
    Takes the second string and joins it into the first string.
*/
void CSjoin(String *s1, String *s2){
    int oldlen = s1->len;
    int newlen = s1->len + s2->len - 1;
    s1->len = newlen;
    s1->content = realloc(s1->content, sizeof(char)*newlen);
    memcpy(s1->content + oldlen - 1, s2->content, sizeof(char)*s2->len);
    s1->content[newlen-1] = '\0';
}