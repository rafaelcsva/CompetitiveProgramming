#include <bits/stdc++.h>

using namespace std;

multiset< pair< int, int > > con, tmpcon;

const int N = int(1e6) + 10;
int mark[N];

int main(){
    int t;

    scanf("%d", &t);

    for(int test = 1 ; test <= t ; test++){
        int n, m;

        scanf("%d %d", &n, &m);

        for(int i = 0 ; i < m ; i++){
            int ci;
            scanf("%d", &ci);

            con.insert({ci, 1});
        }

        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                scanf("%d", &mark[j]);
                // printf("%d ", mark[j]);

                auto u = con.lower_bound({mark[j], 0});

                if(u == con.end() || u->first != mark[j]){
                    continue;
                }

                mark[j] = 0;
                tmpcon.insert(*u);
                con.erase(u);
            }

            for(int j = 0 ; j < m ; j++){
                if(mark[j]){
                    auto u = con.begin();

                    if(u->second == 0){
                        ans++;
                    }

                    tmpcon.insert({mark[j], 0});
                    con.erase(u);
                    mark[j] = 0;
                }
            }

            con = tmpcon;
            tmpcon.clear();
        }

        printf("Case #%d: %d\n", test, ans);
        con.clear();
    }

    return 0;
}