#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // 1010 11
		bool neg = (dividend < 0 and divisor > 0 or dividend > 0 and divisor < 0);
		long long ldividend = llabs(dividend);
		long long ldivisor = llabs(divisor);
		long long res = 0;
		
		if (ldivisor == 1)
			if (ldividend <= INT_MAX)
				return int(neg ? -ldividend: ldividend);
			else
				return 0;

		while(ldividend >= ldivisor) {
			res += 1;
			ldividend -= ldivisor;
		}
		
		if (res <= INT_MAX)
			return (neg ? -res: res);
		else
			return 0;
    }
};

int main(void) {
	
	cout << Solution().divide(10, 3) << endl;
	cout << Solution().divide(-7, -3) << endl;
	cout << Solution().divide(7, -3) << endl;
	cout << Solution().divide(-2147483648, -1) << endl;
	
	return 0;
}
