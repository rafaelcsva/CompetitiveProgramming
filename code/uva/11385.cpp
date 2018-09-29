//17, 07, 2018, 10:11:41 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = int(1e6);
map<ll, int>fibonacci;
ll a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    ll first = 1, second = 2;
    fibonacci[first] = 1;
    fibonacci[second] = 2;

    for(int i = 3 ; second <= 1LL << 31LL ; i++){
        ll next = first + second;
        first = second;
        second = next;

        fibonacci[second] = i;
    }

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        int len = 0;

        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
            len = max(len, fibonacci[a[i]]);
        }
        
        string s;

        cin.ignore();
        getline(cin, s);

        string out(len, ' ');

        int j = 0;

        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                if(j < n){
                    out[fibonacci[a[j]] - 1] = s[i];
                    j++;
                }
            }
        }

        cout << out << endl;
    }

    return 0;
}