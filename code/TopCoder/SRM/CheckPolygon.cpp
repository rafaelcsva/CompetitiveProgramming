//10, 10, 2018, 12:49:28 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
  
struct Point 
{ 
    ll x; 
    ll y; 
}; 
  
// Given three colinear points p, q, r, the function checks if 
// point q lies on line segment 'pr' 
bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 
  
// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(Point p, Point q, Point r) 
{ 
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
    // for details of below formula. 
    ll val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
  
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
    // Find the four orientations needed for general and 
    // special cases 
    ll o1 = orientation(p1, q1, p2); 
    ll o2 = orientation(p1, q1, q2); 
    ll o3 = orientation(p2, q2, p1); 
    ll o4 = orientation(p2, q2, q1); 
  
    // General case 
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false; // Doesn't fall in any of the above cases 
} 

struct vec{
    ll x, y;
};

vec toVec(Point a, Point b) {       // convert 2 points to vector a->b
    vec r;

    r.x = b.x - a.x;
    r.y = b.y - a.y;

    return r; 
}

ll cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool collinear(Point p, Point q, Point r) {
 return abs(cross(toVec(p, q), toVec(p, r))) == 0; }

const int N = 100;
Point p[N];
char buffer[N];

class CheckPolygon{
    public:
        string check(vector <int> X, vector <int> Y){
            int n = X.size();

            for(int i = 0 ; i < n ; i++){
                p[i].x = X[i];
                p[i].y = Y[i];
            }

            for(int i = 2 ; i < n ; i++){
                if(collinear(p[i], p[i - 1], p[i - 2])){
                    return "Not simple";
                }
            }

            for(int i = 0 ; i < n ; i++){
                for(int j = i + 1 ; j < n ; j++){
                    if(p[i].x == p[j].x && p[i].y == p[j].y){
                        return "Not simple";
                    }
                }
            }

            if(collinear(p[0], p[n - 1], p[n - 2])){
                return "Not simple";
            }

            for(int i = 0 ; i < n ; i++){
                int nxt = (i + 1) % n;

                for(int j = 0 ; j < n ; j++){
                    if(j == i || j == nxt)
                        continue;

                    int nxj = (j + 1) % n;

                    if(nxj == i || nxj == nxt)
                        continue;

                    if(doIntersect(p[i], p[nxt], p[j], p[nxj])){
                        return "Not simple";
                    }
                }
            }

            p[n].x = p[0].x;
            p[n].y = p[0].y;

            double area = 0.0;

            for(int i = 0 ; i < n ; i++){
                double x1 = p[i].x, x2 = p[i + 1].x;
                double y1 = p[i].y, y2 = p[i + 1].y;

                area += (x1 * y2 - x2 * y1);
            } 

            area = fabs(area) / 2.0;
            
            sprintf(buffer, "%.1lf", area);

            string ret = "";

            for(int i = 0 ; i < strlen(buffer) ; i++){
                ret += buffer[i];
            }

            return ret;
        }
};