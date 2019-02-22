//24, 11, 2018, 06:07:56 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    cin >> t;

    while(t--){
        ll n, m;

        cin >> n >> m;

        ll x1, y1, x2, y2;
        ll x3, y3, x4, y4;

        cin >> x1 >> y1 >> x2 >> y2;

        cin >> x3 >> y3 >> x4 >> y4;

        if(n * m == 1LL){
            cout << 0 << " " << 1 << endl;
            continue;
        }

        ll tot = n * m;
        ll white = tot / 2LL;
        ll black = tot / 2LL;

        if(tot & 1LL){
            white++;
        }

        ll qwhite, qblack;
        ll area1;
        ll xt = max(x1, x3);
        ll yt = max(y1, y3);
        ll xk = min(x2, x4);
        ll yk = min(y2, y4);
        
        if(xt <= xk && yt <= yk){
            // cout << "aqui" << endl;

            ll dx = abs(xt - xk) + 1LL, dy = abs(yt - yk) + 1LL;

            ll area = dx * dy;
            // cout << "area = " << area << endl;

            area1 = (x2 - x1 + 1LL) * (y2 - y1 + 1LL);
    
            if((x1 + y1) & 1LL){
                qblack = (area1 + 1LL) / 2LL;
                qwhite -= (area1) / 2LL;
            }else{
                qblack = (area1) / 2LL;
                qwhite = (area1 + 1LL) / 2LL;
            }

            ll qwhite2, qblack2;
            
            if((xt + yt) & 1LL){
                qwhite2 = (area) / 2LL;
                qblack2 = (area + 1LL) / 2LL;
            }else{
                qwhite2 = (area + 1LL) / 2LL;
                qblack2 = (area) / 2LL;
            }
            // cout <<" ret = " << (qblack - qblack2) << endl;

            black -= (qblack - qblack2);
            white += (qblack - qblack2);
        }else{
            area1 = (x2 - x1 + 1LL) * (y2 - y1 + 1LL);

            if((x1 + y1) & 1LL){
                qblack = (area1 + 1LL) / 2LL;
                qwhite -= (area1) / 2LL;
            }else{
                qblack = (area1) / 2LL;
                qwhite = (area1 + 1LL) / 2LL;
            }

            // cout << "ret = " << qblack << endl;
            black -= (qblack);
            white += qblack;
        }

        ll area2 = (x4 - x3 + 1LL) * (y4 - y3 + 1LL);

        if((x3 + y3) & 1LL){
            black += area2 / 2LL;
            white -= area2 / 2LL;
        }else{
            black += (area2 + 1LL) / 2LL;
            white -= (area2 + 1LL) / 2LL;
        }

        cout << white << " " << black << endl;
    }

    return 0;
}