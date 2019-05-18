#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
const int N = int(1e6);
ll a[N];
multiset< ll > mst1, mst2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    ll z;
    
    cin >> n >> z;
	 
	for(int i = 0 ; i < n ; i++){
	    cin >> a[i];    
	}
		
	sort(a, a + n);
	
	for(int i = n / 2 ; i < n ; i++){
		mst1.insert(a[i]);
	}

	int pairs = 0;
	assert(z);
	
	for(int i = 0 ; i < n / 2 ; i++){    
	    auto e = mst1.lower_bound(a[i] + z);
	    
	    if(e != mst1.end()){
	        mst1.erase(e);
	        pairs += 1;
	    }
	}

	cout << pairs << endl;
	
	return 0;
}