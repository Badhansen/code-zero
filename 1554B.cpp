#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> val;
long long func(int i, int j, int k)
{
    long long res = 1ll * val[i].second * 1ll * val[j].second
                    - 1ll * k * (val[i].first | val[i - 1].first);
    return res;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        val.resize(n);
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            val[i] = {x, i + 1};
        }
        sort(begin(val), end(val));
        long long ans = INT_MIN;ki
        int l = 0, r = n - 1;
        while(l < r){
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            long long r1 = func(m1, m2)
        }
        cout << ans << endl;
    }
    return 0;
}




