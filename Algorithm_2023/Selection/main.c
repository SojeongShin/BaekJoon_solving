#pragma warning(disable :4996)
#define MAX_LEN 100
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int score[MAX_LEN];         // 점수 초기저장

int in_rank;   // 사용자로부터 받은 등수 input
int in_score;   // 사용자로부터 받은 점수 input
char grade;

int cnt_ppl ;   // 총 학생 수
int A, B, C;    // 학점당 학생 수
char a_grade;   // A학점 마지막 학생의 점수
char b_grade;   // B학점 마지막 학생의 점수

void swap(int arr[MAX_LEN], int idx1, int idx2) {
    int temp = score[idx1];
    score[idx1] = score[idx2];
    score[idx2] = temp;
}

/////// selection Algorithm ///////
int Selection(int arr[MAX_LEN], int l, int r, int which) {

    if(l == r) return arr[l];
    int left = l + 1;
    int right = r;
    int pivot = (left+right)/2;

    swap(arr, pivot, l);

    while (left <= right) {
        // pivot보다 작은 숫자들 pass
        while (left <= r && arr[left] <= arr[l]) left++;
        while (right >= l && arr[right] >= arr[l]) right--;
        if (left > right) break;
        swap(arr, right, left);
    }
    swap(arr, l, r);
    int smallGroupSize = right - left;

    if (which <= smallGroupSize+1) {
        return Selection(arr, right+1, l, which - (smallGroupSize+1));
    }
}


void init()
{
    /////// 파일 읽어오기 ///////
    FILE *fs;
    char str[MAX_LEN];
    fs = fopen("/Users/sojeongshin/CLionProjects/Algorithm/GradeSorting/grade.txt", "r+");

    /////// 파일 문자열을 정수화하여 배열에 넣음 ///////
    while (feof(fs) == 0) {
        fgets(str, MAX_LEN, fs);
        score[cnt_ppl] = atoi(str); // 문자열을 정수화
        cnt_ppl++;
    }
    fclose(fs); // 파일 닫기
}



/////// 원하는 학생의 원점수를 가져오는 함수 ///////
int getScore()
{
//    printf("석차 %d등의 점수: %d점\n", in_rank, grade_score[in_rank]);
    int rank_score = Selection(score, 0, cnt_ppl-1, cnt_ppl - in_rank +1);
    return rank_score;
}


void evalGrade()
{
    /////// A, B, C로 학점 나누기(내림 적용) ///////
    A = floor(cnt_ppl / 10 * 3);
    B = floor(cnt_ppl / 10 * 5);
    C = cnt_ppl - (A+B);

    a_grade = Selection(score, 0, cnt_ppl -1, cnt_ppl - A+1);
    b_grade = Selection(score, 0, cnt_ppl -1, cnt_ppl - B+1);

    if (in_score >= a_grade){ grade = 'A';}
    else if (a_grade> in_score && in_score >= b_grade) { grade = 'B';}
    else { grade = 'C';}
}


//////// 최종 결과 출력하기 /////////
void run()
{
    printf("2020001581 신소정\n");

    /////// 사용자로부터 점수를 입력 받고 배열에 넣음 ///////
    printf("점수를 확인할 등수를 입력 해 주세요: ");
    scanf("%d", &in_rank);

    printf("본인의 원 점수를 입력 해 주세요: ");
    scanf("%d", &in_score);
    score[++cnt_ppl] = in_score;


    /////// 등수의 원점수를 찾는 selection function 호출 -> which = 등수(석차) -1 ///////
    printf("석차 %d등의 점수: %d점\n", in_rank, getScore());

    evalGrade();

    /////// 총 학생수 출력 ///////
    printf("총 학생 수(본인 포함): %d 명\n", cnt_ppl);

    //////// 학점, 석차 출력하기 /////////
    printf("학점 당 학생 수| A: %d명, B: %d명, C: %d명\n", A,B,C);

    printf("A학점 마지막 석차 학생의 원점수: %d점\n", a_grade);
    printf("B학점 마지막 석차 학생의 원점수: %d점\n", b_grade);

    /////// 사용자 점수로 학점 계산
    printf("신소정 학생은 현재 %c 학점에 해당하는 석차에 있습니다.\n", grade);

}


int main() {
    init();
    run();
}