#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> val(n);
        long long ans = 0;
        for(int i = 0; i < n; i++){
            cin >> val[i];
        }
        for(int i = 1; i < n; i++){
            ans = max(ans, val[i] * val[i - 1]);
        }

        cout << ans << endl;
    }
    return 0;
}



