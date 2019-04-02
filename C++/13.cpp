#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
		
		
		int num = 0;

		int num_span[]{1000, 500,  100, 50, 10, 5,  1};
		char char_span[]{'M', 'D',  'C', 'L', 'X', 'V', 'I'};
		unordered_map<char, int> mp;

		int span = sizeof(num_span) / sizeof(num_span[0]);

		for (int i = 0; i < span; ++i)
			mp[char_span[i]] = num_span[i];

		for (int i = 0; i < s.length(); ++i) {
			int j = i + 1;
			if (j < s.length() && mp[s[i]] < mp[s[j]]) {
				num += (mp[s[j]] - mp[s[i]]);
				++i;
			}
			else {
				num += mp[s[i]];
			}
		}

		return num;

    }
};

int main(int argc, char *argv[]) {

	cout << Solution().romanToInt(string(argv[1])) << endl;
	return EXIT_SUCCESS;
}
