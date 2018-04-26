#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const int N = 20;
ld n, s, y;
ld ve[N], d[N], p[N], c[N];
ld EPS = 0.0000000000000000000L;
ld EPSM = -0.0000000000000000000L;
ld MN = 0.000001;

bool the_car_kild_me(ld pos, ld v, ld d, ld c, ld mv, ld w){
    ld my_time = ld(w) / ld(mv);
    
    if(d){
        ld back = pos - c;
        ld aftu = pos + ld(v) * my_time;
        
        if(back <= EPSM && aftu >= EPS || abs(back) < MN || abs(aftu) < MN){
            return true;
        }else{
            return false;
        }
    }else{
        ld back = pos + c;
        ld aftu = pos - ld(v) * my_time;

        if(back >= EPS && aftu <= EPSM || abs(back) < MN || abs(aftu) < MN){
            return true;
        }else{
            return false;
        }
    }
}

ld wait_car(ld pos, ld v, ld d, ld c){
    ld car_time = 0.00L;

    if(d){
        if(pos <= EPSM){
            car_time += ld(-pos) / ld(v);
            pos = 0.00L;
        }

        car_time += ld(c - pos) / ld(v);

        return car_time;
    }else{
        if(pos >= EPS){
            car_time += ld(pos) / ld(v);
            pos = 0.00L;
        }

        car_time += ld(c + pos) / ld(v);

        return car_time;
    }
}

int main (){
    int t;

    cin >> t;

    while(t--){
        cin >> n >> s >> y;

        for (int i = 0 ; i < n ; i++) {
            cin >> ve[i];
        }

        for (int i = 0 ; i < n ; i++) {
            cin >> d[i];
        }

        for (int i = 0 ; i < n ; i++) {
            cin >> p[i];
        }

        for(int i = 0 ; i < n ; i++){
            cin >> c[i];
        }

        ld time = 0.00L;

        for(int i = 0 ; i < n ; i++){
            ld pos = 0.00L;

            if(d[i]){
                pos = ld(p[i]) + ld(ve[i]) * time;
            }else{
                pos = ld(p[i]) - ld(ve[i]) * time;
            }

            if(the_car_kild_me(pos, ve[i], d[i], c[i], s, y)){
                time += wait_car(pos, ve[i], d[i], c[i]);
            }
            time += ld(y) / ld(s);
        }  

        cout << fixed << setprecision(6) << time << endl;
    }

    return 0;
}