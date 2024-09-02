#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h> 

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"

extern int ft_strlen(char *str);
extern char* ft_strcpy(char *dest, char *src);
int strcmp(const char *s1, const char *s2);
extern int ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strdup(const char *s);

void compare_results(const char* function_name, const char* test_input, int expected, int actual) {
    printf(BLUE "%s:\n" RESET, function_name);
    if (expected == actual) {
        printf("  Input: \"%s\"\n", test_input);
        printf("  Result: " GREEN "%d " RESET "(Expected: %d)\n", actual, expected);
    } else {
        printf("  Input: \"%s\"\n", test_input);
        printf("  Result: " RED "%d " RESET "(Expected: %d)\n", actual, expected);
    }
}

void compare_strings(const char* function_name, const char* src, const char* result, const char* expected) {
    printf(BLUE "%s:\n" RESET, function_name);
    if (strcmp(result, expected) == 0) {
        printf("  Source: \"%s\"\n", src);
        printf("  Result: " GREEN "\"%s\" " RESET "(Expected: \"%s\")\n", result, expected);
    } else {
        printf("  Source: \"%s\"\n", src);
        printf("  Result: " RED "\"%s\" " RESET "(Expected: \"%s\")\n", result, expected);
    }
}

void test_comparisons() {
    char test_str1[] = "Hello, world!";
    char test_str2[] = "12345";
    char test_str3[] = "";
    char buffer[100];
    int intret;
    int intret_std;
    
    // ft_strlen
    intret = ft_strlen(test_str1);
    intret_std = strlen(test_str1);
    compare_results("ft_strlen", test_str1, intret_std, intret);
    
    intret = ft_strlen(test_str2);
    intret_std = strlen(test_str2);
    compare_results("ft_strlen", test_str2, intret_std, intret);
    
    intret = ft_strlen(test_str3);
    intret_std = strlen(test_str3);
    compare_results("ft_strlen", test_str3, intret_std, intret);

    printf("we got here\n");
    // ft_strcpy
    char dest1[50];
    char dest2[50];
    ft_strcpy(dest1, test_str1); // normal string
    strcpy(dest2, test_str1);
    compare_strings("ft_strcpy", test_str1, dest1, dest2);
    
    char dest3[50];
    char dest4[50];
    ft_strcpy(dest3, test_str3); // empty string
    strcpy(dest4, test_str3);
    compare_strings("ft_strcpy", test_str3, dest3, dest4);

    char dest5[50];
    char dest6[50];
    ft_strcpy(dest4, "A long string with spaces and symbols! @#%^&*()"); // null pointer
    strcpy(dest5, "A long string with spaces and symbols! @#%^&*()");
    compare_strings("ft_strcpy", dest4, dest5, dest5);

    // strcmp
    intret = strcmp(test_str1, test_str1); // same stuff
    intret_std = strcmp(test_str1, test_str1);
    compare_results("strcmp", test_str1, intret_std, intret);
    
    intret = strcmp(test_str1, test_str2); // "Hello world!" vs "12345"
    intret_std = strcmp(test_str1, test_str2);
    compare_results("strcmp", test_str2, intret_std, intret);

    intret = strcmp(test_str2, test_str1); // "12345" vs "Hello world!"
    intret_std = strcmp(test_str2, test_str1);
    compare_results("strcmp", test_str1, intret_std, intret);

    // ft_write
    char test_write[] = "Testing ft_write (this is the test)\n";
    printf(BLUE "Testing ft_write:\n" RESET);
    printf("  ft_write Output: ");
    if (ft_write(STDOUT_FILENO, test_write, sizeof(test_write) - 1) == -1) {
        printf(RED "ft_write failed: %s\n" RESET, strerror(errno));
    } else {
        printf(GREEN "ft_write succeeded\n" RESET);
    }
    
    printf("  Standard write Output: ");
    if (write(STDOUT_FILENO, test_write, sizeof(test_write) - 1) == -1) {
        printf(RED "write failed: %s\n" RESET, strerror(errno));
    } else {
        printf(GREEN "write succeeded\n" RESET);
    }
    intret = ft_write(-25, test_write, sizeof(test_write) - 1);
    intret_std = write(-25, test_write, sizeof(test_write) - 1);
    compare_results("ft_write", test_write, intret_std, intret);

    // read
    printf(BLUE "Testing ft_read:\n" RESET);
    printf("Type something and press Enter (it's reading stdin into a buffer and printing out the result): \n");
    ssize_t bytes_read = ft_read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        printf(RED "ft_read failed: %s\n" RESET, strerror(errno));
    } else {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer
        printf(GREEN "ft_read read %ld bytes: \"%s\"\n" RESET, bytes_read, buffer);
    }
    printf("Now test the original read syscall wrapper:\n");
    bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        printf(RED "read failed: %s\n" RESET, strerror(errno));
    } else {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer
        printf(GREEN "read read %ld bytes: \"%s\"\n" RESET, bytes_read, buffer);
    }
    // bad fd
    bytes_read = ft_read(-1, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        printf(RED "ft_read failed: %s\n" RESET, strerror(errno));
    }

    // ft_strdup
    char* dup1 = ft_strdup(test_str1); // "Hello world!"
    char* dup1_std = strdup(test_str1);
    compare_strings("ft_strdup", test_str1, dup1, dup1_std);
    free(dup1);
    free(dup1_std);
    
    char* dup2_std = strdup(test_str3);
    char* dup2 = ft_strdup(test_str3); // ""
    compare_strings("ft_strdup", test_str3, dup2, dup2_std);
    // free(dup2);
    // free(dup2_std);
}

int main() {
    test_comparisons();
    return 0;
}

