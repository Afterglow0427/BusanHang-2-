#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#define LEN_MIN 15
#define LEN_MAX 50
#define PROB_MIN 10
#define PROB_MAX 90

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

    int width;
    int p = rand() % 100;

    printf("train length(15~50)>>");
    scanf_s("%d", &width);

    if (width<LEN_MIN || width>LEN_MAX) {
        exit(0);
    }

    printf("percentile probability 'p'(10~90)>>");
    scanf_s("%d", &p);

    if (p<PROB_MIN || p>PROB_MAX) {
        exit(0);
    }
    int i;
    for (i = 0; i <= width; i++) {
        printf("#");
    }
    printf("\n");
    printf("#");


    // 세 사람의 위치->변수: citizen_loc, dongseok_loc, zombie_loc 각각이 몇 번 열인지
    int citizen_loc = width - 4;
    int zombie_loc = width - 1;
    int dongseok_loc = width;
    int prev_citizen_loc, prev_zombie_loc;
    // 출력

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

    int turn = 0;
    //반복
    while (1) {

        // 이벤트
        turn++;
        prev_citizen_loc = citizen_loc;
        prev_zombie_loc = zombie_loc;


        //시민 이동: citizen_loc 가 변함
        if (turn == 1 || turn % 2 == 1) {
            int citizen = rand() % 100;
            if (citizen >= p) {
                citizen_loc--;
            }
            else {
                citizen_loc;
            }

            //좀비 이동 :zombie_loc가 변함.
            int zombie = rand() % 100;
            if (zombie >= p) {
                zombie_loc--;
            }
            else {
                zombie_loc;
            }
        }
        else if (turn % 2 == 0) {
            int citizen = rand() % 100;
            if (citizen >= p) {
                citizen_loc--;
            }
            else {
                citizen_loc;
            }

            //좀비 이동 :zombie_loc가 변함.
            int zombie = rand() % 100;
            if (zombie < 100) {
                zombie_loc;
            }

        }

        // 출력

        for (i = 0; i <= width; i++) {
            printf("#");
        }
        printf("\n");
        printf("#");

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
        printf("#");
        printf("\n");
        for (i = 0; i <= width; i++) {
            printf("#");
        }
        printf("\n\n");
        //시민,좀비 상태 출력
        //시민
        if (citizen_loc < prev_citizen_loc) {
            printf("citizen : %d -> %d", prev_citizen_loc - 1, citizen_loc - 1);

        }
        else {
            printf("citizen : stay %d", prev_citizen_loc - 1);
        }
        printf("\n");
        //좀비
        if (turn % 2 == 0) {
            printf("zombie : stay %d (cannot move)", zombie_loc - 2);
        }

        else if (turn == 1 || turn % 2 == 1) {
            if (zombie_loc < prev_zombie_loc) {
                printf("zombie : %d -> %d", prev_zombie_loc - 2, zombie_loc - 2);
            }
            else {
                printf("zombie : stay %d", prev_zombie_loc - 2);
            }
        }


        printf("\n");




        //게임 결과
        if (citizen_loc == 2) {
            break;
        }
        if (zombie_loc - citizen_loc == 1) {
            break;
        }


        printf("\n\n");

        Sleep(4000);
    }
    if (citizen_loc == 2) {
        printf("\n");
        printf("SUCCESS!\n");
        printf("Citizen(s) escaped to the next train\n");
    }
    else {
        printf("\n");
        printf("GAME OVER!\n");
        printf("Citizen(s) has(have) been attacked by a zombie\n");
    }

    return 0;
}









