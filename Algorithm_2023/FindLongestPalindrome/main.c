#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 최대 문자열 길이 설정
#define MAX_LENGTH 1000

// 가장 긴 회문의 부분 문자열을 찾는 함수
int palindrome(char* S, int i, int j) {
    int max_s = 0, max_e = 0;
    int dp[MAX_LENGTH][MAX_LENGTH];
    int len = j - i + 1;    // 주어진 문자열의 길이

    // dp 배열 초기화
    for (int s = 0; s < len; ++s) {
        for (int e = 0; e < len; ++e) {
            dp[s][e] = 0;
        }
    }

    for (int s = len - 1; s >= 0; --s) {
        for (int e = s; e < len; ++e) {
            // 시작, 끝 인덱스가 같다면 문자 1개 이므로 문자열 길이가 1인 회문
            if (s == e) {
                dp[s][e] = 1;
            }
            // 시작, 끝의 인덱스의 차이가 1이고, 그 값이 같다면 'bb'형태의 회문
            else if (s + 1 == e) {
                dp[s][e] = (S[s] == S[e]) ? 1 : 0;
            }
            // 시작, 끝의 문자가 같고 그 안의 문자들 또한 회문
            else {
                dp[s][e] = (S[s] == S[e]) && dp[s + 1][e - 1];
            }

            if (dp[s][e] && max_e - max_s < e - s) {
                max_s = s;
                max_e = e;
            }
        }
    }
/*
    // 결과 문자열 할당 및 복사
    char* result = (char*)malloc((max_e - max_s + 2) * sizeof(char));
    strncpy(result, text + max_s, max_e - max_s + 1);
    result[max_e - max_s + 1] = '\0';
*/

    return max_e - max_s +1;
}

int main() {
    char S[] = "KBCDXBMBXCABAD";
    int result = palindrome(S, 0, 13);

    printf("The longest palindromic substring is: %d\n", result);

    // 메모리 해제
//    free(result);

    return 0;
}
