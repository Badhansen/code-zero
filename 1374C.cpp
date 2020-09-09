// AC
#include<bits/stdc++.h>
using namespace std;
int main(){
    int total;
    cin >> total;
    while(total--){
        int n;
        string s;
        cin >> n;
        cin >> s;
        int brc = 0, ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                brc++;
            }
            else{
                brc--;
                if(brc < 0){
                    brc = 0;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}