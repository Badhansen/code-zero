#include<bits/stdc++.h>
using namespace std;
typedef long long Long;
int main(){
    int n, k;
    cin >> n >> k;
    int typeable[26] = {0};
    string str;
    cin >> str;
    for(int i = 0; i < k; i++){
        char c;
        cin >> c;
        typeable[c - 'a'] = 1;
    }
    Long dp[n + 1] = {0};
    Long ans = 0;
    for(int i = 0; i < n; i++){
        if(typeable[str[i] - 'a']){
            dp[i + 1] = dp[i] + 1;
        }
        else{
            dp[i + 1] = 0;
        }
        ans += dp[i + 1];
    }
    cout << ans << "\n";
    return 0;
}
