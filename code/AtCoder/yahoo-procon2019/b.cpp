//09, 02, 2019, 10:09:21 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 4;
int deg[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 0 ; i < 3 ; i++){
        int u, v;

        scanf("%d %d", &u, &v);
        u--, v--;

        deg[u]++;
        deg[v]++;
    }

    sort(deg, deg + N);

    if(deg[0] == 1 && deg[1] == 1 && deg[2] == 2 && deg[3] == 2){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    
    return 0;
}