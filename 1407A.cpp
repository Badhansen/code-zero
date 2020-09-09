#include<bits/stdc++.h>
using namespace std;

#define MAX 1001
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n + 1);
        int count_one = 0, count_zero = 0, odd_sum = 0, even_sum = 0;
        for(int i = 1; i <= n; i++){
            cin >> v[i];            
            if(v[i] == 0) count_zero++;
            else count_one++;
            if(i & 1) odd_sum += v[i];
            else even_sum += v[i];
        }
        if(odd_sum == even_sum){
            cout << n << endl;
            for(int i = 1; i <= n; i++){
                cout << v[i] << " ";
            }
            cout << endl;
        }
        else if(count_zero >= n / 2){
            cout << count_zero << endl;
            for(int i = 1; i <= count_zero; i++){
                cout << 0 << " ";
            }
            cout << endl;
        }
        else{
            if(count_one & 1) count_one--;
            cout << count_one << endl;
            for(int i = 1; i <= count_one; i++){
                cout << 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
