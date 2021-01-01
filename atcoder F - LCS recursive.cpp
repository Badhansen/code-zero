// AC
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 3000 + 5;
int n, m;
string s, t;
int dp[maxn][maxn];

int rec(int i, int j){
    if(i >= n || j >= m)
        return 0;
    int &ret = dp[i][j];
    if(ret != -1)
        return ret;
    if(s[i] == t[j])
        ret = 1 + rec(i + 1, j + 1);
    else
        ret = max(rec(i + 1, j), rec(i, j + 1));
    return ret;
}
string lcs(int i, int j){
    if(i == n || j == m)
        return "";
    else if(s[i] == t[j])
        return s[i] + lcs(i + 1, j + 1);
    else if(dp[i + 1][j] > dp[i][j + 1])
        return lcs(i + 1, j);
    else
        return lcs(i, j + 1);
}
int main(){
    cin >> s >> t;
    n = s.size(), m = t.size();

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) dp[i][j] = -1;
    rec(0, 0);
    string ans = lcs(0, 0);
    cout << ans << endl;
    return 0;
}
