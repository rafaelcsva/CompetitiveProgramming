#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
typedef long long ll;
double a[N];
const double eps=1e-4;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	double d;
	scanf("%d %lf",&n,&d);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf",&a[i]);
	}
	double l=-2e16,r=2e16;
	while(r-l>eps)
	{
		double midl=l+(r-l)/3.0;
		double midr=r-(r-l)/3.0;
		double movl=fabs(a[0]-midl),movr=fabs(a[0]-midr);
		for (int i = 1; i < n; ++i)
		{
			if(movl-fabs((midl+i*d)-a[i])<eps)
				movl=fabs((midl+i*d)-a[i]);
			if(movr-fabs((midr+i*d)-a[i])<eps)
				movr=fabs((midr+i*d)-a[i]);
		}
		if(movl-movr>eps)
			l=midl;
		else
			r=midr;
	}
	// cout<<l<<" "<<r<<"\n";
	double mov=fabs(a[0]-l);
	for (int i = 1; i < n; ++i)
	{
		if(mov-fabs((l+i*d)-a[i])<eps)
				mov=fabs((l+i*d)-a[i]);
	}
	 l=-2e16,r=2e16;
	while(r-l>eps)
	{
		double midl=l+(r-l)/3.0;
		double midr=r-(r-l)/3.0;
		double movl=fabs(a[0]-midl),movr=fabs(a[0]-midr);
		for (int i = 1; i < n; ++i)
		{
			if(movl-fabs((midl-i*d)-a[i])<eps)
				movl=fabs((midl-i*d)-a[i]);
			if(movr-fabs((midr-i*d)-a[i])<eps)
				movr=fabs((midr-i*d)-a[i]);
		}
		if(movl-movr>eps)
			l=midl;
		else
			r=midr;
	}
	double mov1=fabs(a[0]-l);
	for (int i = 1; i < n; ++i)
	{
		if(mov1-fabs((l-i*d)-a[i])<eps)
				mov1=fabs((l-i*d)-a[i]);
	}
	if(mov1-mov<eps)
		mov=mov1;
    long long mitn = floor(mov * 10.0);

	printf("%lld.%lld\n",mitn / 10LL, mitn % 10LL);

    return 0;
}