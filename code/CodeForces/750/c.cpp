#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        cin >> n;
        string s;

        cin >> s;

        int ans = int(1e9);

        for(char a = 'a' ; a <= 'z' ; a++){
            int i = 0, j = n - 1;
            int tmp = 0;
            bool frag = true;

            while(i <= j){
                if(s[i] == s[j]){
                    i++, j--;
                }else{
                    if(s[i] == a){
                        i++;
                        tmp++;
                    }else if(s[j] == a){
                        j--;
                        tmp++;
                    }else{
                        frag = false;
                        break;
                    }
                }
            }

            if(frag){
                ans = min(ans, tmp);
            }
        }


        cout << (ans == int(1e9) ? -1 : ans) << "\n";
    }

    return 0;
}