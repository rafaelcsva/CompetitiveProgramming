//28, 07, 2018, 08:52:52 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 1e5;
int qtd[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        for(int i = 0 ; i < n ; i++){
            int x;

            cin >> x;

            qtd[x]++;
        }

        int r = 0;

        for(int i = 1 ; i < N ; i++){
            r = max(r, qtd[i] + qtd[i + 1]);
        }

        cout << r << endl;

        memset(qtd, 0, sizeof qtd);
    }
    return 0;
}