#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int p = 9;
        if(n <= 10){
            for(int i = 0; i < n; i++){
                cout << p;
                p--;
                if(p == -1) p = 9;
            }
            cout << endl;
        }
        else{
            for(int i = 0; i < 10; i++){
                cout << p;
                p--;
            }
            p = 1;
            for(int i = 10; i < n; i++){
                cout << p;
                p++;
                if(p == 10) p = 0;
            }
            cout << endl;
        }
    }
    return 0;
}
