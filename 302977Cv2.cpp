#include<bits/stdc++.h>
using namespace std;

typedef long long Long;
const Long inf = 1e17;

int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int pr[n + 1];
    int vi[n + 1];
    Long dp[n + 1][8];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 8; j++){
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0ll;
    for(int i = 0; i < n; i++){
        string str;
        cin >> pr[i] >> str;
        int vitamin_mask = 0;
        for(int j = 0; j < str.size(); j++){
            int pos = 'C' - str[j];
            vitamin_mask |= (1 << pos);
        }
        vi[i] = vitamin_mask;
    }
    for(int i = 1; i <= n; i++){
        for(int mask = 0; mask < 8; mask++){
            dp[i][mask] = min(dp[i][mask], dp[i - 1][mask]);
            dp[i][mask | vi[i - 1]] = min(dp[i][mask | vi[i - 1]], dp[i - 1][mask] + pr[i - 1]);
        }
    }
    Long ans = dp[n][7];
    if(ans == inf) ans = -1;
    cout << ans << '\n';
    return 0;
}

