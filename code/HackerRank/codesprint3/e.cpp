#include <bits/stdc++.h>

using namespace std;

const int V = 100010;

int c[V];

vector<int>graph[V];

int cor[V];

void solve(int v, int dp[][2], int dp1[][2]){
	cor[v] = 1;

	if(c[v] == 0){
		dp[v][1] = 1;
		dp1[v][1] = -1;
	}else{
		dp[v][1] = -1;
		dp1[v][1] = 1;
	}
	
	for(int i = 0; i < graph[v].size() ; i++){
		if(!cor[graph[v][i]]){
			solve(graph[v][i], dp, dp1);

			if(dp[v][1] < dp[v][1]+dp[graph[v][i]][1]){
				dp[v][1] = dp[v][1] + dp[graph[v][i]][1];
			}

			if(dp[v][0] < dp[graph[v][i]][0]){
				dp[v][0] = dp[graph[v][i]][0];
			}
	
			if(dp[v][0] < dp[graph[v][i]][1]){
				dp[v][0] = dp[graph[v][i]][1];
			}

			if(dp1[v][1] < dp1[v][1]+dp1[graph[v][i]][1]){
				dp1[v][1] = dp1[v][1] + dp1[graph[v][i]][1];
			}

			if(dp1[v][0] < dp1[graph[v][i]][0]){
				dp1[v][0] = dp1[graph[v][i]][0];
			}
	
			if(dp1[v][0] < dp1[graph[v][i]][1]){
				dp1[v][0] = dp1[graph[v][i]][1];
			}
		}	
	}
}

priority_queue<int>q;
int s;

void printtel(int v, int mod, int dp[][2], int t, int signal){
	if(mod){
		if(c[v] == t)
			s++;
		else
			s--;

		q.push(-v);

	}

//	cout<<s<<" -|- "<<dp[v][1]<<" -|- "<<v<<endl;
	cor[v] = 2;
	
	for(int i = 0 ; i < graph[v].size() ; i++){

		if(cor[graph[v][i]] != 2){
			if(mod && dp[graph[v][i]][1] > 0 && dp[graph[v][i]][1] <= s){
				printtel(graph[v][i], 1, dp, t, signal);
			}
			else if(!mod){
				if(dp[graph[v][i]][0] == s){
					printtel(graph[v][i], mod, dp, t, signal);
				}else if(dp[graph[v][i]][1] == s){
					printtel(graph[v][i], !mod, dp, t, signal);	
				}
			}
		}
	}
}

int dp[V][2];
int dp1[V][2];

int main (){
	int n;
	
	cin>>n;
	

	for(int i = 1 ; i <= n ; i++){
		cin>>c[i];
	}

	for(int i = 0 ; i < n-1 ; i++){
		int a, b;

		cin>>a>>b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	solve(1, dp, dp1);

	int a = max(abs(dp[1][0]), abs(dp[1][1]));
	int b = max(abs(dp1[1][0]), abs(dp1[1][1]));

	if(a < b || (a == b) && b == abs(dp1[1][1])){
		cout<<abs(b)<<endl;

		if(abs(dp1[1][0]) > abs(dp1[1][1])){
			s = abs(dp1[1][0]);

			printtel(1, 0, dp1, 0, -1);	
		}else{
			s = abs(dp1[1][1]);
			
			printtel(1, 1, dp1, 0, -1);
		}
	}else{
		cout<<a<<endl;

		if(abs(dp[1][1]) > abs(dp[1][0])){
			s = abs(dp[1][1]);
			printtel(1, 1, dp, 1, 1);
		}else{
			s = abs(dp[1][0]);
			
			printtel(1, 0, dp, 1,1);
		}
	}	

	cout<<q.size()<<'\n';

	while(!q.empty()){
		cout<<-q.top()<<" ";

		q.pop();
	}

	cout<<'\n';

	return 0;
}
