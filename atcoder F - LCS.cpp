// AC
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 3000 + 5;
int n, m;
string s, t;
int dp[maxn][maxn];

int main(){
    cin >> s >> t;
    n = s.size(), m = t.size();

    for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) dp[i][j] = -1;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <=m; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int len = dp[n][m];
    char ans[len + 1];
    ans[len] = '\0';
    while(n > 0 && m > 0){
        if(s[n - 1] == t[m - 1]){
            ans[len - 1] = s[n - 1];
            n--, m--,len--;
        }
        else if(dp[n - 1][m] > dp[n][m - 1]){
            n--;
        }
        else{
            m--;
        }
    }
    cout << ans << endl;
    return 0;
}

