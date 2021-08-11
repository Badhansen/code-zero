#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int d = n / 3;
        int arr[3] = {0};
        arr[1] = arr[2] = d;
        arr[n % 3]++;
        cout << arr[1] << " " << arr[2] << endl;

    }
    return 0;
}


