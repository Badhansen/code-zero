// AC
#include<bits/stdc++.h>
using namespace std;
using LL = long long int;
const int MAX = 2e5 + 11;
vector<int> adj[MAX];
int dis[MAX];
bool visit[MAX];
bool tour[MAX];
LL child[MAX];
vector<pair<int, int>> vt;
LL ans;
LL dfs(int u){
    visit[u] = true;
    child[u] = 1;
    for(auto v : adj[u]){
        if(visit[v] == false){
            dis[v] = dis[u] + 1;
            child[u] += dfs(v);
        }
    }
    return child[u];
}
LL dfs2(int u){
    visit[u] = true;
    LL child = 0;
    for(auto v : adj[u]){
        if(visit[v] == false){
            child += dfs2(v);
        }
    }
    if(tour[u] == false) child++;
    else ans += child;
    return child;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
        vt.push_back({dis[i] - child[i], i});
    }
    sort(vt.begin(), vt.end());
    k = n - k;
    for(auto x : vt){
        if(k == 0) break;
        tour[x.second] = true;
        k--;
    }
    memset(visit, false, sizeof(visit));
    dfs2(1);
    cout << ans << endl;
    return 0;
}

