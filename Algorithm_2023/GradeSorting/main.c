//#include <stdio.h>
//
//int main() {
//    printf("Hello World!");
//
//    return 0;
//}
//
// Created by Sojeong Shin on 2023/10/04.
//

//#pragma warning(disable :4996)
//#define MAX_LEN 100
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//int score[MAX_LEN];         // 점수 초기저장
//
//int in_rank;   // 사용자로부터 받은 등수 input
//int in_score;   // 사용자로부터 받은 점수 input
//char grade;
//
//int cnt_ppl ;   // 총 학생 수
//int A, B, C;    // 학점당 학생 수
//char a_grade;   // A학점 마지막 학생의 점수
//char b_grade;   // B학점 마지막 학생의 점수
//
//
///////// selection Algorithm ///////
//int Selection(int pivot, int l, int r, int which) {
//
//    // 탈출조건
//    if ( (pivot <0 || pivot >= cnt_ppl) ||
//         (l <0 || l >= cnt_ppl) ||
//         (r <0 || r >= cnt_ppl)) {
//        printf("exit:: found location %d, which is %d\n", which+1, score[which]);
//        return 0;
//    }
//
//    // 기본적인 quick sort
//    int left = l;
//    int right = r;
//
//    while (1) {
//        // pivot보다 작은 숫자들 pass
//        while (score[pivot] > score[left]) {
//            left++;
//        }
//        // pivot보다 큰 숫자들 pass
//        while (score[pivot] < score[right]) {
//            right--;
//        }
//
//        // large group과 small group을 만들기 위해
//        // pivot보다 큰 left와 피봇보다 작은 right의 자리를 바꿈
//        if (left < right) {
//            int temp = score[left];
//            score[left] = score[right];
//            score[right] = temp;
//        }
//        else {  // small group과 large group으로 나뉜 상태
//            if (right == which) { // 내가 찾는 위치 which가 right와 동일하다면
//                //printf("found %d number is %d\n", right+1, score[pivot]);
//                return score[pivot];
//            }
//            else {
//                // pivot과 right의 위치 바꿈
//                int temp = score[pivot];
//                score[pivot] = score[right];
//                score[right] = temp;
//
//                // 내가 찾고자하는 which가 right의 왼쪽인지, 오른쪽인지 검사
//                if (which < right) { // small group 배열만 확인
//                    return Selection(pivot,pivot+1,right-1,which);
//                }
//                else { // large group 배열만 확인
//                    return Selection(right+1,right+2,right,which);
//                }
//            }
//        }
//    }
//}
//
//
//
//
//void init()
//{
//    /////// 파일 읽어오기 ///////
//    FILE *fs;
//    char str[MAX_LEN];
//    fs = fopen("/Users/sojeongshin/CLionProjects/Algorithm/GradeSorting/grade.txt", "r+");
//
//    /////// 파일 문자열을 정수화하여 배열에 넣음 ///////
//    while (feof(fs) == 0) {
//        fgets(str, MAX_LEN, fs);
//        score[cnt_ppl] = atoi(str); // 문자열을 정수화
//        cnt_ppl++;
//    }
//    fclose(fs); // 파일 닫기
//}
//
//
//
///////// 원하는 학생의 원점수를 가져오는 함수 ///////
//int getScore()
//{
////    printf("석차 %d등의 점수: %d점\n", in_rank, grade_score[in_rank]);
//
//    int rank_score = Selection(0, 1, cnt_ppl-1, in_rank-1);
//    return rank_score;
//
//}
//
//
//void evalGrade()
//{
//    /////// A, B, C로 학점 나누기(내림 적용) ///////
//    A = floor(cnt_ppl / 10 * 3);
//    B = floor(cnt_ppl / 10 * 5);
//    C = cnt_ppl - (A+B);
//
//    a_grade = Selection(0, 1, cnt_ppl -1, A-1);
//    b_grade = Selection(0, 1, cnt_ppl -1, B-1);
//
//    if (in_score >= score[a_grade-1]){ grade = 'A';}
//    else if (score[b_grade-1] > in_score && in_score >= score[C+1]) { grade = 'B';}
//    else { grade = 'C';}
//}
//
//
////////// 최종 결과 출력하기 /////////
//void run()
//{
//    printf("2020001581 신소정\n");
//
//    /////// 사용자로부터 점수를 입력 받고 배열에 넣음 ///////
//    printf("점수를 확인할 등수를 입력 해 주세요: ");
//    scanf("%d", &in_rank);
//
//    printf("본인의 원 점수를 입력 해 주세요: ");
//    scanf("%d", &in_score);
//    score[++cnt_ppl] = in_score;
//
//
//    /////// 등수의 원점수를 찾는 selection function 호출 -> which = 등수(석차) -1 ///////
//    printf("석차 %d등의 점수: %d점\n", in_rank, getScore());
//
//    evalGrade();
//
//    /////// 총 학생수 출력 ///////
//    printf("총 학생 수(본인 포함): %d 명\n", cnt_ppl);
//
//    //////// 학점, 석차 출력하기 /////////
//    printf("학점 당 학생 수| A: %d명, B: %d명, C: %d명\n", A,B,C);
//
//    printf("A학점 마지막 석차 학생의 원점수: %d점\n", a_grade);
//    printf("B학점 마지막 석차 학생의 원점수: %d점\n", b_grade);
//
//    /////// 사용자 점수로 학점 계산
//    evalGrade();
//    printf("신소정 학생은 현재 %c 학점에 해당하는 석차에 있습니다.\n", grade);
//
//}
//
//
//int main() {
//    init();
//    run();
//}