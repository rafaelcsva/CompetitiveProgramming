//06, 05, 2018, 11:28:53 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
const int N = 110;
ll a[N];

vector<vector<int> >adj;
vector<int>top_sort;
int color = 1;
int cor[N];
int in[N];

void dfs(int x){
    cor[x] = color;
    
    for(int i = 0 ; i < adj[x].size() ; i++){
        int u = adj[x][i];

        if(cor[u] != color){
            dfs(u);
        }
    }

    top_sort.push_back(x);
}

int main(){
    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    adj.resize(n + 1);
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(a[j] % 2LL == 0LL){
                if(a[i] == a[j] / 2LL){
                    in[j]++;
                    adj[i].push_back(j);
                }
            }
            if(a[i] % 3LL == 0LL){
                if(a[i] / 3LL == a[j]){
                    in[j]++;
                    adj[i].push_back(j);
                }
            }
        }
    }
    
    for(int i = 0 ; i < n ; i++){
        if(in[i] == 0){
            dfs(i);
            break;
        }
    }

    for(int i = n - 1 ; i >= 0 ; i--){
        int u = top_sort[i];
        char c = i == 0 ? '\n' : ' ';

        cout << a[u] << c;
    }

    return 0;
}