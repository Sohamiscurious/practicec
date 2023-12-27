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

void Insertion(int A[],int n){
  int i,j,x;
  for(i=1;i<n;i++){//we start from one because we assume that the first element is already sorted
    j=i-1;//j is the index of the previous element
    x=A[i];//x is the element to be inserted

    while(j>-1 && A[j]>x){//we compare the element to be inserted with the elements before it
      A[j+1]=A[j];//we shift the elements to the right which are greater than x
      j--;//we decrement j to compare with the next element before it
      
    }
    A[j+1]=x;//we insert x at the correct position decrement is not done here so plus one
}
}
void SelectionSort(int A[], int n ){
    int i,j,k;
    for(i=0;i<n-1;i++){//this is basically the number of passes
        for(j=k=i;j<n;j++){//j and k will start from current i and j will interate till end
            if(A[j]<A[k]){
                k=j;//j finds a smaller element than k is updated there 
            }
        }
        //outside this loop we have found k smallest lets swap it with our current i
        swap(&A[i],&A[k]);
    }
}
int partition(int A[],int l,int h){
    int pivot=A[l];
    int i=l,j=h;
    do{
        do{i++}while(A[i]<=pivot);//ulta thinking
        do{j--}while(A[j]>pivot);//ulta thinking
        if(i<j){
            swap(A[i],A[j]);
        }
    }while(i<j);
    swap(A[l],A[j]);//i is not greater than j we perform final swap
    return j
}
void QuickSort(int A[],int l,int h){
    int j;
    
    if(l<h){
        j=partition(A,l,h);//the element where partion happens
        QuickSort(A,l,j);//left side partion
        QuickSort(A,j+1,h);//right side partion
    }
}

//iterative version of merge sort
void Merge(int A[],int l,int mid,int h){
    int i,j,k;
    int B[100];//auxillary array
    
    while(i<=mid && j<=h){
        if(A[i]<A[j])
            B[k++]=A[i++]; //copying elements from i because it is less lol
        else
            B[k++]=A[j++]; //here j wala column ka element is less
    }
    for(;i<mid;i++ ){
        B[k++]=A[i]; //copying remaining elemetns as one list is smaller than the other list
    }
    for(;j<=h;j++){
        B[k++]=A[j];
    }
    for(int i=l;i<=h;i++){
        A[i]=B[i];//transfering elements
    }
    
}
//recursive approach
void MergeSort(int A[],int l,int h){
    int mid;
    if(l<h){
        mid=(l+h)/2;
        MergeSort(A,l,mid);//performs merge sort on left side of mid 
        MergeSort(A,mid+1,h);//right side
        Merge(A,l,mid,h);
    }
}

void MergeSort(int A[], int n) {
    int p, l, h, mid, i; // Declare variables for MergeSort

    for (p = 2; p <= n; p = p * 2) { // Loop through increasing sub-array sizes (powers of 2)
        for (i = 0; i + p - 1 < n; i = i + p) { // Iterate through the array with sub-array size 'p'
            l = i; // Set the left boundary of the sub-array
            h = i + p - 1; // Set the right boundary of the sub-array
            mid = (l + h) / 2; // Calculate the midpoint of the sub-array
            Merge(A, l, mid, h); // Merge the two halves of the sub-array
        }
    }

    if (p / 2 < n) { // Check if there are remaining elements after main merging loops
        Merge(A, 0, (p / 2) - 1, n - 1); // Merge the remaining elements into the sorted array
    }
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int findMax(int A[],int n){
    int max=INT32_MIN;
    int i;
    for(i=0;i<n;i++){
        if(A[i]>max){
            max=A[i];
        }
    }
    return max;
}
void CountSort(int A[],int n){
    int i,j,max,*C;
    max=findMax(A,n);
    C=(int *)malloc(sizeof(int)*(max+1));
    for(i=0;i<max+1;i++){
        C[i]=0;//intialise our count array with zeros
    }
    for(i=0;i<n;i++){
        C[A[i]]++;//increment count array element . this is done first by finding the value by index . and that value is index for count array
    }
    i=0;j=0;
    while(j<max+1){
        if(c[j]>0){
            A[i++]=j;//add the element to the our original array
            C[j]--;// decrement the count
        }
        else{
            j++;//move to next element
        }
    }
}
void countSort(int arr[], int n, int exp) {
    int output[n]; // Output array
    int count[10] = {0}; // Initialize count array for digits 0 to 9

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] contains sorted numbers according to current digit
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(int arr[], int n) {
    int max = getMax(arr, n); // Get the maximum number from the array

    // Perform counting sort for every digit. exp is the exponent of 10.
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp); // Call countSort to sort the numbers based on the current digit
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

    SelectionSort(A, n);//just change the name here for the sort you want to estabish

    printf("Sorted array:\n");
    for (int k = 0; k < n; k++) {
        printf("%d ", A[k]);
    }
    printf("\n");

    return 0;
}
