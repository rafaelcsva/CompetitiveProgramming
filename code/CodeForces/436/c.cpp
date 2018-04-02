#include <bits/stdc++.h>

#define	ll	long long

using namespace std;

int main (){
	ll cnt = 0;

	ll a, b, f, k;

	cin>>a>>b>>f>>k;

	if(b/a >= k){
		cout<<"0\n";
	}else if(b < f || b < (a-f) ||(k > 1 && (b < (a-f)+(a-f) || b < 2*f))){
		cout<<"-1\n";
	}else{
		ll pos = 0;
		int gas = b;
		
		while(k != 0){
			if(pos%4 == 0){
				gas -= f;
				pos++;
			}else if(pos%4 == 1){
				if(k > 1 && gas < 2*(a-f)|| k == 1 && gas < (a-f)){
					gas = b;
					cnt++;
				}
				
				gas -= (a-f);
				pos++;
				k--;
			}else if(pos%4 == 2){
				gas -= (a-f);
				
				pos++;
			}else if(pos%4 == 3){
				if(k > 1 && gas < 2*f || k == 1 && gas < f){
					gas = b;

					cnt++;
				}

				gas -= f;
				pos++;
				k--;
			}
		}
		cout<<cnt<<'\n';
	}

	return 0;
}