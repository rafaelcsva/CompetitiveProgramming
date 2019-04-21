#include <bits/stdc++.h>
using namespace std;

typedef pair< int, int >    pii;

const int N = int(1e6 + 10);
const int M = int(1e3 + 100);
bool marked[M][M];
char tab[M][M];
int n, m;
int comp = 0;
int startl[N], endr[N];
int startd[N], endu[N];
const int B = 2010;

const int D = 4;
int vi[] = {0, 0, -1, 1};
int vj[] = {1, -1, 0, 0};
int bit[M];
int active;
set< pii > st;

class Event{
    public:
    int x;
    int tp;
    int idx;
    
    Event(int a, int b, int i){
        this->idx = i;
        this->x = a;
        this->tp = b;
    }
    
    bool operator <(Event &other){
        if(this->x < other.x){
            return true;
        }else if(this->x > other.x){
            return false;
        }
        
        return this->tp < other.tp;
    }
};

vector< Event > vertical, horizontal;

bool ok(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;    
}

bool line_sweep2(){
    for(int i = 0 ; i < vertical.size() ; i++){
        if(vertical[i].tp){
            auto u = st.lower_bound({vertical[i].idx, 0});

            pii d = *u;

            st.erase(u);

            d.second--;

            if(d.second){
                st.insert(d);
            }
        }else{
            auto u = st.lower_bound({vertical[i].idx, 0});

            if(u == st.end() || u->first != vertical[i].idx){
                st.insert({vertical[i].idx, 1});
            }else{
                pii d = *u;
                st.erase(u);

                d.second++;
                st.insert(d);
            }
        }
        // cout << st.size() << " sz " << endl;

        if(vertical.size() / 2 == st.size()){
            return true;
        }
    }

    return false;
}

bool line_sweep1(){
    for(int i = 0 ; i < horizontal.size() ; i++){
        if(horizontal[i].tp){
            auto u = st.lower_bound({horizontal[i].idx, 0});

            pii d = *u;

            st.erase(u);

            d.second--;

            if(d.second){
                st.insert(d);
            }
        }else{
            auto u = st.lower_bound({horizontal[i].idx, 0});

            if(u == st.end() || u->first != horizontal[i].idx){
                st.insert({horizontal[i].idx, 1});
            }else{
                pii d = *u;
                st.erase(u);

                d.second++;
                st.insert(d);
            }
        }
        
        if(line_sweep2()){
            // cout << "deu no " << horizontal[i].idx << endl;
            return true;
        }
    }
    
    return false;
}

void dfs(int i, int j){
    startl[comp] = min(startl[comp], j);
    endr[comp] = max(endr[comp], j);
    startd[comp] = min(startd[comp], i);
    endu[comp] = max(endu[comp], i);
    
    marked[i][j] = true;
    
    for(int k = 0 ; k < D ; k++){
        int x = vi[k] + i;
        int y = vj[k] + j;
        
        if(ok(x, y) && !marked[x][y] && tab[x][y] == 'W'){
            dfs(x, y);
        }
    }    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    
    cin >> t;
    
    while(t--){
        cin >> n >> m;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cin >> tab[i][j];
            }
        }
        
        comp = active = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(tab[i][j] == 'W' && !marked[i][j]){
                    // cout << "(i, j) = " << i << " " << j << endl;
                    comp++;
                    startl[comp] = endr[comp] = j;
                    startd[comp] = endu[comp] = i;
                    
                    dfs(i, j);
                }
            }
        }
        
        for(int i = 1 ; i <= comp ; i++){
            if(startl[i] == 0 || endr[i] == m - 1 || startd[i] == 0 || endu[i] == n - 1){
                continue;
            } 
            
            active++;
            
            //cout << startl[i] + 1<< " " << endr[i] + 2 << " x " << startd[i] + 1 << " " << endu[i] + 2 << endl;
            
            horizontal.push_back(Event(startl[i] + 1, 0, i));
            horizontal.push_back(Event(endr[i] + 2 + 1, 1, i));
            
            vertical.push_back(Event(startd[i] + 1, 0, i));
            vertical.push_back(Event(endu[i] + 2 + 1, 1, i));
        }   
        
        // cout << active << " eh active " << vertical.size() / 2 << endl;
        sort(horizontal.begin(), horizontal.end());
        sort(vertical.begin(), vertical.end());
        
        if((active <= B) && (active == 0 || line_sweep1())){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
        //cout << "active " << active << " " << comp << endl;
        
        horizontal.clear();
        vertical.clear();
        st.clear();
        memset(marked, false, sizeof marked);
    }
   
	return 0;
}