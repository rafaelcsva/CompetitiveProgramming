#include <bits/stdc++.h>

using namespace std;

int clas(char c){
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        return 1;
    }

    return 2;
}

int main(){
    int t;

    cin >> t;

    for(int test = 1 ; test <= t ; test++){
        string s;

        cin >> s;

        int ans = int(1e9);

        for(char a = 'A' ; a <= 'Z' ; a++){
            int tmp = 0;

            for(int i = 0 ; i < s.length() ; i++){
                if(s[i] == a) continue;

                if(clas(s[i]) == clas(a)){
                    tmp += 2;
                }else{
                    tmp++;
                }
            }

            ans = min(ans, tmp);
        }

        printf("Case #%d: %d\n", test, ans);
    }

    return 0;
}