#include <bits/stdc++.h>

using namespace std;

const int N = 30;
int fat[N];

int find(int x){
	if(fat[x] == x){
		return x;
	}
	
	return fat[x] = find(fat[x]);
}

int cost = 0;

vector<pair<char, char> >resp;

void fuse(int u, int v){
	int x = find(u);
	int y = find(v);
	
	if(x != y){
		cost++;
		
		resp.push_back(make_pair(char(u + 'a'), char(v + 'a')));
		
		if(x < y){
			fat[y] = x;
		}else{
			fat[x] = y;
		}
	}
}


int main (){
	int n;
	
	cin >> n;
	
	string a, b;
	
	for(int i = 0 ; i < N ; i++){
		fat[i] = i;
	}
	
	cin >> a;
	cin >> b;
	
	for(int i = 0 ; i < n; i++){
		fuse(a[i] - 'a', b[i] - 'a');
	}
	
	printf("%d\n", cost);
	
	for(int i = 0 ; i < cost ; i++){
		printf("%c %c\n", resp[i].first, resp[i].second);
	}
	return 0;
}
