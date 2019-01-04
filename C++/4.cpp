#include <iostream>
#include <vector>
using namespace std;

double ffind(vector<int>&& nums1, vector<int>&& nums2) {

    int total_len = nums1.size() + nums2.size();
    int mid = total_len / 2;
    bool two = (total_len % 2 == 0);

    if (two)
        mid -= 1;

    int mid2 = mid + 1;
    int th1 = 0, th2 = 0;

    bool flag1 = true;
    bool flag2 = false;

    bool last;
    bool second_last;

    double mid_val;

    if (nums1.size() == 0 || nums2.size() == 0) {
        vector<int> &arr = (nums1.size() == 0 ? nums2 : nums1);
        if (!two)
            return (double)arr[arr.size() / 2];
        else
            return ((arr[arr.size() / 2 - 1] + arr[arr.size() / 2]) / 2.0);
    }
    
    for (int i = 0; i < mid2; ++i) {
        if (th1 < nums1.size() && (nums1[th1] < nums2[th2] || th2 == nums2.size()))
            ++th1, last = flag1;
        else 
            ++th2, last = flag2;
    }

    if (two) {
        if (th1 < nums1.size() && (nums1[th1] < nums2[th2] || th2 == nums2.size()))
            second_last = flag1;
        else 
            second_last = flag2;
    }

    mid_val = (last == flag1 ? nums1[th1-1] : nums2[th2 - 1]);

    if (two) {
        mid_val = (mid_val + (second_last == flag1 ? nums1[th1] : nums2[th2])) / 2.0;
    }


    return mid_val;
}

int main() {

    cout << ffind({1, 2}, {3, 4}) << endl;

    return 0;
}
