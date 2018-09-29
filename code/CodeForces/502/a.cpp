//08, 08, 2018, 11:06:07 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

vector< pii > ranks;

bool compar(pii a, pii b){
    if(a.first > b.first){
        return true;
    }

    if(a.first < b.first){
        return false;
    }

    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        int sum = 0;
        
        for(int j = 0 ; j < 4 ; j++){
            int x;

            scanf("%d", &x);

            sum += x;
        }

        ranks.push_back({sum, i});
    }

    sort(ranks.begin(), ranks.end(), compar);

    for(int i = 0 ; i < n ; i++){
        if(ranks[i].second == 0){
            printf("%d\n", i + 1);
            return 0;
        }
    }
    
    return 0;
}