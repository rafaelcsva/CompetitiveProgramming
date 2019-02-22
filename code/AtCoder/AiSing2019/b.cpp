//12, 01, 2019, 10:04:12 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    int a, b;

    cin >> a >> b;

    int qa = 0, qab = 0, qb = 0;

    for(int i = 0 ; i < n ; i++){
        int ci;

        cin >> ci;

        if(ci <= a){
            qa++;
        }else if(ci > b){
            qb++;
        }else{
            qab++;
        }
    }
    
    cout << min({qa, qb, qab}) << endl;
    
    return 0;
}