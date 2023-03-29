//
// Created by leeyu on 2023/3/29.
//
int addDigits(int num){
    while (num > 9) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}

int addDigits_re(int num){
    if (num < 10)
        return num;

    int sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }

    return addDigits_re(sum);
}

int addDigits_O1(int num){
    if (!num) return 0;
    else return num % 9 ? num % 9 : 9;
}