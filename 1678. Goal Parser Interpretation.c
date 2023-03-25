//
// Created by leeyu on 2023/3/25.
//
char * interpret(char * command){
    char *ans = malloc(strlen(command) + 1);
    int j = 0;
    for (int i = 0; i < strlen(command); ++i) {
        if (command[i] == '(') {
            ++i;
            if (command[i] == ')') {
                ans[j++] = 'o';
            } else {
                ans[j++] = 'a';
                ans[j++] = 'l';
            }
        } else if (command[i] == 'G'){
            ans[j++] = 'G';
        }
    }
    ans[j] = '\0';
    return ans;
}