#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main(void ) {
    vector<char> str;
    vector<char> pre_str;
    
    string input;
    cin >> input;

    for (int i = 0; i < input.size(); ++i) {
        
        if (count(str.begin(), str.end(), input[i]) == 0) {
            str.push_back(input[i]);
        } else {
            if (pre_str.size() > str.size()) {
            } else {
                pre_str.clear();
                for (auto ele : str)
                    pre_str.push_back(ele);
            }

            if (input.size() - i  - 1 <= pre_str.size()) 
                break;

            int same_ind = 0;
            for (auto  ele : str) {
                if (input[i] == ele)
                    break;
                same_ind += 1;
            }

            i = (i - str.size() + same_ind);
            str.clear();

        }
    }

    int maxsize = max(pre_str.size(), str.size());
    cout << maxsize << endl;

    return 0;
}
