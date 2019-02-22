//26, 10, 2018, 09:53:34 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 10;
int n;
int a[N];
map< string, int > dis1, dis2;
queue< string > q;

int bfs(string &init, map< string, int > &dis1, map< string, int > &dis2, int mdepth){
    q.push(init);
    dis1[init] = 0;
    int r = 10;

    while(!q.empty()){
        string u = q.front();
        // cout << u << endl;
        q.pop();

        if(dis2.count(u) != 0){
            r = min(dis1[u] + dis2[u], r);
        }

        if(dis1[u] >= mdepth){
            continue;
        }

        for(int i = 0 ; i < n ; i++){
            string v = "";

            for(int j = i ; j < n ; j++){
                v.push_back(u[j]);
                string ot = "";
                string lef = "";
                // cout << i << ", " << j << endl;

                for(int k = 0 ; k < n ; k++){
                    if(!(i <= k && k <= j)){
                        ot.push_back(u[k]);
                    }
                }
                // cout << ot << endl;
                
                int lim = n - (j - i);

                for(int k = 0 ; k < lim ; k++){
                    string t = lef + v + ot;

                    if(dis1.count(t) == 0){
                        dis1[t] = dis1[u] + 1;
                        q.push(t);
                    }

                    if(ot.length() > 0){
                        lef.push_back(ot[0]);
                        ot = ot.substr(1);
                    }
                }
            }
        }
    }

    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test = 1;

    while(true){
        scanf("%d", &n);

        if(n == 0)
            break;
            
        string initial = "";
        string end = "";

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);

            initial.push_back(char(a[i] + '0'));
            end.push_back(char(i + '0' + 1));
        }

        bfs(initial, dis1, dis2, 2);

        printf("Case %d: %d\n", test++, bfs(end, dis2, dis1, 3));
        dis1.clear();
        dis2.clear();
    }

    return 0;
}