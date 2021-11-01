#include <stdio.h>

/// Maximum size of the arrays
const int DIM = 1e5+1;

void print_subarray(int arr[], int leftBorder, int rightBorder){
    while(leftBorder <= rightBorder) printf("%d ", arr[leftBorder ++]);
    printf("\n");
    return;
}

void sort_subarray_in_increasing_order(int arr[], int leftBorder, int rightBorder, int tmp[]){
/** 
 *  This function sorts subarray of array <arr> from <leftBorder> to <rightBorder> inclusive using MergeSort algorithm
 **/
    if (leftBorder >= rightBorder) return;
    int mid = (leftBorder + rightBorder)/2;
    sort_subarray_in_increasing_order(arr, leftBorder, mid, tmp);
    sort_subarray_in_increasing_order(arr, mid+1, rightBorder, tmp);
    int i=leftBorder, j=mid+1, k=leftBorder;
/**
 *  <i> is used to iterate through the first half of the subarray
 *  <j> is used to iterate through the second half of the subarray
 *  <k> is used to iterate through the temporary array
**/
    while(k <= rightBorder){
        if (i<=mid && j<=rightBorder){
            if (arr[i] < arr[j]) tmp[k ++] = arr[i ++];
            else tmp[k ++] = arr[j ++];
        }else{
            if (i <= mid) tmp[k ++] = arr[i ++];
            else tmp[k ++] = arr[j ++];
        }
    }
    while(leftBorder <= rightBorder){
        arr[leftBorder] = tmp[leftBorder];
        leftBorder ++;
    }
    return;
}

int main(){
    int a[DIM], b[DIM], answer[DIM], tmp[DIM], n, m, k = 0;
/// Getting arrays from input:
    printf("Size of array A: ");
    scanf("%d", &n);
    printf("Elements of array A: ");
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    printf("Size of array B: ");
    scanf("%d", &m);
    printf("Elements of array B: ");
    for (int i=0; i<m; i++) scanf("%d", &b[i]);
/// Sorting arrays:
    sort_subarray_in_increasing_order(a, 0, n-1, tmp);
    sort_subarray_in_increasing_order(b, 0, m-1, tmp);
/** Finding answer using two iterators:
 *  iterator <i> for array <a> and iterator <j> for array <b>;
 *  for each a[i] we find first b[j] such that a[i] <= b[j] by skipping all b[j] that are smaller than a[i];
 *  as arrays are sorted, we can confidently say that if a[i] < b[j], then a[i] is surely not present in array <b>;
 *  so, if a[i] == b[j], we add a[i] to the answer;
 * */
    int i = 0, j = 0;
    while(i < n && j < m){
        while(j < m && b[j] < a[i]) j ++;
        if (b[j] == a[i]) answer[k ++] = a[i];
        i ++;
    }
/// Printing answer:
    printf("\nSize of intersection of arrays A and B: %d\n", k);
    printf("Elements of intersection of arrays A and B: ");
    print_subarray(answer, 0, k-1);
    return 0;
}