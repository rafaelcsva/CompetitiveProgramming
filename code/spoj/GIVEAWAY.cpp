#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int a[N];
int SQ;
vector< int > st[N];

int query(int l, int r, int c){
    int sum = 0;

    for(int i = l ; i <= r ; ){
        if(i % SQ == 0 && (i + SQ - 1) <= r){
            const int block = i / SQ;

            sum += st[block].end() - lower_bound(st[block].begin(),
                                        st[block].end(), c);
            i += SQ;
        }else{
            // printf("%d ", a[i]);
            sum += (a[i] >= c);
            ++i;
        }
    }
    // printf("\n");

    return sum;
}

int main(){
    int n;

    scanf("%d", &n);

    SQ = sqrt(n) + 1;

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);

        st[i / SQ].push_back(a[i]);
    } 

    for(int i = 0 ; i < SQ ; i++){
        sort(st[i].begin(), st[i].end());
    }

    int m;
    // printf("sai!\n");
    scanf("%d", &m);

    while(m--){
        int op, as, b, c;

        scanf("%d %d %d", &op, &as, &b);

        as--;
        b--;

        if(op == 0){
            scanf("%d", &c);

            printf("%d\n", query(as, b, c));
        }else{
            const int old = a[as];
            const int block = as / SQ;
    
            int pos = lower_bound(st[block].begin(), st[block].end(), old)
                - st[block].begin();

            st[block][pos] = b;
            a[as] = b;

            sort(st[block].begin(), st[block].end());
        }
    }
    return 0;
}