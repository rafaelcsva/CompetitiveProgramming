//15, 08, 2018, 09:54:46 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 50;
string s[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> s[i];
    }

    int len = s[0].length();
    int best = 1e9;

    for(int j = 0 ; j < len ; j++){
        int moves = j;
        
        for(int i = 1 ; i < n ; i++){
            bool find = false;
            
            for(int k = 0 ; k < len ; k++){
                bool ok = true;

                for(int f = 0 ; f < len ; f++){
                    int p1 = (f + j) % len;
                    int p2 = (f + k) % len;

                    if(s[0][p1] != s[i][p2]){
                        ok = false;
                        break;
                    }
                }

                if(ok){
                    moves += k;
                    find = true;
                    break;
                }
            }

            if(!find){
                moves = 1e9;
                break;
            }
        }

        best = min(best, moves);
    }

    if(best == 1e9){
        cout << "-1" << endl;
    }else{
        cout << best << endl;
    }

    return 0;
}