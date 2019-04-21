//01, 04, 2019, 18:11:06 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;
multiset< int > mst[2];
int a[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        int n, m;

        cin >> n >> m;

        mst[0].clear();
        mst[1].clear();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cin >> a[i][j];
            }
        }

        for(int i = 0 ; i < m ; i++){
            mst[0].insert(a[0][i]);
        }

        int beat = 0;
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                auto u = mst[!(i & 1)].find(a[i][j]);

                if(u != mst[!(i & 1)].end()){
                    mst[!(i & 1)].erase(u);
                    beat++;
                }

                mst[i & 1].insert(a[i][j]);
            }

            mst[!(i & 1)].clear();
        }

        cout << beat << endl;
    }

    return 0;
}