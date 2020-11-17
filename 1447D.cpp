#include<bits/stdc++.h>
using namespace std;

#define Max 5001

int n, m;
string a, b;
int dp[Max][Max];

int rec(int i, int j){
    if(i >= n || j >= m)
        return 0;
    int &ret = dp[i][j];
    if(ret != -1)
        return ret;
    ret = 0;
    if(a[i] == b[j])
        ret = rec(i + 1, j + 1) + 2;
    int l = rec(i + 1, j) - 1;
    int r = rec(i, j + 1) - 1;
    ret = max({ret, l, r});
    return ret;
}

int main(){
    cin >> n >> m;
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    rec(0, 0);
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
