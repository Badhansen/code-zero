#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int sum = 0, all = 1, affected = 0;
        for(int i = 0; i < n; i++){
            int a; 
            cin >> a;
            sum += (x - a);
            if(a != x) all = 0;
            if(a == x) affected = 1;
        }
        if(all){
            cout << 0 << endl;
        }
        else if(sum == 0 || affected){
            cout << 1 << endl;
        }
        else{
            cout << 2 << endl;
        }
    }
    return 0;
}