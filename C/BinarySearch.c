#include <stdio.h>
int binarySearch (int arr[], int l, int r, int x){

    if (r >= l) {
        int mid = (r+l)/2;
        printf("%d %d\n",l,r);
        if (arr[mid] == x){
            return mid;
        }else if (arr[mid] > x){
            return binarySearch(arr,l,mid-1,x);
        }else{
            return binarySearch(arr,mid+1,r,x);
        }
    }
    return -1;
}

int main (){
    int arr[] = {2,3,10,14,40};
    int n = sizeof(arr) / sizeof(arr[0]);
    // printf("%d",n);
    int x = 14;
    int result = binarySearch (arr, 0, n - 1, x) ;
    (result == -1) ? printf ("Element is not present in array") : printf ("Element is present at index %d", result) ;
    return 0;
}