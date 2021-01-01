#include<bits/stdc++.h>
using namespace std;

const int Max = 200005;
int n;
int pr[Max];
int vi[Max];
int dp[Max][8];

int rec(int pos, int mask){
    if(pos >= n){
        if(mask == 7)
            return 0;
        return INT_MAX / 2;
    }
    int &ret = dp[pos][mask];
    if(ret != -1){
        return ret;
    }
    ret = INT_MAX / 2;
    ret = min(ret, rec(pos + 1, mask | vi[pos]) + pr[pos]);
    ret = min(ret, rec(pos + 1, mask));
    return ret;
}
int main(){
    cin >> n;
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
    memset(dp, -1, sizeof dp);
    int ans = rec(0, 0);
    if(ans == INT_MAX / 2) ans = -1;
    cout << ans << '\n';
    return 0;
}
