#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#define LEN_MIN 15
#define LEN_MAX 50
#define PROB_MIN 10
#define PROB_MAX 90

//함수 선언
void printTrain();
void printStatus(int turn);
void moveCitizen();
void moveZombie(int turn);
void reset();
void user();
void GameResult();

int width, p, citizen_loc, zombie_loc, dongseok_loc, prev_citizen_loc, prev_zombie_loc;

//기차 길이 출력
void printTrain() {
    int i;
    for (i = 0; i <= width; i++) {
        printf("#");
    }
    printf("\n#");

    for (int i = 2; i <= width; i++) {
        if (i == citizen_loc) {
            printf("C");
        }
        else if (i == dongseok_loc) {
            printf("M");
        }
        else if (i == zombie_loc) {
            printf("Z");
        }
        else {
            printf(" ");
        }
    }
    printf("#\n");
    for (i = 0; i <= width; i++) {
        printf("#");
    }
    printf("\n\n");
}

// 상태 출력 함수
void printStatus(int turn) {
    if (citizen_loc < prev_citizen_loc) {
        printf("citizen : %d -> %d\n", prev_citizen_loc - 1, citizen_loc - 1);
    }
    else {
        printf("citizen : stay %d\n", prev_citizen_loc - 1);
    }

    if (turn % 2 == 0) {
        printf("zombie : stay %d (cannot move)\n", zombie_loc - 2);
    }
    else {
        if (zombie_loc < prev_zombie_loc) {
            printf("zombie : %d -> %d\n", prev_zombie_loc - 2, zombie_loc - 2);
        }
        else {
            printf("zombie : stay %d\n", prev_zombie_loc - 2);
        }
    }
    printf("\n");
}

// 시민 이동 함수
void moveCitizen() {
    int citizen = rand() % 100;
    if (citizen >= p) {
        citizen_loc--;
    }
}

// 좀비 이동 함수
void moveZombie(int turn) {
    int zombie = rand() % 100;
    if ((turn == 1 || turn % 2 == 1) && zombie >= p) {
        zombie_loc--;
    }
}

// 초기화 함수
void reset() {
    citizen_loc = width - 4;
    zombie_loc = width - 1;
    dongseok_loc = width;
}

// 사용자 입력 함수
void user() {
    printf("train length(15~50)>>");
    scanf_s("%d", &width);

    if (width < LEN_MIN || width > LEN_MAX) {
        exit(0);
    }

    printf("percentile probability 'p'(10~90)>>");
    scanf_s("%d", &p);

    if (p < PROB_MIN || p > PROB_MAX) {
        exit(0);
    }
}

// 게임 결과 출력 함수
void GameResult() {
    if (citizen_loc == 2) {
        printf("\nSUCCESS!\nCitizen(s) escaped to the next train\n");
    }
    else {
        printf("\nGAME OVER!\nCitizen(s) has(have) been attacked by a zombie\n");
    }
}

//main(void) 시작
int main(void) {
    srand((unsigned int)time(NULL));


    printf("\n\n\n\n");

    printf("######    ##  ##   #####      ##    ##   ##           #######   #####   ##   ##  ######    ######  #######\n");
    printf("##  ##   ##  ##  ##   ##    ####   ###  ##           ##   ##  ##   ##  ### ###   ##  ##     ##     ##  ##\n");
    printf(" ##  ##   ##  ##  ##        ##  ##  #### ##               ##   ##   ##  #######   ##  ##     ##     ##\n");
    printf(" #####    ##  ##   #####    ######  ## ####              ##    ##   ##  ## # ##   #####      ##     ####\n");
    printf("##  ##   ##  ##       ##   ##  ##  ##  ###             ##     ##   ##  ##   ##   ##  ##     ##     ##\n");
    printf("##  ##   ##  ##  ##   ##   ##  ##  ##   ##            ##  ##  ##   ##  ##   ##   ##  ##     ##     ##  ##\n");
    printf("######     ####    #####    ##  ##  ##   ##           #######   #####   ##   ##  ######    ######  #######\n");

    Sleep(3000);
    void clear(); {

        system("cls");

    }
    user();
    reset();
    printTrain();

    int turn = 0;
    while (1) {
        turn++;
        prev_citizen_loc = citizen_loc;
        prev_zombie_loc = zombie_loc;

        moveCitizen();
        moveZombie(turn);

        printTrain();
        printStatus(turn);

        if (citizen_loc == 2 || zombie_loc - citizen_loc == 1) {
            break;
        }

        Sleep(4000);
    }

   GameResult();
    return 0;
}









