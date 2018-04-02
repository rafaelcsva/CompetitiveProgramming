#include <bits/stdc++.h>

using namespace std;
const int N = 230;
int adj[N][N], pre[N][N], stam[N];
typedef pair<int, int>  pii;
pii pt[N];
const int INF = (int) 1e9;
int size = 0, p[N], dis[N], source = 0;

void regenerate(int n){
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= n ; j++){
            adj[i][j] = pre[i][j];
        }
    }
}

void addEdge(int i, int j, int w, bool isSource = false){
    i *= 2;
    
    if(isSource){
        pre[source][i] = w;
    }else{
        j *= 2;
        pre[i + 1][j] = INF;
        pre[j + 1][i] = INF;
    }

}

double dist(int i, int j){
    int dx = pt[i].first - pt[j].first, dy = pt[i].second - pt[j].second;

    return sqrt(dx * dx + dy * dy);
}

bool bfs(int sink){
    queue<int>q;
    memset(dis, -1, sizeof dis);

    q.push(source);
    dis[source] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();
       // cout << u / 2;

        if(u % 2){
        //    cout << "'";
        }
        //cout << ' ';

        for(int i = 0 ; i <= size ; i++){
            if(adj[u][i] && dis[i] == -1){
                dis[i] = 1;
                p[i] = u;
                q.push(i);
            }
        }
    }
    //cout << " ended candidate\n";

    return dis[sink] != -1;
}

int augment(int sink){
    int r = (int) 1e9;
    int ac = sink;

    while(ac != source){
      //  cout << ac / 2;
        if(ac % 2){
        //    cout << "'";
        }
    //    cout << ' ';
        r = min(r, adj[p[ac]][ac]);
        ac = p[ac];
    }
 //   cout << ac << " ended \n";

    ac = sink;

    while(ac != source){
        adj[p[ac]][ac] -= r;
        adj[ac][p[ac]] += r;

        ac = p[ac];
    }

    return r;
}

bool edmonds_karp(int sink, int tot){
    int max_flow = 0;

    while(bfs(sink)){
        max_flow += augment(sink);
    }

   // cout << max_flow << '\n';

    return max_flow >= tot;
}

int main (){
    int t;
    int tot = 0;
    
    ios::sync_with_stdio(false);

    cin >> t;

    while(t--){
        int n;
        double d;
        memset(pre, 0, sizeof pre);
        memset(adj, 0, sizeof adj);

        cin >> n >> d;

        size = 2 * n + 1;

        for(int i = 1 ; i <= n ; i++){
            int x, y, n, m;

            cin >> x >> y >> n >> stam[i];
            
            int u = 2 * i;

            pre[u][u + 1] = stam[i];
            addEdge(i, 0, n, true);

            tot += n;

            pt[i] = {x, y};

            for(int j = 1 ; j < i ; j++){
                if(dist(i, j) <= d){
                //    cout << "builded edge (" << i << "," << j << ")\n"; 
                    addEdge(i, j, m);
                }
            }
        }

        bool find = false;

        for(int i = 1 ; i <= n ; i++){
            int u = 2 * i;

            regenerate(size);
            //cout << i << " running\n";
            if(edmonds_karp(u, tot)){
                if(find){
                    cout << ' ';
                }

                cout << i - 1 ;

                find = true;
            }
           
        }

        if(!find){
            cout << "-1";
        }
        cout << '\n';

        tot = 0;
    }

    return 0;
}