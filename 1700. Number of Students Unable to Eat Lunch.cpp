//
// Created by leeyu on 2023/8/4.
//
#include <iostream>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        while (sandwiches.size() != 0) {
            if (find(students.begin(), students.end(), sandwiches[0]) != students.end()) {
                if (sandwiches[0] == students[0]) {
                    sandwiches.erase(sandwiches.begin());
                    students.erase(students.begin());
                } else {
                    students.push_back(students[0]);
                    students.erase(students.begin());
                }
            } else {
                break;
            }
        }
        return students.size();
    }
};