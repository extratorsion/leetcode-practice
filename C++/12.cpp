#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
		string str;

		int num_span[]{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		string char_span[]{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

		int span = sizeof(num_span) / sizeof(num_span[0]);

		for (int i = 0; i < span; ++i) {
			while(num >= num_span[i]) {
				str += char_span[i];
				num -= num_span[i];
			}
		}


		return str;
    }
};

int main(int argc, char* argv[]) {

	cout << Solution().intToRoman(atoi(argv[1])) << endl;
	return EXIT_SUCCESS;
}
