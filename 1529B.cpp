#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int ans = 1, mini = INT_MAX;
        for(int i = 1; i < n; i++){
            mini = min(mini, abs(v[i] - v[i - 1]));
            if(v[i] > mini){
                break;
            }
            else{
                ans++;
            }

        }
        cout << ans << endl;
    }
    return 0;
}
