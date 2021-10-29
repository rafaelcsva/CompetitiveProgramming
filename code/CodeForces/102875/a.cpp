#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
const int SQN = 333;
vector< int > sq[N];
int perm[SQN][40];
int rev[SQN][40];
int cnt[SQN][40];
int a[N];
int n, p;

void update1(int l, int r, int k){
    int f1 = l / SQN + 1;
    int f2 = r / SQN - 1;

    for(int d = f1 ; d <= f2 ; d++){
        int tmp_p[40];
        int cnt_p[40];

        for(int j = 0 ; j < p ; j++){
            int r = (j + k) % p;

            tmp_p[j] = r;
            cnt_p[j] = cnt[d][r];
        }

        for(int j = 0 ; j < p ; j++){
            perm[d][j] = tmp_p[perm[d][j]];
            rev[perm[d][j]] = j;
            cnt[d][j] = cnt_p[j];
        }
    }

    while(l % SQN && l <= r){
        int p = l % SQN;

        sq[f1 - 1][p] = ;
        l++;
    }
}

int main(){

    scanf("%d %d", &n, &p);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
        a[i] %= p;
        int pos = i / SQN;
        cnt[pos][a[i]]++;
    }

    for(int i = 0 ; i < SQN ; i++){
        for(int j = 0 ; j < 40 ; j++){
            perm[i][j] = j;
            rev[i][j] = j;
        }
    }

    int q;

    scanf("%d", &q);

    while(q--){
        int t, l, r, k;

        scanf("%d %d %d %d", &t, &l, &r, &k);

        if(t == 1){
            update1(l, r, k);
        }
    }

    return 0;
}
