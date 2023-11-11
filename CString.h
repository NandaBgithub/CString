typedef struct{
    // length counts the null byte
    int len;
    char *content;
} String;

void CSassign(String *destination, char *string);

String *CSconcat(String *str1, String *str2);

void CSjoin(String *s1, String *s2);

char **CSpartition(String *str, int interval);

void CScut(String *str, int start, int end);