#include <bits/stdc++.h>

using namespace std;

vector< int > sort_cyclic_shifts(vector< int > const &s){
    int n = s.size();
    const int alphabet = 302;
    vector< int > p(n), c(n), cnt(max(alphabet, n), 0);
    for(int i = 0 ; i  < n ; i++){
        cnt[s[i]]++;
    }
    for(int i = 1 ; i < alphabet ; i++){
        cnt[i] += cnt[i - 1];
    }
    for(int i = 0 ; i < n ; i++){
        p[--cnt[s[i]]] = i;
    }
    cnt[p[0]] = 0;
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
            if(cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector< int > suffix_array_construction(vector< int > s){
    s.push_back(0);
    vector< int > sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());

    return sorted_shifts;
}

typedef long long   ll;
const int N = int(5e5) + 10;
const int endSeq = 301;
int ra[N];
ll pr[N];
const ll mod = ll(1e9) + 7LL;

int main(){
    pr[0] = 1LL;

    for(int i = 1 ; i < N ; i++){
        pr[i] = (365LL * pr[i - 1]) % mod;
    }

    int n;

    while(scanf("%d", &n) != EOF){
        vector< int > s;
        
        int total = 0;

        for(int i = 0 ; i < n ; i++){
            int ki;

            scanf("%d", &ki);

            total += ki;

            for(int i = 0 ; i < ki ; i++){
                int vi;

                scanf("%d", &vi);
                s.push_back(vi);
            }
            s.push_back(endSeq);
        }

        auto sa = suffix_array_construction(s);

        for(int i = 0 ; i < sa.size() ; i++){
            ra[sa[i]] = i;
        }

        set< pair< int, int > > st;

        st.insert({ra[0], 0});

        for(int i = 1 ; i < int(s.size()) - 1 ; i++){
            if(s[i] == endSeq){
                st.insert({ra[i + 1], i + 1});
            }
        }

        ll ans = 0LL;

        while(st.size() > 0){
            auto bg = *st.begin();

            ans += ll(s[bg.second]) * pr[total--];
            ans %= mod;

            if(s[bg.second + 1] != endSeq){
                st.insert({ra[bg.second + 1], bg.second + 1});
            }

            st.erase(bg);
        }

        printf("%lld\n", ans);
    }
    return 0;
}