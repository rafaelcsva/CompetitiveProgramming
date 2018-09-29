#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int p[N];
int cnt[N];
bool isRec[N];
set<int>st;
set<int>::iterator up;

int main (){
	int n;
	int best = -1;
	int mCont = 0;

	cin >> n;

	for(int i = 0 ; i < n ; i++){
		cin >> p[i];
	}

	if(n == 1){
		printf("1\n");
		return 0;
	}

	int ma = p[0];
	best = 1;
	isRec[ma] = true;
//	cout << "best " << best << '\n';
	st.insert(p[0]);

	for(int i = 1 ; i < n ; i ++){
        up = st.upper_bound(p[i]);
		
		//if(up != st.end())
	//	cout << *up << ' ' << p[i] << '\n';
		if(up == st.end()){
			isRec[p[i]] = true;
		}
		else if(*up == ma){
			cnt[*up]++;
		}
		ma = max(p[i], ma);

		st.insert(p[i]);
	}

//	cout << isRec[1] << '\n';
	for(int i = 1 ; i <= n ; i++){
		if(cnt[i] > mCont){
			if(cnt[i] == 1 && isRec[i]){
				continue;
			}

			//cout << i << '\n';
			mCont = cnt[i];
			best = i;
		}else if(cnt[i] == mCont){
			if(isRec[best] && !isRec[i]){
				best = i;
			}
		}
	}

	cout << best << "\n";

	return 0;
}