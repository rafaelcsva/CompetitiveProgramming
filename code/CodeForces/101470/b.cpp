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
        for(int i = 1 ; i < classes ; i++){
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

const int N = int(2e5) + 10;
int rk[N];
int dp[N];
string s;
vector< int > p;

bool can(int x, int r, int sz, int n){
    // printf("try %d %d %d %d\n", x, r, sz, n);

    for(int i = 0 ; i <= sz ; i++){
        int taked = 0;
        int j = i;
        while(taked != r && j - i < n){
            if(rk[j] <= x){
                // cout << "pega " << s.substr(p[rk[j]], sz + 1) <<" " << i << endl;
                taked++;
                j += sz + 1;
            }else{
                j += sz;
            }
        }

        if(j - i <= n && taked == r){
            // cout << s.substr(p[x], sz + 1) << " works on " << i << "\n" ;
            return true;
        }
    }

    return false;
}

int main(){
    freopen("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    cin >> s;
    s = s + s;

    p = suffix_array_construction(s);

    for(int i = 0 ; i < p.size() ; i++){
        rk[p[i]] = i;
    }

    int sz = n / k;

    if((n % k) == 0){
        for(int i = 0 ; i < sz ; i++){
            dp[i] = rk[i];
        }

        int ans = 2 * n;

        for(int i = sz ; i < n ; i++){
            dp[i] = max(dp[i - sz], rk[i]);
    
            if(i >= n - sz){
                ans = min(ans, dp[i]);
            }
        }
        cout << s.substr(p[ans], sz) << "\n";
    }else{
        int lo = 0, hi = 2 * n;
        int r = -1;

        while(lo <= hi){
            int mid = (lo + hi) >> 1;

            if(can(mid, n % k, sz, n)){
                r = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        // assert(r != -1);

        cout << s.substr(p[r], sz + 1) << "\n";
    }

    return 0;
}