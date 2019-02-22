//28, 11, 2018, 12:56:41 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
vector< int > con[N];
int tmp[4][N];
int s0[2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        int si, ri;

        cin >> si >> ri;

        con[si].push_back(ri);
    }

    for(int i = 1 ; i <= m ; i++){
        if(con[i].size() > 0ul){
            tmp[0][s0[0]++] = i;
            sort(con[i].begin(), con[i].end(), greater< int >());

            for(int j = 1 ; j < con[i].size() ; j++){
                con[i][j] += con[i][j - 1];
            }
        }
    }

    int best = 0;

    for(int peoples = 0 ; peoples < n ; peoples++){
        int pos = peoples & 1;
        int other = !pos;

        if(s0[pos] == 0){
            break;
        }

        int te = 0;

        for(int i = 0 ; i < s0[pos] ; i++){
            int u = tmp[pos][i];

            if((peoples + 1) <= con[u].size() && con[u][peoples] > 0){
                tmp[other][s0[other]++] = u;
                te += con[u][peoples];
            }
        }
        
        best = max(best, te);
        s0[pos] = 0;
    }

    // assert(best == 22);
    cout << best << endl;

    return 0;
}