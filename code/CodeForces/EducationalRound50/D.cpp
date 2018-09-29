#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define pb push_back
using ll = long long;
using ii = pair<int,int>;

const double eps = 1e-9;
const int mod = 1000000007;
const int N = 300005;

int n, m;
int a[N], b[N];
vector< pii > v[N];
ll gcd[N];

int main(){
	scanf("%d", &n);
	ll suma = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", a+i);
		suma += a[i];
	}

	scanf("%d", &m);
	ll sumb = 0;
	for(int i = 0; i < m; i++){
		scanf("%d", b+i);
		sumb += b[i];
	}
	if(suma != sumb){
		printf("-1\n");
	}
	else{
		int ans = 0;
		int ida = 1, idb = 1;
		ll sa = a[0], sb = b[0];
		while(ida != n || idb != m){
			if(sa < sb){
				sa += a[ida++];
			}
			else if(sb < sa){
				sb += b[idb++];
			}
			else{
				ans++;
				sa = sb = 0;
				sa += a[ida++];
				sb += b[idb++];
			}
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}