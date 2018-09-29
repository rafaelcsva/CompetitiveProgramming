//19, 07, 2018, 18:10:27 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;


int a, b;
int BLOCK = 10;
const int ITERACTIONS = 100;
int debug;

ld area(ld height){
    ld t = sqrt(a * a - height * height);

    if(debug){
        cout << height << ' ' << t << endl;
    }
    
    return (height * (t + 2.0L * b)) / 2.0L;
}

const ld EPS = 0.000000000001L;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d%d", &a, &b);

    ld mn = 0, mx = a;

    for(int i = 0 ; i < ITERACTIONS ; i++){
        ld mid1 = (2.0L * mn + mx) / 3.0L;
        ld mid2 = (mn + 2.0L * mx) / 3.0L;
        cout << area(mid1) << ' ' << area(mid2) << endl;

        if((area(mid1) - area(mid2)) < EPS){
            mn = mid1;
        }else{
            mx = mid2;
        }
    }

    debug = 1;
    printf("%Lf %Lf %Lf\n", area(1.96995), mn, mx);

    return 0;
}