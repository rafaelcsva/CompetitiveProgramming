#include <bits/stdc++.h>

using namespace std;

int main (){
	string st;
	
	
	while(cin>>st){
		if(st[0] == '*')
			break;
			
		int r = 0;
		double valores[10000];
		valores['W'] = 64;
		valores['H'] = 32;
		valores['Q'] = 16;
		valores['E'] = 8;
		valores['S'] = 4;
		valores['T'] = 2;
		valores['X'] = 1;
		
		int s = 0;
	
		for(int i = 1 ; i < st.length() ; i++){
		//	printf("%c\n", st[i]);
			if(st[i] == '/'){
				if(s == 64)
					r++;
				s = 0;
			}else{
				s+=valores[st[i]];
			}
		} 
		
		printf("%d\n", r);
	}
	
	return 0;
	
}
