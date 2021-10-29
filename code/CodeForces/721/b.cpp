#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        int q0 = 0;
        int movbob = 0;
        int n;
        string s;

        cin >> n >> s;

        for(int i = 0, j = n - 1 ; i <= j ; i++, j--){
            if(s[i] == s[j] && s[i] == '0'){
                q0++;
                if(j != i){
                    q0++;
                }
            }else if(s[i] != s[j]){
                movbob++;
            }
        }

        int p = 0;
        int movalice = 0;

        // if((movbob & 1) && (q0 & 1) == 0){
        //     q0++;
        //     movbob--;
        // }
        if(q0 == 1){
            movalice = 1;
        }else if(q0 & 1){
            movalice = q0 / 2;
            movbob += q0 / 2 + 1;
        }else if(q0){
            if(movbob >= 1){
                movbob--;
                movalice++;
                movalice += (q0 - 2) / 2;
                movbob = (q0 - 2) / 2 + 2;
            }else{
                movalice = (q0 - 2) / 2 + 2;
                movbob += (q0 - 2) / 2;
            }
        }

        // cout << movalice << " " << movbob << endl;

        if(movalice > movbob){
            cout << "BOB\n";
        }else if(movalice < movbob){
            cout << "ALICE\n";
        }else{
            cout << "DRAW\n";
        }
    }

    return 0;
}