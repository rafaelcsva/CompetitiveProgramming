//28, 11, 2018, 08:51:57 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 20;
int mark[N];
int test = 1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        for(int i = 1 ; i <= n - 1 ; i++){
            int xi;

            cin >> xi;

            mark[xi] = test;
        }

        for(int i = 1 ; i <= n ; i++){
            if(mark[i] != test){
                cout << i << endl;
                break;
            }
        }

        test++;
    }

    return 0;
}