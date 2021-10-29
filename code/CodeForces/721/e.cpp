#include <bits/stdc++.h>

using namespace std;

const int N = int(4e4);
int a[N];

const int INF = int(2e9);
int n, k;
int last[N];
vector<int> dp_before, dp_cur;
stack< int > st[N];
map< pair< int, int >, int > dp;
vector< int > v[N];

int c(int i, int j){
    if(i == j){
        return 0;
    }

    pair< int, int > k = {i, j};

    if(dp.count(k) != 0){
        return dp[k];
    }

    int pt = upper_bound(v[a[i]].begin(), v[a[i]].end(), i) - v[a[i]].begin();
    int add = 0;

    if(pt != v[a[i]].size() && v[a[i]][pt] <= j){
        add = v[a[i]][pt] - i;
    }
    return dp[k] = add + c(i + 1, j);
}

// compute dp_cur[l], ... dp_cur[r] (inclusive)
void compute(int l, int r, int optl, int optr)
{
    if (l > r)
        return;
    int mid = (l + r) >> 1;
    pair<long long, int> best = {INF, -1};

    for (int k = optl; k <= min(mid, optr); k++) {
        int ai = a[k];

        best = min(best, {(k - 1 < 0 ? 0 : dp_before[k - 1]) + c(k, mid), k});
    }

    dp_cur[mid] = best.first;

    // printf("%d on [%d, %d] gives %d on %d\n", mid, optl, optr, dp_cur[mid], best.second);
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

int main(){
    memset(last, -1, sizeof last);

    scanf("%d %d", &n, &k);

    dp_before.resize(n);
    dp_cur.resize(n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
        v[a[i]].push_back(i);
    }

    int ans = 0;

    for(int i = 0 ; i < n ; i++){
        if(last[a[i]] != -1){
            ans += i - last[a[i]];
            // printf("%d\n", a[i]);
        }
        last[a[i]] = i;

        dp_cur[i] = ans;
    }

    k--;

    while(k){
        // printf("cur = %d\n", dp_cur[n - 1]);
        swap(dp_cur, dp_before);
        compute(0, n - 1, 0, n - 1);
        k--;
    }

    printf("%d\n", dp_cur[n - 1]);

    return 0;
}