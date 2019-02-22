#include <bits/stdc++.h>
using namespace std;

typedef pair< int, int >    pii;

set< int > st;

class Monkey{
    public:
    int v, a, b;
};

const int N = 300;
int sink, source;
const int M = N + 3;
Monkey monkeys[N];
int adj[M][M];
int sz;
pii intervals[M];
vector< pii > bel_intervals[N];
int cap[M];
int pnt[M];
int father[M], vis[M];
const int inf = int(1e9);
queue< int > q;

bool bfs(int n){
    memset(vis, 0, sizeof vis);
    memset(father, -1, sizeof father);
    
    q.push(source);
    vis[source] = 1;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for(int i = 0 ; i < n ; i++){
            if(adj[u][i] && !vis[i]){
                father[i] = u;
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    
    return vis[sink];
}

int edmonds_karp(int n){
    int flow = 0;
    
    while(bfs(n)){
        int mn_edge = inf;
        int cur = sink;
        
        while(cur != source){
            mn_edge = min(mn_edge, adj[father[cur]][cur]);
            cur = father[cur];
        }
        
        cur = sink;
        // printf("adding %d, the path is printed bellow:\n", mn_edge);

        while(cur != source){
            // printf("%d ", cur);
            adj[father[cur]][cur] -= mn_edge;
            adj[cur][father[cur]] += mn_edge;
            cur = father[cur];
        }
        // printf("\n");
        
        flow += mn_edge;
    }
    
    return flow;
}

int main() {
    int n, m;
    int test = 1;

    while(scanf("%d", &n), n){
        scanf("%d", &m);
        
        int sum = 0;
        
        for(int i = 0 ; i < n ; i++){
            scanf("%d %d %d", &monkeys[i].v, &monkeys[i].a, &monkeys[i].b);
        
            st.insert(monkeys[i].a);
            st.insert(monkeys[i].b);
        
            sum += monkeys[i].v;
        }
        
        int f = 0;
        
        int sz = st.size() - 1;
        source = n + sz;
        sink = source + 1;
        
        for(auto it = st.begin(), nxt = next(it) ; nxt != st.end() ; it++, nxt++){
            intervals[f].first = *it;
            intervals[f].second = *nxt;
            cap[f] = *nxt - *it;
            pnt[f] = *it;
            adj[f + n][sink] = cap[f] * m;
            
            f++;
        }
        st.clear();
        
        for(int i = 0 ; i < n ; i++){
            adj[source][i] = monkeys[i].v;
            
            for(int j = 0 ; j < sz ; j++){
                int a = max(monkeys[i].a, intervals[j].first);
                int b = min(monkeys[i].b, intervals[j].second);
                
                if(a < b){
                    adj[i][j + n] = b - a;
                }else{
                    adj[i][j + n] = 0;
                }
            }
        }
        
        int val = edmonds_karp(sink + 1);
        
        if(val == sum){
            printf("Case %d: Yes\n", test++);
            
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < sz ; j++){
                    int a = max(monkeys[i].a, intervals[j].first);
                    int b = min(monkeys[i].b, intervals[j].second);
                    
                    if(a < b){
                        if(adj[i][j + n] != b - a){
                            int ret = (b - a) - adj[i][j + n];
                            // printf("%d wants %d from (%d, %d)\n", i, ret, a, b);

                            int bb = pnt[j] + ret;
                            
                            if(bb > b){
                                bel_intervals[i].push_back({pnt[j], b});
                                bel_intervals[i].push_back({a, a + ret - (b - pnt[j])});
                                pnt[j] = a + ret - (b - pnt[j]);
                            }else{
                                bel_intervals[i].push_back({pnt[j], bb});
                                pnt[j] = bb;
                            }
                            
                            if(pnt[j] == b){
                                pnt[j] = a;
                            }
                        }
                    }
                }
                
                sort(bel_intervals[i].begin(), bel_intervals[i].end());
            }
            
            int l = -1, r = -1;
            
            for(int i = 0 ; i < n ; i++){
                vector< pii > tmp;
                l = bel_intervals[i][0].first;
                r = bel_intervals[i][0].second;
                
                for(int j = 1 ; j < bel_intervals[i].size() ; j++){
                    if(bel_intervals[i][j].first == r){
                        r = bel_intervals[i][j].second;
                    }else{
                        tmp.push_back({l, r});
                        l = bel_intervals[i][j].first;
                        r = bel_intervals[i][j].second;
                    }
                }
                
                tmp.push_back({l, r});
                
                bel_intervals[i] = tmp;
            }
            
            for(int i = 0 ; i < n ; i++){
                printf("%lu", bel_intervals[i].size());
                
                for(int j = 0 ; j < bel_intervals[i].size() ; j++){
                    printf(" (%d,%d)", bel_intervals[i][j].first, bel_intervals[i][j].second);
                }
                printf("\n");
                bel_intervals[i].clear();
            }
        }else{
            printf("Case %d: No\n", test++);
        }
        
        memset(adj, 0, sizeof adj);
    }
    
	return 0;
}
