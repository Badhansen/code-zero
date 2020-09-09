// AC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        string res(60, 'a');
        cout << res << endl;
        for(int i = 0; i < n; i++){
            if(res[v[i]] == 'z'){
                res[v[i]] = 'a';
            }
            else{
                res[v[i]]++;
            }
            cout << res << endl;
        }
    }
    return 0;
}