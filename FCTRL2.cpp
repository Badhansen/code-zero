#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        vector<int> arr;
        int n;
        cin >> n;

        arr.push_back(1);
        int carry = 0;

        for(int i = 2; i <= n; i++){
            vector<int> t;
            for(int j = arr.size() - 1; j >= 0; j--){
                int r = arr[j] * i + carry;
                carry = r / 10;
                t.push_back(r % 10);
            }
            while(carry){
                t.push_back(carry % 10);
                carry /= 10;
            }
            reverse(t.begin(), t.end());
            arr = t;
        }
        for(auto el : arr){
            cout << el;
        }
        cout << endl;
    }
    return 0;
}
