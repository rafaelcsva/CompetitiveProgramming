//25, 11, 2018, 16:11:24 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

ll mod1 = 402653189LL, mod2 = 805306457LL;
const int N = int(1e6 + 10);
ll pref1[N], pref2[N];
ll x, y;
ll d = 0LL;
ll pow1[N], pow2[N];

// store x, y, and d as global variables
void extendedEuclid(ll a, ll b) {
    if (b == 0) { x = 1; y = 0; d = a; return; }
    // base case
    extendedEuclid(b, a % b);
    // similar as the original gcd
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

ll MOD(ll val, ll mod){
    return ((val % mod) + mod) % mod;
}

ll inverso(ll a, ll mod){
    extendedEuclid(a, mod);

    return MOD(x, mod);
}

ll MOD1(ll val){
    ll mod = mod1;

    return ((val % mod) + mod) % mod;
}

ll MOD2(ll val){
    ll mod = mod2;
    
    return ((val % mod) + mod) % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;

    cin >> s >> t;

    ll n0, n1;
    n0 = n1 = 0LL;

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '0'){
            n0++;
        }else{
            n1++;
        }
    }
    pow1[0] = pow2[0] = 1LL;
    ll k1 = 31LL, k2 = 31LL;

    for(int i = 0 ; i < t.length() ; i++){
        t[i] = t[i] - 'a' + 1;

        pref1[i + 1] = pow1[i] * t[i];
        pref1[i + 1] += pref1[i];
        pref1[i + 1] %= mod1; 

        pref2[i + 1] = pow2[i] * t[i];
        pref2[i + 1] += pref2[i];
        pref2[i + 1] %= mod2;

        pow1[i + 1] = pow1[i];
        pow1[i + 1] *= k1;
        pow1[i + 1] %= mod1;

        pow2[i + 1] = pow2[i];
        pow2[i + 1] *= k2;
        pow2[i + 1] %= mod2;
    }

    ll len = t.length();
    ll cnt = 0LL;

    for(ll s1 = 1LL ; s1 <= len ; s1++){
        ll res = len - s1 * n1;

        if(res <= 0LL){
            break;
        }
        
        if(res % n0 == 0LL){
            ll s0 = res / n0;
            ll i = 1;
            ll val10 = -1LL, val20 = -1LL;
            ll val11 = -1LL, val21 = -1LL;
            bool ok = true;
            int nxt = 0;

            while(i <= len){
                if(s[nxt] == '0'){
                    ll val1 = (MOD1(pref1[i + s0 - 1] - pref1[i - 1])) * inverso(pow1[i - 1], mod1);
                    val1 = MOD1(val1);

                    ll val2 = (MOD2(pref2[i + s0 - 1] - pref2[i - 1])) * inverso(pow2[i - 1], mod2);
                    val2 = MOD2(val2);

                    if(val10 == -1LL){
                        assert(val1 != -1LL && val2 != -1LL);
                        val10 = val1;
                        val20 = val2;
                    }else{
                        if(val10 != val1 || val20 != val2){
                            ok = false;
                            break;
                        }
                    }

                    i += s0;
                }else{
                    ll val1 = (MOD1(pref1[i + s1 - 1] - pref1[i - 1])) * inverso(pow1[i - 1], mod1);
                    val1 = MOD1(val1);

                    ll val2 = (MOD2(pref2[i + s1 - 1] - pref2[i - 1])) * inverso(pow2[i - 1], mod2);
                    val2 = MOD2(val2);

                    if(val11 == -1LL){
                        assert(val1 != -1LL && val2 != -1LL);
                        val11 = val1;
                        val21 = val2;
                    }else{
                        if(val11 != val1 || val21 != val2){
                            ok = false;
                            break;
                        }
                    }

                    i += s1;
                }

                nxt++;
            }

            if(ok && val11 != val10 && val21 != val20){
                cnt++;
            }
        }else{
            // cout << s1 << " rejected au" << endl;
        }
    }

    cout << cnt << endl;

    return 0;
}