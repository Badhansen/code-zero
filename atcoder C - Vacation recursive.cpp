// AC
#include<iostream>
#include<cstring>

using namespace std;

#define MAX_DAYS 100010
#define MAX_CHOICE 4

int n;
int item[MAX_DAYS][MAX_CHOICE];
int dp[MAX_DAYS][MAX_CHOICE];

int rec(int pos, int choice){
    if(pos >= n)
        return 0;
    int &ret = dp[pos][choice];
    if(ret != -1)
        return ret;
    ret = 0;
    if(choice == 1){
        ret = max(ret, rec(pos + 1, 2) + item[pos][2]);
        ret = max(ret, rec(pos + 1, 3) + item[pos][3]);
    }
    else if(choice == 2){
        ret = max(ret, rec(pos + 1, 1) + item[pos][1]);
        ret = max(ret, rec(pos + 1, 3) + item[pos][3]);
    }
    else{
        ret = max(ret, rec(pos + 1, 1) + item[pos][1]);
        ret = max(ret, rec(pos + 1, 2) + item[pos][2]);
    }
    return ret;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> item[i][1] >> item[i][2] >> item[i][3];
    }
    memset(dp, -1, sizeof dp);
    int ans = rec(0, 1);
    ans = max(ans, rec(0, 2));
    ans = max(ans, rec(0, 3));
    cout << ans << endl;

    return 0;
}
