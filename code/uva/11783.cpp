#include <bits/stdc++.h>

using namespace std;

const long double eps = 1e-13;

struct PT {
    typedef long double  T;
    T x, y;
    PT(T _x = 0, T _y = 0) : x(_x), y(_y){}
    PT operator +(const PT &p) const { return PT(x + p.x, y + p.y); }
    PT operator -(const PT &p) const { return PT(x - p.x, y - p.y); }
    PT operator *(T c)  const { return PT(x * c, y * c); }
    T operator *(const PT &p) const { return x * p.x + y * p.y; }
    T operator %(const PT &p) const { return x * p.y - y * p.x; }
    bool operator < (const PT &p) const { return x != p.x ? x < p.x : y < p.y; }
    bool operator == (const PT &p) const { return x == p.x && y == p.y; }

    friend std::ostream& operator << (std::ostream &os, const PT &p) {
		return os << p.x << ' ' << p.y;
	}

	friend std::istream& operator >> (std::istream &is, PT &p) {
		return is >> p.x >> p.y;
	}
};

struct Segment {
    typedef long double T;
    PT p1, p2;
    T a, b, c;

    Segment() {}

    Segment(PT st, PT en){
        p1 = st, p2 = en;
        a = -(st.y - en.y);
        b = st.x - en.x;
        c = a * en.x + b * en.y;
    }

    T plug(T x, T y){
        return a * x + b * y - c;
    }

    T plug(PT p){
        return plug(p.x, p.y);
    }

    bool inLine(PT p) { return (p - p1) % (p2 - p1) == 0; }
    bool inSegment(PT p){
        return inLine(p) && (p1 - p2) * (p - p2) >= 0 && (p2 - p1) * (p - p1) >= 0;
    }

    bool isParallel(Segment s){
        return a * s.b == b * s.a;
    }

    PT lineIntersection(Segment s){
        T A = a, B = b, C = c;
        T D = s.a, E = s.b, F = s.c;
        T x = (T) C * E - (T) B * F;
        T y = (T) A * F - (T) C * D;
        T tmp = (T) A * E - (T) B * D;

        x /= tmp;
        y /= tmp;

        return PT(x, y);
    }

    bool polygonIntersection(const std::vector< PT > &poly){
        T l = -1e18, r = 1e18;
        for(auto p: poly){
            T z = plug(p);
            l = std::max(l, z);
            r = std::min(r, z);
        }
        return l - r > eps;
    }
};

const int N = int(1e5);
bool mark[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Segment a({0, 0}, {1, 1}), b({11, 11}, {16, 16});
    // auto ipt = a.lineIntersection(b);
    // printf("%Lf %Lf %Lf, %Lf %Lf %Lf\n", a.a, a.b, a.c, b.a, b.b, b.c);

    int n;

    while(cin >> n){
        if(n == 0) break;

        vector< Segment > segs;

        for(int i = 0; i < n ; i++){
            PT p1, p2;

            cin >> p1 >> p2;

            segs.push_back(Segment(p1, p2));

            mark[i] = false;
        }

        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            bool frag = mark[i];

            for(int j = i + 1 ; j < n ; j++){
                if(segs[j].inSegment(segs[i].p1) || segs[j].inSegment(segs[i].p2)){
                    ans++;
                    frag = true;
                    mark[j] = true;
                    continue;
                }

                if(segs[i].isParallel(segs[j])){
                    continue;
                }

                auto ipt = segs[i].lineIntersection(segs[j]);

                if(segs[i].inSegment(ipt) && segs[j].inSegment(ipt)){
                    mark[j] = true;
                    frag = true;
                    ans++;
                }
            }

            if(!frag){
                ans += 2;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}