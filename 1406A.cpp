#include<bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t, ts = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int v;
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            cin >> v;
            mp[v]++;
        }
        bool flag = true;
        vector<int> a, b;
        for(int i = 0; i <= 100; i++){
            if(mp[i] > 0){
                int x = mp[i];
                // if(x % 2 == 0){
                //     if(flag){
                //         a.push_back(i);
                //         b.push_back(i);
                //     }
                //     else{
                //         a.push_back(i);
                //     }
                // }
                // else{
                //     a.push_back(i);
                //     flag = false;
                // }
                if(x == 1){
                    a.push_back(i);
                    flag = false;
                }
                else{
                    if(flag){
                        a.push_back(i);
                        b.push_back(i);
                    }
                    else a.push_back(i);
                }
            }
            else{
                break;
            }
        }
        int A, B;
        A = B = 0;
        int sz_a = a.size();
        int sz_b = b.size();
        if(sz_a != 0){
            A = a[sz_a - 1] + 1;
        }
        if(sz_b != 0){
            B = b[sz_b - 1] + 1;
        }
        cout << A + B << endl;
    }
    return 0;
}
