#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        string str;
        cin >> n >> q;
        cin >> str;
        for(int i = 0; i < q; i++){
            int l, r;
            cin >> l >> r;
            l--, r--;
            bool flag = true;
            for(int j = 0; j < l && flag; j++){
                if(str[l] == str[j]){
                    flag = false;
                }
            }
            for(int j = r + 1; j < n && flag; j++){
                if(str[r] == str[j]){
                    flag = false;
                }
            }
            cout << (flag ? "NO" : "YES") << endl;
        }

    }
    return 0;
}

