#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int maxn = 2e5 + 5;
ll arr[maxn];


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        ll positive = 0;
        ll negative = 0;

        for(int i = 2; i < n; i++){
            ll temp = arr[i] + positive - negative;
            if(arr[1] == temp) continue;
            if(arr[1] > temp){
                positive += (arr[1] - temp);
            }
            else{
                negative += (temp - arr[1]);
            }
        }

        ll ans = positive + negative;
        positive = 0;
        negative = 0;

        for(int i = 2; i < n; i++){
            ll temp = arr[i] + positive - negative;
            if(arr[0] ==  temp) continue;
            if(arr[0] > temp){
                positive += (arr[0] - temp);
            }
            else{
                negative += (temp - arr[0]);
            }

        }

        ans = min(ans, positive + negative);
        positive = 0;
        negative = 0;
        ll a = arr[n - 1];
        ll b = arr[n - 2];
        arr[n - 1] = b;
        //for(int i = 0; i < n; i++) cout << arr[i] << " ";
        for(int i = 1; i < n; i++){
            ll temp = arr[i] + positive - negative;
            if(arr[0] == temp) continue;
            if(arr[0] > temp){
                positive += (arr[0] - temp);
            }
            else{
                negative += (temp - arr[0]);
            }
        }

        ans = min(ans, positive + negative);
        positive = 0;
        negative = 0;
        arr[n - 1] = a;
        arr[n - 2] = a;
        //for(int i = 0; i < n; i++) cout << arr[i] << " ";
        for(int i = 1; i < n; i++){
            ll temp = arr[i] + positive - negative;
            if(arr[0] ==  temp) continue;
            if(arr[0] > temp){
                positive += (arr[0] - temp);
            }
            else{
                negative += (temp - arr[0]);
            }

        }
        ans = min(ans, positive + negative);
        arr[n - 2] = b;
        sort(arr, arr + n);
        if(arr[1] == arr[n - 1]){
            cout << 0 << endl;
        }
        else{
            cout << ans << endl;
        }
    }
    return 0;
}

