//heap sort happens when we delete a element and store it in the last index

#include <stdio.h> // Including standard input/output header file

void Insert(int A[], int n) { // Function to insert element into the heap
    int i = n, temp; // Initializing variables i and temp
    temp = A[i]; // Storing the value at index i of array A[] in temp
    while (i > 1 && temp > A[i / 2]) { // Loop to maintain the max heap property
        A[i] = A[i / 2]; // Moving elements down the heap
        i = i / 2; // Moving to the parent node
    }
    A[i] = temp; // Placing the inserted element at the correct position in the heap
}

int Delete(int A[], int n) { // Function to delete the root (max value) from the heap
    int i, j, x, temp, val; // Declaring variables for heap operations
    val = A[1]; // Storing the root value (max value) of the heap in val
    x = A[n]; // Storing the last element of the heap in x
    A[1] = A[n]; // Placing the last element at the root
    A[n] = val; // Placing the previous root value at the last position
    i = 1; // Initializing variables for heap reordering
    j = i * 2; // Calculating the left child of the root
    while (j <= n - 1) { // Loop to reorder the heap
        if (j < n - 1 && A[j + 1] > A[j]) // Comparing left and right child to find the larger child
            j = j + 1; // Selecting the larger child
        if (A[i] < A[j]) { // If the current node is smaller than its child
            temp = A[i]; // Swapping the current node with its larger child
            A[i] = A[j];
            A[j] = temp;
            i = j; // Moving to the child node
            j = 2 * j; // Updating the left child
        } else
            break; // Break the loop if the heap property is satisfied
    }
    return val; // Returning the deleted value (previous root)
}

int main() {
    int H[] = {0, 14, 15, 5, 20, 30, 8, 40}; // Initializing an array representing a heap
    int i; // Declaring a variable for iteration
    for (i = 2; i <= 7; i++) // Inserting elements into the heap
        Insert(H, i); // Using the Insert function to maintain the heap property
    for (i = 7; i > 1; i--) { // Deleting elements from the heap
        Delete(H, i); // Using the Delete function to remove elements while maintaining the heap property
    }
    for (i = 1; i <= 7; i++) // Loop to print the remaining elements in the heap
        printf("%d ", H[i]); // Printing each element
    printf("\n"); // Printing a newline after the elements are printed
    return 0; // Indicating successful completion of the program
}
