#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int p = 60;
const int maxn = 2e5 + 11;
ll arr[maxn];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        ll sum = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            sum += arr[i];
        }
        ll mini = sum / x;
        if(sum % x != 0) mini++;
        ll maxi = 0;
        for(int i = 0; i < n; i++){
            ll tmp = arr[i] / x;
            if(arr[i] % x != 0) tmp++;
            maxi += tmp;
        }
        cout << mini << " " << maxi << endl;
    }
    return 0;
}




