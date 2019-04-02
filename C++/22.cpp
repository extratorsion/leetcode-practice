#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
		string beg; 
		auto valid = [](const string& str) {
			stack<char> S;
			for (char ch: str)
				if (ch == '(')
					S.push('(');
				else if (!S.empty() and ch == ')' and S.top() == '(')
					S.pop();
				else
					return false;
			return S.empty();
		};
		cout << valid(")())") << endl;
		for (int i = 0; i < n; ++i) 
			beg.push_back('(');
		
		for (int i = 0; i < n; ++i) 
			beg.push_back(')');
		
		vector<string> res;	
		do {
			res.push_back(beg);
		} while (next_permutation(beg.begin(), beg.end()));
		vector<string> ret;
		for (string& str: res)
			if (valid(str))
				ret.push_back(str);
		return ret;
    }
};

int main(void) {
	for (string& str: Solution().generateParenthesis(4))
		cout << str << endl;
	return 0;
}
