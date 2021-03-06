#include<iostream>

using namespace std;
void merge(int *arr, int low, int mid, int high){
    int temp[high - low + 1];
    int i = low, j = mid + 1, k = 0;
    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= high){
        temp[k++] = arr[j++];
    }
    for(int i = low, k = 0; i <= high; i++, k++){
        arr[i] = temp[k];
    }
}
void merge_sort(int *arr, int low, int high){
    if(low < high){
        int mid = low + (high-low)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 }; 
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < arr_size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    merge_sort(arr, 0, arr_size - 1);
    for(int i = 0; i < arr_size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}