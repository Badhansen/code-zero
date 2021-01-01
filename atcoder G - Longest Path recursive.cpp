// AC
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 5;
int n, m;
vector<int> adj[maxn];
int dp[maxn];
bool vis[maxn];

void dfs(int node){
    vis[node] = true;
    for(int i = 0; i < adj[node].size(); i++){
        if(!vis[adj[node][i]])
            dfs(adj[node][i]);
        dp[node] = max(dp[node], 1 + dp[adj[node][i]]);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 0; i <= n; i++){
        dp[i] = 0;
        vis[i] = false;
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i])
            dfs(i);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
