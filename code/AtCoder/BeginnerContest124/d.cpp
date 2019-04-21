//13, 04, 2019, 09:10:51 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5;
pii v[N];
int w[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    string s;

    cin >> n >> k;
    k--;
    cin >> s;

    int carry = 0;
    int idx = 1;
    int id = 1;

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '1' && carry < 0){
            v[id++] = {abs(carry), max(1, idx - 1)};
            carry = 0;
        }else if(s[i] == '0' && carry > 0){
            w[idx++] = carry;
            carry = 0;
        }

        if(s[i] == '1'){
            carry++;
        }else{
            carry--;
        }
    }

    if(carry > 0){
        w[idx++] = carry;
    }else if(carry < 0){
        v[id++] = {abs(carry), idx - 1};
    }

    for(int i = 1 ; i <= idx ; i++){
        w[i] += w[i - 1];
    }

    for(int i = 1 ; i <= id ; i++){
        v[i].first += v[i - 1].first;
    }

    int best = 0;

    if(id == 1){
        cout << w[1] << endl;
        // cout << "aqui" << endl;
    }else{
        // cout << id << endl;
        for(int i = 1 ; i < id ; i++){
            // cout << "log = " << v[i].second << endl;
            // cout << v[i].first << " -> " ;

            if(i + k >= id){
                // cout << v[id].first << " y " << endl;
                best = max(best, v[id].first - v[i - 1].first + w[v[id - 1].second + 1] - w[v[i].second - 1]);
            }else{

                // cout << v[i + k].first << " x " << endl;
                best = max(best, v[i + k].first - v[i - 1].first + w[v[i + k].second + 1] - w[v[i].second - 1]);
            }

            // break;
        }

        cout << best << endl;
    }
    
    return 0;
}