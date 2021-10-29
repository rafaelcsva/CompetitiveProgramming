#include <bits/stdc++.h>

using namespace std;

using cd = complex<double>;
const double PI = acos(-1);
const int N = int(2e5) + 10;
__int128 MOD = 998244353LL;
__int128 fat[N];

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<__int128> multiply(vector<__int128> const& a, vector<__int128> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<__int128> result(n);
    for (int i = 0; i < n; i++)
        result[i] = __int128(round(fa[i].real())) % MOD;
    return result;
}

__int128 bigMOD(__int128 a,__int128 p,__int128 m=MOD)
{
    __int128 ret=1;
    while(p>0)
    {
        if(p&1)ret=(ret*a)%MOD;
        p>>=1;
        a=(a*a)%MOD;
    }
    return ret;
}

__int128 comb(int n, int k){
    __int128 inv = bigMOD((fat[n - k] * fat[k]), MOD - 2, MOD);

    return (fat[n] * inv);
}

int cnt[30];
vector< vector<__int128> > res;
long long pref[N];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    fat[0] = 1ll;

    for(__int128 i = 1ll ; i < N ; i++){
        fat[i] = (i * fat[i - 1]) % MOD;
    }

    int n, q;

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int ai;

        cin >> ai;

        for(int j = 0 ; j < 30 ; j++){
            int e = 1 << j;

            if(ai & e){
                cnt[j]++;
            }
        }
    }

    for(int i = 0 ; i < 30 ; i++){
        vector< __int128 > a, b;
        for(int j = 0 ; j <= cnt[i] ; j++){
            if(j & 1){
                a.push_back(comb(cnt[i], j));
            }else{
                a.push_back(0LL);
            }
        }

        for(int j = 0 ; j <= n - cnt[i]; j++){
            b.push_back(comb(n - cnt[i], j));
        }

        res.push_back(multiply(a, b));
    }

    for(int i = 1 ; i <= n ; i++){
        for(__int128 j = 0 ; j < 30 ; j++){
            __int128 e = 1LL << j;

            pref[i] += res[j].size() > i ? (res[j][i] * e) % MOD : 0LL;

            if(pref[i] >= MOD){
                pref[i] -= MOD;
            }
        }

        pref[i] += pref[i - 1];

        if(pref[i] >= MOD){
            pref[i] -= MOD;
        }
    }

    cin >> q;

    while(q--){
        int m;

        cin >> m;

        cout << pref[m] << '\n';
    }

    return 0;
}