// AC
#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
using namespace std;

#define MAX_ITEMS 105
#define MAX_SUM 100005
#define ll long long


int n, W;
int wt[MAX_ITEMS];
int val[MAX_ITEMS];
ll dp[MAX_ITEMS][MAX_SUM];
bool visit[MAX_ITEMS][MAX_SUM];

ll rec(int pos, int make){
    if(pos == n){
        if(make == 0)
            return 0;
        return INT_MAX;
    }
    ll &ret = dp[pos][make];
    bool &memo = visit[pos][make];
    if(memo)
        return ret;
    memo = true;
    ret = INT_MAX;
    if(val[pos] <= make){
        ret = min(ret, rec(pos + 1, make - val[pos]) + wt[pos]);
    }
    ret = min(ret, rec(pos + 1, make));
    return ret;
}
int main(){
    cin >> n >> W;
    for(int i = 0; i < n; i++){
        cin >> wt[i] >> val[i];
    }
    for(int i = 100000; i >= 0; i--){
        int ans = rec(0, i);
        if(ans <= W){
            cout << i << endl;
            break;
        }
    }
    return 0;
}



