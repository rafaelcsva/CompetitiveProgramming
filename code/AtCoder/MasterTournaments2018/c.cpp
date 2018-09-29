//07, 07, 2018, 09:30:31 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ld n, m, d;

    cin >> n >> m >> d;

    ld h = n - d;
    ld mean = ((h * (m - 1LL)) / n) / n;
    
    if(d != 0LL){
        cout << fixed << setprecision(10) << (2.0L * mean) << endl;
    }else{
        cout << fixed << setprecision(10) << mean << endl;
    }
    
    return 0;
}