//02, 12, 2018, 10:02:56 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;

    cin >> s;

    int num = 0;
    int best = 1e9;
    
    for(int i = 0 ; i <= int(s.length()) - 3 ; i++){
        num = (s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + (s[i + 2] - '0');

        best = min(best, abs(753 - num));
    }

    cout << best << endl;

    return 0;
}