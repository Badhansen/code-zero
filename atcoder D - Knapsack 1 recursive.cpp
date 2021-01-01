// AC
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

#define MAX_ITEM 101
#define MAX_WEIGHT 100011

int n, W;
int wt[MAX_ITEM];
int val[MAX_ITEM];
long dp[MAX_ITEM][MAX_WEIGHT];

long rec(int pos, int w){
    cout << pos << " " << w << endl;
    if(w < 0)
        return INT_MIN;
    if(pos == n){
        if(w >= 0)
            return 0;
        else
            return INT_MIN;
    }
    if(dp[pos][w] != -1)
        return dp[pos][w];
    long left = 0, right = 0;
    if(wt[pos] <= w)
        left = rec(pos + 1, w - wt[pos]) + val[pos];
    right = rec(pos + 1, w);
    return dp[pos][w] = max(left, right);
}
int main(){
    cin >> n >> W;
    for(int i = 0; i < n; i++){
        cin >> wt[i] >> val[i];
    }
    for(int i = 0; i <= n; i++) for(int j = 0; j <= W; j++) dp[i][j] = -1;
    long ans = rec(0, W);
    cout << ans << endl;
    return 0;
}
