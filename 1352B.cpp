// AC
#include<bits/stdc++.h>
using namespace std;
int path[101];
int n, k;
bool rec(int n, int step, bool isEnable){
    if(isEnable == false){
        if(n <= 0) return false;
        if(step == k && n % 2 != 1) return false;
        if(step == k && n % 2 == 1){
            cout << "YES" << endl;
            path[step] = n;
            for(int i = 1; i <= k; i++){
                cout << path[i] << " ";
            }
            cout << endl;
            return true;
        }
        path[step] = 1;
        return rec(n - 1, step + 1, isEnable);
    }
    else{
        if(n <= 0) return false;
        if(step == k && n % 2 != 0) return false;
        if(step == k && n % 2 == 0){
            cout << "YES" << endl;
            path[step] = n;
            for(int i = 1; i <= k; i++){
                cout << path[i] << " ";
            }
            cout << endl;
            return true;
        }
        path[step] = 2;
        return rec(n - 2, step + 1, isEnable);
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        bool r = rec(n , 1, true);
        if(r) continue;
        r = rec(n , 1, false);
        if(r) continue;
        cout << "NO" << endl;
    }
    return 0;
}
