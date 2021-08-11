#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 7;
string s,t;

bool solve()
{
    int l1 = s.size(),l2=t.size();

    int i=0,j=0,last=0;
    int p = (l1-l2)&1;
    for(i=p;i<l1 && j<l2;)
    {
        if(s[i]==t[j])
        {
            i++;
            j++;
        }
        else
        {
            i+=2;
        }
    }


    if(j==l2)   return true;
    return false;

}
int main ()
{
    int n;
    cin>>n;
    while(n--)
    {
        cin>>s>>t;
        if(s.size()<t.size())
        {
            printf("NO\n");
            continue;
        }
        else if(s.size()==t.size())
        {
            if(s==t)
            {
               printf("YES\n");
            }
            else{
               printf("NO\n");
            }
            continue;
        }
        else
        {
            bool f = solve();
            if(f)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}
