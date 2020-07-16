#include<bits/stdc++.h>

using namespace std;
void merge(int *arr, int low, int mid, int high)
{
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
    for(int i = low, j = 0; i <= high; i++, j++){
        arr[i] = temp[j];
    }
}
void merge_sort(int *arr, int low, int high)
{
    if(low < high){
        int mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main()
{
    srand(time(NULL));
    int arr[100001], n;
    cin >> n;
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 10;
    }
    cout << "Before Sort:\n";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    merge_sort(arr, 0, n - 1);
    cout << "\nAfter sorting\n";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}