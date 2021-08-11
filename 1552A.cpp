#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string st, a;
        cin >> st;
        a = st;
        sort(a.begin(), a.end());
        int fr = 0;
        for(int i = 0; i < n; i++){
            if(a[i] != st[i]) fr++;
        }
        cout << fr << endl;
    }
    return 0;
}


