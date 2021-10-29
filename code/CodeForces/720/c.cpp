#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int a[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        int mn = 1;

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &a[i]);

            if(a[mn] > a[i]){
                mn = i;
            }
        }

        vector< pair< pair< int, int >, pair< int, int > > > op;

        int add = 1;

        for(int j = mn + 1; j <= n ; j++){
            op.push_back({{mn, j}, {a[mn], a[mn] + add}});
            add++;
        }

        add = 1;
        for(int j = mn - 1 ; j >= 1 ; j--){
            op.push_back({{mn, j}, {a[mn], a[mn] + add}});
            add++;
        }

        printf("%lu\n", op.size());

        for(auto u: op){
            printf("%d %d %d %d\n", u.first.first, u.first.second, u.second.first, u.second.second);
        }
    }

    return 0;
}