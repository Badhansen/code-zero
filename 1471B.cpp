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
        vector<pair<ll, ll>> cnt;
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(arr[i] % x == 0){
                cnt.push_back({arr[i] / x, x});
            }
            else{
                flag = false;
                break;
            }
        }
        for(int i = 0; flag && i < cnt.size(); i++){
            if(cnt[i].first % x == 0){
                cnt.push_back({cnt[i].first / x, cnt[i].second * x});
            }
            else{
                break;
            }
        }
        for(int i = 0; i < cnt.size(); i++){
            sum += (cnt[i].first * cnt[i].second);
        }
        cout << sum << endl;
    }
    return 0;
}





