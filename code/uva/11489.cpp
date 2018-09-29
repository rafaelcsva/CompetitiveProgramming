//16, 07, 2018, 10:50:06 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    for(int i = 0 ; i < t;  i++){
        string s;

        cin >> s;

        int sum = 0;
        int n = s.length();

        int digits = 0;
        
        for(int j = 0 ; j < n ; j++){
            sum += int(s[j] - '0');

            if(s[j] == '3' || s[j] == '6' || s[j] == '9'){
                digits++;
            }
        }

        bool can = false;

        for(int j = 0 ; j < n ; j++){
            int d = int(s[j] - '0');

            if((sum - d) % 3 == 0){
                can = true;
            }
        }

        if(sum % 3 != 0){
            digits++;
        }

        if(digits == n - 1){
            digits++;
        }

        cout << "Case " << i + 1 << ": ";

        if((digits & 1) && can){
            cout << "S" << endl;
        }else{
            cout << "T" << endl;
        }
    }

    return 0;
}