#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
//2-2 �λ���(1)���� ����
//�Ķ����
#define LEN_MIN 15  //���� ����
#define LEN_MAX 50
#define STM_MIN 0   //������ ����
#define STM_MAX 5
#define PROB_MIN 10 //Ȯ��
#define PROB_MAX 90
#define AGGRO_MIN 0 //��׷� ����
#define AGGRO_MAX 5

//������ �̵� ����
#define MOVE_LEFT 1
#define MOVE_STAY 0

//������ ���� ���
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2

//������ �ൿ
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2


//2-1 20�� �̳� �Լ��� �ڵ� ���̱�

int width, p, stm, dongseok, citizen_loc, zombie_loc, dongseok_loc, prev_citizen_loc, prev_zombie_loc;
int aggro = 0;
//�Լ� ����
void printTrain();
void printStatus(int turn);
void moveCitizen();
void moveZombie(int turn);
void moveDongseok();
void reset();
void user();
void userDongseok();
void GameResult();



//���� ���� ���
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

// ���� ��� �Լ�
void printStatus(int turn) {
    if (citizen_loc < prev_citizen_loc) {
        printf("citizen : %d -> %d (aggro: %d)\n", prev_citizen_loc - 1, citizen_loc - 1,aggro);

    }
    else {
        printf("citizen : stay %d (aggro: %d)\n", prev_citizen_loc - 1,aggro);
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

// �ù� �̵� �Լ�
void moveCitizen() {
    int citizen = rand() % 100;
    if (citizen >= p) {
        citizen_loc--;
        aggro++;
    }
    else {
        aggro--;
    }
}

// ���� �̵� �Լ�
void moveZombie(int turn) {
    int zombie = rand() % 100;
    if ((turn == 1 || turn % 2 == 1) && zombie >= p) {
        zombie_loc--;
    }
}

//���� �̵� �Լ�
void moveDongseok() {
    if (MOVE_STAY == dongseok) {
        dongseok_loc;
    }
    else if (MOVE_LEFT == dongseok) {
        dongseok_loc--;
    }
    
}
// �ʱ�ȭ �Լ�
void reset() {
    citizen_loc = width - 4;
    zombie_loc = width - 1;
    dongseok_loc = width;
}

// ����� �Է� �Լ�//2-2 �Է°� ó��
void user() {
    while (1) {
        printf("train length(15~50)>>");
        scanf_s("%d", &width);
        if (width >= LEN_MIN && width <= LEN_MAX) {
            break;
        }
    }

    while (1) {
        printf("madongseok stamina(0~5)>>");
        scanf_s("%d", &stm);
        if (stm >= STM_MIN && stm <= STM_MAX) {
            break;
        }

    }

    while (1) {
        printf("percentile probability 'p'(10~90)>>");
        scanf_s("%d", &p);
        if (p >= PROB_MIN && p <= PROB_MAX) {
            break;
        }
    }
}
//���� �Է� �Լ�
void userDongseok() {
    while (1) {
        printf("madongseok move(0:stay, 1:left)>>");
        scanf_s("%d", &dongseok);
        if (dongseok == MOVE_LEFT || dongseok == MOVE_STAY) {
            break;
        }
    }

}
// ���� ��� ��� �Լ�
void GameResult() {
    if (citizen_loc == 2) {
        printf("\nSUCCESS!\nCitizen(s) escaped to the next train\n");
    }
    else {
        printf("\nGAME OVER!\nCitizen(s) has(have) been attacked by a zombie\n");
    }
}

//main(void) ����
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

    Sleep(1000);
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

        userDongseok();
        moveDongseok();
        

        if (citizen_loc == 2 || zombie_loc - citizen_loc == 1) {
            break;
        }

        
    }

   GameResult();
    return 0;
}









