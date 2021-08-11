#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int ans = 0;
        while(n){
            int r = n % 10;
            n /= 10;
            ans = max(ans, r);
        }
        cout << ans << endl;
    }
}
