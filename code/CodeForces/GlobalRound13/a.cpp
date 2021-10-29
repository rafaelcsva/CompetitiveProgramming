#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int a[N];
int cnt[2];

int main(){
    int n, q;

    scanf("%d %d", &n, &q);

    for(int i = 0 ; i < n ; i++) scanf("%d", &a[i]), cnt[a[i]]++;

    while(q--){
        int t, p;

        scanf("%d %d", &t, &p);

        if(t == 1){
            p--;

            cnt[a[p]]--;
            a[p] = !a[p];
            cnt[a[p]]++;
        }else{
            printf("%d\n", cnt[1] >= p);
        }
    }

    return 0;
}