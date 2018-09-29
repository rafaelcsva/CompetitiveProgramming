//07, 09, 2018, 10:10:20 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 30;
vector< int > v;
map< vector< int > , int > cnt;
int a[N], b[N];
int n;

void solve(int p){
    if(p == n){
        cnt[v]++;
        return;
    }

    for(int i = 0 ; i < n ; i++){
        swap(v[i], v[p]);
        solve(p + 1);

        swap(v[i], v[p]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    scanf("%d", &n);

    // for(int i = 1 ; i <= n ; i++){
    //     v.push_back(i);
    // }

    // solve(0);
    
    // vector< int > best, worst;
    // int ans = 0, ans2 = 1e9;
    
    // for(map< vector< int >, int >::iterator it = cnt.begin() ; it != cnt.end() ; it++){
    //     printf("a sequencia: ");
    //     if(it->second > ans){
    //         ans = it->second;
    //         best = it->first;
    //     }
    //     if(it->second < ans2){
    //         ans2 = it->second;
    //         worst = it->first;
    //     }
    //     for(int i = 0 ; i < (it->first).size() ; i++){
    //         printf("%d ", (it->first)[i]);
    //     }
    //     printf("apareceu %d vezes!\n", it->second);
    // }

    // printf("a sequencia: ");
    // for(int i = 0 ; i < best.size() ; i++){
    //     printf("%d ", best[i]);
    // }
    // printf("apareceu %d vezes!\n", ans);

    // printf("a sequencia: ");
    // for(int i = 0 ; i < worst.size() ; i++){
    //     printf("%d ", worst[i]);
    // }
    // printf("apareceu %d vezes!\n", ans2);
    
    if(n == 1){
        printf("1\n1\n");
        return 0;
    }

    if(n == 2){
        printf("1 2\n1 2\n");
        return 0;
    }

    int num = n;
    
    for(int i = n - 1 ; i > n / 2 ; i--){
        a[i] = num;
        num--;
    }
    a[n] = num--;
    
    for(int i = n / 2 - 1; i >= 1 ; i--){
        a[i] = num--;
    }
    a[n / 2] = num;

    b[1] = n;
    num = 1;

    for(int i = 2 ; i <= n ; i++){
        b[i] = num++;
    }
    
    for(int i = 1 ; i <= n ; i++){
        char c = i == n ? '\n' : ' ';
        printf("%d%c", a[i], c);
    }

    for(int i = 1 ; i <= n ; i++){
        char c = i == n ? '\n' : ' ';
        printf("%d%c", b[i], c);
    }

    return 0;
}