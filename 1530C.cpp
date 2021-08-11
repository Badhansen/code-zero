#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a, b;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            a.push_back(x);
        }
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            b.push_back(x);
        }
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        vector<int> A(n, 0), B(n , 0);
        for(int i = 0; i < n; i++){
            if(i == 0) A[i] = a[i], B[i] = b[i];
            else{
                A[i] = A[i - 1] + a[i];
                B[i] = B[i - 1] + b[i];
            }
        }
        int k = n - n / 4;
        if(A[k - 1] >= B[k - 1]) cout << 0 << endl;
        else{
            int count = 1;
            while(1){
                int nn = n + count;
                int kk = nn - nn / 4;
                int cnt = max(0, kk - count);
                int me = 0, liya = 0;
                if(cnt == 0){
                    me = 100 * count;
                    liya = B[n - 1];
                }
                else{
                    me = 100 * count + A[cnt - 1];
                    if(kk >= n) liya = B[n - 1];
                    else liya = B[kk - 1];
                }
                if(me >= liya) break;
                count++;
            }
            cout << count << endl;
        }
    }
    return 0;
}


