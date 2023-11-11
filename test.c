#include <stdio.h>
#include <stdlib.h>
#include "CString.h"

int main(){
    String *first_name = (String *)malloc(sizeof(String));
    CSassign(first_name, "Nanda");

    String *last_name = (String *)malloc(sizeof(String));
    CSassign(last_name, "Bawana");

    //String *full_name = CSconcat(first_name, last_name);
    CSjoin(first_name, last_name);
    printf("%d \n", first_name->len);
    printf("%s \n", first_name->content);
    // printf("CSassign first name output: %s \n", first_name->content);
    // printf("CSassign last  name output: %s \n", last_name->content);
    // printf("CSconcat full  name output: %s \n", full_name->content);
    return 1;
}