//17, 07, 2018, 12:46:04 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 10100;
int c[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a;

    cin >> n >> a;

    for(int i = 1 ; i <= n ; i++){
        cin >> c[i];
    }

    int lef = a, rig = a;

    int taked = 0;

    while(lef >= 1 || rig <= n){
        if(lef == rig){
            taked += c[lef];
        }else{
            if(lef < 1){
                taked += c[rig];
            }
            else if(rig > n){
                taked += c[lef];
            }else if(c[lef] && c[rig]){
                taked += c[lef] + c[rig];
            }
        }

        lef--, rig++;
    }

    cout << taked << endl;

    return 0;
}