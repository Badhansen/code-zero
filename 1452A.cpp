#include<bits/stdc++.h>
using namespace std;
const int Max = 200005;
int main(){
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        if(x == 0 && y == 0){
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        int flg = 1;
        if(x<y) swap(x,y);

        while(x && y){
            if(flg) x--;
            else y--;
            flg ^= 1;
            ans++;
        }

        if(x || y) ans += max(x, y) * 2 - 1;
        cout << ans << endl;
    }
    return 0;
}



