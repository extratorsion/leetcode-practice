#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <unordered_set>


using namespace std;



class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return {};
		struct FourNum {
			int arr[4];
			bool operator==(const FourNum& fn) const {
				for (int i = 0; i < 4; ++i) 
					if (fn.arr[i] != arr[i])
							return false;
				return true;
			};
		};

		struct HashFourNum {
			size_t operator()(const FourNum& fn) const {
				return size_t(fn.arr[0]) * size_t(fn.arr[3]) +
						size_t(fn.arr[1]) * size_t(fn.arr[2]);
			}
		};

		sort(nums.begin(), nums.end());

		auto _bsearch = [](vector<int>& vec, int low, int high, int val) -> int {
			while(low <= high) {
				int mid = (low + high) >> 1;
				if (vec[mid] == val)
					return mid;
				else if (vec[mid] < val) 
					low = mid + 1;
				else
					high = mid - 1;
			}
			return -1;
		};

		unordered_set<FourNum, HashFourNum> fset;
		vector<vector<int>> res;
		for (int i = 0; i < nums.size() - 3; ++i) {
			for (int j = i + 1; j < nums.size() - 2; ++j) {
				for (int k = j + 1; k < nums.size() - 1; ++k) {
					int remain = (target - nums[i] - nums[j] - nums[k]);
					int ind = _bsearch(nums, k + 1, nums.size() - 1, remain);
					if (ind == -1)
						continue;
					FourNum fn{{nums[i], nums[j], nums[k], remain}};
					if (fset.count(fn) == 0) {
						vector<int> item(fn.arr, fn.arr + 4);
						res.push_back(item);
						fset.insert(fn);
					}
				}
			}
		}
		return res;
	}

	static void print_vec(vector<int> vec) {
		for (int i = 0; i < vec.size() - 1; ++i) {
			cout << vec[i] << " ";
		}
		if (vec.size()) 
			cout << vec[vec.size() - 1] << endl;
	}
};

int main(void) {
	vector<int> vec{1, 0, -1, 0, -2, 2};
	for (vector<int>& vec: Solution().fourSum(vec, 0))
		Solution::print_vec(vec);	
	
	return 0;
}

