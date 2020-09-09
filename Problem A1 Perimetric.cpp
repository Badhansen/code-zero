#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
typedef long long Long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int t, ts = 1;
    cin >> t;
    while(t--){
        Long n, k, w;
        Long al, bl, cl, dl, ah, bh, ch, dh;
        cin >> n >> k >> w;
        vector<Long> l(n), h(n);
        for(int i = 0; i < k; i++){
            cin >> l[i];
        }
        cin >> al >> bl >> cl >> dl;
        for(int i = 0; i < k; i++){
            cin >> h[i];
        }
        cin >> ah >> bh >> ch >> dh;
        for(int i = k; i < n; i++){
            l[i] = ((al * l[i - 2]) % dl + (bl * l[i - 1]) % dl + cl) % dl + 1;
            h[i] = ((ah * h[i - 2]) % dh + (bh * h[i - 1]) % dh + ch) % dh + 1;
        }
        for(int i = 0; i < n; i++){
            cout << l[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; i++){
            cout << h[i] << " ";
        }
        cout << endl;
        Long ans = 1;
        Long mx = h[0];
        Long first = l[0], last = l[0] + w;
        Long sum = 2ll * (w + mx);
        ans = (ans % MOD * (2ll * (w + mx)) % MOD) % MOD;
        for(int i = 1; i < n; i++){
            mx = max(mx, h[i]); 
            if(l[i] >= first && l[i] <= last){
                last = l[i] + w;
                ans = (ans % MOD * (2ll * (last - first + mx)) % MOD) % MOD;
            }
            else{
                first = l[i];
                last = first + w;
                ans = (ans % MOD * (ans + (2ll * (last - first + mx)) % MOD)) % MOD;
            }
            cout << first << " -- " << last << endl;
            
        }
        cout << "Case #" << ts++ << ": " << ans << "\n";
    }
    return 0;
}