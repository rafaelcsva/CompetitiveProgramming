//06, 04, 2019, 08:37:21 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 3e5 + 100;
int f[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    memset(f, -1, sizeof f);

    cin >> n;

    int best = 0;

    for(int i = 0 ; i < n ; i++){
        cin >> f[i];
    }

    int i = 0, j = n - 1;

    while(f[i] == f[n - 1]){
        i++;
    }

    while(f[j] == f[0]){
        j--;
    }

    cout << max(j, (n - 1) - i) << endl;
    
    return 0;
}