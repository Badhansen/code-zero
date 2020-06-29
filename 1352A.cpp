// AC
#include<bits/stdc++.h>
using namespace std;
int Pow(int a, int b){
    int res = 1;
    for(int i = 0; i < b; i++){
        res *= a;
    }
    return res;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[100];
        int id = 0;
        int pos = 0;
        while(n != 0){
            int r = n % 10;
            n /= 10;
            if(r > 0){
                int d = r * Pow(10, pos);
                arr[id++] = d;
            }
            pos++;
        }
        cout << id << endl;
        for(int i = 0; i < id; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
