//
// Created by Sojeong Shin on 2023/10/04.
//

#pragma warning(disable :4996)
#define MAX_LEN 100
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int score[MAX_LEN];         // 점수 초기저장
int sorted_score[MAX_LEN];  // 오름차순 점수 저장
int grade_score[MAX_LEN];   // 등수확인을 위한 내림차순 점수 저장


int in_rank;   // 사용자로부터 받은 등수 input
int in_score;   // 사용자로부터 받은 점수 input
char grade;

int cnt_ppl ;   // 총 학생 수
int A, B, C;    // 학점당 학생 수


///////// 분할정복 알고리즘 ///////
void merge(int left, int right)
{
    int mid = (left + right) / 2;

    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right)
    {
        if (score[i] <= score[j])
            sorted_score[k++] = score[i++];
        else
            sorted_score[k++] = score[j++];
    }

    /////// 남아있는 레코드 일괄 복사 ///////
    if(i>mid) {
        for (int tmp = j; tmp <= right; tmp++) {
            sorted_score[k++] = score[tmp];
        }
    }
    else {
        for (int tmp = i; tmp <= mid; tmp++) {
            sorted_score[k++] = score[tmp];
        }
    }

    /////// sorted_score 배열을 score 배열에 재복사 ///////
    for (int i = left; i <= right; i++) score[i] = sorted_score[i];
}

void divide(int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        divide(left, mid);
        divide(mid + 1, right);
        merge(left, right);
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
void getScore()
{
    /////// score 배열을 내림차순으로 재복사 ///////
    int j=1;
    for (int i = cnt_ppl; i > 0; i--) {
        //printf("%d\n", score[i]);
        grade_score[j++] = score[i];
    }
    printf("석차 %d등의 점수: %d점\n", in_rank, grade_score[in_rank]);
}


void evalGrade()
{
    /////// A, B, C로 학점 나누기(내림 적용) ///////
    A = floor(cnt_ppl / 10 * 3);
    B = floor(cnt_ppl / 10 * 5);
    C = cnt_ppl - (A+B);

    if (in_score >= grade_score[A]){ grade = 'A';}
    else if (grade_score[A] > in_score && in_score >= grade_score[B]) { grade = 'B';}
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


    //////// 분할정복 함수 호출 ////////
    divide(0, cnt_ppl);

    getScore();
    evalGrade();

    /////// 총 학생수 출력 ///////
    printf("총 학생 수(본인 포함): %d 명\n", cnt_ppl);

    //////// 학점, 석차 출력하기 /////////
    printf("학점 당 학생 수| A: %d명, B: %d명, C: %d명\n", A,B,C);

    printf("A학점 마지막 석차 학생의 원점수: %d점\n", score[C + B + 1]);
    printf("B학점 마지막 석차 학생의 원점수: %d점\n", score[C+1]);

    /////// 사용자 점수로 학점 계산
    printf("신소정 학생은 현재 %c 학점에 해당하는 석차에 있습니다.\n", grade);

}


int main() {
    init();
    run();
}