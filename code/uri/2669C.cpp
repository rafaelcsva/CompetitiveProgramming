#include <bits/stdc++.h>

using namespace std;

using cd = complex<double>;
const double PI = acos(-1);
typedef long long   ll;

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

vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
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

    vector<ll> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

const int N = 26 * int(1e5) + 10;
int pref[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;

    int sum = 0;
    // pref[0] = 1;

    for(int i = 0 ; i < s.length() ; i++){
        int add = s[i] - 'a' + 1;
        sum += add;

        pref[sum] = 1;

        // cout << sum << " ";
    }
    // cout << "\n";

    vector< ll > a, b;
    
    for(int i = 0 ; i <= sum ; i++){
        a.push_back(pref[i]);
        b.push_back(pref[sum - i] || i == sum);
    }

    auto c = multiply(a, b);
    int cnt = 0;

    for(int i = sum + 1 ; i < c.size() ; i++){
        if(c[i]){
            cnt++;
            // printf("%d\n", i - sum);
        }
    }

    cout << cnt << "\n";

    return 0;
}