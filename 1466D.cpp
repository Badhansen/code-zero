#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 1e5 + 10;
vector<pair<int, int>> node;
int wt[maxn];
int dgr[maxn];
bool vis[maxn];
bool flag = false;
vector<int> gr[maxn];
ll sum = 0;

void dfs(int u){
    vis[u] = true;
    for(auto &v : gr[u]){
        if(!vis[v]){
            sum += wt[u] + wt[v];
            if(flag == false && u == 1){
                dfs(v);
                flag = true;
            }
            else{
                node.push_back({wt[u], u});
                dfs(v);
            }


        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        sum = 0;
        flag = false;
        node.clear();
        for(int i = 0; i <= n; i++){
            gr[i].clear();
            vis[i] = false;
        }
        for(int i = 1; i <= n; i++){
            cin >> wt[i];
        }
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        dfs(1);
        sort(node.begin(), node.end());
        vector<int> ans;
        ans.push_back(sum);
        for(int i = 0; i < node.size(); i++){
            sum -= wt[node[i].second];
            ans.push_back(sum);
        }
        int siz = ans.size();
        for(int i = siz - 1; i >= 0; i--){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}



