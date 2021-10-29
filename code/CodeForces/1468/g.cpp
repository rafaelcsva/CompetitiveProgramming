#include <bits/stdc++.h>

using namespace std;

struct point2d {
    double x, y;
    point2d() {}
    point2d(double x, double y): x(x), y(y) {}
    point2d& operator+=(const point2d &t){
        x += t.x;
        y += t.y;
        return *this;
    }

    point2d& operator-=(const point2d &t){
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point2d& operator*=(double t){
        x *= t;
        y *= t;
        return *this;
    }
    point2d& operator/=(double t){
        x /= t;
        y /= t;
        return *this;
    }
    point2d operator+(const point2d &t) const {
        return point2d(*this) += t;
    }
    point2d operator-(const point2d &t) const {
        return point2d(*this) -= t;
    }
    point2d operator*(double t) const {
        return point2d(*this) *= t;
    }
    point2d operator/(double t) const {
        return point2d(*this) /= t;
    }
};

point2d operator*(double a, point2d b){
    return b * a;
}

double cross(point2d a, point2d b){
    return a.x * b.y - a.y * b.x;
}

point2d intersect(point2d a1, point2d d1, point2d a2, point2d d2){
    return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
}


bool ccw(point2d a, point2d b, point2d c){
    return cross(b - a, c - a) <= 0.0;
}

const int N = int(2e5) + 10;
point2d p[N];

double dist(point2d a, point2d b){
    return hypot(a.x - b.x, a.y - b.y);
}

bool equal_coef(point2d a1, point2d a2, point2d b1, point2d b2){
    a1 -= a2;
    b1 -= b2;

    return a1.x * b1.y == a1.y * b1.x; 
}

int main(){
    int n, h;

    // auto test = intersect(point2d(0, 0), point2d(1, 1), point2d(0, 1), point2d(1, 0) - point2d(0, 1));
    
    // printf("%lf, %lf\n", test.x, test.y);

    scanf("%d %d", &n, &h);

    for(int i = 0 ; i < n ; i++){
        scanf("%lf %lf", &p[i].x, &p[i].y);
    }

    point2d eye;
    point2d last = p[n - 1];
    eye.x = p[n - 1].x;
    eye.y = p[n - 1].y + h;

    double ans = 0.0;

    for(int i = n - 2 ; i >= 0 ; i--){
        if(ccw(eye, last, p[i])){    
            auto it = (equal_coef(last, eye, p[i], p[i + 1]))
            ? p[i + 1] : intersect(eye, last - eye, p[i], p[i + 1] - p[i]);
            // printf("it = %lf, %lf\n", it.x, it.y);
            ans += dist(it, p[i]);
            last = p[i];
            // printf("pushs %d\n", i + 1);
        }
    }

    printf("%.8lf\n", ans);

    return 0;
}