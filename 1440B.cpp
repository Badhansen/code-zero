#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        vector<int> v;
        cin >> n >> k;
        for(int i = 0; i < n * k; i++){
            int a;
            cin >> a;
            v.push_back(a);
        }
        int tr = (n / 2) + 1;
        long long ans = 0;
        int cnt = 0;
        for(int i = n * k - tr; i >= 0 && cnt < k; i = i - tr, cnt++){
            //cout << v[i] << " ";
            ans += v[i];
        }
        //cout << endl;
        cout << ans << endl;
    }
    return 0;
}
