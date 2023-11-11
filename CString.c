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

/*
    Partitions strings into string groups of size interval
    eg. str = "abs", interval = 2
        output = {"ab", "s"}
    The above interval has a remainder since 3%2 = 1 then the last string will be size 1
*/
char **CSpartition(String *str, int interval){
    int fullsize = (str->len)/interval;

    int remaindersize = ((str->len)+1)%interval;
    int i, j, k = 0;
    char **res = (char **)malloc(sizeof(char*) * fullsize);

    printf("remaindersize = %d\n", remaindersize);
    printf("fullSize = %d\n", fullsize);
    
    for (i = 0; i<fullsize; i++){
        res[i] = (char *)malloc(sizeof(char) * (interval+1));

        for (j = 0; j<interval; j++){
            (res[i])[j] = str->content[k];
            printf("string: %c j = %d\n", (res[i])[j], j);
            k++;
        }

        (res[i])[j] = '\0';
        j = 0;
    }

    // remaining strings that dont fit in partition goes at the end
    if (remaindersize > 0){        
        res[fullsize] = (char *)malloc(sizeof(char) * (remaindersize+1));
        for (j = 0; j<remaindersize; j++){
            res[fullsize][j] = str->content[k];
            printf("string: %c j = %d\n", (res[i])[j], j);
            k++;
        }

        (res[fullsize])[j] = '\0';    
    }

    return res;
}

/*
    cut part of a string exclusive from start index to the next index
    the returned string is a resized string
*/
void CScut(String *str, int start, int end){
    String *res = (String *)malloc(sizeof(String));
    res->len = (end - start) + 2;
    res->content = (char *)malloc(sizeof(char) * res->len);
    printf("res->len = %d\n", res->len);

    int j = start, i= 0;
    for (i; i<(res->len)-1; i++){
        res->content[i] = str->content[j];
        printf("res->content[i] = %c\n", res->content[i]);
        j++;
    }
    printf("j = %d\n", j);
    printf("i = %d\n", i);
    res->content[i] = '\0';
    free(str);
    str->len = res->len;
    str->content = res->content;
}
