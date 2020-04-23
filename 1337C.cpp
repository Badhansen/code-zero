#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 11;
vector<int> adj[MAX];
vector<int> leaf_node;
vector<int> path[MAX];
int leaf[MAX];
int vis[MAX];
int intime[MAX];
int outtime[MAX];
int timer;

void dfs(int n, int p) {
    leaf[n] = 0;
    vis[n] = 1;
    intime[n] = ++timer;
    path[n].insert(path[n].end(), path[p].begin(), path[p].end());
    if(adj[n].size() == 1){
        leaf[n] = 1;
        leaf_node.push_back(n);
    }
    for(auto it : adj[n]){
        if(!vis[it]){
            dfs(it, n);
            leaf[n] += leaf[it];
        }
    }
}
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    for(int i = 1; i <= n; i++){
        path[i].push_back(i);
    }
    dfs(1, 1);

    vector<pair<int, int>> vt;
    for(int i = 1; i <= n; i++){
        vt.push_back({leaf[i], i});
        path[i].pop_back();
    }
    sort(vt.begin(), vt.end());
    for(int i = 1; i <= n; i++){
        cout << i  << " : ";
        for(auto x : path[i]){
            cout << x << " ";
        }
        cout << endl;
    }
    for(auto c : vt){
        cout << c.second << " " << c.first << endl;
    }
    if(leaf_node.size() == k){
        int answer = 0;
        for(auto x : leaf_node){
            answer += path[x].size() - 1;
        }
        cout << answer << endl;
    }
    else if(leaf_node.size() > k){
        vector<pair<int, int>> pt;
        for(auto x : leaf_node){
            pt.push_back({path[x].size(), x});
        }
        sort(pt.begin(), pt.end(), greater<pair<int, int>>());
        int answer = 0;
        for(int i = 0; i < k; i++){
            answer += pt[i].first - 1;
        }
        cout << answer << endl;
    }
    else{
        int answer = 0;
        bitset<MAX> bit;
        vector<pair<int, int>> pt;
        unordered_map<int, int> mp;
        for(auto x : leaf_node){
            bit.set((1 << x));
            //pt.push_back({path[x].size(), x});
        }
        for(int i = 1; i <= n; i++){
            if(!bit[(1 << i)]){
                pt.push_back({path[i].size(), i});
            }
        }
        sort(pt.begin(), pt.end(), greater<pair<int, int>>());
        cout << "o" << endl;
        int cnt = leaf_node.size();
        for(int i = 0; i < pt.size(); i++){
            if(cnt == k) break;
            mp[pt[i].second] = 1;
            cnt++;
        }
        for(int i = 2; i <= n; i++){
            for(auto x : path[i]){
                if(!mp[x]) answer++;
            }
        }
        cout << answer << endl;
    }
    for(auto x : leaf_node){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

