#include <bits/stdc++.h>

int cyclicString(std::string s1) {

  for (int answer = 1; answer < s1.size(); answer++) {
    bool correct = true;
    for (int position = answer; position < s1.size() - answer; position++) {
	std::cout << position << ' ' << position + answer << '\n';
      if (s1[position] != s1[position + answer]) {
        correct = false;
        break;
      }
    }
    if (correct) {
      return answer;
    }
  }
  return s1.size();
}

int main (){
	std:: cout << cyclicString("cabca") << '\n';
	return 0;
}
