//02, 07, 2018, 14:24:35 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = int(1e6);
int mark[N];
int pos[N];
int test = 1;
int z, i, m, l;

int f(int n){
    return (z * n + i) % m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);    

    while(cin >> z >> i >> m >> l){
        if(z == 0){
            break;
        }

        int k = 0;

        while(true){
            if(mark[l] != test){
                mark[l] = test;
                pos[l] = k;
            }

            if(pos[l] != k){
                cout << "Case " << test << ": ";
                cout << k - pos[l] << endl;
                break;
            }

            k++;
            l = f(l);
        }

        test++;
    }

    return 0;
}