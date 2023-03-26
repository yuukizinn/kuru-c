#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sum.h"
#include <unistd.h>

#define EXCISETAX 0.03 //chap.18
#define PRINT_TEMP printf("temp = %d\n", temp) //chap.18
#define PRINTM(X) printf("%d\n", X) //chap.18

enum {
    NOTHING = 0,
    SUMMER = 1,
    WINTER = 2,
}; //chap.18

typedef struct {
    char name[64];
    int age;
    char sex[6];
} people; //chap.16

int chapter3(void), chapter4(void), chapter5(void), chapter6(void), chapter7(void), 
chapter8(void), chapter9(void), chapter10(void), chapter11(void), chapter13(void), 
chapter14(void), chapter15(void), chapter16(void), chapter17(void), chapter18(void), 
chapter19(void), chapter20(void);

int culc(int); //chap.11
void maxmin(int num, int *max, int *min); //chap.15
void printdata(people pe[]); //chap.16
void insertdata(people pe[]); //chap.16
int culc_enum(int); //chap.18
void printdata_heap(people heap); //chap.19
void insertdata_heap(people heap[]); //chap.19

int ft_putchar(char c) {
    write(1, &c, 1);
    return 0;
}

void rush(int x, int y) {
    int tmp_x = x;
    int tmp_y = y;
    while (0 < y) {
        while (0 < x) {
            if (x == tmp_x || x == tmp_x - tmp_x + 1) {
                if(y == tmp_y || y == tmp_y - tmp_y + 1) {
                    ft_putchar('o');
                } else {
                    ft_putchar('|');
                }
            } else {
                if(y == tmp_y || y == tmp_y - tmp_y + 1) {
                    ft_putchar('-');
                } else {
                    ft_putchar(' ');
                }
            }
            x = x -1;
        }
        x = tmp_x;
        y = y -1;
        printf("\n");
    }
}

int main(int argc, char *argv[]){
    // chapter19();
    // int value;
    // value = sum(10, 100);
    // printf("%d", Public);

    rush(5,5);
    return 0;
}





int chapter3(void) {
    printf("Intel\t: Core i7\n");
    printf("AMD\t: Phenom Ⅱ\n");
    return 0;
}

int chapter4(void) {
    printf("%d / %d = %d...%d\n", 40, 13, 40 / 13, 40 % 13);
    return 0;
}

int chapter5(void) {
    int juice, milk, sum, change;
    float tax;
    juice = 198;
    milk = 138;
    tax = 1.05;
    
    sum = (juice + milk * 2) * tax;
    change = 1000 - sum;
    printf("お釣りは%d円\n", change);
    return 0;
}

int chapter6(void) {
    int price;

    scanf("%d", &price);
    printf("1割引だと%d円\n", (int)(price - (price * 0.1)));
    printf("3割引だと%d円\n", (int)(price - (price * 0.3)));
    return 0;
}

int chapter7(void) {
    int year;

    scanf("%d", &year);
    if(year % 4 == 0) {
        printf("%d年は冬季オリンピックが開催されます。", year);
    }else if(year % 2 == 0 && year % 4 != 0) {
        printf("%d年は夏季オリンピックが開催されます。", year);
    }
    return 0;
}

int chapter8(void) {
    int month;

    scanf("%d", &month);
    switch(month) {
        case 1:
            printf("睦月");
            break;
        case 2:
            printf("如月");
            break;
        case 3:
            printf("弥生");
            break;
        default:
            printf("月なし");
    }
    return 0;
}

int chapter9(void) {
    int i;
    int j;

    for(i = 1; i <= 9; i++) {
        for(j = 1; j <= 9; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
    return 0;
}

int chapter10(void) {
    int score;

    do {
        if(score != 0) {
            printf("0~100の値を入力してください。\n");
        }
        printf("点数を入力してください。\n");
        scanf("%d", &score);
    } while(score < 0 || score > 100);
    printf("入力された点数%d\n", score);
    return 0;
}

int chapter11(void) {
    int year, hold;

    scanf("%d", &year);
    hold = culc(year);

    switch(hold) {
        case 0:
            printf("開かれない");
            break;
        case 1:
            printf("夏季五輪");
            break;
        case 2:
            printf("冬季五輪");
            break;
    }
    return 0;
}
int culc(int year) {
    if(year % 2 == 0) {
        if(year % 4 == 0) {
            return 1;
        } else {
            return 2;
        }
    } else {
        return 0;
    }
}

int chapter13(void) {
    int i;
    int num;
    int array[10];

    for(i = 0; i <= 9; i++) {
        scanf("%d", &num);
        array[i] = num;
    }
    for(i = 9; i >= 0; i--) {
        printf("%d", array[i]);
    }
    return 0;
}

int chapter14(void) {
    char str[20];
    char myoji[10];
    char namae[10];

    printf("%s", "苗字を入力してください。");
    scanf("%s", myoji);
    
    printf("%s", "名前を入力してください。");
    scanf("%s", namae);
    
    sprintf(str, "%s%s", myoji, namae);
    printf("%s", str);

    return 0;
}

int chapter15(void) {
    int i = 0;
    int array[10];
    array[9] = -1;
    int num;
    int max = 0;
    int min = 100;

    while(array[i] != -1) {
        scanf("%d", &array[i]);
        i++;
        if(array[i] == -1) {
            break;
        }
    } 
    for(i = 0; i < 9; i++) {
        printf("num = %d\n", array[i]);
        maxmin(array[i], &max, &min);
    }
    printf("max = %d\nmin = %d\n", max, min);
    return 0;
}

void maxmin(int num, int *max, int *min) {
    if(*max < num) {
        *max = num;
    }
    if (*min > num) {
        *min = num;
    }
}

int chapter16(void) {
    int i = 0;
    people pe[4];

    insertdata(pe);
    printdata(pe);
    
    return 0;
}

void insertdata(people pe[]) {
    int i;
    int select;

    for(i = 0; i < 3 ; i++) {
        printf("%d人目の情報を入力してください。\n", i + 1);

        printf("名前を入力してください。\n");
        scanf("%s", pe[i].name);
    
        printf("年齢を入力してください。\n");
        scanf("%d", &pe[i].age);
    
        printf("性別を入力してください。\n");
        printf("1：man　2：woman\n");
        scanf("%d", &select);
        if(select == 1) {
            strcpy(pe[i].sex, "man");
        } else if(select == 2) {
            strcpy(pe[i].sex, "woman");
        } else {
            printf("error");
        }
    }
} //chap.16

void printdata(people pe[]) {
    int i = 0;

    for(i = 0; i < 3; i++) {
        printf("%d人目の情報です。\n", i + 1);
        printf("名前：%s\n", pe[i].name);
        printf("年齢：%d\n", pe[i].age);
        printf("性別：%s\n", pe[i].sex);
    }
} //chap.16

int chapter17(void) {
    FILE *file;
    file = fopen("test.csv", "w");
    fprintf(file, "%d, %s, %d\n", 1, "野比のび太", 0);
    fprintf(file, "%d, %s, %d\n", 1, "野比のび太", 0);
    fprintf(file, "%d, %s, %d\n", 1, "野比のび太", 0);
    fprintf(file, "%d, %s, %d\n", 1, "野比のび太", 0);
    fclose(file);

    return 0;
}

int chapter18(void) {
    int year, hold;

    scanf("%d", &year);
    hold = culc(year);

    switch(hold) {
        case NOTHING:
            printf("開かれない");
            break;
        case SUMMER:
            printf("夏季五輪");
            break;
        case WINTER:
            printf("冬季五輪");
            break;
    }
    return 0;
}
int culc_enum(int year) {
    if(year % 2 == 0) {
        if(year % 4 == 0) {
            return SUMMER;
        } else {
            return WINTER;
        }
    } else {
        return NOTHING;
    }
}

int chapter19(void) {

    int i, count, datasize;
    people *heap;

    datasize = 10;
    heap = (people *)malloc(sizeof(people) * datasize);
    if(heap == NULL) exit(0);

    count = 0;
    while(1) {
        insertdata_heap(&heap[count]);
        if (heap[count].age < 0) break;
        count++;

        if (count > datasize) {
            datasize +=10;
            heap = (people *)realloc(heap, sizeof(people) * datasize);
        }
    }

    for(i = 0; i < count; i++) {
        printdata_heap(heap[i]);
    }

    free(heap);

    return 0;
}

void insertdata_heap(people heap[]) {
    printf("名前を入力してください。\n");
    scanf("%s", heap->name);
    printf("年齢を入力してください。\n");
    scanf("%d", &heap->age);
    printf("性別を入力してください。\n");
    scanf("%s", heap->sex);
} //chap.19

void printdata_heap(people heap) {
    printf("名前：%s\n", heap.name);
    printf("年齢：%d\n", heap.age);
    printf("性別：%s\n", heap.sex);
} //chap.19
