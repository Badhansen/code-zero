#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int p = 60;

int main(){
    int t;
    cin >> t;
    while(t--){
        int w, h, n;
        cin >> w >> h >> n;
        int a = 0, b = 0;
        while(w % 2 == 0){
            a++;
            w /= 2;
        }
        while(h % 2 == 0){
            b++;
            h /= 2;
        }
        ll ans = 1 << (a + b);
        if(ans >= n){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}


