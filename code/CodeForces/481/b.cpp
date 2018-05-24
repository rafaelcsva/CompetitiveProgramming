//13, 05, 2018, 06:10:00 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int main(){
    string s;
    int n;

    cin >> n;
    cin >> s;

    int cnt = 0;
    int rmv = 0;

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == 'x'){
            if(cnt == 2){
                rmv++;
            }else{
                cnt++;
            }
        }else{
            cnt = 0;
        }
    }

    cout << rmv << endl;

    return 0;
}