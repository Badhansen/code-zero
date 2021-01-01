// AC
#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAX_STONE 100010
#define MAX 1000000000

int n, k;
int dp[MAX_STONE];
int val[MAX_STONE];
int rec(int pos){
    if(pos == n - 1)
        return 0;
    int &ret = dp[pos];
    if(ret != -1)
        return ret;
    ret = MAX;
    for(int i = 1; i <= k; i++){
        if(pos + i < n)
            ret = min(ret, rec(pos + i) + abs(val[pos + i] - val[pos]));
    }
    return ret;
}
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    for(int i = 0; i <= n; i++){
        dp[i] = -1;
    }
    int ans = rec(0);
    cout << ans << endl;
    return 0;
}

