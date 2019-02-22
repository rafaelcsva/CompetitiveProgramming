//12, 01, 2019, 10:01:30 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h, w;

    cin >> n >> h >> w;

    cout << (n - h + 1) * (n - w + 1) << endl; 
    
    return 0;
}