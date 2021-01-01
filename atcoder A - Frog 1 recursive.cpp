// AC
#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAX_STONE 100010

int n;
int dp[MAX_STONE];
int val[MAX_STONE];

/*
int rec(int pos){
    if(pos < 0)
        return INT_MAX / 2;
    if(pos == 0)
        return 0;
    if(dp[pos] != -1)
        return dp[pos];
    int left = rec(pos - 1) + abs(val[pos] - val[pos - 1]);
    int right = INT_MAX / 2;
    if(pos >= 2)
        right = rec(pos - 2) + abs(val[pos] - val[pos - 2]);
    return dp[pos] = min(left, right);
}
*/
int rec(int pos){
    if(pos >= n)
        return INT_MAX / 2;
    if(pos == n - 1)
        return 0;
    if(dp[pos] != -1)
        return dp[pos];
    int left = INT_MAX / 2;
    int right = INT_MAX / 2;
    left = rec(pos + 1) + abs(val[pos + 1] - val[pos]);
    if(pos + 2 < n)
        right = rec(pos + 2) + abs(val[pos + 2] - val[pos]);
    return dp[pos] = min(left, right);
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    for(int i = 0; i <= n; i++) dp[i] = -1;
    // int ans = rec(n - 1);
    int ans = rec(0);
    cout << ans << endl;
    return 0;
}
