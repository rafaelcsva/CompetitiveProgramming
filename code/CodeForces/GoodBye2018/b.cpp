//30, 12, 2018, 12:43:53 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;
pii p[N], b[N];
map< pii, int > cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> p[i].first >> p[i].second;
    }

    for(int i = 0 ; i < n ; i++){
        cin >> b[i].first >> b[i].second;
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            int x = b[j].first + p[i].first;
            int y = b[j].second + p[i].second;

            cnt[{x, y}]++;

            if(cnt[{x, y}] == n){
                cout << x << " " << y << endl;
                return 0;
            }
        }
    }

    return 0;
}