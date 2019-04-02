#include <iostream>
#include <climits>
#include <cmath>
#include <string>
using namespace std;

int myAtoi(string str) {
	int i = 0;
	for(; i < str.length(); ++i) 
		if (!(str[i] == ' ' or str[i] == '\t'))
			break;
	str = str.substr(i);
	if (isalpha(str[0]))
		return 0;
	bool isneg = (str[0] == '-');
	if (str[0] == '-' or str[0] == '+')
		str = str.substr(1);
	bool zero_start = true;
	int zero_cnt = 0;
	for (int i = 0; i < str.length(); ++i) 
		if (str[i] == '0' && zero_start)
			zero_cnt+=1;
		else
			break;
	str = str.substr(zero_cnt);


	int len = 0;
	for (int i = 0; i < str.length(); ++i) 
		if (str[i] <= '9' && str[i] >= '0')
			len += 1;
		else 
			break;
	str = str.substr(0, len);	
	if (str.length() > 10)
		return INT_MAX ;
	
	long long ret = 0;
	for (int i = 0; i < str.length(); ++i) 
		ret += (str[i] - '0') * pow(10, str.length() - i - 1);
	if (isneg)
		ret = -ret;
	if (ret >  INT_MAX || ret < INT_MIN)
		return INT_MAX ;
	else
		return int(ret);
}

int main(void) {
	string str;
	cin>> str;
	cout << myAtoi(str) << endl;

	return 0;
}
