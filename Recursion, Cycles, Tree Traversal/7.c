
#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define BLACK 1
#define MARKED 2

#define BOUND_SIZE 2

int max(int a, int b) {
    return (a > b ? a : b);
}

int check(int currRow, int currCol, int ** picture) {
    if (picture[currRow][currCol] == WHITE) {
        picture[currRow][currCol] = MARKED;
        return 0;
    }

    int figureSquare;
    if (picture[currRow][currCol] == BLACK)
        figureSquare = 1;
    
    picture[currRow][currCol] = MARKED;
        
    if (picture[currRow - 1][currCol] == BLACK)
        figureSquare += check(currRow - 1, currCol, picture);
    if (picture[currRow][currCol - 1] == BLACK)
        figureSquare += check(currRow, currCol - 1, picture);
    if (picture[currRow + 1][currCol] == BLACK)
        figureSquare += check(currRow + 1, currCol, picture);
    if (picture[currRow][currCol + 1] == BLACK)
        figureSquare += check(currRow, currCol + 1, picture);

    return figureSquare;
}

int n;
int m;
int ** picture;

int main() {
    scanf("%d %d", &n, &m);
    picture = (int **)malloc((n + BOUND_SIZE) * sizeof(int *));
    int i;
    for (i = 0; i < n + BOUND_SIZE; ++i)
        picture[i] = (int *)malloc((m + BOUND_SIZE) * sizeof(int));
    int j;
    for (i = 0; i < n + BOUND_SIZE; ++i)
        for (j = 0; j < m + BOUND_SIZE; ++j)
            if (i == 0 || i == n + 1 || j == 0 || j == m + 1)
                picture[i][j] = MARKED;
            else
                scanf("%d", &picture[i][j]);
    
    int maxFigureSize = 0;
    for (i = 0; i < n + BOUND_SIZE; ++i)
        for (j = 0; j < m + BOUND_SIZE; ++j)
            if (picture[i][j] != MARKED)
                maxFigureSize = max(maxFigureSize, check(i, j, picture));
    printf("%d", maxFigureSize);
    return 0;
}