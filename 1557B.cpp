#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

void solve()
{
    vector<pii> v;
    int n,temp,k;

    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back({temp,i});
    }

    sort(v.begin(),v.end());

    int sol[n],i=0;
    for(auto it: v)
        sol[it.second] = i++;

    int comp = 1;

    for(int i=1;i<n;i++)
    {
        if(sol[i]!=sol[i-1]+1)
        {
            comp++;
        }
    }

    if(comp<=k)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}

int main ()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
}
