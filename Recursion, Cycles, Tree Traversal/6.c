
#include <stdio.h>
#include <stdlib.h>

#define BOUND 2

#define EMPTY 0
#define WALL 1
#define REACHED 2

void check(int currRow, int currCol, int ** labyrinth) {
    labyrinth[currRow][currCol] = REACHED;
    if (labyrinth[currRow - 1][currCol] == EMPTY)
        check(currRow - 1, currCol, labyrinth);
    if (labyrinth[currRow][currCol - 1] == EMPTY)
        check(currRow, currCol - 1, labyrinth);
    if (labyrinth[currRow + 1][currCol] == EMPTY)
        check(currRow + 1, currCol, labyrinth);
    if (labyrinth[currRow][currCol + 1] == EMPTY)
        check(currRow, currCol + 1, labyrinth); 
}

int n;
int m;
int ** labyrinth;

int main() {
    scanf("%d %d", &n, &m);
    labyrinth = (int **)malloc((n + BOUND) * sizeof(int *));
    int i;
    for (i = 0; i < n + BOUND; ++i)
        labyrinth[i] = (int *)malloc((m + BOUND) * sizeof(int));
    int j;
    for (i = 0; i < n + BOUND; ++i)
        for (j = 0; j < m + BOUND; ++j)
            if (i == 0 || i == n + 1 || j == 0 || j == m + 1)
                labyrinth[i][j] = WALL;
            else
                scanf("%d", &labyrinth[i][j]);
    check(1, 1, labyrinth);
    printf("%s", labyrinth[n][m] == REACHED ? "exists" : "doesn't exist");
    return 0;
}