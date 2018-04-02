#include <bits/stdc++.h>

using namespace std;

const int N = 5000;

int main (){
	string s;
	int prefa[N];
	int prefb[N];
	
	cin >> s;
	
	if(s[0] == 'a'){
		prefa[0] = 1;
		prefb[0] = 0;
	}else{
		prefa[0] = 0;	
		prefb[0] = 1;
	}
	
	int n = s.length();

	for(int i = 1 ; i < n ; i++){
		prefa[i] = prefa[i-1];
		prefb[i] = prefb[i-1];

		if(s[i] == 'a')
			prefa[i]++;
		else
			prefb[i]++;
	}

	int l = 0;

	for(int i = 0 ; i < n ; i++){
		for(int j = i ; j < n ; j++){
			l = max(l, prefa[n - 1] - prefa[j] + prefb[j] - prefb[i] + prefa[i]);	
			
			l = max(l, prefa[n - 1] - prefa[j] + prefb[j]);
			
			if(i > 0){
				l = max(l, prefa[n - 1] - prefa[j] + prefb[j] - prefb[i-1] + prefa[i-1]);
			}
		}
	}

	cout << l << endl;

	return 0;
}
