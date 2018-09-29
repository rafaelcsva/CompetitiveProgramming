//18, 08, 2018, 09:32:26 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 510;
vector< int > pos[N];
int pre[N][N];
int n, m, q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d %d %d", &n, &m, &q);

    for(int i = 0 ; i < m ; i++){
        int l, r;

        scanf("%d %d", &l, &r);

        pos[r].push_back(l);
    }

    for(int i = 1 ; i <= n ; i++){
        sort(pos[i].begin(), pos[i].end());
    }

    for(int i = 1 ; i <= n ; i++){
    
        for(int j = i ; j <= n ; j++){
            if(j > i)
                pre[i][j] = pre[i][j - 1];
            
            int lo = lower_bound(pos[j].begin(), pos[j].end(), i) - pos[j].begin();  
            int hi = upper_bound(pos[j].begin(), pos[j].end(), j) - pos[j].begin();

            pre[i][j] += hi - lo;
        }
    }

    while(q--){
        int l, r;

        scanf("%d %d", &l, &r);

        printf("%d\n", pre[l][r]);
    }

    return 0;
}