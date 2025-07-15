#include<stdio.h>
#define MAX_SIZE 100

int a[MAX_SIZE][MAX_SIZE];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int ks(int n, int w, int val[], int weight[]) {
    if (a[n][w] != -1)
        return a[n][w];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0)
                a[i][j] = 0;
            else if (weight[i - 1] > j)
                a[i][j] = a[i - 1][j];
            else
                a[i][j] = max(val[i - 1] + a[i - 1][j - weight[i - 1]], a[i - 1][j]);
        }
    }
    return a[n][w];
}

int main() {
    int n, w;
    int val[MAX_SIZE], weight[MAX_SIZE];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter the weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter the maximum weight capacity: ");
    scanf("%d", &w);

    // Initialize the a array to -1
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            a[i][j] = -1;
        }
    }

    int result = ks(n, w, val, weight);
    printf("The maximum value is: %d\n", result);

    return 0;
}
