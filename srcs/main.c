#include <stdio.h>

extern int ft_strlen(char *s);
extern char *ft_strcpy(char *dest, char *src);
extern int ft_strcmp(char *s1, char *s2);

//  test ft_strlen
// test ft_strcpy
// test ft_strcmp
// test ft_write
// test ft_read
// test ft_strdup
void test_ft_strcmp(void) {
    char s1[] = "hello";
    char s2[] = "hello";
    int result = ft_strcmp(s1, s2);
    printf("Return value should be 0: %d\n", result);
    s2[0] = 'j';
    result = ft_strcmp(s1, s2);
    printf("Return value should be 1: %d\n", result);
    s1[0] = 'j';
    s2[0] = 'h';
    result = ft_strcmp(s1, s2);
    printf("Return value should be -1: %d\n", result);
    return;
}


int main() {
    int result = ft_strlen("hello");
    printf("Return value should be 5: %d\n", result);
    char destination[100];
    char *strcpy_result = ft_strcpy(destination, "world");
    printf("destination: %s, strcpy_result: %s\n", destination, strcpy_result);
    test_ft_strcmp();
    return 0;
}