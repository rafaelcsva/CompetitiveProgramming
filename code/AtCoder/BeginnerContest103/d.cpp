//21, 07, 2018, 10:18:23 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = int(1e5 + 10);
int keep[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        int l, r;

        cin >> l >> r;

        keep[l] += 1;
        keep[r] -= 1; 
    }

    for(int i = 1 ; i <= m ; i++){
        keep[i] += keep[i - 1];
    }

    

    return 0;
}