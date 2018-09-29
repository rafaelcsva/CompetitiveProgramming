//15, 07, 2018, 17:12:04 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 101000;
int a[N], c[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        cin >> c[i];
    }

    for(int i = 0 ; i < m ; i++){
        cin >> a[i];
    }

    int cnt = 0;
    int j = 0;

    for(int i = 0 ; i < n ; i++){
        if(j == m){
            break;
        }

        if(a[j] >= c[i]){
            j++;
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}