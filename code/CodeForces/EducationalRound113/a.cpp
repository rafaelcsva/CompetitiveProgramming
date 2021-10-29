#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        int n;
        string s;
    
        bool frag = false;
        cin >> n >> s;
        
        for(int i = 0 ; i < n ; i++){
            int tmp = 0;

            for(int j = i ; j < n ; j++){
                if(s[j] == 'a'){
                    tmp++;
                }else{
                    tmp--;
                }

                if(tmp == 0){
                    cout << i + 1 << " " << j + 1 << "\n";
                    frag = true;
                    break;
                }
            }
            if(frag){
                break;
            }
        }
        if(!frag){
            cout << "-1 -1\n";
        }
    }

    return 0;
}