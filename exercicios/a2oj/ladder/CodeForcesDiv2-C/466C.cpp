#include <bits/stdc++.h>

#define	MAXIMO	800010
#define	ll	long long
using namespace std;

int main (){
	int n;
	ll a[MAXIMO];
	ll s = 0;
	cin>>n;

	for(int i = 0 ; i < n ; i++){
		cin>>a[i];

		s+=a[i];
	}

	int k = 0;
	ll m = 0;

	if(s%3 == 0){
		
		do{
			m+=a[k];
			k++;
		}while(k < n-1 && m != s/3);


		if(m == s/3){
			int n1 = 1;
		
			while(a[k] == 0&&k < n){
				n1++;
				k++;
			}
		
			m = 0;

			do{
				m+=a[k];
				k++;
			}while(k < n-1 && m != s/3);

			if(m == s/3){
				int n2 = 1;
		
				
				while(a[k] == 0 && k < n-1){
					n2++;
					k++;
				}

				cout<<n1*n2<<'\n';
			}else{
				cout<<"0\n";
			}
		}
		else{
			cout<<"0\n";
		}
			
	}else{
		cout<<"0\n";
	}
	
	return 0;
}
