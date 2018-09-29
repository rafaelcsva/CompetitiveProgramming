//31, 08, 2018, 17:41:58 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const ld EPS = 1e-5;
ld PI = 2.0L * acos(0.0L);

struct point{
    ld x, y;

    bool operator == (point other) const{
        return fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS);
    }
};

struct vec{
    ld x, y;
    vec(ld _x, ld _y) : x(_x), y(_y){}
};

ld dist(point a, point b){
    return hypot(a.x - b.x, a.y - b.y);
}

ld dot(vec a, vec b){
    return (a.x * b.x + a.y * b.y);
}

ld norm_sq(vec v){
    return v.x * v.x + v.y * v.y;
}

vec toVec(point a, point b){
    return vec(b.x - a.x, b.y - a.y);
}

ld RAD_to_DEG(ld theta){
    return theta * 180.0L / PI;
}

ld DEG_to_RAD(ld theta){
    return theta * PI / 180.0L;
}

// rotate p by theta degrees CCW w.r.t origin (0, 0)
point rotate(point p, ld theta) {
  ld rad = DEG_to_RAD(theta);    // multiply theta with PI / 180.0
  return point{p.x * cos(rad) - p.y * sin(rad),
               p.x * sin(rad) + p.y * cos(rad)}; }
               
point translate(point p, vec v){
    return {p.x + v.x, p.y + v.y};
}

vec scale(vec v, ld s){
    return {v.x * s, v.y * s};
}

ld distToLine(point p, point a, point b, point &c){
    vec ap = toVec(a, p), ab = toVec(a, b);
    ld u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    
    return dist(p, c);
}

ld distToLineSegment(point p, point a, point b, point &c){
    vec ap = toVec(a, p), ab = toVec(a, b);
    ld u = dot(ap, ab) / norm_sq(ab);
    
    if(u < 0.0){
        c = {a.x, a.y};
        return dist(p, a);
    }
    if(u > 1.0){
        c = point{b.x, b.y};
        return dist(p, b);
    }

    return distToLine(p, a, b, c);
}

ld cross(vec a, vec b){
    return a.x * b.y - a.y * b.x;
}

bool ccw(point p, point q, point r){
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

bool collinear(point p, point q, point r){
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

point pivot;

bool angleCmp(point a, point b){
    if(collinear(pivot, a, b)){
        return dist(pivot, a) < dist(pivot, b);
    }

    ld d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    ld d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector< point > CH(vector<point> P){
    int i, j, n = (int)P.size();
    if(n <= 3){
        if(!(P[0] == P[n - 1])) P.push_back(P[0]);
        return P;
    }

    int P0 = 0;

    for(i = 1 ; i < n ; i++){
        if(P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x)){
            P0 = i;
        }
    }

    point tmp = P[0]; P[0] = P[P0]; P[P0] = tmp;

    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);

    vector<point>S;
    S.push_back(P[n - 1]); S.push_back(P[0]); S.push_back(P[1]);
    i = 2;

    while(i < n){
        j = int(S.size() - 1);

        bool b = ccw(S[j - 1], S[j], P[i]) ;

        if(b){
            S.push_back(P[i++]);
        }else{
            S.pop_back();
        }
    }

    return S;
}

vector< point > P;

void print(vector< point > P){
    for(int i = 0 ; i < P.size() ; i++){
        printf("%.2Lf %.2Lf\n", P[i].x, P[i].y);
    }
}

ld adjust(ld num){
    // ll rest = num * 1000LL;
    // if(rest % 10LL){
    //     rest += 10LL - rest % 10LL;
    // }
    
    // num = rest / 1000.0L;
    
    return num;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int test = 1;

    while(scanf("%d", &n) != EOF){
        if(n == 0)
            break;

        ld x, y;

        for(int i = 0 ; i < n ; i++){
            scanf("%Lf %Lf", &x, &y);

            P.push_back({x, y});
        }

        P = CH(P);

        ld best = 1e9;

        if(P.size() <= 3){
            best = 0.0L;
        }
        // print(P);
        // printf("eu tenho %lu pontos!\n", P.size());

        for(int i = 0 ; i < int(P.size() - 1) ; i++){
            ld tmp = 1e9;

            for(int j = 0 ; j < P.size() ; j++){
                if(j != i && j != i + 1){
                    point c;

                    distToLineSegment(P[j], P[i], P[i + 1], c);
                    // printf("%.2Lf %.2Lf\n", c.x, c.y);
                    vec u(-c.x, -c.y);

                    ld theta;

                    if(c.x < P[j].x){
                        if(c.y > P[j].y){
                            theta = atan2(c.y - P[j].y, P[j].x - c.x);
                        }else{
                            theta = -atan2(P[j].y - c.y, P[j].x - c.x);
                        }
                    }else{
                        if(c.y > P[j].y){
                            theta = -atan2(c.y - P[j].y, c.x - P[j].x);
                        }else{
                            theta = atan2(P[j].y - c.y, c.x - P[j].x);
                        }
                    }
                    
                    theta = RAD_to_DEG(theta);
                    // printf("theta = %.2Lf\n", theta);
                    ld mnx = 1e9, mxx = -1e9;

                    for(int k = 0 ; k < P.size() ; k++){
                        point d = P[k];

                        d = translate(d, u);

                        d = rotate(d, theta);

                        if(mnx - d.x > EPS){
                            mnx = d.x;
                        }

                        if(d.x - mxx > EPS){
                            mxx = d.x;
                        }
                    }

                    ld dis = dist(c, P[j]);
                    ld ot = mxx - mnx;

                    if(dis - ot > -EPS){
                        // printf("ok\n");
                        if(tmp - dis > EPS){
                            tmp = dis;
                        }
                    }else{
                        // printf("not ok %.2Lf %.2Lf(%.2Lf, %.20Lf)\n", dis, ot, mxx, mnx);
                    }
                }
            }

            if(best - tmp > EPS){
                best = tmp;
            }
        }

        printf("Case %d: %.2Lf\n", test++, best);

        P.clear();
    }

    return 0;
}