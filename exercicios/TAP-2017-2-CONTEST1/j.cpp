#include <bits/stdc++.h>

using namespace std;

int main (){
	int n;
	
	cin>>n;
	
	int valores[10] = {6,2, 5, 5, 4, 5, 6, 3, 7, 6};
	
	for(int i = 0; i < n ; i++){
		string st;
		
		cin>>st;
		
		int r = 0;

		for(int k = 0 ; k < st.length(); k++){
			r+=valores[st[k]-'0'];
		}
			
		cout<<r<<" leds"<<endl;
	}

	return 0;
	
}
