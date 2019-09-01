#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    string s;
    
    cin >> t;
    
    int test = 1;
    
    while(t--){
        cin >> s;
        
        int r = int(s.length()) - 1;
        int x = 0;
        
        for(int i = 1 ; i < s.length() ; i++){
            if(s[i] == 'B'){
                x++;
            }
        }
        
        cout << "Case #" << test++ << ": ";
        
        if(min((r + 1) / 2, 2) <= x && x < r){
            cout << "Y\n";
        }else{
            cout << "N\n";
        }
    }
    
	return 0;
}