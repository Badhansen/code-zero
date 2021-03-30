#include<bits/stdc++.h>
using namespace std;

/*
    @author: Badhan Sen
    @mail: badhan.cse@gmail.com
    @My code start from here
*/

const int maxn = 1e3 + 11;
string st;
int x, y;
int dp[maxn][3];
bool vis[maxn][3];

int rec(int pos, int prev){
    // 1 is for C
    // 2 is for J
    if(pos >= st.size()){
        return 0;
    }
    if(vis[pos][prev]){
        return dp[pos][prev];
    }
    vis[pos][prev] = true;
    int left = INT_MAX / 2, right = INT_MAX / 2, middle = INT_MAX / 2;
    if(st[pos] == '?'){
        middle = rec(pos + 1, prev);
        if(prev == 1){
            left = x + rec(pos + 1, 2);
        }
        else if(prev == 2){
            right = y + rec(pos + 1, 1);
        }
        else{
            left = rec(pos + 1, 1);
            right = rec(pos + 1, 2);
        }
    }
    else{
        if(st[pos] == 'J'){
            left = rec(pos + 1, 2);
            if(prev == 1){
                left += x;
            }
        }
        else{
            right = rec(pos + 1, 1);
            if(prev == 2){
                right += y;
            }
        }
    }
    return dp[pos][prev] = min({left, middle, right});
}

int main(){
    int t, ts = 1;
    cin >> t;
    while(t--){
        cin >> x >> y >> st;
        memset(vis, false, sizeof vis);
        int answer = rec(0, 0);
        cout << "Case #" << ts++ << ": " << answer << endl;
    }
    return 0;
}
