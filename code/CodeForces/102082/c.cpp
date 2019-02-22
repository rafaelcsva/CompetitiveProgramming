//17, 02, 2019, 17:19:51 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010, MAX_IT = int(1000);
vector< pii > left_corridor, right_corridor, tmpc;
vector< int >corridor, tmp;
bool mark[N][N];

bool check(int r, int s){
	bool ok = true;

	for(int i = 1 ; i <= r ; i++){
		for(int j = 1 ; j <= 2 * s + 1 ; j++){
			if(mark[i][j]){
				// cout << '*';
				// cout << i << " " << j << " " << mark[i][j - 1] << endl;
				// return false;
				return false;
			}else{
				// cout << '.';
			}
		}
		// cout << endl;
	}

	// cout << "ENDED STEP" << endl << endl;

	return ok;
}

bool compar_l(pii &a, pii &b){
	if(a.first > b.first){
		return true;
	}else if(a.first == b.first){
		return a.second > b.second;
	}else{
		return false;
	}
}

bool compar_r(pii &a, pii &b){
	if(a.first > b.first){
		return true;
	}else if(a.first == b.first){
		return a.second < b.second;
	}else{
		return false;
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, s, p;

    cin >> r >> s >> p;

    for(int i = 1 ; i <= p ; i++){
    	int ii, pi;

    	cin	>> ii >> pi;

    	if(pi <= s){
    		// cout << "added for " << s << endl;
    		left_corridor.push_back({ii, pi});
    		mark[ii][pi] = true;
    	}else{
    		right_corridor.push_back({ii, pi + 1});
    		mark[ii][pi + 1] = true;
    	}
    }

    sort(left_corridor.begin(), left_corridor.end(), compar_l);
    sort(right_corridor.begin(), right_corridor.end(), compar_r);

    int tim = 0;
    int corridor_col = s + 1;

    // cout << "checando!\n" << endl;

    while(!check(r, s)){
    	tim++;

    	for(int i = r ; i >= 1 ; i--){
    		if(!mark[i][corridor_col]){
    			continue;
    		}

    		int pos = i;

    		mark[pos][corridor_col] = false;

    		if(pos + 1 == r + 1){
    			// cout << pos << " saiu" << endl;
    			continue;
    		}

    		if(!mark[pos + 1][corridor_col]){
	    		mark[pos + 1][corridor_col] = true;
	    		// corridor[i]++;
    		}else{
    			mark[pos][corridor_col] = true;
    		}
    		// tmp.push_back(corridor[i]);
    	}

    	// corridor = tmp;
    	// tmp.clear();

    	for(int i = 0 ; i < left_corridor.size() ; i++){
    		int &col = left_corridor[i].second;
    		int &row = left_corridor[i].first;

    		if(col == corridor_col){
    			continue;
    		}

    		if(!mark[row][col + 1]){
    			mark[row][col] = false;
    			mark[row][col + 1] = true;
    			col++;

    			// if(col == corridor_col){
    			// 	// cout << row << "entrou no corredor " << row << " " << col - 1 << endl;
    			// 	corridor.push_back(row);
    			// }
    		}
    		tmpc.push_back(left_corridor[i]);
    	}

    	left_corridor = tmpc;
    	tmpc.clear();

    	for(int i = 0 ; i < right_corridor.size() ; i++){
    		int &col = right_corridor[i].second;
    		int &row = right_corridor[i].first;

    		if(col == corridor_col){
    			continue;
    		}
    		// cout << row << " " << col << endl;

    		if(!mark[row][col - 1]){
    			mark[row][col] = false;
    			mark[row][col - 1] = true;
    			col--;

    			// if(col == corridor_col){
    			// 	// cout << row << "entrou no corredor " << row << " " << col + 1 << endl;
    			// 	corridor.push_back(row);
    			// }
    		}
    		tmpc.push_back(right_corridor[i]);
    	}

    	right_corridor = tmpc;
    	tmpc.clear();
    }

    cout << tim << endl;
    
    return 0;
}