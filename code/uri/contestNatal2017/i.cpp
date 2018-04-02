#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e3 + 100;

typedef struct{
	int u, v;
	long long int w;
}Aresta;

int dist(pair<int, int> u, pair<int, int> v){
	int ax = abs(u.first - v.first);
	int ay = abs(u.second - v.second);

	if(ax == 0){
		return ay - 1;
	}

	if(ay == 0){
		return ax - 1;
	}

	int g = __gcd(ax, ay);

	return ax / (ax / g) - 1;
}

bool compar(Aresta a, Aresta b){
	if(a.w <= b.w)
		return true;

	return false;
}

int pai[N];

void init(int n){
	for(int i = 0 ; i < n ; i++){
		pai[i] = i;
	}
}

int query(int u){
	if(pai[u] == u){
		return u;
	}

	return pai[u] = query(pai[u]);
}

int join(int u, int v, int w){
	int pu = query(u);
	int pv = query(v);
	int s = 0;
	
	if(pu != pv){
		s = w;

		if(pu < pv){
			pai[pv] = pu;
		}else{
			pai[pu] = pv;
		}
	}

	return s;
}

pair<int,int>houses[N];
Aresta arestas[1000000];

int main (){
	int t;

	cin >> t;

	while(t--){
		int n;
		long long int k;

		cin >> n >> k;

		init(n);

		for(int i = 0 ; i < n ; i++){
			int a;
			int b;

			cin >> a >> b;

			houses[i].first = a;
			houses[i].second = b;
		}

		int pos = 0;

		for(int i = 0 ; i < n ; i++){
			for(int j = i + 1 ; j < n ; j++){
				arestas[pos].u = i;
				arestas[pos].v = j;
				arestas[pos].w = ((long long int)dist(houses[i], houses[j])) * k;
				
				pos++;
			}
		}

		sort(arestas, arestas + pos, compar);

		long long int sum = 0;

		for(int i = 0 ; i < pos ; i++){
			int u = arestas[i].u;
			int v = arestas[i].v;
			int w = arestas[i].w;
		//	cout << u << ' ' << v <<' ' << w << '\n';
			sum += (long long int)	join(u, v, w);
		}

		cout << sum << '\n';
	}
}
