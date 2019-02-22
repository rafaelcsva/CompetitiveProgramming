//03, 02, 2019, 16:49:19 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef unsigned long long ull;

const int D = 4;
const ll bound = ll(1e9);
pii qu[D] = {{0, 0}, {bound, 0}, {bound, bound}, {0, bound}};
vector< ll > queries_answers;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        for(int i = 0 ; i < D ; i++){
            cout << "Q " << qu[i].first << " " << qu[i].second << endl;

            ll x;

            cin >> x;

            queries_answers.push_back(x);
        }

        ll middle = (bound - queries_answers[D - 1] + queries_answers[0]) >> 1LL;

        ll x;

        cout << "Q 0 " << middle << endl;

        cin >> x;

        cout << "A " << x << " " << queries_answers[0] - x << " " 
            << bound - (queries_answers[1] - queries_answers[0] + x) 
                << " " << bound - (queries_answers[2] - queries_answers[1] + queries_answers[0] - x) << endl;

        int resp;

        cin >> resp;

        assert(resp == 1);
        
        queries_answers.clear();
    }

    return 0;
}