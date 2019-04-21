#include <bits/stdc++.h>

using namespace std;

typedef pair< string, int > psi;

const int N = int(1e5 + 10);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    int ts = 1;
    
    cin >> t;

    while(t--){
        string s;
        
        cin >> s;
        
        string number = "";
        string other = "";
        
        for(int i = 0 ; i < s.length() ; i++){
            if(i == 0 && s[i] == '1'){
                other.push_back(s[i]);
                continue;
            }else{
                if(s[i] != '5'){
                    if(s[i] != '0'){
                        other.push_back(s[i] - 1);
                        number.push_back('1');
                    }else{
                        other.push_back('0');
                        if(number.length())
                            number.push_back('0');
                    }
                }else{
                    other.push_back(s[i] - 2);
                    number.push_back('2');
                }
            }
        }
        
        cout << "Case #" << ts++ << ": ";
        
        if(number.length() == 0){
            for(int i = 0 ; i < s.length() - 1 ; i++){
                cout << 9;
            }
            cout <<  " 1" << endl;
        }else{
            cout << other << " " << number << endl;
        }
    }

    return 0;
}