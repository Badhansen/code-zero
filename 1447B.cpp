#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int sum = 0;
        int mn = INT_MAX;
        int neg = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int a;
                cin >> a;
                if(a < 0) neg++;
                sum += abs(a);
                mn = min(mn, abs(a));
            }
        }
        if(neg & 1){
            sum -= 2 * mn;
        }
        cout << sum << endl;
    }
    return 0;
}
