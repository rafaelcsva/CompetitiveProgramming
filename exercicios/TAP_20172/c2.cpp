#include <bits/stdc++.h>

using namespace std;

int main (){
	int n, k;
	
	int MinB, MaxS = 1;
	
	cin>>n>>k;

	MinB = k;

	for(int i = 0 ; i < n ; i++){
		string s;
		int f;

		cin>>f;
		cin>>s;
		
		if(s == "SAFE"){
			if(f > MaxS)
				MaxS = f;
		}else{
			if(f < MinB)
				MinB = f;
		}
	}

	cout<<MaxS+1<<" "<<MinB-1<<endl;

	return 0;
}
