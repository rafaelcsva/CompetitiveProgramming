//04, 11, 2018, 10:03:20 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int t, a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;
    
    cin >> t >> a;

    t *= 1000, a *= 1000;

    int best = 1e9, besti = -1;

    for(int i = 0 ; i < n ; i++){
        int x;

        cin >> x;

        int temp = t - x * 6;

        if(abs(temp - a) < best){
            besti = i + 1;
            best = abs(temp - a);
        }
    }    

    cout << besti << endl;

    return 0;
}