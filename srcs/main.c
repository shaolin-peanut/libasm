#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

extern int ft_strlen(char *s);
extern char *ft_strcpy(char *dest, char *src);
extern int ft_strcmp(char *s1, char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strdup(const char *s);

void test_ft_strlen(void) {
    printf("ft_strlen tests:\n");
    int result = ft_strlen("hello");
    printf("ft_strlen('hello') should be 5: %d\n", result);
    result = ft_strlen("");
    printf("ft_strlen('') should be 0: %d\n", result);
    result = ft_strlen(NULL);
    printf("ft_strlen(NULL) should be 0: %d\n", result);
    result = ft_strlen("hello world");
    printf("ft_strlen('hello world') should be 11: %d\n", result);
    printf("\n");
}

void test_ft_strcmp(void) {
    printf("ft_strcmp tests:\n");
    char s1[] = "hello";
    char s2[] = "hello";
    int result = ft_strcmp(s1, s2);
    printf("Equal strings: %d (Expected: 0)\n", result);
    s2[0] = 'j';
    result = ft_strcmp(s1, s2);
    printf("s1 < s2: %d (Expected: <0)\n", result);
    s1[0] = 'j';
    s2[0] = 'h';
    result = ft_strcmp(s1, s2);
    printf("s1 > s2: %d (Expected: >0)\n\n", result);
}

void test_ft_strcpy(void) {
    printf("ft_strcpy tests:\n");
    
    char dest1[100];
    char *src1 = "hello";
    ft_strcpy(dest1, src1);
    printf("Copy 'hello': %s\n", dest1);

    char dest2[100];
    char *src2 = "";
    ft_strcpy(dest2, src2);
    printf("Copy empty string: '%s'\n", dest2);

    char dest3[100];
    char *src3 = "A long string with spaces and symbols! @#$%^&*()";
    ft_strcpy(dest3, src3);
    printf("Copy long string: %s\n", dest3);

    char dest4[10];
    char *src4 = "overflow";
    ft_strcpy(dest4, src4);
    printf("Copy to smaller buffer (unsafe, for testing): %s\n", dest4);
    printf("\n");
}

void test_ft_write(void) {
    printf("ft_write tests:\n");
    
    // Valid write to STDOUT
    char buffer1[] = "hello world\n";
    ssize_t result = ft_write(1, buffer1, ft_strlen(buffer1));
    printf("Bytes written (STDOUT): %zd\n", result);

    // Invalid file descriptor
    errno = 0;
    int fd = -1;
    result = ft_write(fd, buffer1, ft_strlen(buffer1));
    if (result == -1) {
        perror("ft_write with invalid fd");
    }

    errno = 0;
    // Writing more than buffer size (no error)
    char buffer2[] = "test\n";
    result = ft_write(STDOUT_FILENO, buffer2, 20);
    printf("Bytes written (overflow attempt): %zd\n", result);

    // Null buffer
    errno = 0;
    result = ft_write(STDOUT_FILENO, NULL, 5);
    if (result == -1) {
        perror("ft_write with null buffer");
    }
    printf("\n");
}

void test_ft_read(void) {
    printf("ft_read tests:\n");
    
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return;
    }
    char buffer[24];
    int result = ft_read(fd, buffer, 24);
    printf("Bytes read: %d, Content: %s\n", result, buffer);
    close(fd);

    errno = 0;
    fd = -1;
    result = ft_read(fd, buffer, 23);
    if (result == -1) {
        perror("ft_read with invalid fd");
    }

    // Reading into null buffer
    fd = open("test.txt", O_RDONLY);
    errno = 0;
    result = ft_read(fd, NULL, 5);
    if (result == -1) {
        perror("ft_read with null buffer");
    }
    close(fd);

    // Reading zero bytes
    fd = open("test.txt", O_RDONLY);
    errno = 0;
    result = ft_read(fd, buffer, 0);
    printf("Reading zero bytes: %d\n", result);
    close(fd);
    printf("\n");
}

void test_ft_strdup(void) {
    printf("ft_strdup tests:\n");
    char str[] = "hello world";
    char *result = ft_strdup(str);
    printf("Duplicated string: %s\n", result);
    free(result);

    char str2[] = "";
    result = ft_strdup(str2);
    printf("Duplicated empty string: %s\n", result);
    free(result);
    printf("\n");
}

int main(void) {
    test_ft_strlen();
    test_ft_strcpy();
    test_ft_strcmp();
    test_ft_write();
    test_ft_read();
    test_ft_strdup();
    return 0;
}