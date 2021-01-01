// AC
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAX_DAYS 100010
#define MAX_CHOICE 4

int n;
int item[MAX_DAYS][MAX_CHOICE];
int dp[MAX_DAYS][MAX_CHOICE];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> item[i][1] >> item[i][2] >> item[i][3];
    }

    dp[0][1] = item[0][1];
    dp[0][2] = item[0][2];
    dp[0][3] = item[0][3];

    for(int i = 1; i < n; i++){
        dp[i][1] = item[i][1] + max(dp[i - 1][2], dp[i - 1][3]);
        dp[i][2] = item[i][2] + max(dp[i - 1][1], dp[i - 1][3]);
        dp[i][3] = item[i][3] + max(dp[i - 1][1], dp[i - 1][2]);
    }
    cout << max({dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]}) << endl;

    return 0;
}

