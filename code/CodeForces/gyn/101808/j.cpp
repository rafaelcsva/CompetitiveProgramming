#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

struct p_info{
    int l, r, p, d;

    void advance(){
        if(p == l){
            d = 1;
        }else if(p == r){
            d = 0;
        }

        int inc = 0;

        if(d){
            inc = 1;
        }else{
            inc = -1;
        }

        p += inc;
    }
};

p_info p[2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        for(int i = 0 ; i < 2 ; i++){
            scanf("%d %d %d %d", &p[i].l, &p[i].r, &p[i].p, &p[i].d);
        }

        int k;

        scanf("%d", &k);

        int cnt = 0;
        
        while(k--){
            p[0].advance();
            p[1].advance();

            if(p[0].p == p[1].p){
                cnt++;
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}