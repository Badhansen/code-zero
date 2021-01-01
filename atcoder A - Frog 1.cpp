// AC
#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAX_STONE 100010

int n;
int dp[MAX_STONE];
int val[MAX_STONE];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        dp[i] = dp[i - 1] + abs(val[i] - val[i - 1]);
        if(i > 1){
            dp[i] = min(dp[i], dp[i - 2] + abs(val[i] - val[i - 2]));
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}

