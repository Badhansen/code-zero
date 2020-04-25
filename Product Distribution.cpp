// https://www.hackerrank.com/contests/hack-the-interview-ii-global/challenges/distribution-in-m-bins/problem
// AC
#include<bits/stdc++.h>
using namespace std;
using LL = long long int;
const int MOD = 1e9 + 7;

int maxScore(vector<int> a, int m) {
    int n = a.size();
    sort(a.begin(), a.end());
    int divided_segment = n / m;
    int pos = 1, cnt = 0;
    LL ans = 0;
    LL res = 0;
    for(int i = 0; i < n; i++){
        if(pos == divided_segment){
            res += a[i];
            if(i == n - 1) ans = ans + res * pos;
        }
        else if(cnt == m){
            ans = ans + res * pos;
            res = a[i];
            cnt = 1;
            pos++;
        }
        else{
            res += a[i];
            cnt++;
            if(cnt == m){
                ans = ans + res * pos;
                pos++;
                cnt = 0;
                res = 0;
            }
        }
    }
    ans %= MOD;
    return ans;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> vt(n);
    for(int i = 0; i < n; i++){
        cin >> vt[i];
    }
    cout << maxScore(vt, m) << endl;
    return 0;
}
