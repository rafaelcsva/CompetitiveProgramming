#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >    pii;
typedef pair< pii, int >    pipii;
const int N = int(2e5 + 10);
pipii qu[N];
vector< int > adj[N];
int in[N], out[N];
int idx[N];
int a[N];
int last[N];
int T = 0;
int resp[N];
int arr[N];
vector< int > carry;
int pt = 0;
int sparse_table[N][20];
int n, m, q;
// int color[N];

void dfs(int u){
    carry.push_back(u);

    if(carry.size() >= n){
        // cout << "aqui " << u << " " << carry[pt] << endl;
        arr[u] = carry[carry.size() - n];
    }
    // cout << "T = " << T << endl;
    assert(in[u] == 0);

	in[u] = T;
	
	for(int v: adj[u]){
		T++;
		dfs(v);
	}	
	
    carry.pop_back();
	out[u] = T;
}

void buildSparseTable(int arr[], int n){
    for(int i = 0 ; i < n ; i++){
        sparse_table[i][0] = arr[i];
        // cout << i << " - " << arr[i] << endl;
    }

    for(int j = 1 ; (1 << j) <= n ; j++){
        for(int i = 0 ; (i + (1 << j) - 1) < n ; i++){
            if(sparse_table[i][j - 1] >= sparse_table[i + (1 << (j - 1))][j - 1]){
                sparse_table[i][j] = sparse_table[i][j - 1];
            }else{
                sparse_table[i][j] = sparse_table[i + (1 << (j - 1))][j - 1];
            }
        }
    }
}

int query(int L, int R){
    int j = (int)log2(R - L + 1);

    return max(sparse_table[L][j], sparse_table[R - (1 << j) + 1][j]);
}

int main(){
    memset(arr, -1, sizeof arr);

    scanf("%d %d %d", &n, &m, &q);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);

        idx[a[i]] = i;
    }

    for(int i = 1 ; i <= m ; i++){
        int pi;

        scanf("%d", &pi);

        int bef = (idx[pi] - 1 + n) % n;

        if(last[a[bef]]){
            adj[last[a[bef]]].push_back(i);
        }

        last[pi] = i;
    }

    for(int i = 1 ; i <= m ; i++){
        if(in[i] == 0){
            T++;
            pt = 0;
            dfs(i);
        }
    }

    buildSparseTable(arr, m + 1);

    for(int i = 0 ; i < q;  i++){
        int li, ri;

        scanf("%d %d", &li, &ri);
        
        int u = query(li, ri);
        
        printf("%d", (u >= li));
    }
    printf("\n");

    return 0;
}