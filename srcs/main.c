#include <stdio.h>

extern int ft_strlen(char *s);
extern char *ft_strcpy(char *dest, char *src);

int main() {
    int result = ft_strlen("hello");
    printf("Return value should be 5: %d\n", result);
    char destination[100];
    char *strcpy_result = ft_strcpy(destination, "world");
    printf("destination: %s, strcpy_result: %s\n", destination, strcpy_result);
    return 0;
}