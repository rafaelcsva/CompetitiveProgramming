//25, 07, 2018, 13:43:18 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 21;
ull fat[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    fat[0] = 1LL;

    for(ull i = 1 ; i < N ; i++){
        fat[i] = i * fat[i - 1];
    }

    int t;

    cin >> t;

    while(t--){
        string s;

        cin >> s;
        set<char>st(s.begin(), s.end());
        
        ull n;

        cin >> n;
        
        sort(s.begin(), s.end());

        int len = s.length();

        for(int i = 0 ; i < s.length() && n ; i++){
            ll q = n / fat[len - i - 1];

            set<char>::iterator it = st.begin();
            advance(it, q);

            char c = *it;

            for(int j = 0 ; j < s.length() ; j++){
                if(s[j] == c){
                    swap(s[j], s[i]);
                    sort(s.begin() + i + 1, s.end());
                }
            }

            st.erase(it);

            n -= q * fat[len - i - 1];
        }

        cout << s << endl;
    }

    return 0;
}