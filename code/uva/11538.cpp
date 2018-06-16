//12, 06, 2018, 18:34:30 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = int(1e6 + 100);
ll c[N][4], s[N];

void pascal(){
    for(int i = 0 ; i < N ; i++){
        c[i][0] = 1LL;
        if(i < 4){
            c[i][i] = 1LL;
        }
        
        for(int j = 1 ; j < min(i, 3) ; j++){
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

int main(){
    pascal();

    int n, m;

    for(int i = 2 ; i < N ; i++){
        s[i] = c[i][2] + s[i - 1];
    }

    while(scanf("%d %d", &n, &m) != EOF){
        if(n == 0)
            break;

        ll sum = c[m][2] * n + c[n][2] * m;

        ll d = min(n, m);

        ll tmp = c[d][2] * (max(n, m) - d + 1);

        d--;

        if(d){
            tmp += s[d] * 2LL;
        }

        sum += 2LL * tmp;

        cout << sum * 2LL << endl;
    }

    return 0;
}