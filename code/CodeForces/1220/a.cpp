#include <bits/stdc++.h>

using namespace std;

string one = "one";
string zero = "zero";
int cnt[1000];

bool is_possible_one(){
	for(int i = 0 ; i < one.length() ; i++){
		if(!cnt[one[i]]){
			return false;
		}
	}

	for(int i = 0 ; i < one.length() ; i++){
		cnt[one[i]]--;
	}

	return true;
}

bool is_possible_zero(){
	for(int i = 0 ; i < zero.length() ; i++){
		if(!cnt[zero[i]]){
			return false;
		}
	}

	for(int i = 0 ; i < zero.length() ; i++){
		cnt[zero[i]]--;
	}

	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;

	int n;

	cin >> n;
	cin >> s;

	for(int i = 0 ; i < n ; i++){
		cnt[s[i]]++;
	}

	while(is_possible_one()){
		cout << 1 << " ";
	}

	while(is_possible_zero()){
		cout << 0 << " ";
	}

	return 0;
}