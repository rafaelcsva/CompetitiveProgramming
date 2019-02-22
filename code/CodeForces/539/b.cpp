//16, 02, 2019, 16:14:01 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

set< char > st;

bool is_palindrome(string &s){
    int i = 0, j = int(s.length()) - 1;

    while(i <= j){
        if(s[i] != s[j]){
            return false;
        }

        i++, j--;
    }

    return true;
}

bool cut(int pos, string &s){
    string p1 = s.substr(0, pos + 1);
    string p2 = s.substr(pos + 1);

    string r = p2 + p1;

    if(is_palindrome(r) && r != s){
        return true;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s, t;

    cin >> s;

    int n = s.length();

    for(int i = 0 ; i < n ; i++){
        if((n & 1) && i == (n / 2)){
            continue;
        }

        st.insert(s[i]);

        t.push_back(s[i]);
    }

    if(st.size() == 1 || n == 1){
        cout << "Impossible" << endl;
    }else{
        string p1, p2;

        for(int i = 0 ; i < n ; i++){
            if((n & 1) && i == (n / 2)){
                continue;
            }

            if(i < n / 2){
                p1.push_back(s[i]);
            }else{
                p2.push_back(s[i]);
            }
        }

        string r = p2 + p1;
        
        if(is_palindrome(r) && r != t){
            if(n & 1){
                cout << 2 << endl;
            }else{
                cout << 1 << endl;
            }
        }else{
            bool can2 = false;
            int i = 0, j = int(t.length() - 1);
            string a1, a2;

            while(i <= j){
                a1.push_back(t[i]);
                a2.insert(a2.begin(), t[j]);
                string f = a2 + a1; 
                // cout << a1 << " " << a2 << endl;
                if(is_palindrome(f) && a1 != a2){
                    can2 = true;
                    break;
                }
                i++, j--;
            }

            if(n & 1){
                st.insert(s[n / 2]);

                if(can2){
                    cout << 2 << endl;
                }
                else if(st.size() == 2){
                    cout << 3 << endl;
                }else{
                    cout << 4 << endl;
                }
            }else{
                bool can = false;

                for(int i = 0 ; i < n ; i++){
                    can |= cut(i, t);
                    if(can){
                        // cout << i + 1 << endl;
                        break;
                    }
                }

                if(can){
                    cout << 1 << endl;
                }else{
                    if(can2){
                        cout << 2 << endl;
                    }else{
                        cout << 3 << endl;
                    }
                }
            }
        }
    }

    return 0;
}