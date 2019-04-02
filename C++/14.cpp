#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
			return "";
		string comPrefix;
		
		int min_length = strs[0].length();
		for (int i = 1; i < strs.size(); ++i)
			if (min_length > strs[i].length())
				min_length = strs[i].length();

		for (int l = 0; l < min_length; ++l) {
			char ch = strs[0][l];
			for (int i = 1; i < strs.size(); ++i) 
				if (ch != strs[i][l])
					return comPrefix;
			comPrefix += ch;
		}
		return comPrefix;
	}

};

int main(int argc, char *argv[]) {

	vector<string> vec {"flower", "flow", "flight"};

	cout << Solution().longestCommonPrefix(vec) << endl;
	return EXIT_SUCCESS;
}
