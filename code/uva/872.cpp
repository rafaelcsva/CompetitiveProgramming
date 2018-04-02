#include <bits/stdc++.h>

using namespace std;

const int N = 30;
char s[1000], dp[1000];
vector<char>vt, graph[N];
map<char, int>mp;
int n;
bool printed = false;

bool canPut(char c, int mask){
	int k = mp[c];
	int u = 1 << k;
	
	if(mask & u){
		//cout << "1\n";
		return false;
	}
	
	for(int i = 0 ; i < graph[k].size() ; i++){
		int v = 1 << mp[graph[k][i]];
		
		if(mask & v){
		//	cout << "2\n";
			return false;
		}
	}
	
	return true;
}

void back(int mask, string a){
	if(mask == (1 << n) - 1){
		cout << a << '\n';
		printed = true;
	}else{
		if(mask != 0){
			a += " ";
		}
		
		for(int i = 0 ; i < n ; i++){
			int u = 1 << mp[vt[i]];
			
			if(canPut(vt[i], mask)){
				back(mask | u << mp[i], a + vt[i]);
			}else{
			//	cout << "can't append " << vt[i] << " in " << a << '\n';
			}	
		}
	}
}

int main (){
	int t;
	bool f = false;
	
	scanf("%d", &t);
	
	while(t--){
		
		if(f){
			printf("\n");
		}
		
		f = true;
		
		scanf("\n%[^\n]s", s);
		scanf("\n%[^\n]s", dp);
		
		int m = 0;
		
		for(int i = 0 ; i < strlen(s) ; i += 2){
			vt.push_back(s[i]);
			mp[s[i]] = m++;
		}	
		
		for(int i = 0 ; i < strlen(dp) ; i += 4){
			graph[mp[dp[i]]].push_back(dp[i + 2]);
		}
		
		printed = false;
		n = vt.size();
		back(0, "");
		
		if(!printed){
			printf("NO\n");
		}
		
		for(int i = 0 ; i < n ; i++){
			graph[mp[vt[i]]].clear();
		}
		
		mp.clear();
		vt.clear();
	}

	return 0;
}
