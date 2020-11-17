#include<bits/stdc++.h>
using namespace std;
typedef long long Long;
int main()
{
    int test;
    cin >> test;
    while(test--){
        Long x;
        cin >> x;
        Long n = 1, d = 2ll;
        int ans = 0;
        while(x > 0ll){
            Long sum = n * (n + 1) / 2ll;
            x -= sum;
            if(x >= 0ll) ans++;
            else break;
            n += d;
            d = d * 2ll;
        }
        cout << ans << endl;    
    }
    return 0;
}