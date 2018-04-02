#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
typedef pair<int, int>	pii;
pii packages[N], containers[N];

int main (){
	int n, m;
	
	scanf("%d%d", &n, &m);
	
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &packages[i].first);
	}
	
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &packages[i].second);
	}
	
	for(int i = 0 ; i < m ; i++){
		scanf("%d", &containers[i].first);
	}
	
	for(int i = 0 ; i < m ; i++){
		scanf("%d", &containers[i].second);
	}

	sort(packages, packages + n);
	sort(containers, containers + m);
	
	int cat = 0;
	int j = 0;
	int i = 0;
	
	while(i < n){
		int qtd = packages[i].second;
		
		while(j < m && 2 * packages[i].first * packages[i].first >= 4 * containers[j].first * containers[j].first){
			j++;
		}
		
		if(j >= m){
			break;
		}
		
		int cap = containers[j].second;
		int mn = min(qtd, cap);
		
		cat += mn;
		
		packages[i].second -= mn;
		containers[j].second -= mn;
		
		if(containers[j].second == 0){
			j++;
		}
		
		if(packages[i].second == 0){
			i++;
		}
	}
	
	printf("%d\n", cat);
	
	return 0;
}
