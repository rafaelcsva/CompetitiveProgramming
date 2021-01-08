#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200001 ;
const ll mod=1e9+7LL;
vector<int> lista[N];
int n;
ll dp[N][3];
ll inv(ll x)
{
	ll b=mod-2,at=x,rs=1;
	while(b)
	{
		if(b&1)
			rs=(rs*at)%mod;
		at=(at*at)%mod;
		b>>=1;
	}
	return rs;
}
ll solve(int p,int x)
{
	if(lista[p].empty())
	{
		return 1;
	}
	ll &ans=dp[p][x];
	if(ans!=-1)
		return ans;
	ll at=1,nat;
	for (auto u:lista[p])
	{
		at=(at*solve(u,0))%mod;
	}
	if(x==0)
		ans=at;
	else
		ans=0;
	for (auto u:lista[p])
	{
		nat=(((at*solve(u,1))%mod)*inv(solve(u,0)))%mod;
		// cout<<u<<" "<<nat<<"<-\n";
		ans=(ans+nat)%mod;
	}
	return ans;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);  
    cin>>n;
    int x;
    // cout<<inv(1)<<"\n";
    memset(dp,-1,sizeof(dp));
    for (int i = 2; i <= n; ++i)
    {
    	cin>>x;
    	lista[x].push_back(i);
    }
    cout<<solve(1,0)<<"\n";
    return 0;
}