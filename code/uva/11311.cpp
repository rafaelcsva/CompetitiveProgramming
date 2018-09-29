//16, 07, 2018, 10:37:59 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){

        int n, m, r, c;
        cin >> n >> m >> r >> c;

        int left = c, right = m - c - 1;
        int up = r, down = n - r - 1;

        if(left ^ right ^ up ^ down){
            cout << "Gretel" << endl;
        }else{
            cout << "Hansel" << endl;
        }

    }

    return 0;
}