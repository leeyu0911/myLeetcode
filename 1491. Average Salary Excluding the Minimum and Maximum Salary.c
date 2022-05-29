//
// Created by leeyu on 2022/5/29.
// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/



double average(int* salary, int salarySize){
    int min = 1000000;
    int max = 1000;
    int sum = 0;
    for (int i = 0; i < salarySize; ++i) {
        sum += salary[i];
        if (salary[i] < min) min = salary[i];
        if (salary[i] > max) max = salary[i];
    }
    sum = sum - max - min;
    double avg = (double)sum / (double)(salarySize-2);
    return avg;
}
