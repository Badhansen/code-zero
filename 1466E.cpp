#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int p = 60;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> v(n);
        vector<int> cnt(p, 0);
        for(int i = 0; i < n; i++){
            cin >> v[i];
            for(int j = 0; j < p; j++){
                cnt[j] += v[i] >> j & 1;
            }
        }
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll Or = 0, And = 0;
            for(int j = 0; j < p; j++){
                if((v[i] >> j) & 1){
                    Or += (1ll << j) % mod * n;
                    And += (1ll << j) % mod * cnt[j];
                }
                else{
                    Or += (1ll << j) % mod * cnt[j];
                }
            }
            Or %= mod, And %= mod;
            ans = (ans + 1ll * Or * And) % mod;
        }
        cout << ans << endl;
    }

    return 0;
}
