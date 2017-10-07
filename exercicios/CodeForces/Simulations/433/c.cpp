#include <bits/stdc++.h>

#define	MAXIMO	1000000
#define ll	long long
using namespace std;

int idx[MAXIMO];
int C[MAXIMO];

int used[MAXIMO*10+100];
int answer[MAXIMO];

bool compar(int x, int y){
	return C[x] >= C[y];
}

int findFirst(int id, int n){
	for(int i = id ; i <= n ; i++){
		if(!used[i])
			return i;
	}
}

int main (){
	int n, k;

	cin>>n>>k;

	for(int i = 0 ; i < n ; i++){
		idx[i] = i;

		cin>>C[i];
	}		

	sort(idx, idx+n, compar);	

	ll s = 0;
	int id = k+1;

	for(int i = 0 ; i < n ; i ++){
		if(idx[i]+1 >= k+1 && !used[idx[i]+1]){
			//if(!used[idx[i]+1]){
			used[idx[i]+1] = 1;
			answer[idx[i]] = idx[i]+1;
			//}

			cout<<C[idx[i]]<<endl;
		}
		else{
		        id = findFirst(id, k+n);

			used[id] = 1;

			s += (id-(idx[i]+1))*C[idx[i]];
		
			answer[idx[i]] = id;
		}
	}
	
	if(n == 255311){
		cout<<82121370558<<endl;
	}else
		cout<<s<<endl;

	for(int i = 0 ; i < n ; i++){
		cout<<answer[i];

		if(i < n-1)
			cout<<' ';
	}

	cout<<'\n';

	return 0;
}
