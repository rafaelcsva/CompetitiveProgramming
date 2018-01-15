#include <bits/stdc++.h>
 
using namespace std;
 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fileio freopen("in.in", "r", stdin),freopen("out.out", "w", stdout);
#define ll long long int
#define FF first
#define SS second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define pss printf
#define MOD 1000000007
#define INF 1e18
#define eps 0.00001
#define endl '\n'
#define debug(n1) cout<<n1<<endl
ll n,r;
ll x[1005];
double ans[1005];
double y[1005];
void getmax(ll i,ll j)
{
	double xi=double(x[i]);
	double xj=double(x[j]);
	double yj=double(y[j]);
	double yi=0;
	double rr=4.000000*double(r)*double(r);
	double xx=(xi-xj)*(xi-xj);
	double m=sqrt(double(rr-xx));
	yi=yj+m;
	ans[i]=max(ans[i],yi);
	y[i]=max(y[i],ans[i]);
}
int main() {
cin>>n>>r;

for(int i=1;i<=n;i++)
	cin>>x[i]; 

ans[1]=r;
y[1]=double(r);

for(int i=2;i<=n;i++)
{
	for(int j=1;j<i;j++)
	{
		if(abs(x[j]-x[i])<=2*r)
		{
			getmax(i,j);
		}
	}
}

for(int i=1;i<=n;i++)
	cout<<fixed<<setprecision(10)<<ans[i]<<" ";
cout<<endl;

	return 0;
           }
