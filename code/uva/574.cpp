#include <bits/stdc++.h>

using namespace std;

int v[20];

bool comp(string a, string b, int i, int j){
	if(i >= a.length()){
		return true;
	}
	
	if(j >= b.length()){
		return false;
	}
	//cout << a << ' ' << i << ' ' <<  b <<' ' << j << '\n';
	int na = 0;
	int pt = 1;
	
	while(i < a.length() && a[i] != '+'){
		na = na * pt + (a[i] - '0');
		pt = pt * 10; 
		
		i++;
	}
	
	pt = 1;
	
	int nb = 0;
	
	while(j < b.length() && b[j] != '+'){
		nb = nb * pt + (b[j] - '0');
		pt = pt * 10;
		
		j++; 
	}
	
	if(na > nb){
		return false;
	}else if(na < nb){
		return true;
	}else{
		return comp(a, b, i + 1, j + 1);
	}
}

bool comp(string a, string b){
//	cout << a << ' ' << b << '\n';
	return comp(a, b, 0, 0);
}

bool (*pt_comp)(string, string) = &comp;
	
set<string, bool (*)(string, string) >sumns(pt_comp);
set<string>::reverse_iterator it, tmp;

int main (){
	int n, t;
	
	ios::sync_with_stdio(false);
	
	while(cin >> t >> n){
		if(n == 0 && t == 0){
			break;
		}
		
		for(int i = 0 ; i < n ; i++){
			
			cin >> v[i];
		}
				
		cout << "Sums of " << t << ":\n";
		
		bool find = false;

		for(int i = 0 ; i < (1 << n) ; i++){
			int sum = 0;
			
			bitset<10>st(i);
			
			for(int j = 0 ; j < n ; j++){
				if(i & (1 << j)){
					sum += v[j];
				}
			}
			
			if(sum == t){
				sum = 0;
				string s = "";

				for(int j = 0 ; j < n ; j++){
					if(i & (1 << j)){
						sum += v[j];
						
						find = true;
						s += to_string(v[j]);
						
						if(sum == t){
							break;
						}else{
							s += "+";
						}
					}
				}
			///	cout << s <<'\n';
				sumns.insert(s);
			}
		}
		
		if(sumns.size() == 0){
			cout << "NONE\n";
		}else{
			for(it = sumns.rbegin() ; it != sumns.rend() ; it++){
				cout << *it << '\n';
				
				tmp = it;
				tmp++;
				
				while(tmp != sumns.rend() && *tmp == *it){
					tmp++;
				}
				
				it = --tmp;
			}
		}
		
		sumns.clear();
	}

	return 0;
}
