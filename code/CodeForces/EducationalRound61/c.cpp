//05, 03, 2019, 12:20:10 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(5e3 + 10);
int cnt[N][N];
int ind[N];
int mark[N];
vector< int > v[N];
pii painters[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;

    scanf("%d %d", &n, &q);
    
    for(int i = 0 ; i < q ; i++){
        scanf("%d %d", &painters[i].first, &painters[i].second);
        
        for(int j = painters[i].first ; j <= painters[i].second ; j++){
            mark[j]++;

            if(mark[j] <= 2){
                v[j].push_back(i);
            }
        }
    }

    int markeds = 0;

    for(int i = 1 ; i <= n ; i++){
        if(mark[i]){
            markeds++;

            if(mark[i] <= 2){
                if(mark[i] == 1){
                    ind[v[i][0]]++;
                }else{
                    cnt[v[i][0]][v[i][1]]++;
                }
            }
        }
    }

    int best = 0;

    for(int i = 0 ; i < q ; i++){
        for(int j = i + 1 ; j < q ; j++){
            int ret = 0;

            ret = ind[i] + ind[j] + cnt[i][j];

            best = max(best, markeds - ret);
        }
    }

    cout << best << endl;

    return 0;
}