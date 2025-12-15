//ch.sc.u4cse24146
#include <stdio.h>
#define MAX 100

struct Stack {
    int items[MAX];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

void dfs(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    struct Stack stack;
    initStack(&stack);

    push(&stack, start);

    while (!isEmpty(&stack)) {
        int vertex = pop(&stack);

        if (!visited[vertex]) {
            printf("%d ", vertex);
            visited[vertex] = 1;
            int i;
            for (i = n - 1; i >= 0; i--) {
                if (graph[vertex][i] == 1 && !visited[i]) {
                    push(&stack, i);
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    int i,j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS traversal (using stack): ");
    dfs(graph, n, start);
    printf("\n");

    return 0;
}

