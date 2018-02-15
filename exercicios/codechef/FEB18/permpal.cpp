#include <bits/stdc++.h>
     
using namespace std;

const int M = 30, N = 26;
vector<int>p[M];
int n, t, cnt[M], pt[M];
char aux[101000];

string makePalindromic(){
	int ini = 0, end = n - 1;
	string s;
	
	for(int i = 0 ; i < N ; i++){
		while(cnt[i] >= 2){
			cnt[i] -= 2;
			
			aux[ini] = aux[end] = char(i + 'a');
			ini++, end--;
		}
		
		if(cnt[i]){
			cnt[i]--;
			aux[n / 2] = char(i + 'a');
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		s += aux[i];
	}
	
	return s;
}

int main (){
	ios::sync_with_stdio(false);
	cin >> t;

	while(t--){
		string s;
		cin >> s;
	
		n = s.length();
			
		
		
		for(int i = 0 ; i < n ; i++){
			int u = s[i] - 'a';
			
			cnt[u]++;
			p[u].push_back(i);
		}
	
		int cntodd = 0;
	
		for(int i = 0 ; i < N ; i++){
			if(cnt[i] % 2 != 0){
				cntodd++;
			}
		}
		
		if(cntodd != n % 2){
			cout << "-1\n";
		}else{
			s = makePalindromic();
			
			for(int i = 0 ; i < n ;i++){
				char c = i == n - 1 ? '\n' : ' ';
				int u = s[i] - 'a';
				
				cout << p[u][pt[u]++] + 1 << c;
			}
		}
		
		for(int i = 0 ; i < N ; i++){
			p[i].clear();
			cnt[i] = pt[i] = 0;
		}
	}

	return 0;
} 
