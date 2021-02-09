#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int p = 60;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int one = 0, two = 0;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(a == 1) one++;
            else two++;
        }
        if(two % 2 == 0 && one % 2 == 0){
            cout << "YES" << endl;
        }
        else if(two % 2 == 1){
            if(one > 2 && (one - 2) % 2 == 0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}

