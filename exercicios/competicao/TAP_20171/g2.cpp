#include <bits/stdc++.h>

#define MAXIMO	110

using namespace std;

typedef struct {
	string first;
	string last;
}Nome;

Nome nomes[MAXIMO];

bool compar(Nome a, Nome b){
	
	if(a.last > b.last){
		return false;
	}else if(a.last < b.last){
		return true;
	}else{
		if(a.first > b.first)
			return false;
			
		return true;
	}
}

int main (){
	int n;
	
	cin>>n;
	
	for(int i = 0 ; i < n ; i++){
		cin>>nomes[i].first>>nomes[i].last;
	}
	
	sort(nomes, nomes+n, compar);
	
	for(int i = 0 ; i < n ; i++)
		cout<<nomes[i].first<<" "<<nomes[i].last<<"\n";
		
	return 0;
}
