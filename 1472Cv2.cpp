#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int p = 60;
const int maxn = 2e5 + 11;
int arr[maxn];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
        }
        vector<ll> dp(n + 1, 0);
        for(int i = n; i >= 1; i--){
            if(arr[i] + i <= n){
                dp[i] = arr[i] + dp[arr[i] + i];
            }
            else{
                dp[i] = arr[i];
            }
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            ans = max(ans, dp[i]);
        }
        printf("%lld\n", ans);
    }

    return 0;
}



