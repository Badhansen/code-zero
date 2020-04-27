#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
using ll = long long int;

ll child[5000001],vis[300001],ans=0,tour[300001],dis[300001];

vector<ll>v[300001];

vector<pair<ll,ll>>vp;

ll po(ll a,ll n)

{

    ll ans=1;

    for(int i=1; i<=n; i++)

        ans*=a;

    return ans;

}



ll dfs(ll start)

{

    vis[start]=1;

    for(int i=0; i<v[start].size(); i++)

    {

        ll u=v[start][i];

        if(vis[u]==0)

        {

            dis[u]=dis[start]+1;

            child[start]+=dfs(u);

        }

    }

    return child[start]+1;

}



ll dfs2(ll start)

{

    ll child=0;

    vis[start]=1;

    for(int i=0; i<v[start].size(); i++)

    {

        ll u=v[start][i];

        if(vis[u]==0)

        {

            child+=dfs2(u);

        }

    }

    if(tour[start]==0)

    {

        child++;

    }

    else

        ans+=child;

    return child;

}



int main()

{

    ios::sync_with_stdio(false);

    cin.tie(nullptr);





    ll n,k;

    cin>>n>>k;

    k=n-k;

    for(int i=1; i<n; i++)

    {

        ll a,b;

        cin>>a>>b;

        v[a].push_back(b);

        v[b].push_back(a);

    }

    dfs(1);

    for(int i=1; i<=n; i++)

    {

        vp.push_back(make_pair(dis[i]-child[i],i));

    }

    sort(vp.begin(),vp.end());

    for(int j=0; j<vp.size(); j++)

    {

        if(k==0)

            break;

        tour[vp[j].second]=1;

        k--;

    }

    memset(vis,0,sizeof(vis));

    ll d=dfs2(1);

    cout<<ans<<endl;

    return 0;

}
