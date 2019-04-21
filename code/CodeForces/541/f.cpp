//23, 02, 2019, 08:16:22 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e5);
int father[N], pos[N];
int w[N];
vector< pii > v;

pii find(int x){
    if(x == father[x]){
        return {x, 0};
    }

    pii u = find(father[x]);
    pos[x] += u.second;
    father[x] = u.first;

    return {father[x], pos[x]};
}

void join(int u, int v){
    int x = find(u).first;
    int y = find(v).first;

    if(x != y){
        if(x < y){
            father[y] = x;
            pos[y] = w[x];
            w[x] += w[y]; 
        }else{
            father[x] = y;
            pos[x] = w[y];
            w[y] += w[x];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        father[i] = i;
        w[i] = 1;
    }

    for(int i = 1 ; i <= n - 1 ; i++){
        int li, ri;

        cin >> li >> ri;

        join(li, ri);
    }

    for(int i = 1 ; i <= n ; i++){
        v.push_back({find(i).second, i});
        // cout << i << " " << find(i).second << endl;
    }

    sort(v.begin(), v.end());
    
    for(int i = 0 ; i < n ; i++){
        cout << v[i].second << " ";
    }

    cout << endl;

    return 0;
}