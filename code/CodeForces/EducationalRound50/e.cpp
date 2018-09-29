#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))

typedef long long   ll;
typedef pair< int, int > pii;

double DEG_to_RAD(double d) { return d * PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / PI; }

// struct point_i { int x, y; };    // basic raw form, minimalist mode
struct point_i { int x, y;     // whenever possible, work with point_i
  point_i() { x = y = 0; }                      // default constructor
  point_i(int _x, int _y) : x(_x), y(_y) {} };         // user-defined

struct point { double x, y;   // only used if more precision is needed
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
  bool operator < (point other) const { // override less than operator
    if (fabs(x - other.x) > EPS)                 // useful for sorting
      return x < other.x;          // first criteria , by x-coordinate
    return y < other.y; }          // second criteria, by y-coordinate
  // use EPS (1e-9) when testing equality of two floating points
  bool operator == (point other) const {
   return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };

double dist(point p1, point p2) {                // Euclidean distance
                      // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
  return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double

// rotate p by theta degrees CCW w.r.t origin (0, 0)
point rotate(point p, double theta) {
  double rad = DEG_to_RAD(theta);    // multiply theta with PI / 180.0
  return point(p.x * cos(rad) - p.y * sin(rad),
               p.x * sin(rad) + p.y * cos(rad)); }

struct line { double a, b, c; };          // a way to represent a line

// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
  if (fabs(p1.x - p2.x) < EPS) {              // vertical line is fine
    l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;           // default values
  } else {
    l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
    l.c = -(double)(l.a * p1.x) - p1.y;
} }

// not needed since we will use the more robust form: ax + by + c = 0 (see above)
struct line2 { double m, c; };      // another way to represent a line

int pointsToLine2(point p1, point p2, line2 &l) {
 if (abs(p1.x - p2.x) < EPS) {          // special case: vertical line
   l.m = INF;                    // l contains m = INF and c = x_value
   l.c = p1.x;                  // to denote vertical line x = x_value
   return 0;   // we need this return variable to differentiate result
 }
 else {
   l.m = (double)(p1.y - p2.y) / (p1.x - p2.x);
   l.c = p1.y - l.m * p1.x;
   return 1;     // l contains m and c of the line equation y = mx + c
} }

bool areParallel(line l1, line l2) {       // check coefficients a & b
  return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }

bool areSame(line l1, line l2) {           // also check coefficient c
  return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); }

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
  if (areParallel(l1, l2)) return false;            // no intersection
  // solve system of 2 linear algebraic equations with 2 unknowns
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  // special case: test for vertical line to avoid division by zero
  if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
  else                  p.y = -(l2.a * p.x + l2.c);
  return true; }

point lineIntersectSeg(point p, point q, point A, point B) {
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x * B.y;
  double u = fabs(a * p.x + b * p.y + c);
  double v = fabs(a * q.x + b * q.y + c);
  return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v)); }

typedef pair< pii, int > pipii;
const int N = 3000, M = 1e6;
point p[N], ot[N];
int who[N];
set< pii > st[N];
int mark[M * 3];
vector < pipii > te[3 * M];

bool is_integer(point tmp){
    ll x = tmp.x, y = tmp.y;

    if(fabs(tmp.x - x) < EPS && fabs(tmp.y - y) < EPS){
        // printf("%.3lf %.3lf eh inteiro!\n", tmp.x, tmp.y);
        return true;
    }else{
        // printf("%.3lf %.3lf nao eh inteiro! %.5lf %.5lf\n", tmp.x, tmp.y, fabs(tmp.x - x), fabs(tmp.y - y));
    }

    return false;
}

bool bel(point p, point a, point b){
    if(p == a || p == b){
        return true;
    }
    
    double y = p.y;
    double x = p.x;
    double x1, x2;

    if(a.x - b.x > EPS){
        x1 = b.x;
        x2 = a.x;
    }else{
        x1 = a.x;
        x2 = b.x;
    }

    if((y - a.y > -EPS && b.y - y > -EPS) && (x - x1 > -EPS && x2 - x > -EPS)){
        return true;
    }else{
        return false;
    }
}

int main(){
    int n;

    scanf("%d", &n);

    ll cnt_all = 0LL;

    for(int i = 0 ; i < 2 * n ; i++){
        scanf("%lf %lf", &p[i].x, &p[i].y);
    }

    cnt_all = n * 2LL;

    for(int i = 0 ; i < 2 * n ; i += 2){
        if(p[i].y - p[i + 1].y > EPS){
            swap(p[i], p[i + 1]);
        }
        
        ll a1 = p[i].x, b1 = p[i].y;
        ll a2 = p[i + 1].x, b2 = p[i + 1].y;
        
        ll la = abs(a1 - a2), lb = abs(b1 - b2);

        ll g = __gcd(la, lb);
        gcd[i] = g;

        cnt_all += (g - 1LL);

        // printf("line %lld %lld %lld %lld adds %lld\n", a1, b1, a2, b2, g - 1LL + 2LL);
    }

    line u, v;
    int sz = 0;
    
    cout << cnt_all << endl;
    
    for(int i = 0 ; i < 2 * n ; i += 2){
        pointsToLine(p[i], p[i + 1], u);
        
        for(int j = i + 2 ; j < 2 * n ; j += 2){
            pointsToLine(p[j], p[j + 1], v);

            if(areSame(u, v)){
                pii axu1 = {p[i].x, p[i].y}, axu2 = {p[i + 1].x, p[i + 1].y};
                pii axv1 = {p[j].x, p[j].y}, axv2 = {p[j + 1].x, p[j + 1].y};

                pii r1, r2;

                if(axu1.second > axv1.second){
                    r1 = axu1;
                }else{
                    r1 = axv1;
                }

                if(axu2.second < axv2.second){
                    r2 = axu2;
                }else{
                    r2 = axv2;
                }

                if(r1.second <= r2.second){
                    ll la = abs(r1.first - r2.first);
                    ll lb = abs(r2.second - r1.second);

                    ll g = __gcd(la, lb);

                    cnt_all -= (g + 1LL);
                    ot[sz].x = r1.first;
                    ot[sz].y = r1.second;
                    who[sz] = i;
                    sz++;
                    who[sz] = i;
                    ot[sz].x = r2.first;
                    ot[sz].y = r2.second;
                    sz++;
                }
            }else{
                point tmp;
                
                if(areIntersect(u, v, tmp)){
                    if(is_integer(tmp) && bel(tmp, p[i], p[i + 1]) && bel(tmp, p[j], p[j + 1])){
                        te[i].push_back({tmp.x, 1});
                        te[i].push_back({tmp.x, tmp.x});
                        cnt_all--;
                    }
                }
            }
        }
    }


    printf("%lld\n", cnt_all);

    return 0;
}