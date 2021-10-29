#include <bits/stdc++.h>

using namespace std;

using cd = complex<double>;
const double PI = acos(-1);

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

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
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

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

int main(){
    string s, t;

    cin >> s >> t;

    reverse(t.begin(), t.end());

    vector< int > a[2], b[2];

    for(int i = 0 ; i < s.length() ; i++){
        a[0].push_back(s[i] == '0');
        a[1].push_back(s[i] == '1');
    } 

    for(int i = 0 ; i < t.length() ; i++){
        b[0].push_back(t[i] == '0');
        b[1].push_back(t[i] == '1');
    }

    auto e = multiply(a[0], b[0]);
    auto f = multiply(a[1], b[1]);

    int ans = int(s.length());

    for(int i = int(t.length()) - 1 ; i < s.length() ; i++){
        ans = min(ans, int(t.length()) - (e[i] + f[i]));
    }

    printf("%d\n", ans);

    return 0;
}