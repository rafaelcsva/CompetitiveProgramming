#include <bits/stdc++.h>

using namespace std;

int main (){
	int n;
	
	cin>>n;
	
	for(int i = 0 ; i < n ; i++){
		int m;
		
		cin>>m;
		
		string s;
		
		map<string, double>fruit;
		
		for(int k = 0 ; k < m ; k++){
				cin>>s;
				double p;
				
				cin>>p;
				
				fruit[s] = p;
		}
		
		int p;
		
		cin>>p;
		
		double t = 0.0;
		int qtd;
		
		for(int k = 0 ; k < p ; k++){
			cin>>s>>qtd;
			
			t += fruit[s]*qtd;
		}
		
		cout<<"R$ "<<fixed<<setprecision(2)<<t<<endl;
	}
}
