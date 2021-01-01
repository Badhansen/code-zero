#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> vt(n);
        for(int i = 0; i < n; i++){
            cin >> vt[i];
        }
        set<int> st;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int d = abs(vt[i] - vt[j]);
                st.insert(d);
            }
        }
        cout << st.size() << endl;
    }
    return 0;
}
