#include <bits/stdc++.h>

#define MAXIMO	109999
#define ll	long long

using namespace std;

ll a[MAXIMO];
ll maior = -99999999999;
ll menor = 99999999999;

int main (){
	int n, k;
	
	cin>>n>>k;

	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	
		menor = min(a[i], menor);
		maior = max(a[i], maior);
	}

	if(k > 2){
		cout<<maior<<endl;
	}else if(k == 2){
		cout<<max(a[0], a[n-1])<<endl;
	}else{
		cout<<menor<<endl;
	}

	return 0;
}
