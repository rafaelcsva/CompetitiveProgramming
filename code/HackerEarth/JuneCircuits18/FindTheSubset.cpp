//17, 06, 2018, 17:33:21 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = int(1e5 + 100);
ll v[N];
ll aux[N];

int main(){
    int n, m, d;
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> d;

    for(int i = 0 ; i < m ; i++){
        cin >> v[i];
        aux[i] = v[i];
    }


    sort(v, v + m);
    int printed = 0;
    
    for(int i = 0 ; i < m ; i++){
        char c = printed == n - 1 ? '\n' : ' ';
        
        if(aux[i] <= v[n - 1]){
            cout << aux[i] << c;
            printed++;
        }
    }

    return 0;
}