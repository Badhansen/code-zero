#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 1e5 + 10;

int wt[maxn];
int dgr[maxn];
ll sum = 0;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        sum = 0;
        for(int i = 0; i <= n; i++){
            dgr[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            cin >> wt[i];
            sum += wt[i];
        }
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            dgr[v]++;
            dgr[u]++;
        }
        priority_queue<pair<ll, int>> qt;
        for(int i = 1; i <= n; i++){
            if(dgr[i] >= 2){
                qt.push({wt[i], i});
            }
        }
        vector<ll> ans;
        ans.push_back(sum);
        for(int i = 2; i < n; i++){
            pair<ll, int> p = qt.top();
            //cout << p.first << " " << p.second;
            qt.pop();
            sum += p.first;
            ans.push_back(sum);
            dgr[p.second]--;
            if(dgr[p.second] >= 2){
                qt.push(p);
            }
        }
        for(auto a : ans){
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}




