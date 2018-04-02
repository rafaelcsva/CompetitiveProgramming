#include <bits/stdc++.h>

using namespace std;

int main (){
	int n;
	int n1 = -1, n2 = -1, cnt1 = 0, cnt2 = 0;
	bool np = false, ns = false;

	cin>>n;

	bool flag = true;

	for(int i = 0 ; i < n ; i++){
		int a;

		cin>>a;

		if(!np && !(ns && n2 == a)){
			np = true;
			n1 = a;
			cnt1++;
		}else if(!ns && !(np && n1 == a)){
			ns = true;
			n2 = a;
			cnt2++;
		}
		else if(n1 == a){
			cnt1++;
		}else if(n2 == a){
			cnt2++;
		}else{
			flag = false;
		}		
	}

	if(!flag){
		cout<<"NO\n";
	}else{
		if(cnt1 == cnt2){
			cout<<"YES\n"<<n1<<" "<<n2<<"\n";
		}else{
			cout<<"NO\n";
		}
	}

	return 0;
	
}