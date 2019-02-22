//15, 11, 2018, 17:35:12 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5);
bool is_small[N];
int rec[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    scanf("%d", &t);

    while(t--){
        int n, m, k;

        scanf("%d %d %d", &n, &m, &k);

        int last = 0;

        for(int i = 1 ; i <= n ; i++){
            char c;

            scanf("\n%c", &c);

            if(c == 'S'){
                is_small[i] = true;
                last = i;
            }

            rec[i] = last;
        }

        int up_to = k;
        int dumb = 0;

        while(m--){
            char r;
            int num;

            scanf("\n%c", &r);

            if(r == 'W'){
                scanf("%d", &num);
                if(num <= up_to && is_small[num]){
                    dumb++;
                }

                up_to = max(up_to, rec[num]);
            }else{
                up_to = last;
            }
        }

        printf("%d\n", dumb);

        memset(is_small, false, sizeof is_small);
        memset(rec, 0, sizeof rec);
    }

    return 0;
}