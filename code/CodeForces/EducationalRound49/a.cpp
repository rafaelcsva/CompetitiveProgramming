//18, 08, 2018, 11:36:09 Rafaelcs cpp
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

    while(t--){
        int n;

        cin >> n;

        string s;

        cin >> s;
        
        bool flag = true;
        
        for(int i = 0, j = n - 1 ; i < n / 2 ; i++, j--){
            int next_1, prev_1, next_2, prev_2;

            if(s[i] == 'a'){
                prev_1 = -1;
            }else{
                prev_1 = s[i] - 1;
            }

            if(s[j] == 'a'){
                prev_2 = -2;
            }else{
                prev_2 = s[j] - 1;
            }

            if(s[i] == 'z'){
                next_1 = -3;
            }else{
                next_1 = s[i] + 1;
            }

            if(s[j] == 'z'){
                next_2 = -4;
            }else{
                next_2 = s[j] + 1;
            }

            if(next_1 == next_2 || next_1 == prev_2 || prev_1 == prev_2 || prev_1 == next_2){
                continue;
            }else{
                flag = false;
                break;
            }
        }

        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}