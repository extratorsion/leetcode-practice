#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int> height) {
		auto area = [&](int i, int j) {
			return (j - i) * min(height[i], height[j]);
		};
		int max_area = 0;
		for (int i = 0; i < height.size(); ++i) {
			for (int j = 0; j < height.size(); ++j) {
				if (area(i, j) > max_area) {
					max_area = area(i, j);
				}
			}
		}

		return max_area;

	}
};

int main(void) {
	cout << Solution().maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) << endl;
	return EXIT_SUCCESS;
}
