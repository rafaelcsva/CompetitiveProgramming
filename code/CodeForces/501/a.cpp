//31, 07, 2018, 12:32:04 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

bool mark[110];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 0 ; i < n ; i++){
        int l, r;

        scanf("%d %d", &l, &r);

        for(int j = l ; j <= r ; j++){
            mark[j] = 1;
        }
    }

    vector< int > v;
    
    for(int i = 1 ; i <= k ; i++){
        if(!mark[i]){
            v.push_back(i);
        }
    }

    printf("%lu\n", v.size());

    for(int u: v){
        printf("%d ", u);
    }

    printf("\n");
    
    return 0;
}