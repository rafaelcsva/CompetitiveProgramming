#include <bits/stdc++.h>
 
using namespace std;

typedef pair< int, int >    pii;

const int K = 19;
const int N = int(3e5) + 10;
vector< pii > segtree[N + 10][K + 1];
int aux[N + 10];
int a[N + 10];
const int C = 4;
int llog[N + 10];

vector< pii > merge(vector< pii > a, vector< pii > b){
    for(auto u: a){
        // if(u.second){
        //     printf("%d\n", u.second);
        // }
        aux[u.second] += u.first;
    }

    for(auto u: b){
        // if(u.second){
        //     printf("%d\n", u.second);
        // }
        aux[u.second] += u.first;
    }

    vector< pii > ans;

    for(auto u: a){
        ans.push_back({aux[u.second], u.second});    
    }

    for(auto u: b){
        ans.push_back({aux[u.second], u.second});
    }

    sort(ans.begin(), ans.end());

    auto it = unique(ans.begin(), ans.end());
    ans.resize(distance(ans.begin(), it));

    reverse(ans.begin(), ans.end());

    if(ans.size() > C){
        ans.resize(C);
    }

    for(auto u: a){
        aux[u.second] = 0;
    }

    for(auto u: b){
        aux[u.second] = 0;
    }
    
    assert(ans.size() <= C);
    return ans;
}

void build(){
    for(int i = 0 ; i < N ; i++){
        segtree[i][0] = {{1, a[i]}};
    }

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++){
            segtree[i][j] = merge(segtree[i][j-1], segtree[i + (1 << (j - 1))][j - 1]);
            assert(segtree[i][j].size() <= C);
        }
}

vector< pii > query(int L, int R){
    vector< pii > ve;

    for (int j = K; j >= 0; j--) {
        if ((1 << j) <= R - L + 1) {
            ve = merge(ve, segtree[L][j]);
            L += 1 << j;
        }
    }
    return ve;
}

int main(){
    llog[1] = 0;
    for (int i = 2; i < N; i++)
        llog[i] = llog[i/2] + 1;
        
	int n, q;
	scanf("%d%d", &n, &q);

    for (int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }

    build();
    // printf("builded!\n");

    for (int k = 0; k < q; ++k){
        int l, r;

        scanf("%d %d", &l, &r);

        auto u = query(l, r);

        // for(auto v: u){
        //     printf("%d %d\n", v.first, v.second);
        // }
        int val = u[0].first;

        int x = r - l + 1;

        int half = (x + 1) / 2;
        int cnt = 1;

        if(half < val){
            int rest = x - val;

            val -= (rest + 1);

            cnt += val;
        }

        printf("%d\n", cnt);
    }

	return 0;
}