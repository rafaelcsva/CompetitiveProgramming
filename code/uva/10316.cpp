//04, 04, 2019, 09:50:49 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

typedef pair< double, double >  pdd;

const int N = 1010;
pdd airport[N];
const double radius = 4000.0;
const double eps = 1e-9;
const double inf = 1e18;
const double PI = acos(-1.0);

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

    int n;

    while(cin >> n){
        for(int i = 0 ; i < n ; i++){
            cin >> airport[i].first >> airport[i].second;
        }

        double best = inf;
        int best_i = -1;

        for(int i = n - 1 ; i >= 0 ; i--){
            double tmp = -1.0;

            for(int j = 0 ; j < n ; j++){
                if(i == j){
                    continue;
                }

                double d = gcDistance(airport[i], airport[j], radius);

                if(d - tmp > eps){
                    tmp = d;
                }
            }

            if(best - tmp > eps){
                best = tmp;
                best_i = i;
            }
        }

        assert(best_i != -1);

        cout << fixed << setprecision(2) << airport[best_i].first << " " << airport[best_i].second << endl;
    }

    return 0;
}