#include <bits/stdc++.h>

using namespace std;

const int N = int(510);
typedef pair< int, int >    pii;

typedef pair< int, pii > pipii;
vector< pipii > con;
int k[N];

bool compar(pipii a, pipii b){
    return a.first > b.first;
}

int main(){
    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> k[i];
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1; j < n ; j++){
            con.push_back({abs(k[i] - k[j]), {i + 1, j + 1}});
        }
    }

    sort(con.begin(), con.end(), compar);

    for(auto u: con){
        cout << "? " << u.second.first << " " << u.second.second << endl;

        string ans;

        cin >> ans;

        if(ans == "Yes"){
            cout << "! " << u.second.first << " " << u.second.second << endl;
            return 0;
        }
    }

    cout << "! 0 0" << endl;

    return 0;
}