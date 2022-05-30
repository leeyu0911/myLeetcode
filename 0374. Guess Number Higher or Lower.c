//
// Created by leeyu on 2022/5/29.
// https://leetcode.com/problems/guess-number-higher-or-lower/


/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n){
    long int left = 0;
    long int right = n;
    long int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        int g = guess(mid);
        if (g == 0)
            return mid;
        else if (g == -1)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return 0;
}