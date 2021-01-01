#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, c0, c1, h;
        string s;
        cin >> n >> c0 >> c1 >> h;
        cin >> s;
        int zero = 0, one = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') zero++;
            else one++;
        }
        int ans = 0;
        ans = zero * c0 + one * c1;
        ans = min(ans, (zero + one) * c1 + zero * h);
        ans = min(ans, (zero + one) * c0 + one * h);
        cout << ans << endl;
    }
    return 0;
}
