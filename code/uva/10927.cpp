//23, 08, 2018, 19:40:56 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
typedef struct{
    int x, y, z;
}Point;

Point points[N];
set< int > idx;
vector< pii > slots;
map<int, int> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    while(scanf("%d", &n) != EOF){
        if(n == 0){
            break;
        }

        for(int i = 0 ; i < n ; i++){
            scanf("%d %d %d", &points[i].x, &points[i].y, &points[i].z);
            idx.insert(points[i].x);
        }

        int id = 1;

        for(set< int >::iterator it = idx.begin() ; it != idx.end() ; it++){
            mp[*it] = id++;
        }

        for(int i = 0 ; i < n ; i++){
            slots[mp[points[i].x]].push_back({points[i].y, points[i].z});
        }

        
    }
    return 0;
}