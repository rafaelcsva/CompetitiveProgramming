//15, 11, 2018, 14:39:01 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;

map< ll, pii > mp;
vector< ll > numbers;
vector< ll > v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll pot = 1LL;

    for(ll i = 1LL ; i <= 9LL ; i++){
        for(ll d = 1LL ; d <= 9LL ; d++){
            numbers.push_back(pot * d);
            // cout << pot * d << endl;
        }

        pot *= 10LL;
    }

    // cout << pot << endl;
    numbers.push_back(pot);
    // cout << numbers.size() << endl;

    for(int i = 0 ; i < numbers.size() ; i++){
        for(int j = 0 ; j < numbers.size() ; j++){
            v.push_back(numbers[i] * numbers[j]);
            mp[numbers[i] * numbers[j]] = {numbers[i], numbers[j]};
        }
    }

    int t;

    cin >> t;

    while(t--){
        ll a, b;

        cin >> a >> b;

        ll prod = a * b;

        bool printed = false;

        for(map< ll, pii >::iterator it = mp.begin() ; it != mp.end() ; it++){
            ll other = prod - it->first;

            if(mp.count(abs(other)) != 0){
                pii ed = it->second;
                pii ot = mp[abs(other)];

                bool signal2 = false;
                bool signal1 = false;

                if(other < 0LL){
                    signal2 = true;
                }

                if(signal1){
                    cout << "-";
                }

                cout << ed.first << " x " << ed.second << " ";

                if(signal2){
                    cout << "- ";
                }else{
                    cout << "+ ";
                }

                cout << ot.first << " x " << ot.second << endl;

                printed = true;
                break;
            }
            
            other = prod + it->first;

            if(mp.count(abs(other)) != 0){
                pii ed = it->second;
                pii ot = mp[abs(other)];

                bool signal2 = false;
                bool signal1 = true;

                if(other < 0LL){
                    signal2 = true;
                }

                if(signal1){
                    cout << "-";
                }

                cout << ed.first << " x " << ed.second << " ";

                if(signal2){
                    cout << "- ";
                }else{
                    cout << "+ ";
                }

                cout << ot.first << " x " << ot.second << endl;

                printed = true;
                break;
            }
        }

        assert(printed);
    }

    return 0;
}