#include<iostream>
#include<vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> st(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int cnt = 0;
        for (int i = 1; i < n - 1; i++) {
            if (v[i - 1] < v[i] && v[i] > v[i + 1]) {
                st[i] = 2;
                cnt++;
            }
            if (v[i - 1] > v[i] && v[i] < v[i + 1]) {
                st[i] = 1;
                cnt++;
            }
        }
        bool flag = true;
        for (int i = 0; i < n - 2; i++) {
            if(st[i] * 100 + st[i + 1] * 10 + st[i + 2] == 121){
                cnt -= 3;
                flag = false;
                break;
            }
            if(st[i] * 100 + st[i + 1] * 10 + st[i + 2] == 212){
                cnt -= 3;
                flag = false;
                break;
            }
        }
        for (int i = 0; flag && i < n - 2; i++) {
            if(st[i] * 10 + st[i + 1] == 12){
                cnt -= 2;
                break;
            }
            if(st[i] * 10 + st[i + 1] == 21){
                cnt -= 2;
                break;
            }
        }
        if(flag){
            cout << max(0, cnt - 1) << endl;
        }
        else{
            cout << max(0, cnt) << endl;
        }
    }
    return 0;
}

