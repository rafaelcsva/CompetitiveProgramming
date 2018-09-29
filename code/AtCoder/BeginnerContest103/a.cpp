//21, 07, 2018, 09:53:29 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int a[3];
vector<int>v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 0 ; i < 3 ; i++){
        cin >> a[i];
    }

    sort(a, a + 3);

    int best = 1e9;

    do{
        int tmp = abs(a[1] - a[0]) + abs(a[2] - a[1]);

        best = min(best, tmp);

    }while(next_permutation(a, a + 3));

    cout << best << endl;
    
    return 0;
}