#include <bits/stdc++.h>

using namespace std;

bool contains(string s, string p){
	for(int i = 0 ; i < s.length() ; i++){
		for(int j = 0 ; j < p.length() ; j++){
			if(p[j] == s[i])
				return true;
		}
	}
	
	return false;
}

bool lower(string s){
	for(int i = 0 ; i < s.length() ; i++){
		if(s[i] >= 'a' && s[i] <= 'z')
			return true;
	}
	
	return false;
}


bool upper(string s){
	for(int i = 0 ; i < s.length() ; i++){
		if(s[i] >= 'A' && s[i] <= 'Z')
			return true;
	}
	
	return false;
}

int main (){
	int n;
	string s;
	string special = "!@#$%^&*()-+";
	string digit = "1234567890";
	
	int resp = 0;
	
	cin >> n >> s;
	
	if(! contains(s, special)){
		resp++;
	}
	
	if(! contains(s, digit)){
		resp++;
	}
	
	if(! lower(s)){
		resp++;
	}
	
	if(! upper(s)){
		resp++;
	}
	
	cout << max(6 - n, resp) << endl;
	
	return 0;
	
}
