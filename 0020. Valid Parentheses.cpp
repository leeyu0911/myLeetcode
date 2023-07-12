//
// Created by leeyu on 2023/7/12.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        for (auto c: s) {
            if (c == '(' || c == '[' || c == '{') {
                queue.push_back(c);
            } else {
                if (!queue.empty()) {
                    char cc = queue.back();
                    queue.pop_back();
                    if ((c == ')' && cc == '(') ||
                        (c == ']' && cc == '[') ||
                        (c == '}' && cc == '{')) {
                        continue;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        if (queue.empty())
            return true;
        else
            return false;
    }
private:
    vector<char> queue;
};

int main() {
    Solution S = Solution();
    cout << S.isValid("()") << endl;
}