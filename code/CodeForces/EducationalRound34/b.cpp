#include <bits/stdc++.h>

using namespace std;

int main(){
    int h1, a1, c1;
    int h2, a2;

    cin >> h1 >> a1 >> c1;
    cin >> h2 >> a2;

    int phase = 0;

    vector< string > comm;

    while(true){
        phase++;
        if(h2 - a1 <= 0){
            comm.push_back("STRIKE");
            break;
        }
        if(h1 - a2 <= 0){
            comm.push_back("HEAL");
            h1 += c1;
        }else{
            comm.push_back("STRIKE");
            h2 -= a1;
        }
        h1 -= a2;
    }

    cout << comm.size() << "\n";

    for(auto u: comm){
        cout << u << "\n";
    }

    return 0;
}