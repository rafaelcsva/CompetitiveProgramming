#include <bits/stdc++.h>

using namespace std;


#ifdef __WIN32__
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif

inline void writeChar(char c) {
    putchar_unlocked(c);
}

bool readChar(char &c) {
    c = getchar_unlocked();
    return c != EOF;
}

template<typename T>
inline void writeInt(T n){ 
    register int idx = 20; 
    if( n < 0 ) putchar_unlocked('-'); 
    n = abs(n); 
    char out[21]; 
    out[20] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' '); 
} 

struct complex_t {
	double a {0.0}, b {0.0};

	complex_t(){

	}

	complex_t(double na, double nb = 0.0) : a{na}, b{nb} {}

	const complex_t operator+(const complex_t &c) const {
		return complex_t(a + c.a, b + c.b);
	}

	const complex_t operator-(const complex_t &c) const {
		return complex_t(a - c.a, b - c.b);
	}

	const complex_t operator*(const complex_t &c) const {
		return complex_t(a * c.a - b * c.b, a * c.b + b * c.a);
	}

	const complex_t operator/(double r) const {
		return complex_t(a / r, b / r);
	}
};

using cd = complex_t;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w = w * wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x = x / n;
    }
}

void multiply(vector< cd > const &a, vector< cd > const &b, vector< int > &result){
	vector< cd > fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while(n < a.size() + b.size()){
		n <<= 1;
	}

	fa.resize(n);
	fb.resize(n);

	fft(fa, false);
	fft(fb, false);

	for(int i = 0 ; i < n ; i++){
		fa[i] = fa[i] * fb[i];
		// printf("%lf\n", fa[i].a);
	}

	fft(fa, true);

	for(int i = 0 ; i < result.size() ; i++){
		result[i] = floor(fa[i].a + 1e-5);
	}
}

vector< int > sum;
const int N = int(1e5 + 10);
vector< cd > a, b;
vector< int > r;

char s[N], t[N];
double pre[30];

int main(){
	int n = 0, m = 0;
	char c;

	for(int i = 0 ; i < 26 ; i++){
		pre[i] = (2.0 * PI * i) / 26.0;
	}

	while(readChar(c)){
		n = m = 0;

		s[n++] = c;

		while(readChar(c)){
			if(c == '\n')
				break;

			s[n++] = c;
		}

		while(readChar(c)){
			if(c == '\n'){
				break;
			}

			t[m++] = c;
		}

		if(m > n){
			writeChar('0');
			writeChar('\n');
			continue;
		}

		a.resize(n);
		b.resize(m);
		r.resize(n);

		sum.resize(n);

		reverse(t, t + m);

		for(int i = 0 ; i < n ; i++){
			double alphai = pre[s[i] - 'a'];

			a[i] = {cos(alphai), sin(alphai)};
		}

		int c = 0;

		for(int i = 0 ; i < m ; i++){
			if(t[i] == '?'){
				c++;
				b[i] = {0.0, 0.0};

				continue;
			}

			double bi = pre[t[i] - 'a'];
			
			b[i] = {cos(bi), -sin(bi)};
		}

		multiply(a, b, r);

		int cnt = 0;

		for(int i = m - 1 ; i < n ; i++){
			// printf("%d\n", r[i]);

			if(r[i] == m - c){
				cnt++;
				// printf("%d\n", i);
			}
		}

		writeInt(cnt);
		writeChar('\n');

		sum.clear();
	}

	return 0;
}
