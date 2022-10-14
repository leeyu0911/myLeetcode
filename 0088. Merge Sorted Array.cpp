//
// Created by leeyu on 2022/10/14.
//
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = m - 1, n2 = n - 1, t = m + n -1;
        while (n1 >= 0 && n2 >= 0) {
            if (nums1[n1] > nums2[n2]) {
                nums1[t] = nums1[n1];
                --n1;
            } else {
                nums1[t] = nums2[n2];
                --n2;
            }
            --t;
        }
        while (n2 >= 0) {
            nums1[t] = nums2[n2];
            --t;--n2;
        }
    }
};