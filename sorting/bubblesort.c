#include <stdio.h>

void BubbleSort(int A[], int n) {
    int i, j, flag, temp;
    for (i = 0; i < n - 1; i++) { // Total passes to be performed
        flag = 0;
        for (j = 0; j < n - 1 - i; j++) { // -i because that part is already sorted, comparisons
            if (A[j] > A[j + 1]) { // Ascending order 
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) { // No swaps performed
            break;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int A[n]; // Declaring array of size 'n'

    printf("Please enter %d elements for the array:\n", n);
    for (int z = 0; z < n; z++) {
        scanf("%d", &A[z]);
    }

    BubbleSort(A, n);

    printf("Sorted array:\n");
    for (int k = 0; k < n; k++) {
        printf("%d ", A[k]);
    }
    printf("\n");

    return 0;
}
