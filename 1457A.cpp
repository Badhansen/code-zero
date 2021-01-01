#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, m, r, c, t, ans;
    cin >> t;
    while(t--){
        cin >> n >> m >> r >> c;
        ans = abs(1 - r) + abs(1 - c);
        ans = max(ans, abs(1 - r) + abs(m - c));
        ans = max(ans, abs(n - r) + abs(1 - c));
        ans = max(ans, abs(n - r) + abs(m - c));
        cout << ans << endl;
    }
}
