#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int p = 60;
const int maxn = 2e5 + 11;
int arr[maxn];
vector<int> gr[maxn];
bool vis[maxn];
ll sum;

int dfs(int u){
    vis[u] = true;
    sum += arr[u];
    for(auto &v : gr[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 0; i <= n; i++){
            vis[i] = false;
            gr[i].clear();
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
            int v = arr[i] + i;
            if(v <= n){
                gr[i].push_back(v);
            }
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            if(vis[i] == false){
                sum = 0;
                dfs(i);
                ans = max(sum, ans);
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}



