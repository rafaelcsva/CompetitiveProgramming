//13, 10, 2018, 09:37:06 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
ll a[N];
int p[N];
int cnt[N];
int d[N][20];
int aux[N];
int n;
bool mark[N];

void gen(){
    memset(mark, false, sizeof mark);
    memset(aux, 0, sizeof aux);

    for(int i = 0 ; i < n ; i++){
        int t = p[i];

        while(t >= 0 && !mark[t]){
            cnt[t]++;
            aux[t]++;
            t--;
        }

        t = p[i] + 1;

        while(t < n && !mark[t]){
            cnt[t]++;
            aux[t]++;
            t++;
        }

        mark[p[i]] = true;
    }

    for(int i = 0 ; i < n ; i++){
        d[i][aux[i]]++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];

        p[i] = i;
    }

    cout << "aqui !" << endl;

    // int t = 0;
    do{
        // t++;
        gen();
    }while(next_permutation(p, p + n));
    // cout << t << " permutacoes " << endl;

    for(int i = 0 ; i < n ; i++){
        cout << cnt[i] << " -> " ;

        for(int j = 1 ; j <= n ; j++){
            cout << d[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;

    return 0;
}