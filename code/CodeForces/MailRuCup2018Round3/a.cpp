//25, 11, 2018, 14:37:32 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 110;
int cnt[N + 10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int ti;

        cin >> ti;

        for(int j = 0 ; j < ti ; j++){
            int xi;

            cin >> xi;

            cnt[xi]++;
        }
    }

    for(int i = 1 ; i <= N ; i++){
        if(cnt[i] == n){
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}