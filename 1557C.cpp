#include<bits/stdc++.h>

using namespace std;
typedef long long Long;

const int Maxn = 2e5 + 11, Mod = 1e9 + 7;

Long fact[Maxn], ifact[Maxn], inv[Maxn];
Long n, k, evenSum;
Long dp[Maxn][5];

Long bMOD(int a, int b)
{
    if(b == 0)
        return 1ll;
    Long ans = bMOD(a, b / 2);
    ans = (ans * ans) % Mod;

    if(b & 1) ans = (ans * a) % Mod;
    return ans;
}
void call()
{

    fact[0] = 1;
    for(int i=1; i<Maxn; i++){
        fact[i] = (fact[i-1] * i) % Mod;
    }
    ifact[0] = 1;
    inv[1] = 1;
    for(int i=2; i<Maxn; i++){
        inv[i] = ((Mod -(Mod/i)) % Mod * inv[Mod%i] % Mod) % Mod;
    }
    for(int i=1; i<Maxn; i++){
        ifact[i] = (ifact[i - 1] * inv[i]) % Mod;
    }
}
Long nCr(int n, int r)
{
    int res = (ifact[r] * ifact[n-r]) % Mod;
    res = (res * fact[n]) % Mod;
    return res;
}
Long solve(int pos, int flag)
{
    if(pos >= k) return 1ll;
    if(dp[pos][flag] != -1){
        return dp[pos][flag];
    }
    Long ret = 0;
    if(flag){
        ret = (bMOD(2, n) * solve(pos + 1, flag)) % Mod;
    }
    else{
        ret = (evenSum * solve(pos + 1, flag)) % Mod;
        if(n & 1){
            ret = (ret + solve(pos + 1, flag)) % Mod;
        }
        else{
            ret = (ret + solve(pos + 1, 1)) % Mod;
        }
    }
    return dp[pos][flag] = ret;
}
int main()
{
    call();
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        evenSum = 0;
        for(int i = 0; i < n; i += 2) {
            evenSum = (evenSum + nCr(n, i)) % Mod;
        }
        memset(dp, -1, sizeof dp);
        Long answer = solve(0, 0) % Mod;
        cout << answer << endl;
    }
    return 0;
}
