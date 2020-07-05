/*
    题目名字: 谁拿了最多奖学金
    题目编号: 7906
    日期: 2020 年 6 月 29 日
*/

#include <stdio.h>
#include <string.h>

typedef struct student{
    char name[20];
    int score1;
    int score2;
    bool master;
    bool west;
    int paper_num;
    int money;
}student;

int main(){
    int N, max_i, max, sum;
    char temp;
    student _list[110];
    scanf("%d", &N);
    max = -1; sum = 0;
    for(int i = 0; i < N; i++){
        scanf("%s %d %d", _list[i].name, &_list[i].score1, &_list[i].score2); getchar();
        scanf("%c", &temp); if(temp == 'Y') _list[i].master = true; else _list[i].master = false; getchar();
        scanf("%c", &temp); if(temp == 'Y') _list[i].west = true; else _list[i].west = false;
        scanf("%d", &_list[i].paper_num);
        _list[i].money = 0;
        if(_list[i].score1 > 80 && _list[i].paper_num >= 1) _list[i].money += 8000;
        if(_list[i].score1 > 85 && _list[i].score2 > 80) _list[i].money += 4000;
        if(_list[i].score1 > 90) _list[i].money += 2000;
        if(_list[i].score1 > 85 && _list[i].west == true) _list[i].money += 1000;
        if(_list[i].score2 > 80 && _list[i].master == true) _list[i].money += 850;
        if(_list[i].money > max) {
            max = _list[i].money;
            max_i = i;
        }
        sum += _list[i].money;
    }
    printf("%s\n%d\n%d\n", _list[max_i].name, _list[max_i].money, sum);
}