#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        string s;

        cin >> s;
    
        bool frag = false;

        for(int i = 0 ; i < n ; i++){
            if(i + 1 > n / 2 && s[i] == '0'){
                cout << "1 " << i + 1 << " 1 " << i << "\n";
                frag = true;
                break; 
            }
        }

        if(frag) continue;

        int hf = n / 2;

        int rn = n - 1, ln = (n + 1) / 2;
        int rrn = n - 2, lln = (n + 1) / 2 - 1;

        if(s[lln] == '0'){
            rrn++;
        }

        cout << ln + 1 << " " << rn + 1 << " " << lln + 1 << " " << rrn + 1 << "\n";
    }

    return 0;
}