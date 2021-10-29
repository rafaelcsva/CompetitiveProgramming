#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        string s;
        int n;

        cin >> n;
        cin >> s;

        string ans = "-1";

        for(char a = 'a' ; a <= 'z' ; a++){
            string t = "";
            t.push_back(a);

            if(s.find(t) == string::npos){
                ans = t;
                break;
            }
        }
        if(ans == "-1"){
            for(char a = 'a' ; a <= 'z' ; a++){
                for(char b = 'a' ; b <= 'z' ; b++){
                    string t = "";
                    t.push_back(a);
                    t.push_back(b);

                    if(s.find(t) == string::npos){
                        ans = t;
                        break;
                    }
                }
                if(ans != "-1"){
                    break;
                }
            }

            if(ans == "-1"){
                for(char a = 'a' ; a <= 'z' ; a++){
                    for(char b = 'a' ; b <= 'z' ; b++){
                        for(char c = 'a' ; c <= 'z' ; c++){
                            string t = "";

                            t.push_back(a);
                            t.push_back(b);
                            t.push_back(c);

                            if(s.find(t) == string::npos){
                                ans = t;
                                break;
                            }
                        }
                        if(ans != "-1"){
                            break;
                        }
                    }
                    if(ans != "-1"){
                        break;
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}