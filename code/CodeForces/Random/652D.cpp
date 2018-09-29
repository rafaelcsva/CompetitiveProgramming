//28, 09, 2018, 17:45:25 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< pii, int >    pipii;
const int N = 7e5;
pipii seg[N];
set< int > stx;
map< int, int > mp;

int BIT[N];
int resp[N];

int LSOne(int x){
    return x & (-x);
}

int query(int x){
    int sum = 0;

    while(x > 0){
        sum += BIT[x];
        x -= LSOne(x);
    }

    return sum;
}

void update(int x, int val){
    while(x < N){
        BIT[x] += val;
        x += LSOne(x);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d %d", &seg[i].first.first, &seg[i].first.second);
        stx.insert(seg[i].first.first), stx.insert(seg[i].first.second);
        seg[i].second = i;
    }

    int id = 1;

    for(set< int >::iterator it = stx.begin() ; it != stx.end() ; it++){
        mp[*it] = id++;
    }

    for(int i = 0 ; i < n ; i++){
        seg[i].first.first = mp[seg[i].first.first];
        seg[i].first.second = mp[seg[i].first.second];
    }

    sort(seg, seg + n);

    for(int i = n - 1 ; i >= 0 ; i--){
        resp[seg[i].second] = query(seg[i].first.second);
        update(seg[i].first.second, 1);
    }

    for(int i = 0 ; i < n ; i++){
        printf("%d\n", resp[i]);
    }

    return 0;
}