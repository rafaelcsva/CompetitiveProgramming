//16, 07, 2018, 20:48:58 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

map<string, string>mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    getline(cin, s);

    // cin.ignore();

    string build = "";
    while(true){
        getline(cin, s);

        if(s == "___________"){
            break;
        }

        char c = 0;

        for(int i = s.length() - 2, j = 0 ; i >= 2 ; i--, j++){
            if(s[i] == 'o'){
                c |= 1 << j;
            }else if(s[i] == '.'){
                j--;
            }
        }

        if(c)
            build += c;
    }

    cout << build.substr(0, build.length() - 1) << endl;

    return 0;
}