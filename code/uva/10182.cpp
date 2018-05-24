//11, 05, 2018, 23:32:57 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
vector<pii>pattern;
vector<pii>r;
const int N = 100010;

int main(){
    pattern.push_back({-1, 0});
    pattern.push_back({0, -1});
    pattern.push_back({1, -1});
    pattern.push_back({1, 0});
    pattern.push_back({0, 1});
    pattern.push_back({0, 1});
    pattern.push_back({-1, 1});
    
    int i = 0;
    r.push_back({0, 0});
    
    int ii = 0, ij = 1;

    while(r.size() < N){
        for(int k = 0 ; k < pattern.size() ; k++){
            for(int j = 0 ; j < 1 + i ; j++){
                r.push_back({ii, ij});

                ii += pattern[k].first;
                ij += pattern[k].second;
            }
        }

        i++;
    }
        
    int n;

    while(cin >> n){
        n--;
        cout << r[n].first << ' ' << r[n].second << endl;
    }
    
    return 0;
}