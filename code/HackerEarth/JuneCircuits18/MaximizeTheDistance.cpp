//17, 06, 2018, 19:08:46 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

priority_queue<pipii>pq;
const int N = int(1e5);
int pai[N];

int find(int x){
    if(pai[x] == x){
        return x;
    }

    return pai[x] = find(pai[x]);
}

bool join(int i, int j){
    int x = find(i), y = find(j);

    if(x != y){
        if(x > y){
            pai[x] = y;
        }else{
            pai[y] = x;
        }

        return true;
    }

    return false;
}

int main(){
    int n, t;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> t;

    for(int i = 1 ; i <= n ; i++){
        pai[i] = i;
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            int x;

            cin >> x;

            if(j > i){
                pq.push({x, {i, j}});
            }
        }
    }

    for(int i = 1 ; i < n ; i++){
        cout << i << ' ' << i + 1 << endl;
    }

    return 0;
}