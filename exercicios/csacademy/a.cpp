#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
vector<int>graph[N];
int cor[N], t, h;
int mer[N];
int flag = 0;

bool dfs(int x, int v){
    cor[x] = t;
    bool ver = false;
    
    for(int i = 0 ; i < graph[x].size() ; i++){
        if(cor[graph[x][i]] != t){
            if(graph[x][i] == v){
                ver = true;
		cor[graph[x][i]] = t;
		mer[x] = h;
            }else{
                if(dfs(graph[x][i], v)){
			mer[graph[x][i]] = h;
		}
            }
        }else{
            if(graph[x][i] == v || mer[graph[x][i]] == h){
                flag = 1;
            }
        }
    }
    
    return ver;
}

int main() {
    int n, m;
    
    scanf("%d%d", &n, &m);
    
    for(int i = 0 ; i < m ; i++){
        int a, b;
        
	scanf("%d%d", &a, &b);
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(t = 1, h = 2; t <= m ; t++, h++){
        int a, b;
        
        scanf("%d%d", &a, &b);
        
        flag = 0;
        
	printf("%d\n", dfs(a, b));
    }
    return 0;
}
