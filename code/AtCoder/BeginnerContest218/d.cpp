#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
int x[N], y[N];
map< pair< int, int >, bool > mp;

int main(){
    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> x[i] >> y[i];
    
        mp[{x[i], y[i]}] = true;
    }

    int ans = 0;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(x[i] < x[j] && y[i] < y[j]){
                if(mp[{x[i], y[j]}] && mp[{x[j], y[i]}]){
                    ans++;
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}