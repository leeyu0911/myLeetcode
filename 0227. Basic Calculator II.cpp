//
// Created by leeyu on 2023/7/15.
//
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int calculate(string s) {
        if (s.length() == 0 ) return 0;

        int sum = 0;
        int the_num = 0;
        int pre_num = 0;
        char sign = '+';

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                the_num = int(c - '0') + the_num * 10;
            }

            if (!isdigit(c) && !iswspace(c) || i == s.length() - 1) {
                switch (sign) {
                    case '+':
                        sum += pre_num;
                        pre_num = the_num;
                        break;
                    case '-':
                        sum += pre_num;
                        pre_num = -the_num;  // fix the last sigh is subtraction
                        break;
                    case '*':
                        pre_num *= the_num;
                        break;
                    case '/':
                        pre_num /= the_num;
                        break;
                }
                sign = c;
                the_num = 0;
            }
        }

        return sum + pre_num;
    }
};


int main() {
    Solution S = Solution();
    cout << S.calculate(" 3/2 ") << endl;
    cout << S.calculate("0-2147483647") << endl;
}