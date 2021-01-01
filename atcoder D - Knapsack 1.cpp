// AC
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, W;
    cin >> n >> W;
    vector<int> wt(n + 1), val(n + 1);
    for(int i = 0; i < n; i++){
        cin >> wt[i] >> val[i];
    }
    long dp[n + 1][W + 1];
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(i == 0 || w == 0){
                dp[i][w] = 0;
            }
            else if(wt[i - 1] <= w){
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]],
                               dp[i - 1][w]);
            }
            else{
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    cout << dp[n][W] << endl;
    return 0;
}
