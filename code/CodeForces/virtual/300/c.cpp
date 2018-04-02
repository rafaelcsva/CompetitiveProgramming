#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 10;
typedef pair<int, int>  pii;
int n, m;
pii p[N];

bool can(int x){
    bool ok = false;

    if(p[0].first != 1){
        int diff = abs(p[0].second - x);

        if(diff <= p[0].first - 1){
            return true;
        }
    }

    for(int i = 0 ; i < m - 1 ; i++){
        int diff1 = abs(p[i].second - x);
        int diff = diff1 + abs(x - p[i + 1].second);

        if(diff <= p[i + 1].first - p[i].first){
            return true;
        }
    }

    if(p[m - 1].first != n){
        int diff = abs(p[m - 1].second - x);

        if(diff <= n - p[m - 1].first){
            return true;
        }
    }

    return false;
}

bool ver(){
    for(int i = 0 ; i < m - 1 ; i++){
        int diff = abs(p[i].second - p[i + 1].second);

        if(diff > p[i + 1].first - p[i].first){
            return false;
        }
    }

    return true;
}

int main (){
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        cin >> p[i].first >> p[i].second;
    }

    if(!ver()){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int ini = p[0].second, end = (int) 1e9;
    int r = p[0].second;

    while(ini <= end){
        int mid = (ini + end) / 2;

        if(can(mid)){
            r = mid;
            ini = mid + 1;
        }else{
            end = mid - 1;
        }
    }

    if(r == -1){
        cout << "IMPOSSIBLE\n";
    }else{
        cout << r << '\n';
    }

    return 0;
}