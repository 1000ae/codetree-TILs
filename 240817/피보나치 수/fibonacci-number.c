#include <stdio.h>
#include <stdlib.h>

int* arr = NULL;

int pibo (int depth);
int main() {
    int n = 0;
    int i = 0;
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));
    
    for(i = 0; i < n; i++){
        arr[i] = -1;
    }
    printf("%d", pibo(n));
    free(arr);
    return 0;
}

int pibo (int depth){
    if(arr[depth - 1] != -1){
        return arr[depth - 1];
    }
    if(depth == 1 || depth == 2){
        arr[depth - 1] = 1;
        return 1;
    }
    else{
        arr[depth - 1] = pibo(depth - 1) + pibo(depth - 2);
        return arr[depth - 1];
    }

}