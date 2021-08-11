/* Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(‐1) = a^(m‐2) (mod m)
*/


#include<bits/stdc++.h>

using namespace std;
long long pow(int a, int b, int MOD)
{
    long long x=1, y=a;
    while(b>0){
        if(b%2==0){
            x=x*y;
            x%=MOD;
        }



    }



}
int main()
{



    return 0;
}
