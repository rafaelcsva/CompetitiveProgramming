#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = 60;
ll a[N][N];
const ll k = ll(1e6) + 3LL;
int n = 50, m = 12;
ll c[N];

ll evaluate(ll x){
	ll t = 1LL;
	ll sum = 0LL;

	for(int i = 0 ; i < m - 1 ; i++){
		sum = (sum + c[i] * t) % k;
		t = (t * x) % k;
	}

	return sum;
}

void swap_lines(int i, int j){
    for(int c = 0 ; c < m ; c++){
        swap(a[i][c], a[j][c]);
    }
}
 
ll fast_pow(ll base, ll expo, ll mod){
    //assert(expo == mod - 2LL);
    ll r = 1LL;
    ll carry = base;
    //cout << base << " ^ " << expo << " % " << mod ;
   
    while(expo){
        if(expo & 1LL){
            r = (r * carry) % mod;
        }
       
        expo >>= 1LL;
        carry = (carry * carry) % mod;
    }
   
    //cout << " = " << r << endl;
   
    return r;
}
 
int gauss(){
    int r = 0;
    int last_choosed = -1;
    //show_matrix();
   
    for(int c = 0 ; c < m - 1 ; c++){
        int j = r;
       
        for(int i = r ; i < n ; i++){
            //assert(a[i][c] >= 0LL && a[i][c] < k);
           
            if(a[i][c]){
                j = i;
                break;
            }
        }
       
        if(!a[j][c]){
            continue;
        }
       
        //cout << "escolhi a " << j << endl;
       
        swap_lines(r, j);
       
        ll inv = fast_pow(a[r][c], k - 2LL, k);
       
        for(int col = 0 ; col < m ; col++){
            a[r][col] = (a[r][col] * inv) % k;
        }
       
        for(int i = 0 ; i < n ; i++){
            if(!a[i][c] || i == r){
                continue;
            }
           
            ll t = a[i][c];
           
            for(int j = 0 ; j < m ; j++){
                a[i][j] = ((a[i][j] - t * a[r][j]) % k + k) % k;
            }
        }
       
        //show_matrix();
        r++;
    }
   
    return r;
}
 

void print_matrix(){
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			printf("%6lld ", a[i][j]);
		}
		printf("\n");
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(ll i = 0 ; i < n ; i++){
		cout << "? " << i << endl;

		ll xi;

		cin >> xi;

		while(xi == -1);

		ll t = 1LL;

		for(int j = 0 ; j < m - 1 ; j++){
			a[i][j] = t;
			t = (t * i) % k;
		}

		a[i][m - 1] = xi;
	}

	// print_matrix();

	int r = gauss();

	assert(r == m - 1);

	for(int i = 0 ; i < m - 1 ; i++){
		int cnt = 0;

		for(int j = 0 ; j < m - 1 ; j++){
			cnt += (a[i][j] != 0LL);
		}

		assert(cnt <= 1);

		c[i] = a[i][m - 1];
	}

	for(ll x = 0 ; x < k ; x++){
		ll e = evaluate(x);

		if(e == 0LL){
			cout << "! " << x << endl;
			return 0;
		}
	}

	cout << "! -1" << endl;

	return 0;
}