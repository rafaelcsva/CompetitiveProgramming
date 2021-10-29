#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

using cd = complex< double >;
const double PI = acos(-1);

void fft(vector< cd > &a, bool invert) {
    int n = a.size();

    for(int i = 1, j = 0 ; i < n ; i++){
        int bit = n >> 1;
        for(; j & bit ; bit >>= 1){
            j ^= bit;
        }
        j ^= bit;

        if(i < j){
            swap(a[i], a[j]);
        }
    }

    for(int len = 2 ; len <= n ; len <<= 1){
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for(int i = 0 ; i < n ; i += len){
            cd w(1);
            for(int j = 0 ; j < len / 2 ; j++){
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if(invert){
        for(cd & x : a)
            x /= n;
    }
}

vector< int > multiply(vector< int > const &a, vector< int > const &b){
    vector< cd > fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;

    while(n < a.size() + b.size()){
        n <<= 1;
    }

    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for(int i = 0 ; i < n ; i++){
        fa[i] *= fb[i];
    }
    fft(fa, true);

    vector< int > result(n);

    for(int i = 0 ; i < n ; i++){
        result[i] = round(fa[i].real());
    }

    return result;
}

const int N = 60010;
const int offset = 30000;
int cnta[N], cntc[N];
int va[N], vb[N], vc[N];
vector< int > ca, cc;

int main(){
    int na;

    scanf("%d", &na);

    for(int i = 0 ; i < na ; i++){
        scanf("%d", &va[i]);
        va[i] += offset;
        cnta[va[i]]++;
    }

    int nb;

    scanf("%d", &nb);

    for(int i = 0 ; i < nb ; i++){
        scanf("%d", &vb[i]);
        vb[i] += offset;
    }

    int nc;

    scanf("%d", &nc);

    for(int i = 0 ; i < nc ; i++){
        scanf("%d", &vc[i]);
        vc[i] += offset;
        cntc[vc[i]]++;
    }

    for(int i = 0 ; i < N ; i++){
        ca.push_back(cnta[i]);
        cc.push_back(cntc[i]);

        // printf("on %d w've %d, %d\n", i, cnta[i], cntc[i]);
    }

    auto cd = multiply(ca, cc);

    ll ans = 0;

    for(int i = 0 ; i < nb ; i++){
        ans += ll(cd[2 * vb[i]]);
    }

    printf("%lld\n", ans);

    return 0;
}