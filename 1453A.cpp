#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> a(n), b(m);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < m; i++){
            cin >> b[i];
        }
        int cnt = 0, i = 0, j = 0;
        while(i < n && j < m){
            if(a[i] == b[j]){
                i++, j++, cnt++;
            }
            else if(a[i] > b[j]){
                j++;
            }
            else{
                i++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

