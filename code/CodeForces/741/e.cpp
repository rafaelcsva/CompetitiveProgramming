#include <bits/stdc++.h>

using namespace std;

vector< int > sort_cyclic_shifts(string const &s){
    int n = s.size();
    const int alphabet = 256;

    vector< int > p(n), c(n), cnt(max(alphabet, n), 0);
    for(int i = 0 ; i < n ; i++){
        cnt[s[i]]++;
    }
    for(int i = 1 ; i < alphabet ; i++){
        cnt[i] += cnt[i - 1];
    }
    for(int i = 0 ; i < n ; i++){
        p[--cnt[s[i]]] = i;
    }

    c[p[0]] = 0;
    int classes = 1;

    for(int i = 1 ; i < n ; i++){
        if(s[p[i]] != s[p[i - 1]]){
            classes++;
        }

        c[p[i]] = classes - 1;
    }

    vector< int > pn(n), cn(n);
    for(int h = 0 ; (1 << h) < n ; ++h){
        for(int i = 0 ; i < n ; i++){
            pn[i] = p[i] - (1 << h);
            if(pn[i] < 0){
                pn[i] += n;
            }
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for(int i = 0 ; i < n ; i++){
            cnt[c[pn[i]]]++;
        }
        for(int i = 1 ; i < classes; i++){
            cnt[i] += cnt[i - 1];
        }
        for(int i = n - 1 ; i >= 0 ; i--){
            p[--cnt[c[pn[i]]]] = pn[i];
        }
        cn[p[0]] = 0;
        classes = 1;
        for(int i = 1 ; i < n ; i++){
            pair< int, int > cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair< int, int > prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};

            if(cur != prev){
                ++classes;
            }
            cn[p[i]] = classes - 1;
        }

        c.swap(cn);
    }

    return p;
}

vector< int > suffix_array_construction(string s){
    s += "$";
    vector< int > sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());

    return sorted_shifts;
}

vector< int > lcp_construction(string const &s, vector< int > const &p){
    int n = s.size();
    vector< int > rank(n, 0);

    for(int i = 0 ; i < n ; i++){
        rank[p[i]] = i;
    }

    int k = 0 ;
    vector< int > lcp(n - 1, 0);
    for(int i = 0 ; i < n ; i++){
        if(rank[i] == n - 1){
            k = 0;
            continue;
        }

        int j = p[rank[i] + 1];
        while(i + k < n && j + k < n && s[i + k] == s[j + k]){
            k++;
        }

        lcp[rank[i]] = k;
        if(k){
            k--;
        }
    }

    return lcp;
}

const int N = 5010;
int dp[N];
int n;

int solve(int i, vector< int > &p, vector< int > &lcp){
    int &ans = dp[i];

    if(ans != -1){
        return ans;
    }

    int mn = int(1e9);
    ans = 0;

    for(int j = i + 1 ; j < p.size() ; j++){
        mn = min(mn, lcp[j - 1]);

        if(p[j] > p[i]){
            ans = max(ans, solve(j, p, lcp) + n - p[j] - mn);
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        memset(dp, -1, sizeof dp);

        string s;

        cin >> n;
        cin >> s;

        auto p = suffix_array_construction(s);
        auto lcp = lcp_construction(s, p);

        int ans = 0;

        for(int i = 0 ; i < p.size() ; i++){
            ans = max(ans, n - p[i] + solve(i, p, lcp));
        }

        printf("%d\n", ans);
    }

    return 0;
}