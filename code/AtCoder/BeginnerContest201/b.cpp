#include <bits/stdc++.h>

using namespace std;

typedef pair< int, string > montain;

const int N = 1010;
montain m[N];

int main(){
    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> m[i].second >> m[i].first;
    }

    sort(m, m + n);

    cout << m[n - 2].second << endl;

    return 0;
}