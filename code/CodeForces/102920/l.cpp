#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
typedef long long ll;
vector<pair<ll,ll>> v;
ll bs(ll h,ll p)
{
	int l=0,r=v.size()-1;
	while(r-l>100)
	{
		// cout<<l<<" "<<r<<"\n";
		int midl=l+(r-l)/3;
		int midr=r-(r-l)/3;
        ll ansl = 0;
        ll ansr = 0;

        for(int i = 0 ; i < 50; i++){
            ansl = max(ansl, (v[midl + i].first+h)*(p-v[midl + i].second));
        }

        for(int i = 0 ; i < 50 ; i++){
            ansr = max(ansr, (v[midr - i].first+h)*(p-v[midr - i].second));
        }

		if(ansl > ansr)
			r=midr;
		else
			l=midl;
	}
	ll rs=0;
	while(l<=r)
	{
		rs=max(rs,(v[l].first+h)*(p-v[l].second));
		l++;
	}
	if(v.empty() || 2LL * v[v.size()-1].first < h)
		v.push_back({h,p});
	return rs;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	ll rs=0,h;
	for (int i = 0; i < n; ++i)
	{
		cin>>h;
		rs=max(rs,bs(h,i));
	}
	cout<<rs<<"\n";
}