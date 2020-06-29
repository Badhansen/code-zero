// Not AC
#include<bits/stdc++.h>
using namespace std;
using Long = long long;
int f(Long n, Long k){
    Long low = 1, high = 1e18;
    Long ans;
    while(low <= high){
        Long mid = (high - low) / 2 + low;
        Long d = mid / n;
        if(mid - d < k){
            ans = low;
            low = mid + 1;
        }
        else{
            high = mid + 1;
        }
    }
    return ans;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        Long n, k;
        cin >> n >> k;
        cout << f(n, k) << endl;
    }
    return 0;
}
