#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 11;
vector<int> graph[maxn];
long long v[maxn][2];
long long dp[maxn][2];
int n;

long long rec(int pos, int idx, int pr){
    if(pos >= n) return 0;
    if(dp[pos][idx] != -1) return dp[pos][idx];
    long long ans = INT_MIN;
    long long ret = 0;
    if(pr != -1){
        ret = abs(v[pr][idx] - v[pos][0]);
    }
    for(int i = 0; i < graph[pos].size(); i++){
        if(graph[pos][i] != pr){
            ret += rec(graph[pos][i], 0, pos);
        }
    }
    ans = max(ans, ret);
    ret = 0;
    if(pr != -1){
        ret = abs(v[pr][idx] - v[pos][1]);
    }
    for(int i = 0; i < graph[pos].size(); i++){
        if(graph[pos][i] != pr){
            ret += rec(graph[pos][i], 1, pos);
        }
    }
    return dp[pos][idx] = max(ans, ret);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < maxn; i++){
            graph[i].clear();
            dp[i][0] = dp[i][1] = -1;
        }

        for(int i = 0; i < n; i++){
            cin >> v[i][0] >> v[i][1];
        }
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        long long ans = rec(0, 0, -1);
        cout << ans << endl;
    }
    return 0;
}

