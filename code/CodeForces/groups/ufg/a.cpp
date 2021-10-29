#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    cin >> n;

    string s;
    int sum = 0;

    cin.ignore();
    while(n--){
        getline(cin, s);
        
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '{'){
                sum++;
            }else if(s[i] == '}'){
                sum--;
            }

            if(sum < 0){
                cout << "N\n";
                return 0;
            }
        }
    }

    if(sum == 0){
        cout << "S\n";
    }else{
        cout << "N\n";
    }

    return 0;
}