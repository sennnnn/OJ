#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
// #include <algorithm>

using namespace std;

typedef struct disc{
    int size;
}disc;

vector<disc> plar_a;
vector<disc> plar_b;
vector<disc> plar_c;

vector<disc> hanoi[3] = {plar_a, plar_b, plar_c};

int charToVector(char flag){
    switch(flag){
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        default:
            printf("There is no %c pillar\n", flag);
            exit(0);
    }
}

int step_i = 0;
int n;

void plot_tower_state(){
    int flag;
    for(int i = n-1; i >= 0; i--){
        flag = 0;
        if(i < hanoi[0].size() || i < hanoi[1].size() || i < hanoi[2].size()) flag = 1;
        
        if(i < hanoi[0].size()){
            printf("%d ", hanoi[0][i]);
        }else if(flag == 1) printf("- ");

        if(i < hanoi[1].size()){
            printf("%d ", hanoi[1][i]);
        }else if(flag == 1) printf("- ");

        if(i < hanoi[2].size()){
            printf("%d ", hanoi[2][i]);
        }else if(flag == 1) printf("- ");

        printf("\n");
    }
}

void move(int num, char start, char stop){
    int go_index = charToVector(start);
    int to_index = charToVector(stop);
    disc disc_go = hanoi[go_index][hanoi[go_index].size()-1];
    int to_size = hanoi[to_index].empty() ? 999999 : hanoi[to_index][hanoi[to_index].size()-1].size;
    if(num != disc_go.size){
        printf("Error! The function parameter 'num': %d can't match the real value 'size_go': %d\n", num, disc_go.size);
        exit(-1);
    }
    if(disc_go.size > to_size){
        printf("Error! The size_go (%d) > size_to (%d)\n", disc_go.size, to_size);
        exit(-1);
    }
    step_i++;
    printf("The %d step move number %d disc from %c to %c\n", step_i, num, start, stop);
    hanoi[go_index].pop_back();
    hanoi[to_index].push_back(disc_go);
    plot_tower_state();
}

void hanoi_tower(int num, char a, char b, char c){
    if(num == 1){
        move(num, a, c);
        return;
    }
    hanoi_tower(num-1, a, c, b);
    move(num, a, c);
    hanoi_tower(num-1, b, a, c);
}

int main(){
    while(scanf("%d", &n) != EOF){
        for(int i = n; i > 0; i--){
            disc temp;
            temp.size = i;
            hanoi[0].push_back(temp);
        }
        printf("========begin==========\n");
        plot_tower_state();
        hanoi_tower(n, 'a', 'b', 'c');
    }
}

