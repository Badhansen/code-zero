#include<bits/stdc++.h>
using namespace std;

/*
    @author: Badhan Sen
    @mail: badhan.cse@gmail.com
    @My code start from here
*/

int main(){
    int t, ts = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> value(n);
        vector<int> temp;
        for(int i = 0; i < n; i++){
            cin >> value[i];
        }
        temp = value;
        sort(value.begin(), value.end());
        int answer = 0;
        for(int i = 0; i < n - 1; i++){
            int j = i;
            for(; j < n; j++){
                if(value[i] == temp[j]) break;
            }
            answer += (j - i + 1);
            bool flag = true;
            if(i != j){
                reverse(temp.begin() + i, temp.begin() + j + 1);
            }
        }
        cout << "Case #" << ts++ << ": " << answer << endl;
    }
    return 0;
}
