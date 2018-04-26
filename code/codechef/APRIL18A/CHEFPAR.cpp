//10, 04, 2018, 18:35:30 Rafael de Castro cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main(){
    int n, m, k;
    srand(time(NULL));

    cin >> n >> m >> k;

    for(int i = 0 ; i < n ; i++){
        ll x;

        cin >> x;

        cout << x + rand() % (k + 1) << ' ';
    }

    cout << endl;

    return 0;
}