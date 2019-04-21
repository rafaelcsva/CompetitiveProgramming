//18, 04, 2019, 12:37:17 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

string s;
string target = "ACTG";
const int inf = 1e9;

int cost(string &f){
    int tot = 0;

    for(int i = 0 ; i < f.length() ; i++){
        int cost = min({abs(f[i] - 'A') + 1 + abs(target[i] - 'Z'), abs('Z' - f[i]) + 1 + abs(target[i] - 'A'), abs(target[i] - f[i]) });

        tot += cost;
    }

    return tot;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;

    cin >> n >> s;
    string t = "";

    int best = inf;

    string tmp = "";

    for(int i = 0 ; i <= n - 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            tmp.push_back(s[i + j]);
        }

        best = min(best, cost(tmp));
        tmp = "";
    }
    
    cout << best << endl;

    return 0;
}