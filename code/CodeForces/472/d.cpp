#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 10;

int mark[N];
int n;
int a[N];
set<int>st;
int l = 0, u;

int main (){
	cin >> n;
	
	u = n;
	
	st.insert(u);
	
	for(int i = 1 ; i < n ; i++){
		int x;
		
		cin >> x;
	
		if(x == 0){
			tot += st.size();
			u++;
			st.insert(u);
		}
	}	
	return 0;
}
