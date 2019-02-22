//29, 09, 2018, 09:01:21 Rafaelcs cpp
#include <bits/stdc++.h>
    
using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
    
const int N = int(3e5);
int a[N];
int cnt[N][2];
vector< pii > v1, v0;
int n;
    
bool equal(){
    int x = a[0];
    
    for(int i = 1 ; i < n ; i++){
        if(a[i] != x){
            return false;
        }
    }
    
    return true;
}
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    scanf("%d", &n);
    
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
    
        cnt[a[i]][i % 2]++;
    }
    
    if(equal()){
        printf("%d\n", n / 2);
        return 0;
    }
    
    for(int i = 1 ; i <= N - 100 ; i++){
        if(cnt[i][1]){
            v1.push_back({cnt[i][1], i});
        }
    
        if(cnt[i][0]){
            v0.push_back({cnt[i][0], i});
        }
    }
    
    sort(v0.begin(), v0.end(), greater< pii >());
    sort(v1.begin(), v1.end(), greater< pii >());
    
    int best = 1e9;
    
    for(int i = 0 ; i < min(int(v1.size()), 1000) ; i++){
        for(int j = 0 ; j < min(int(v0.size()), 1000) ; j++){
            if(v0[j].second != v1[i].second){
                best = min(best, n - v0[j].first - v1[i].first);
            }
        }
    }
    
    printf("%d\n", best);
    
    return 0;
}