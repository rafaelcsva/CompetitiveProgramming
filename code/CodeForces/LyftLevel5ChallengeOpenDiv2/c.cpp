//04, 11, 2018, 16:36:57 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

stack< int > vertical;
stack< int > horizontal;
vector< int > tmp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        int l;

        cin >> l;

        tmp.push_back(l);
    }

    sort(tmp.begin(), tmp.end(), greater< int >());

    vertical.push(int(1e9));

    for(int i = 0 ; i < tmp.size() ; i++){
        vertical.push(tmp[i]);
    }

    tmp.clear();

    for(int i = 0 ; i < m ; i++){
        int x1, x2, y;

        cin >> x1 >> x2 >> y;

        if(x1 == 1){
            tmp.push_back(x2);
        }
    }

    sort(tmp.begin(), tmp.end(), greater< int >());

    for(int i = 0 ; i < tmp.size() ; i++){
        horizontal.push(tmp[i]);
    }

    int best = 1e9;
    int steps1 = 0;

    while(!vertical.empty()){
        int tp = vertical.top();

        while(!horizontal.empty()){
            int u = horizontal.top();

            if(u >= tp){
                break;
            }

            horizontal.pop();
        }

        best = min(best, steps1 + int(horizontal.size()));
        
        steps1++;
        vertical.pop();
    }

    cout << best << endl;
    
    return 0;
}