#include <bits/stdc++.h>

using namespace std;

int solve(vector< int > &a, vector< int > &b) {
    int suf = 0;
    int ans = 0;

    for(int i = b.size() - 1 ; i >= 0 ; i--){
        int tmp = 0;
        int bi = b[i];

        int boxes = upper_bound(a.begin(), a.end(), bi) - a.begin();

        if(boxes) {
            tmp = i - (upper_bound(b.begin(), b.end(), bi - boxes) - b.begin()) + 1;
        }

        ans = max(ans, tmp + suf);

        auto r = lower_bound(a.begin(), a.end(), b[i]);

        if(r != a.end() && *r == b[i]){
            suf++;
        }
    }

    return ans;
}

int main() {
    int t;

    scanf("%d", &t);

    while(t--) {
        vector< int > a[2], b[2];

        int n, m;

        scanf("%d %d", &n, &m);

        for(int i = 0 ; i < n ; i++){
            int ai;

            scanf("%d", &ai);

            a[ai > 0].push_back(abs(ai));
        }

        for(int i = 0 ; i < m ; i++){
            int bi;

            scanf("%d", &bi);

            b[bi > 0].push_back(abs(bi));
        }

        reverse(a[0].begin(), a[0].end());
        reverse(b[0].begin(), b[0].end());

        printf("%d\n", solve(a[0], b[0]) + solve(a[1], b[1]));
    }

    return 0;
}
