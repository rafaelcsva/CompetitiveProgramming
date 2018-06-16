//05, 06, 2018, 21:07:02 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = 30000;
int fib[N];
const int MOD = int(1e4);
const int p[] = {60, 300, 1500, 15000};

int main(){
    int t;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;    

    while(t--){
        int a, b, n, m;

        cin >> a >> b >> n >> m;

        int pot = 1;

        for(int i = 0 ; i < m ; i++){
            pot = pot * 10;
        }

        fib[0] = a % pot, fib[1] = b % pot;
        int pos = n % p[m - 1];

        for(int i = 2 ; i <= pos ; i++){
            fib[i] = fib[i - 1] + fib[i - 2];
            fib[i] %= pot;
        }

        cout << fib[pos] << endl;
    }
    
    return 0;
}