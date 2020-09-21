#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t, ts = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string str;
        cin >> str;
        int odd = 0;
        int even = 0;
        for(int i = 1; i <= n; i++){
            int a = str[i - 1];
            if(i % 2 == 0){
                if(a % 2 == 0) even++;
            }
            else{
                if(a % 2 != 0) odd++;
            }
        }
        //cout << even << " " << odd << endl;
        if(n % 2 == 0){
            if(even > 0) cout << 2 << endl;
            else cout << 1 << endl;
        }
        else{
            if(odd > 0) cout << 1 << endl;
            else cout << 2 << endl;
        }
    }
    return 0;
}

