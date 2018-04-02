#include <bits/stdc++.h>

#define MAXIMO	10100
#define ll	long long

using namespace std;

struct Contestant{
	int s, a, b;

	friend bool operator<(Contestant a, Contestant b){
		return max(a.a, a.b) < max(b.a, b.b);
	}
};

Contestant co[MAXIMO];

int main (){
	int n, s;
	ll ans = 0, sum = 0, tot = 0;
	cin>>n>>s;

	priority_queue<Contestant>pq1;
	priority_queue<Contestant>pq2;


	for(int i = 0; i < n ; i++){
		cin>>co[i].s>>co[i].a>>co[i].b;

		tot += co[i].s;


		Contestant a = co[i];
		Contestant b = co[i];

		a.b = -a.b;
		b.a = -b.a;

		pq1.push(a);
		pq2.push(b);
	}

	int pizzas = tot/s + 1;
	
	int aux = s;

	while(aux != 0){
		Contestant t = pq1.top();
		pq1.pop();

		int m = min(aux, t.s);

		sum += t.a * m;

		aux -= m;
	}
	ans = sum;

	aux = s;

	sum = 0;

	while(aux != 0){
		Contestant t = pq2.top();
		pq2.pop();

		int m = min(aux, t.s);

		sum += t.b * m;

		aux -= m;
	}	

	ans = max(sum, ans);

	cout<<ans<<'\n';

	return 0;
}
