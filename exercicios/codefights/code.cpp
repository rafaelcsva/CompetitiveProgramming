#include <bits/stdc++.h>

using namespace std;

int min(int a, int b){
	return a > b ? b : a;
}

double perfectCity() {
    double x1 = 0.4, y1 = 1.0;
    double x2 = 0.9, y2 = 3;
    
    double r = abs(y1-y2);
    double a = floor(x2), b = ceil(x2);
    
    r += min(abs(x1 - b) + abs(b - x2), abs(x1 - a) + abs(a - x2));
    
    return r;
}

int main (){
	std::cout << perfectCity() << '\n';

	return 0;
}
