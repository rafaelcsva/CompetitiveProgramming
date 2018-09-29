//26, 07, 2018, 12:15:03 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 110;
int used[N], qtd[N];
priority_queue<pii>pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        int t;

        cin >> t;

        qtd[t]++;
    }

    if(n > m){
        cout << 0 << endl;
        return 0;
    }

    int days = 100000000;
    for(int j = 0 ; j < n ; j++){
        int best = 0;
        int ans = 0;
        
        for(int i = 1 ; i < N ; i++){
            if(qtd[i]){
                if(qtd[i] / (used[i] + 1) > ans){
                    ans = qtd[i] / (used[i] + 1);
                    best = i;
                }
            }
        }

        used[best]++;
        days = min(days, qtd[best] / used[best]);
    }

    cout << days << endl;

    return 0;
}