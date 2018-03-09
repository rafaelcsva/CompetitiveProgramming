#include <bits/stdc++.h>

using namespace std;

const int N = 210;
map<char*, int>mp;
char *s[N];
int n;
vector<int>graph[N];

int difference(char u[], char v[]){
	int diff = abs(int(strlen(u)) - int(strlen(v)));
	
	for(int i = 0 ; i < min(strlen(u), strlen(v)) ; i++){
		if(u[i] != v[i]){
			diff++;
		}
	}
	
	return diff;
}

void makeAdj(){
	for(int i = 0 ; i < n ; i++){
		for(int j = i + 1 ; j < n ; j++){
			int diff = difference(s[i], s[j]);
//printf("the diference between %s ans %s is %d\n", s[i], s[j], diff); 
			if(diff <= 1){
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}	
}

int bfs(int u, int v){
	int dis[N];
	
	memset(dis, -1, sizeof dis);
	queue<int>q;
	
	q.push(u);
	
	//printf("pushed %s %d\n", s[u], u);
	dis[u] = 0;
	
	while(!q.empty()){
		int a = q.front();
		q.pop();
		
		for(int i = 0 ; i < graph[a].size() ; i++){
			int b = graph[a][i];
//printf("pushed %s %d\n", s[b], b);
			if(dis[b] == -1){
				dis[b] = dis[a] + 1;
				
				q.push(b);
			}
		}
	}
	
	return dis[v];
}

int pos(char u[]){
	for(int i = 0 ; i < n ; i++){
		if(strcmp(u, s[i]) == 0){
			return i;
		}
	}
}

int main(){
	int t;
	char c;
	bool ver = true;
	
	for(int i = 0 ; i < N ; i++){
		s[i] = (char *) malloc(sizeof(char) * N);
	}
	scanf("%d", &t);
	
	while(t--){
		if(ver)
			scanf("%c", &c);
		
		if(!ver)
			printf("\n");
				
		ver = false;
		
		n = 0;
				
		while(true){
			scanf("%s", s[n++]);
			
			if(s[n - 1][0] == '*'){
				break;
			}
		}
		
		makeAdj();
		
		char u[N], v[N];
		string tmp;

		cin.ignore();
				
		while(getline(cin, tmp)){
			
			if(tmp.empty()){
				break;
				
			}
			
			int i;
			int t1 = 0, t2 = 0;
			
			for(i = 0 ; i < tmp.length() ; i++){
				if(tmp[i] != ' '){
					u[t1++] = tmp[i];
				}else{
					break;
				}
			}
			
			u[t1] = '\0';
			
			for(i = i + 1 ; i < tmp.length() ; i++){
				v[t2++] = tmp[i];
			}
			
			v[t2] = '\0';
			
			printf("%s %s %d\n", u, v, bfs(pos(u), pos(v)));
		}
		for(int i = 0 ; i < n ; i++){
			graph[i].clear();
		}
	}
	
	return 0;
}
