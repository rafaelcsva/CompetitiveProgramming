//08, 01, 2019, 16:16:43 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
ll pre_lcm[N], pre_gcd[N], suf_lcm[N], suf_gcd[N];
ll a[N];
bool is_composite[N];
map< int, int > cnt[2];
vector< ll > primes;

void sieve(){
    for(int i = 2 ; i * i < N ; i++){
        if(!is_composite[i]){
            for(int j = i + i ; j < N ; j += i){
                is_composite[j] = true;
            }
        }
    }

    for(ll i = 2LL ; i < N ; i++){
        if(!is_composite[i]){
            primes.push_back(i);
        }
    }
}

ll lcm(ll a, ll b){
    return a * (b / __gcd(a, b));
}

void process(int p, ll num){
    for(int i = 0 ; i < primes.size() ; i++){
        ll k = primes[i];

        if(k * k > num){
            break;
        }

        int t = 0;

        while(num % k == 0LL){
            t++;
            num /= k;
        }

        cnt[p][k] = t;
    }

    if(num != 1LL){
        cnt[p][num] = 1LL;
    }
}

bool is_on_bounds(ll x){
    for(int i = 0 ; i < primes.size() ; i++){
        ll k = primes[i];

        if(k * k > x){
            break;
        }

        int t = 0;

        while(x % k == 0LL){
            t++;
            x /= k;
        }

        if(!(cnt[0][k] <= t && t <= cnt[1][k])){
            return false;
        }
    }

    if(x != 1LL){
        int t = 1;
        int k = x;

        if(!(cnt[0][k] <= t && t <= cnt[1][k])){
            return false;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;

    cin >> t;

    while(t--){
        int n;
        ll x, y;

        cin >> n >> x >> y;

        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }

        if(y % x != 0 || (n == 1LL && x != y)){
            cout << -1 << endl;
        }else{
            if(n == 1LL){
                cout << (a[0] != x) << endl;
                continue;
            }

            int taked = 0;
            process(0, x);
            process(1, y);

            for(int i = 0 ; i < n ; i++){
                if(!is_on_bounds(a[i])){
                    taked++;
                }
            }

            cnt[0].clear();
            cnt[1].clear();

            if(taked >= 2){
                cout << taked << endl;
            }else{
                bool ok = true;

                for(int i = 0 ; i < n ; i++){
                    if(i == 0){
                        pre_gcd[i] = pre_lcm[i] = a[i];
                    }else{
                        pre_gcd[i] = __gcd(pre_gcd[i - 1], a[i]);
                        pre_lcm[i] = lcm(pre_lcm[i - 1], a[i]);
                    }

                    if(pre_lcm[i] > y || pre_gcd[i] < x){
                        ok = false;
                    }

                    assert(pre_lcm[i] > 0LL && pre_gcd[i] > 0LL);
                }

                for(int i = n - 1 ; i >= 0 ; i--){
                    if(i == n - 1){
                        suf_gcd[i] = suf_lcm[i] = a[i];
                    }else{
                        suf_gcd[i] = __gcd(suf_gcd[i + 1], a[i]);
                        suf_lcm[i] = lcm(suf_lcm[i + 1], a[i]);
                    }

                    if(suf_lcm[i] > y || suf_gcd[i] < x){
                        // cout << "2 " << i << endl;
                        ok = false;
                    }

                    assert(suf_lcm[i] > 0LL && suf_gcd[i] > 0LL);
                }

                if(ok){
                    // cout << "aqui!\n" << endl;

                    if(pre_gcd[n - 1] == x && pre_lcm[n - 1] == y){
                        cout << 0 << endl;
                        continue;
                    }
                }

                bool can1 = false;

                for(int i = 0 ; i < n ; i++){
                    ll lfg, rgg, lfl, rgl;

                    if(i == 0){
                        lfg = 0LL, lfl = 1LL;
                        rgg = suf_gcd[i + 1];
                        rgl = suf_lcm[i + 1];
                    }else if(i == n - 1){
                        lfg = pre_gcd[i - 1], lfl = pre_lcm[i - 1];
                        rgg = 0LL;
                        rgl = 1LL;
                    }else{
                        lfg = pre_gcd[i - 1], lfl = pre_lcm[i - 1];
                        rgg = suf_gcd[i + 1];
                        rgl = suf_lcm[i + 1];
                    }

                    if(!(min(lfg, rgg) >= x && max(lfl, rgl) <= y)){
                        continue;
                    }

                    ll g1 = __gcd(lfg, rgg);
                    ll l1 = lcm(lfl, rgl);

                    if(g1 < x || l1 > y){
                        continue;
                    }

                    if(__gcd(g1, x) == x && lcm(l1, x) == y){
                        can1 = true;
                        break;
                    }else if(__gcd(g1, y) == x && lcm(l1, y) == y){
                        can1 = true;
                        break;
                    }
                }

                if(can1){
                    cout << 1 << endl;
                }else{
                    cout << 2 << endl;
                }
            }
        }
    }
    
    return 0;
}