//15, 04, 2019, 12:16:20 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

class OneHandRoadPainting{
    public:
    long long fastest(vector <int> dStart, vector <int> dEnd, int paintPerBrush){
        int j = dEnd.size() - 1;
        ll dist = 0LL;
        ll p = ll(paintPerBrush);
        cout << "p = " << p << endl;

        while(j >= 0){
            ll paint = p;

            dist += 2LL * dEnd[j];

            while(j >= 0 && paint >= dEnd[j] - dStart[j]){
                paint -= (dEnd[j] - dStart[j]);
                j--;
            }

            if(paint && j >= 0){
                dEnd[j] -= paint;
            }
            // cout << j << " ";

            // if(j >= 0){
            //     cout << dEnd[j];
            // }
            // cout << endl;
        }

        return dist;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    OneHandRoadPainting test;

    cout << test.fastest( {1, 10, 20}
,{4, 13, 22}
,2
);
    
    return 0;
}