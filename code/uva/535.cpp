//04, 04, 2019, 09:26:45 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

typedef pair< double, double > pdd;

map< string, pdd >mp;
const double PI = acos(-1.0);
const double radius = 6378.0;

double gcDistance(pdd &p, pdd &q, double radius) {
    double pLat = p.first, pLong = p.second;
    double qLat = q.first, qLong = q.second;

    pLat *= PI / 180.0; pLong *= PI / 180.0;
    // convert degree to radian
    qLat *= PI / 180.0; qLong *= PI / 180.0;
    return radius * acos(cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) +
    cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) +
    sin(pLat)*sin(qLat)); 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string st;

    while(cin >> st){
        double lat, log;

        if(st != "#"){
            cin >> lat >> log;

            mp[st] = {lat, log};

            while(cin >> st){
                if(st == "#"){
                    break;
                }

                cin >> lat >> log;

                mp[st] = {lat, log};
            }
        }

        string a, b;

        while(cin >> a >> b){
            if(a == "#" && b == "#"){
                break;
            }

            cout << a << " - " << b << endl;

            if(mp.count(a) == 0 || mp.count(b) == 0){
                cout << "Unknown" << endl;
                continue;
            }

            ll d = ll(round(gcDistance(mp[a], mp[b], radius)));

            if(d < 0){
                d = 0LL;
            }
            cout << d << " km" << endl;
        }

        mp.clear();
    }

    return 0;
}