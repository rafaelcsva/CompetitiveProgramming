//06, 11, 2018, 19:15:24 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e6), D = 7;
pii adj[D][N][2];
int root[D], cur[D];
string s[N];
int block;
int resp[N];
int pw[D];
deque< int > nodes[D][N];

struct Query{
    int L, R, idx;
    string p;

    bool operator <(Query &other){
        if((this->L) / block != other.L / block){
            return (this->L) / block < other.L / block;
        }

        return this->R < other.R;
    }
};

void update(int trie_num, string &p, int val){
    int u = root[trie_num];
    int cd = pw[trie_num] - 1;
    int i = int(p.length()) - 1;

    while(cd >= 0){
        if(cd > i){
            if(adj[trie_num][u][0].first == -1){
                adj[trie_num][u][0].second = 0;
                cur[trie_num]++;
                adj[trie_num][u][0].first = cur[trie_num];
            }

            adj[trie_num][u][0] += val;
            u = adj[trie_num][u][0].first;
        }else{
            if(p[i] == '0'){
                if(adj[trie_num][u][0].first == -1){
                    adj[trie_num][u][0].second = 0;
                    cur[trie_num]++;
                    adj[trie_num][u][0].first = cur[trie_num];
                }

                adj[trie_num][u][0] += val;
                u = adj[trie_num][u][0].first;
                i--;
            }else{
                if(adj[trie_num][u][1].first == -1){
                    adj[trie_num][u][1].second = 0;
                    cur[trie_num]++;
                    adj[trie_num][u][1].first = cur[trie_num];
                }

                adj[trie_num][u][1] += val;
                u = adj[trie_num][u][1].first;
                i--;
            }
        }

        cd--;
    }
}

string search(int trie_num, string &p){
    int u = root[trie_num];
    int cd = pw[trie_num] - 1;
    int i = int(p.length()) - 1;

    while(cd >= 0){

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int pot = 1;

    for(int i = 0 ; i < T ; i++){
        pw[i] = pot;
        pot *= 10;
    }

    int n, q;

    cin >> n >> q;

    block = sqrt(n);

    for(int i = 1 ; i <= n ; i++){
        cin >> s[i];
    }

    for(int i = 1 ; i <= q ; i++){
        cin >> qu[i].L >> qu[i].R >> qu[i].p;
        qu[i].idx = i;
    }

    return 0;
}