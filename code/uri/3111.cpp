#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2010 ;
const ll mod=998244353LL;
const int inf=N*N+10;
int a[N];
int vis[N][3],dp[N][110],vis2[N][110],t=1;
vector<pair<int,int>> ac[N][3];
vector<int> lista[N];
int solve2(int at,int x,int p,int h)
{
    if(at==lista[p].size())
    {
        if(x!=0)
            return inf;
        return 0;
    }    
    if(vis2[at][x]==t)
        return dp[at][x];
    vis2[at][x]=t;
    dp[at][x]=inf;
    int u=lista[p][at];
    for (auto d:ac[u][h])
    {
        dp[at][x]=min(dp[at][x],d.second+solve2(at+1,x^d.first,p,h));
    }
    return dp[at][x];
}
void solve(int p,int h)
{
    if(vis[p][h])
        return;
    if(lista[p].empty())
    {
        if(h)
        {
            ac[p][h].push_back({a[p],0});
            ac[p][h].push_back({0,1});
        }else
        {
            ac[p][h].push_back({0,0});
        }
        return;
    }
    vis[p][h]=1;
    if(h==1)
    {
        solve(p,0);
        ac[p][1]=ac[p][0];
        for(auto v:lista[p])
        {
            solve(v,0);
        }
    }else
    {
        for(auto v:lista[p])
        {
            solve(v,1);
        }
    }
    for (int i = 0; i < 101; ++i)
    {
        int x=solve2(0,i,p,!h);
        if(x<inf)
        {
            //cout<<p<<" "<<i<<" "<<h<<" "<<i<<"\n";
            if(h)
            {
                ac[p][h].push_back({i^a[p],x});
            }else
            {
                ac[p][h].push_back({i,x});
            }

        }
        t++;
    }

}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    int n; 
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
        cin>>a[i];
    }
    int r,p;
    for (int i = 1; i <= n; ++i)
    {
        cin>>p;
        if(p!=-1)
            lista[p].push_back(i);
        else
            r=i;
    }
    solve(r,0);    
    cout<<ac[r][0][0].second<<"\n";
    return 0;
}