// AC
#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAX_STONE 100010
#define MAX 1000000000

int n, k;
int dp[MAX_STONE];
int val[MAX_STONE];

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        dp[i] = dp[i - 1] + abs(val[i] - val[i - 1]);
        for(int j = 2; j <= k; j++){
            if(i - j >= 0)
                dp[i] = min(dp[i], dp[i - j] + abs(val[i] - val[i - j]));

        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}


