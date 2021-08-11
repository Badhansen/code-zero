#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string st;
        cin >> st;
        int on = 0;
        unordered_map<char, int> m;
        for(int i = 0; i < st.size(); i++){
            m[st[i]]++;
        }
        int ans = 0;
        for(char i = 'a'; i <= 'z'; i++){
            if(m[i] == 1) on++;
            else if(m[i] >= 2) ans++;
        }
        ans += on / 2;
        cout << ans << endl;
    }
    return 0;
}



