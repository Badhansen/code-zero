#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string st;
        cin >> st;
        int siz = st.size();
        int ans = 0;
        for(int i = 1; i < siz; i++){
            if(i == 1 && st[i - 1] == st[i]){
                st[i] = 'A';
                ans++;
            }
            if(i > 1 && (st[i - 1] == st[i] || st[i - 2] == st[i])){
                st[i] = 'A';
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}


