// Ok code
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int msb_pos(int n){
    int pos = -1;
    while(n){
        n >>= 1;
        pos++;
    }
    return pos;
}
int and_operator(int a, int b){
    int ans = 0;
    while(a && b){
        int p = msb_pos(a);
        int q = msb_pos(b);

        if(p != q) return ans;

        ans += (1 << p);

        a -= (1 << p);
        b -= (1 << p);
    }
    return ans;
}

ll and_operator(ll a, ll b){
    while(a < b){
        b -= (b & -b);
    }
    return b;
}
int main(){
    ll n, m;
    while(cin >> n >> m){
        cout << and_operator(n, m) << endl;
    }
    return 0;
}
