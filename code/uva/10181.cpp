//12, 10, 2018, 08:46:06 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int mx = 50;
map< char, pii > walks;
const int MOVES = 4;
const int TAB = 4;
const char moves[MOVES] = {'R', 'L', 'U', 'D'};
map< string, bool > ver;
const int inf = 1e9;

struct State{
    int steps;
    string comm;
    int tab[TAB][TAB];

    bool operator <(const State &other) const{
        return this->steps < other.steps;
    }

    bool operator =(const State &other){
        this->steps = other.steps;
        this->comm = other.comm;

        for(int i = 0 ; i < TAB ; i++){
            for(int j = 0 ; j < TAB ;j++){
                this->tab[i][j] = other.tab[i][j];
            }
        }
    }
};

priority_queue< State > pq;
int max_op = 1e3;

bool is_target_state(State &u){
    int cur = 1;

    for(int i = 0 ; i < TAB ; i++){
        for(int j = 0 ; j < TAB ; j++){
            if(i == TAB - 1 && j == TAB - 1){
                break;
            }

            if(u.tab[i][j] != cur){
                return false;
            }

            cur++;
        }
    }

    return true;
}

pii get_pos_zero(State &u){
    for(int i = 0 ; i < TAB ; i++){
        for(int j = 0 ; j < TAB ; j++){
            if(u.tab[i][j] == 0){
                return {i, j};
            }
        }
    }
}

int heuristica(int tab[][TAB]){
    int tot = 0;

    for(int i = 0 ; i < TAB ; i++){
        for(int j = 0 ; j < TAB ; j++){
            // int pos = i * TAB + j + 1;

            // if(tab[i][j] == 0){
            //     tot += 16 - pos;
            // }else{
            //     tot += abs(pos - tab[i][j]);
            // }

            if(tab[i][j] == 0){
                tot += (TAB - 1) - i + (TAB - 1) - j;
            }else{
                int x = tab[i][j] - 1;
                int li = x / TAB, ci = x % TAB;

                tot += abs(li - i) + abs(ci - j);
            }
        }
    }
    // cout << tot << " is the value " << endl;

    return tot;
}

bool ok(int l, int c){
    return l >= 0 && l < TAB && c >= 0 && c < TAB;
}

State dijkstra(int tab[][TAB]){
    while(!pq.empty()){
        pq.pop();
    }

    ver.clear();

    State initial;

    for(int i = 0 ; i < TAB ; i++){
        for(int j = 0 ; j < TAB ; j++){
            initial.tab[i][j] = tab[i][j];
        }
    }
    
    initial.comm = "";
    // cout << "estou aqui jovem!" << endl;
    initial.steps = -heuristica(tab);
    pq.push(initial);
    // cout << heuristica(tab) << " aqui" << endl;

    int it = 0;

    while(!pq.empty()){
        State u = pq.top();
        pq.pop();

        it++;
        // cout << it << endl;
        if(it >= max_op)    
            break;

        if(ver[u.comm]){
            // cout << "continuei!" << endl;
            continue;
        }

        ver[u.comm] = true;
        if(is_target_state(u)){
            return u;
        }

        if(u.steps * -1 >= mx){
            continue;
        }

        pii pos = get_pos_zero(u);

        for(int i = 0 ; i < MOVES ; i++){
            int l = pos.first + walks[moves[i]].first, c = pos.second + walks[moves[i]].second;

            if(ok(l, c)){
                State v = u;
                // printf("%d %d\n", l, c);

                swap(v.tab[pos.first][pos.second], v.tab[l][c]);
                
                // if(ver[v.tab]){
                //     continue;
                // }

                v.comm.push_back(moves[i]);
                v.steps = v.comm.length() + heuristica(v.tab);
                v.steps *= -1;

                if(ver[v.comm])
                    continue;

                pq.push(v);
            }
        }
    }

    State err;
    err.steps = inf;

    return err;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    walks['R'] = {0, 1};
    walks['L'] = {0, -1};
    walks['U'] = {-1, 0};
    walks['D'] = {1, 0};

    int tab[TAB][TAB];
    int t;

    cin >> t;

    while(t--){
        for(int i = 0 ; i < TAB ; i++){
            for(int j = 0 ; j < TAB; j++){
                int x;

                cin >> tab[i][j];
                // printf("%d ", x);
            }
            // printf("\n");
        }

        // printf("%lu !\n", tab[0].size());

        State r = dijkstra(tab);

        if(r.steps != inf){
            cout << r.comm << endl;
        }else{
            cout << "This puzzle is not solvable." << endl;
        }
    }

    return 0;
}