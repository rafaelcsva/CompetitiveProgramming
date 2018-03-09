#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 100;
int p[N];

typedef long long	ll;
void permute(ll ini, ll size){
	if(size == 1){
		return;
	}
	
	for(ll i = 1 ; i < size; i++){
		swap(p[i + ini], p[i + ini + 1]);
	}
}

int main (){
	ll n, a, b;

	ios::sync_with_stdio(false);
	
	cin >> n >> a >> b;
	
	ll g1 = 0, g2 = 0;
	bool find = false;
	
	for(int i = 1 ; i <= n ; i++){
		p[i] = i;
	}
	
	for(g1 = n ; g1 >= 0 ; g1--){
		g2 = (n - g1 * a) / b;
		
		if(g1 * a + g2 * b == n && g2 >= 0){
			find = true;
			break;
		}
	}
	
	if(!find){
		cout << "-1\n";
		return 0;
	}
	
	int ac = 0;
	
	for(int i = 0 ; i < g1 ; i++){
		ac += a;
		permute(a * i, a);
	}
	
	for(int i = 0 ; i < g2 ; i++){
		permute(ac + b * i, b);
	}
	
	for(int i = 1 ; i <= n ; i++){
		cout << p[i] << ' ';
	}
	
	cout << '\n';
	
	return 0;
}
