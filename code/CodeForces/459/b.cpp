#include <bits/stdc++.h>

using namespace std;

map<string, string>mp;

int main (){
	int n, m;
	
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	
	while(n--){
		string name, ip;
		
		cin >> name >> ip;
		
		mp[ip] = name;
	}
	
	while(m--){
		string comand, ip;
		
		cin >> comand >> ip;
		
		ip = ip.substr(0, ip.length() - 1);
		
		cout << comand << ' ' << ip << "; #" << mp[ip] << '\n';
	}
	
	return 0;
}
