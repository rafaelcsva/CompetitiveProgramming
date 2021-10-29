#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int a[N];
int ans[N];
vector< int > con[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m;

        scanf("%d %d", &n, &m);

        vector< int > vals;

        for(int i = 0 ; i < n * m ; i++){
            scanf("%d", &a[i]);
            vals.push_back(a[i]);
        }

        sort(vals.begin(), vals.end());

        auto it = unique(vals.begin(), vals.end());

        vals.resize(distance(vals.begin(), it));

        for(int i = 0 ; i < n * m ; i++){
            a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
        }

        for(int i = n * m - 1 ; i >= 0 ; i--){
            con[a[i]].push_back(i);
        }

        int cur = 0;

        for(int i = 0 ; i < n ; i++){
            int j = 0;

            while(j < m){
                int rest = m - j;

                if(rest >= con[cur].size()){
                    for(auto u: con[cur]){
                        ans[i * m + j] = u;
                        j++;
                    }
                    con[cur].clear();
                    cur++;
                }else{
                    for(int d = int(con[cur].size() - rest) ; d < con[cur].size() ; d++){
                        ans[i * m + j] = con[cur][d];
                        j++;
                    }

                    vector< int > tmp;

                    for(int d = 0 ; d < int(con[cur].size() - rest) ; d++){
                        tmp.push_back(con[cur][d]);
                    }
                    con[cur] = tmp;
                }
            }
        }

        int anst = 0;

        for(int i = 0 ; i < n * m ; i++){
            int j = i;

            while(true){
                if(ans[j] < ans[i]){
                    anst++;
                }

                if(j % m == 0){
                    break;
                }
        
                j--;
            }
        }
        
        printf("%d\n", anst);
    }

    return 0;
}