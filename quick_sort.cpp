#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}
void quickSort(vector<int> &arr, int low, int high)
{
    if(low < high){
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    quickSort(v, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}