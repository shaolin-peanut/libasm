#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

extern int ft_strlen(char *s);
extern char *ft_strcpy(char *dest, char *src);
extern int ft_strcmp(char *s1, char *s2);
extern int ft_write(int fd, char *buf, int count);
extern int ft_read(int fd, char *buf, int count);
extern char *ft_strdup(char *s);
extern errno;

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

void test_ft_read() {
    int fd = open("test.txt", O_RDONLY);
    char buffer[24];
    int result = ft_read(fd, buffer, 24);
    printf("Return value: %d, str: %s\n", result, buffer);
    close(fd);
    return;
}

void test_ft_strdup() {
    char str[] = "hello world";
    char *result = ft_strdup(str);
    printf("Return value: %s\n", result);
    free(result);
    // test errno
    char str2[] = "";
    errno = 0;
    result = ft_strdup(str2);
    printf("Return value: %s\n", result);
    // free(result);
    if (errno != 0) {
        perror("ft_strdup errno test: ");
    }
    return;
}

void test_ft_write() {
    // int fd = open("test1.txt", O_WRONLY | O_CREAT, 0644);
    int fd = -1;
    char buffer[] = "hello world";
    int result = ft_write(fd, buffer, ft_strlen(buffer));
    printf("write value: %d\n", result);
    // close(fd);
    if (errno != 0) {
        perror("ft_write errno test: ");
    }
    return;
}

int main() {
    errno = 0;
    int result = ft_strlen("hello");
    printf("Return value should be 5: %d\n", result);
    char destination[100];
    char *strcpy_result = ft_strcpy(destination, "world");
    printf("destination: %s, strcpy_result: %s\n", destination, strcpy_result);
    test_ft_strcmp();
    int res = ft_write(1, "hello\n this should not be printed", 6);
    test_ft_write();
    test_ft_read();
    test_ft_strdup();
    return 0;
}