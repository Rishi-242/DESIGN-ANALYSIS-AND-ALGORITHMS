#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int dim[100];
int mcm(int **arr, int *dim, int i, int j) {
    if (arr[i][j] != -1) {
        return arr[i][j];
    }
    if (i == j) {
        return arr[i][j] = 0;
    }
    int min = INT_MAX;
    for (int k = i; k < j; k++) {
        int val = mcm(arr,dim,i,k) + mcm(arr,dim,k+ 1, j) + dim[i-1]*dim[k]*dim[j];
        if (val<min) {
            min=val;
}
}
    return arr[i][j]=min;
}
int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    //int *dim=(int *)malloc((n + 1)*sizeof(int));
    if (dim==NULL) {
        printf("Memory allocation failed\n");
        return 1;
        }
    printf("Enter the dimensions: ");
    for (int k=0;k<=n;k++) {
        scanf("%d", &dim[k]);
        }
    int **arr = (int **)malloc((n+1)*sizeof(int *));
    for (int i=0;i<=n;i++) {
        arr[i] = (int *)malloc((n + 1)*sizeof(int));
        for (int j=0;j<=n;j++) {
            arr[i][j] = -1;
        }}
    printf("The minimum number of multiplications is %d\n", mcm(arr, dim, 1, n));
    for (int i=0; i<=n;i++) {
        free(arr[i]);
    }
   // free(arr);
    //free(dim);
return 0;
}



