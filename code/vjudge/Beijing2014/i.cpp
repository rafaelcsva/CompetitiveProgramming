#include <bits/stdc++.h>

using namespace std;

struct Circle{
public:
	int x, y, r;

	Circle(int x, int y, int r): x(x), y(y), r(r){

	}
};

const double PI = acos(-1.0);
const double eps = double(1e-13);

double area(Circle A, Circle B){
	double x1 = A.x, x2 = B.x;
	double y1 = A.y, y2 = B.y;
	double r1 = A.r;
	double r2 = B.r;
	double a1, a2;

	double d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

	if (d>r1+r2) return 0.0;
	if (d<=abs(r2-r1) && r1>=r2) return PI*r2*r2;
	if (d<=abs(r2-r1) && r2>=r1) return PI*r1*r1;
	double alpha=acos((r1*r1+d*d-r2*r2)/(2*r1*d))*2;
	double beta=acos((r2*r2+d*d-r1*r1)/(2*r2*d))*2;
	a1=(long double)0.5*beta*r2*r2-0.5*r2*r2*sin(beta);
	a2=(long double)0.5*alpha*r1*r1-0.5*r1*r1*sin(alpha);

	return a1 + a2;
}

int main(){
	int test = 1;

	int t;

	scanf("%d", &t);

	while(t--){
		int r, R;
		int x1, y1, x2, y2;
		
		scanf("%d %d", &r, &R);

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		double tot = area(Circle(x1, y1, R), Circle(x2, y2, R));
		double vaz = area(Circle(x1, y1, R), Circle(x2, y2, r)) + area(Circle(x1, y1, r), Circle(x2, y2, R));
		double intersec = area(Circle(x1, y1, r), Circle(x2, y2, r));

		printf("Case #%d: %.6lf\n", test++, tot - vaz + intersec);
	}

	return 0;
}