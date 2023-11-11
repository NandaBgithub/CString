#include <stdio.h>
#include <stdlib.h>
#include "CString.h"

int main(){
    String *first_name = (String *)malloc(sizeof(String));
    CSassign(first_name, "Nada");
    printf("first_name len %d\n", first_name->len);
    // String *last_name = (String *)malloc(sizeof(String));
    // CSassign(last_name, "Bawana");

    //String *full_name = CSconcat(first_name, last_name);
    // printf("CSassign first name output: %s \n", first_name->content);
    // printf("CSassign last  name output: %s \n", last_name->content);
    // printf("CSconcat full  name output: %s \n", full_name->content);

    // CSjoin(first_name, last_name);
    // printf("%d \n", first_name->len);
    // printf("%s \n", first_name->content);
    
    // char **arr;
    // arr = CSpartition(first_name, 2);
    // for (int i = 0; i<2; i++){
    //     printf("%s\n", arr[i]);
    // }

    CScut(first_name, 2, 3);
    printf("CScut first_name result = %s\n", first_name->content);

    return 1;
}