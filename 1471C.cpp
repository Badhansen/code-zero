#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int p = 60;
const int maxn = 3e5 + 11;
int kr[maxn];
int cr[maxn];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll sum = 0;
        for(int i = 1; i <= n; i++){
            cin >> kr[i];
        }
        sort(kr + 1, kr + n + 1, greater<int>());
        for(int i = 1; i <= m; i++){
            cin >> cr[i];
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            if(i <= kr[i]){
                ans += cr[i];
            }
            else{
                ans += cr[kr[i]];
            }
        }
        cout << ans << endl;
    }
    return 0;
}






