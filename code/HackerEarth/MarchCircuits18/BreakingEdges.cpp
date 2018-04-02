#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 1000;
typedef pair<int, int> pii;
vector<pii>edges;
vector<int>adj[N];
int p[N], ini[N], en[N], ft[N];
int mk = 1;

class MyNode{
	int v[30];
	public:
		MyNode(){
		
		}
		
		MyNode(int x){
			int i = 0;
			
			while(i < 30){
				v[i] = x % 2;
				x /= 2;
				i++;
			}
		}
	
	friend MyNode operator -(MyNode l, MyNode r){
		MyNode re;
		
		for(int i = 0 ; i < 30 ; i++){
			re.v[i] = l.v[i] - r.v[i];
		}
		
		return re;
	}
	
	friend MyNode operator +(MyNode l, MyNode r){
		MyNode re;
		
		for(int i = 0 ; i < 30 ; i++){
			re.v[i] = l.v[i] + r.v[i];
		}
		
		return re;
	}
	
	int getNumber(){
		int num = 0;
		int pot = 1;
		
		for(int i = 0 ; i < 30 ; i++){
			if(v[i]){
				num += pot;
			}
			
			pot *= 2;
		}
		
		return num;
	}
};

MyNode MyNodes[N];

void dfs(int x, int f){
	ft[x] = f;
	MyNodes[mk] = MyNode(p[x]);
	ini[x] = mk;
	
	for(int i = 0 ; i < adj[x].size() ; i++){
		int v = adj[x][i];
		
		if(v == f){
			continue;
		}
		
		mk++;
		
		dfs(v, x);
	}
	
	en[x] = mk;
}

int main (){
	int n;
	MyNodes[0] = MyNode(0);
	
	scanf("%d", &n);
	
	for(int i = 1 ; i <= n ; i++){
		scanf("%d", &p[i]);
	}
	
	for(int i = 0 ; i < n - 1 ; i++){
		int u, v;
		
		scanf("%d%d", &u, &v);
		
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.push_back(make_pair(u, v));
	}
	
	dfs(1, 1);
	
	for(int i = 2 ; i <= n ; i++){
		MyNodes[i] = MyNodes[i] + MyNodes[i - 1];
	}
	
	int ways = 0;
	
	for(int i = 0 ; i < edges.size() ; i++){
		int u = edges[i].first, v = edges[i].second;
		
		if(ft[v] == u){
			MyNode r = MyNodes[en[v]] - MyNodes[ini[v] - 1];
			
			if(r.getNumber() == (MyNodes[n] - r).getNumber()){
				ways++;
			}
		}else{
			MyNode r = MyNodes[en[u]] - MyNodes[ini[u] - 1];
			
			if(r.getNumber() == (MyNodes[n] - r).getNumber()){
				ways++;
			}
		}
	}

	printf("%d\n", ways);
		
	return 0;
}
