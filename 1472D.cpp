#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int p = 60;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        priority_queue<int> even, odd;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(a % 2 == 0){
                even.push(a);
            }
            else{
                odd.push(a);
            }
        }
        ll al = 0, bob = 0;
        for(int i = 0; i < n; i++){
            if(even.empty()){
                if(i % 2 == 0) odd.pop();
                else{
                    bob += odd.top();
                    odd.pop();
                }
            }
            else if(odd.empty()){
                if(i % 2 == 0){
                    al += even.top();
                    even.pop();
                }
                else{
                    even.pop();
                }
            }
            else if(!even.empty() && !odd.empty()){
                int ev = even.top();
                int od = odd.top();
                if(ev == od){
                    if(i % 2 == 0){
                        al += ev;
                        even.pop();
                    }
                    else{
                        bob += od;
                        odd.pop();
                    }
                }
                else if(ev > od){
                    if(i % 2 == 0){
                        al += ev;
                        even.pop();
                    }
                    else{
                        even.pop();
                    }
                }
                else{
                    if(i % 2 == 0){
                        odd.pop();
                    }
                    else{
                        bob += od;
                        odd.pop();
                    }
                }
            }
        }
        //cout << al << " " << bob << endl;
        if(al == bob){
            cout << "Tie" << endl;
        }
        else if(al > bob){
            cout << "Alice" << endl;
        }
        else{
            cout << "Bob" << endl;
        }
    }

    return 0;
}

