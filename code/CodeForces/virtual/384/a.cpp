//31, 05, 2018, 09:34:27 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int main(){
    int n, a, b;

    cin >> n >> a >> b;

    a--, b--;

    string s;

    cin >> s;

    if(s[a] == s[b]){
        cout << "0" << endl;
    }else{
        cout << "1" << endl;
    }

    return 0;
}