#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >    pii;

const int N = int(1e5) + 10;
int a[N];
int cnt[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m;

        scanf("%d %d", &n, &m);

        vector< pair< int, int > > v;

        for(int i = 0 ; i < n * m ; i++){
            scanf("%d", &a[i]);
            v.push_back({a[i], -i});
            cnt[i] = 0;
        }

        sort(v.begin(), v.end());

        int ans = 0;

        for(int j = 0 ; j < v.size() ; j++){
            // printf("%d\n", v[j].second);
            v[j].second *= -1;
            cnt[v[j].second]++;

            for(int i = 0 ; i < v[j].second ; i++){
                ans += cnt[i];
                // printf("+%d\n", cnt[i]);
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}