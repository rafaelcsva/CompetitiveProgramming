//17, 07, 2018, 20:42:53 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 30;
int cnt[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a, b;

    while(getline(cin, a)){
        getline(cin, b);

        for(int i = 0 ; i < b.length() ; i++){
            cnt[b[i] - 'a']++;
        }

        vector<char>v;

        for(int i = 0 ; i < a.length() ; i++){
            char c = a[i];

            if(cnt[c - 'a']){
                v.push_back(c);
                cnt[c - 'a']--;
            }
        }

        sort(v.begin(), v.end());

        for(int i = 0 ; i < v.size() ; i++){
            cout << v[i];
        }

        cout << endl;

        memset(cnt, 0, sizeof cnt);
    }

    return 0;
}