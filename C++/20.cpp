#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<char> S;
		unordered_map<char, char> mp {{'(', ')'}, {'[', ']'}, {'{', '}'}};
		for (int i = 0; i < s.length(); ++i) {
			if (isspace(s[i]))
				continue;
			else if (s[i] == '(' or s[i] == '[' or s[i] == '{') {
				S.push(s[i]);
			} else {
				if (!S.empty() && s[i] == mp[S.top()])
					S.pop();
				else
					return false;
			}
		}
		return S.empty();
    }
};

int main(void) {

	cout << boolalpha << Solution().isValid("{ [  ] }") << endl;
	
	return 0;
}

