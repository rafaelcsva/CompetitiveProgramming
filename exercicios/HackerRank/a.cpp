#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int l, r;
}Painter;

const int N = 100010;

bool compar(Painter a, Painter b){
	if(a.l <= b.l && a.r >= b.r)
		return true;
	
	if(a.l < b.l){
		return true;
	}

	if(a.l > b.l){
		return false;
	}

	return a.r <= b.r;
}

int resp[N];
int cnt[N];

int main() {
	int n, m;
	Painter painter[N];

	cin >> n >> m;

	for(int i = 0 ; i < m ; i++){
		cin >> painter[i].l;
		cin >> painter[i].r;
		cnt[painter[i].l]++;
		cnt[painter[i].r]++;
	}

	sort(painter, painter + m, compar);

	for(int i = 0 ;i < m ; i++){
		cout << painter[i].l << " " << painter[i].r << '\n';
	}
	int cur = painter[0].l;
	int diff = painter[0].l - 1;
    
	for(int i = 0 ; i < m ; i++){
		if(painter[i].l > cur){
			diff += painter[i].l - cur - 1;
		}
		
		cur = max(cur, painter[i].r);
	}

	diff += n - cur;

	cur = 0;

	for(int i = 0 ; i < m ; i++){
		int j = i + 1;
		int tmp = i;
		int sum = 0;
		bool ver = false;
		cur = painter[i].l;
 		
		for(int j = i + 1; j < m && painter[j].r <= painter[i].r ; j++){
			ver = true;
			cout << j << ' ' << tmp << '\n';
			i = j;
		
			if(painter[j].l > cur){
				sum += painter[i].l - cur - 1;
			}
	
			cur = max(cur, painter[i].r);
		}

		if(j < m && !ver){
			int diff;
			cout << "here " << i << ' ' << j << '\n';
			if(painter[j].l < painter[i].r){
				diff = painter[i].r - painter[j].l;
			}
		}

		if(ver)
			resp[i] = sum;
		else{
			int inter = painter[tmp].r - painter[tmp].l + 1;

			if(painter[tmp].r != painter[tmp].l){
				if(cnt[painter[tmp].r] > 1){
					inter--;
				}
				if(cnt[painter[tmp].l] > 1)
					inter--;
			}else{
				if(cnt[painter[tmp].r] > 2){
					inter--;
				}
			}	

			resp[tmp] = inter - diff;

			
		}	
	}

	cout << "diff = " << diff << '\n';
	for(int i = 0 ; i < m ; i++){
		cout << resp[i] + diff << '\n';
	}

	return 0;
}
