//17, 07, 2018, 18:03:08 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

map<string, int>mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;

    while(cin >> n >> s){
        int best = 0;
        string bests = "";

        for(int i = 0 ; i <= s.length() - n ; i++){
            string sub = s.substr(i, n);

            mp[sub]++;
            if(mp[sub] > best){
                best = mp[sub];
                bests = sub;
            }
        }

        cout << bests << endl;
        mp.clear();
    }

    return 0;
}