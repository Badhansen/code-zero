#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n;
        vector<int> r(n);
        for(int i = 0; i < n; i++){
            cin >> r[i];
            if(i != 0){
                r[i] += r[i - 1];
            }
        }
        cin >> m;
        vector<int> b(m);
        for(int i = 0; i < m; i++){
            cin >> b[i];
            if(i != 0){
                b[i] += b[i - 1];
            }
        }
        int answer = 0;
        for(int i = 0; i < n; i++){
            answer = max(answer, r[i]);
            for(int j = 0; j < m; j++){
                answer = max(answer, b[j]);
                answer = max(answer, r[i] + b[j]);
            }
        }
        cout << answer << endl;
    }
    return 0;
}
