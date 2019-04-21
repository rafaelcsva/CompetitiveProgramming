//01, 04, 2019, 19:12:47 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, pii >    pipii;

const int N = int(1e5 + 10);
int disk[N];
vector< pii > qu;
vector< pipii > quotes;
pii resp[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m, q;

        scanf("%d %d %d", &n, &m, &q);

        for(int i = 0 ; i < n ; i++){
            int li, ri;

            scanf("%d %d", &li, &ri);

            disk[li]++;
            disk[ri + 1]--;
        }

        int l = 1, r = 0;
        int ac = 0;

        for(int i = 1 ; i <= m ; i++){
            ac += disk[i];

            if(ac == 0){
                if(r < l){
                    r = l = i;
                }else{
                    r++;
                }
            }else{
                if(r >= l){
                    quotes.push_back({r - l + 1, {r, l}});
                }

                r = 0, l = 1;
            }
        }

        if(r >= l){
            quotes.push_back({r - l + 1, {r, l}});
        }

        sort(quotes.begin(), quotes.end());

        for(int i = 0 ; i < q ; i++){
            int qi;

            scanf("%d", &qi);

            qu.push_back({qi, i});
        }

        sort(qu.begin(), qu.end());

        pii cur = {-1, -1};
        int pt = int(quotes.size()) - 1;

        for(int i = int(qu.size()) - 1 ; i >= 0 ; i--){
            while(pt >= 0 && quotes[pt].first >= qu[i].first){
                cur = max(cur, quotes[pt].second);
                pt--;
            }

            int sz = cur.first - cur.second + 1;

            if(sz > qu[i].first){
                // cout << " aqui para " << qu[i].first << endl;
                resp[qu[i].second] = {cur.first, cur.second + sz - qu[i].first};
            }else{
                resp[qu[i].second] = cur;
            }
        }

        for(int i = 0 ; i < q ; i++){
            printf("%d %d\n", resp[i].second, resp[i].first);
            // cout << resp[i].second << " " << resp[i].first << endl;
        }

        qu.clear();
        quotes.clear();
        memset(disk, 0, sizeof(int) * (m + 4));
    }

    return 0;
}