#include <iostream>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <climits>
using namespace std;

int reverse(int x) {
	bool isneg = (x < 0);
	long long X = llabs((long long)x);
	char nums[20];
	int nums_len = 0;

	while (X > 0) {
		nums[nums_len++] = (X % 10) + '0' ;
		X /= 10;
	}

	long long ret = 0;
	int beg = 0;
	bool start = true;
	nums[nums_len] = '\0';

	for (int i = 0; i < nums_len; ++i)
		if (nums[i] == '0' && start)
			beg += 1;
		else {
			break;
		}

	ret = atoll(nums);
	if (ret > INT_MAX || ret < INT_MIN)
		return 0;
	return (isneg ? -ret: ret);
}


int main(void) {
	int val;
	cin >> val;
	cout << reverse(val) << endl;
	return 0;
}
