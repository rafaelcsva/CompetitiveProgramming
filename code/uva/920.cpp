//23, 08, 2018, 12:49:57 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 200;
const ld EPS = 0.00000000001L;

struct point{
    ld x, y;
    point(){
        x = y = 0.0L;
    }

    point(ld _x, ld _y) : x(_x), y(_y){}
    
};

point points[N];

// ld hypot(ld x1, ld x2){
//     return sqrt(x1 * x1 + x2 * x2);
// }

ld dist(point &p1, point &p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct line{
    ld a, b, c;
};

void pointsToLine(point p1, point p2, line &l){
    if(fabs(p1.x - p2.x) < EPS){
        l.a = 1.0L;
        l.b = 0.0L;
        l.c = -p1.x;
    }else{
        l.a = (p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0L;
        l.c = (l.a * p1.x) - p1.y;
    }
}

struct vec{
    ld x, y;
    vec(ld _x, ld _y) : x(_x), y(_y){}
};

vec toVec(point a, point b){
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, ld s){
    return vec(v.x * s, v.y * s);
}

point translate(point p, vec v){
    return point(p.x + v.x, p.y + v.y);
}

ld dot(vec a, vec b){
    return (a.x * b.x + a.y * b.y);
}

ld norm_sq(vec v){
    return v.x * v.x + v.y * v.y;
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

    if(u < 0.0L){
        c = point(a.x, a.y);
        return dist(p, a);
    }
    if(u > 1.0){
        c = point(b.x, b.y);
        return dist(p, b);
    }

    return distToLine(p, a, b, c);
}

bool compar(point &a, point &b){
    return b.x - a.x > EPS;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int c;

    scanf("%d", &c);

    while(c--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%Lf %Lf", &points[i].x, &points[i].y);
        }

        ld area = 0.0L;
        
        sort(points, points + n, compar);
        
        for(int i = 0 ; i < n - 1 ; i++){
            point hig(-1, -1);
            if(points[i + 1].y - points[i].y > EPS){
                continue;
            }
            
            for(int j = i + 1 ; j < n ; j++){
                if(points[j].y > hig.y){
                    hig = points[j];
                }
            }        

            line l;
            
            if(hig.y - points[i].y > EPS){
                continue;
            }
            
            pointsToLine(points[i], points[i + 1], l);
            
            hig.x = (-l.c - l.b * hig.y) / l.a;
            hig.x *= -1.0L;
            // printf("(%.2Lf, %.2Lf)x(%.2Lf, %.2Lf) --- (%.2Lf, %.2Lf) %.2Lf %.2Lf %.2Lf +%.2Lf\n", points[i].x, points[i].y, points[i + 1].x, points[i + 1].y, hig.x, hig.y, l.a, l.b, l.c, dist(hig, points[i]));
            area += dist(hig, points[i]);
        }

        printf("%.2Lf\n", area);
    }

    return 0;
}