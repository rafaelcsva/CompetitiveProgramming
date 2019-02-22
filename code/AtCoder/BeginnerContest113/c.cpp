//04, 11, 2018, 10:07:35 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
vector< pii > cities[N];
pii codes[N];

int get_len(int num){
    int d = 0;

    while(num){
        num /= 10;
        d++;
    }

    return d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    cin >> n >> m;

    for(int i = 0 ; i < m; i++){
        int p, y;

        cin >> p >> y;

        cities[p].push_back({y, i + 1});
    }


    for(int i = 1 ; i <= n ; i++){
        sort(cities[i].begin(), cities[i].end());
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < cities[i].size() ; j++){
            pii u = cities[i][j];

            codes[u.second].first = i;
            codes[u.second].second = j + 1;
        }
    }

    for(int i = 1 ; i <= m ; i++){
        int a = 6 - get_len(codes[i].first);

        while(a){
            printf("0");
            a--;
        }

        printf("%d", codes[i].first);

        a = 6 - get_len(codes[i].second);

        while(a){
            printf("0");
            a--;
        }

        printf("%d\n", codes[i].second);
    }

    return 0;
}