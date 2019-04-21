#include <bits/stdc++.h>

using namespace std;

const int S = 8;
string suffixes[S] = {"", "L", "LL", "U", "UL", "ULL", "LU", "LLU"};
map< char, char > mapping;

bool is_suffix(string &s, string &suf){
	int j = int(suf.length()) - 1;
	int i = int(s.length()) - 1;

	while(i >= 0 && j >= 0){
		if(s[i] != suf[j]){
			return false;
		}

		i--, j--;
	}

	return true;
}

class EllysCodeConstants{
	public:
	string getLiteral(string candidate){
		mapping['O'] = '0';
		mapping['I'] = '1';
		mapping['Z'] = '2';
		mapping['S'] = '5';
		mapping['T'] = '7';

		for(int i = 0 ; i < S ; i++){
			if(is_suffix(candidate, suffixes[i])){
				bool ok = true;
				string hex = "";

				for(int j = 0 ; j < int(candidate.length()) - int(suffixes[i].length()) ; j++){
					char c = candidate[j];

					if(!('A' <= c && c <= 'F') && !('0' <= c && c <= '9')){
						if(mapping.count(c) == 0){
							ok = false;
							break;
						}

						hex.push_back(mapping[c]);
					}else{
						hex.push_back(c);
					}
				}

				if(ok){
					return "0x" + hex + suffixes[i];
				}
			}
		}

		return "";
	}
};

int main(){
	EllysCodeConstants test;

	cout << test.getLiteral("BABACECA") << endl;

	return 0;
}