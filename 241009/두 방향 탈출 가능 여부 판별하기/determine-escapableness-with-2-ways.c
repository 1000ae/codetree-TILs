#include <stdio.h>
#include <stdlib.h>

int row = 0;
int col = 0;
int** matrix = NULL;
int** v_matrix = NULL;

void dfs (int r, int c);
int exs_obj (int r, int c, int dir);
int main() {
    int i = 0;
    int j = 0;

    scanf("%d %d", &row, &col);

    matrix = (int**)malloc(row * sizeof(int*));
    v_matrix = (int**)malloc(row * sizeof(int*));
    matrix[0] = (int*)malloc(row * col * sizeof(int));
    v_matrix[0] = (int*)calloc(row * col, sizeof(int));
    for(i = 1; i < row; i++){
        matrix[i] = matrix[i - 1] + col;
        v_matrix[i] = v_matrix[i - 1] + col;
    }

    
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    dfs(0, 0);
    printf("%d", v_matrix[row - 1][col - 1]);
    
    free(v_matrix[0]);
    free(matrix[0]);
    free(v_matrix);
    free(matrix);
    return 0;
}
void dfs (int r, int c){
    int dx[] = {0, 1};
    int dy[] = {1, 0};
    int dir = 0;

    if(v_matrix[r][c]){
        return;
    }
    else{
        v_matrix[r][c] = 1;
    }
    for(dir = 0; dir < 2; dir++){
        if(exs_obj(r, c, dir)){
            dfs(r + dy[dir], c + dx[dir]);
        }
    }
}
int exs_obj (int r, int c, int dir){
    int dx[] = {0, 1};
    int dy[] = {1, 0};

    if(r + dy[dir] == row || c + dx[dir] == col){
        return 0;
    }
    if(matrix[r + dy[dir]][c + dx[dir]]){
        return 1;
    }
    else{
        return 0;
    }
}