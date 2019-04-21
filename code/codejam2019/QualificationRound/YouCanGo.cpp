#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, ts = 1;
    string s;
    
    cin >> t;
    
    while(t--){
        int n;

        cin >> n;
        cin >> s;    
        
        cout << "Case #" << ts++ << ": ";
        
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == 'E'){
                s[i] = 'S';
            }else{
                s[i] = 'E';
            }
        }
        
        cout << s << endl;
    }
    
    return 0;
}