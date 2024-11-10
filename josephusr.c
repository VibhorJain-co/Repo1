#include <stdio.h>

// Function to solve Josephus problem
int josephus(int n, int k) {
    if (n == 1)
        return 0; // Base case: only one person remains (0-based index)
    else
        return (josephus(n - 1, k) + k) % n;
}

int main() {
    int n, k;
    scanf("%d", &n);
    k=2;

    int result = josephus(n, k) + 1;

    printf("The safe position is: %d\n", result);
    return 0;
}