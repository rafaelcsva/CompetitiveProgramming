//27, 11, 2018, 18:01:53 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e6 + 10);
int z1[N], z2[N];

void z_function(string s, int z[]) {
    int n = (int) s.length();
    
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string t, p;
    int k;

    cin >> t >> p;
    cin >> k;

    z_function(p + "$" + t, z1);

    reverse(p.begin(), p.end());
    reverse(t.begin(), t.end());

    z_function(p + "$" + t, z2);

    int n = t.length();
    int m = p.length();

    vector< int > resp;

    for(int i = 0 ; i <= n - m ; i++){
        int xi = z1[i + m + 1] + z2[n - (i + m - 1) + m];

        if(m - xi <= k){
            resp.push_back(i + 1);
        }
    }

    cout << resp.size() << endl;

    for(int i = 0 ; i < resp.size() ; i++){
        char c = i == int(resp.size()) - 1 ? '\n' : ' ';

        printf("%d%c", resp[i], c);
    }

    return 0;
}