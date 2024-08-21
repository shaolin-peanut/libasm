typedef struct s_list{
    void *data;
    struct s_list *next;
} t_list;

int main(void) {
    t_list *list = 0;
    list = malloc(sizeof(t_list));
    list->data = malloc(sizeof(int));
    *(int *)list->data = 1;
    list->next = 0;
    printf("list->data: %d\n", *(int *)list->data);
    return 0;
}