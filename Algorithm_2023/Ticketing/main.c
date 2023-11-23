#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

#define DATA_LEN 16 // 데이터(가족)의 수가 주어졌으므로, 사이즈에 대한 Definition

#define NUMOFTB 4 // Ticket Box(TB)의 개수
#define TB_STATUS_READY 0 // Ticket Box가 현재 다른 가족을 받을 수 있는 상태이면 Ready
#define TB_STATUS_SLEEP -1 // Ticket Box가 아무런 가족을 처리하고 있지 않으나, 일을 할 수 없는 상태이면 SLEEP
#define TB_STATUS_BUSY // 0보다 큰 정수는 모두 BUSY 상태로 정의(일을 하고 있는 중이며 가족 중 몇 명이 남았는지에 대한 수) : 실제 사용하진 않으나, 의미를 위해 정의하였음

int iData[DATA_LEN];

int static compare(const void* first, const void* second) // 퀵정렬의 오름차순 정렬을 위한 함수,  qsort 함수에 마지막 인자로 사용함
{
    if (*(int*)first > *(int*)second) // 정수에 대하여 첫번째 입력이 두번째 입력보다 크면 1
        return 1;
    else if (*(int*)first < *(int*)second) // 정수에 대하여 첫번째 입력이 두번째 입력보다 작으면 -1
        return -1;
    else
        return 0; // 정수에 대하여 첫번째 입력과 두번째 입력이 같으면 0
}


int init() // 파일에서 데이터를 읽어들이는 함수
{
    FILE* fp = NULL;
    int l_iReadVal = 0; // File에서 정수 부분을 저장하기 위한 변수
    char l_cReadVal = 0x00; // File에서 문자 부분을 저장하기 위한 변수
    int l_iRetVal = 0;
    unsigned int l_uiCount = DATA_LEN; // DATA_LEN과 같은 값인 리터럴 상수
    unsigned int l_uiShift = 0; // 텍스트 파일의 읽어 들인 라인 수를 표현 하는 변수


    fp = fopen("/Users/sojeongshin/CLionProjects/Algorithm/Ticketing/customer.txt", "r"); // File open.
    if (fp == NULL)
    {
        printf("File Open Fail()\n");
        return -1; // 파일을 여는데 실패하였다면, -1을 Return
    }

    while (!feof(fp)) {
        l_iRetVal = fscanf(fp, "%c %d\n", &l_cReadVal, &l_iReadVal); // 정해진 형식을 갖는 파일에서 숫자와 문자 읽어들이는 부분
        iData[l_uiShift++] = l_iReadVal * 100 + l_cReadVal; // 인원수와 알파벳으로 이루어진 번호표가 있을 때, 465 == 4명의 구성원 A(65)번 번호표를 가진 대기자

        if (l_uiCount <= l_uiShift)
            break;
    }
    fclose(fp);
}

void run()
{
    int numOfPass = 0;
    int time = 0;
    int i, j;
    char cTicketBox[NUMOFTB][18]; // Ticket Box의 6시부터 9시까지의 10분 단위의 결과들을 수집하기 위한 2차원 배열
    char cTicketBoxCur[4]; // 현재 처리 중인 티켓 알파벳을 저장하기 위한 변수이며, [0]:1번 Ticket Box의 현재 처리 중인 알파벳 번호
    int iTicketBoxState[4] = {TB_STATUS_READY, TB_STATUS_READY, TB_STATUS_SLEEP, TB_STATUS_SLEEP}; // 초기 Ticket Box 상태, 1번 2번은 Ticket Box는 준비 상태, 3, 4번은 SLEEP 상태

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 18; j++)
        {
            cTicketBox[i][j] = 'X'; // 변수 초기화
        }
    }
    qsort(iData+numOfPass, 6, sizeof(int), compare); // 7시 30분 이전의 앞선 여섯 가족에 대해서만 오름차순 정렬

    while (1)
    {
        if (time == 9) // t == 9일 때, 90분이 경과(7시 30분). 3, 4번 티켓 박스 활성화하고 7시 30분 이후 손님에 대하여 정렬.
        {
            iTicketBoxState[2] = TB_STATUS_READY; // 3번 티켓 박스 활성화
            iTicketBoxState[3] = TB_STATUS_READY; // 4번 티켓 박스 활성화
            qsort(iData + numOfPass, DATA_LEN-numOfPass, sizeof(int), compare); // 현재까지 처리된 가족 외에 처리되지 않은 가족과 7시 30분 이후 가족에 대해 정렬
        }

        for (i = 0; i < NUMOFTB; i++)
        {
            if (numOfPass < DATA_LEN) // len은 총 입력 가족 수(16), numOfPass는 이미 티켓 박스를 할당한 가족 수
            {
                if (iTicketBoxState[i] == TB_STATUS_READY) // i번째 Ticket Box가 Ready 상태라면 작업을 할당
                {
                    iTicketBoxState[i] = iData[numOfPass] / 100; // 100으로 나눴을 때 몫은 가족 구성원의 수
                    cTicketBoxCur[i] = iData[numOfPass] % 100; // 100으로 나눴을 때 나머지는 티켓 알파벳
                    numOfPass++; // 처리한 알파벳의 수는 1 증가
                }
            }

            if (iTicketBoxState[i] > 0) // i번째 Ticket Box가 일을 처리하는 중일 경우
            {
                iTicketBoxState[i]--; // 매 10분마다 1씩 감소하다가 0이 되면 다시 TB_STATUS_READY상태가 됨, 양수일 경우 BUSY 상태이며, 필요 처리 인원수 만큼 정수를 가짐
                cTicketBox[i][time] = cTicketBoxCur[i]; // 이번 10분 사이에 처리한 알파벳 기록
            }
        }
        time++; // 시간 10분 증가 => time 1 증가

        if ((iTicketBoxState[0] == 0) && (iTicketBoxState[1] == 0) && (iTicketBoxState[2] == 0) && (iTicketBoxState[3] == 0) && (numOfPass >= DATA_LEN))
            break; // 모든 Ticket Box의 상태가 TB_STATUS_READY이고 처리한 가족 수가 16 이상이라면 반복문 종료
    }


    // 처리된 최종 결과
    printf("202001581 신소정\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 18; j++)
        {
            printf("%c", cTicketBox[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    init();
    run();
}