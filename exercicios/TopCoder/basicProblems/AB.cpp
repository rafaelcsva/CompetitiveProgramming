#include <bits/stdc++.h>
using namespace std;

class AB{
	public:
	string createString(int N, int K){

		string s(N, 'B');
	
		int cnt = 0;
		int i = 0;							
																																																																																																																														
		int t = 0;
		
		while(i < N-1 && K-t > 0){
			if(t+N-i-1-cnt <= K){
				t+=N-i-1-cnt;
				cnt++;
				s[i] = 'A';
			}
			i++;	

		}
	
		if(K-t!=0){
			return "";
		}

		return s;
	}

};																																																																																																						


