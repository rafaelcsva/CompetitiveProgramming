#include <bits/stdc++.h>

using namespace std;

int main (){
	int n;
	
	cin>>n;

	stack<char>pilha;
		
	string s;
	
	for(int i = 0 ; i < n ; i++){
		cin>>s;
		
		int r = 0;
		
		for(int k = 0 ; k < s.length() ; k++){
			if(s[k] == '<')
				pilha.push(s[k]);
			else if(s[k] == '>'){
				if(!pilha.empty()&&pilha.top() == '<'){
					pilha.pop();
					r++;
				}
			}
		}
		
		while(!pilha.empty()){
			pilha.pop();
		}
		
		cout<<r<<endl;
	}
}
