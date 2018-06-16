#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 300005;

int n;
string s[N];
char ss[N];

int front(){
	int cnt = 0;

	for(int i = 0; ss[i]; i++){
		if(ss[i] == '(') cnt++;
		else cnt--;
		if(cnt < 0) return -1;
	}
	return cnt;
}

int back(){

	int cnt = 0;

	for(int i = strlen(ss)-1; i >= 0; i--){
		if(ss[i] == ')') cnt++;
		else cnt--;
		if(cnt < 0) return -1;
	}
	return cnt;
}

int a[N], b[N];

int cf[N], cb[N];

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%s", ss);
		a[i] = front();
		b[i] = back();

		if(a[i] != -1) cf[ a[i] ]++;
		if(b[i] != -1) cb[ b[i] ]++;

		s[i] = ss[i];
	}

	ll ans = 0;

	for(int i = 0; i < n; i++){
		if(a[i] != -1) ans += cb[ a[i] ];
		if(b[i] != -1) ans += cf[ b[i] ];
	}

	printf("%lld\n", ans / 2);

	

}