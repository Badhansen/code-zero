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

int main(){
    cin >> n >> W;
    for(int i = 0; i < n; i++){
        cin >> wt[i] >> val[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 100000; j++){
            dp[i][j] = 1e11;
        }
    }

    dp[0][0] = 0;
    dp[0][val[0]] = wt[0];

    for(int i = 1; i < n; i++){
        dp[i][0] = 0;
        for(int j = 1; j <= 100000; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= val[i])
                dp[i][j] = min(dp[i][j], wt[i] + dp[i - 1][j - val[i]]);
        }
    }
    for(int i = 100000; i >= 0; i--){
        if(dp[n - 1][i] <= W){
            cout << i << endl;
            break;
        }
    }
    return 0;
}


