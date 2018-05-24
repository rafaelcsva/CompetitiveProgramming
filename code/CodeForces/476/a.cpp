//25, 04, 2018, 14:34:14 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main(){
    int k, n, s, p;

    cin >> k >> n >> s >> p;
    int w = 0;

    if(n % s){
        w = 1;
    }

    int sheets = k * (n / s + w);
    int add = 0;

    if(sheets % p){
        add = 1;
    }

    cout << (sheets) / p + add << endl;

    return 0;
}