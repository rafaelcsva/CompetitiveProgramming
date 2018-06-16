//25, 05, 2018, 13:18:40 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = int(1e5 + 100);
int A, B, F, S, T;
map<string, int>mp;
string names[N];
set<string>groups[N];
set<string>best;
bool cat[N];

class Node{
    public:
        int pai;
        int f, s, t;
        int size;

        Node(int p, int fi, int se, int th, int sz){
            this->pai = p;
            this->f = fi;
            this->s = se;
            this->t = th;
            this->size = sz;
        }

        Node(){

        }
        
        bool canJoin(Node &other){
            return other.f + this->f <= F && other.s + this->s <= S && other.t + this->t <= T && this->size + other.size <= B;
        }

        Node operator +=(Node &other){
            this->f += other.f;
            this->s += other.s;
            this->t += other.t;
            this->size += other.size;
        }
};

Node nodes[N];

int find(int x){
    if(nodes[x].pai == x){
        return x;
    }

    return nodes[x].pai = find(nodes[x].pai);
}

void join(int i, int j){
    int x = find(i);
    int y = find(j);

    if(x != y && nodes[x].canJoin(nodes[y])){
        if(x < y){
            nodes[y].pai = x;
            nodes[x] += nodes[y];
        }else{
            nodes[x].pai = y;
            nodes[y] += nodes[x];
        }
    }
}

int main(){
    int n, m;

    cin >> n >> m >> A >> B >> F >> S >> T;

    for(int i = 1 ; i <= n ; i++){
        cin >> names[i];
        mp[names[i]] = i;

        int t;
        cin >> t;

        if(t == 1){
            nodes[i] = Node(i, 1, 0, 0, 1);
        }else if(t == 2){
            nodes[i] = Node(i, 0, 1, 0, 1);
        }else{
            nodes[i] = Node(i, 0, 0, 1, 1);
        }
    }

    for(int i = 0 ; i < m ; i++){
        string u, v;

        cin >> u >> v;

        join(mp[u], mp[v]);
    }

    int mx = -1;

    for(int i = 1 ; i <= n ; i++){
        Node r = nodes[find(i)];

        if(r.size >= A)
            mx = max(r.size, mx);

        groups[r.pai].insert(names[i]);
    }

    if(mx == -1){
        cout << "no groups" << endl;
        return 0;
    }
    
    for(int i = 1 ; i <= n ; i++){
        Node r = nodes[find(i)];

        if(r.size == mx && !cat[r.pai]){
            cat[r.pai] = true;
            
            for(set<string>::iterator it = groups[r.pai].begin() ; it != groups[r.pai].end() ; it++){
                best.insert(*it);
            }
        }
    }

    for(set<string>::iterator it = best.begin() ; it != best.end() ; it++){
        cout << *it << endl;
    }

    return 0;
}