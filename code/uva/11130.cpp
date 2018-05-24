//28, 04, 2018, 08:30:09 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
ll a, b, v, ang, s;
const ld EPS = 0.0000000001L;

int main(){
    while(cin >> a >> b >> v >> ang >> s){
        if(a == 0)
            break;

        ld x = a / 2.0L, y = b / 2.0L;
        int dir = 1;//1 for up right, 2 for down right, 3 for down left, 4 for up left.
        int cy = 0, cx = 0;

        while(s >= EPS){
            if(dir == 1){
                ld dx = a - x;
                ld dy = b - y;
                lg tg = tan(ang);
                ld diff = tg * dx - dy;

                if(diff > EPS){
                    dx = dy / tg;
                    ld tim = dis / v;

                    if(tim >= s){
                        s -= tim;
                        cy++;
                        ang = 90 - ang;
                    }else{
                        s = -1.0L;
                    }
                }else if(diff == EPS){
                    ld dis = tg * dx;
                    ld tim = dis / v;

                    

                }
                
            }    
        }
    }

    return 0;
}