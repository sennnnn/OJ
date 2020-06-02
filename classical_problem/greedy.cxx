#include <stdio.h>
#include <string.h>
#include <algorithm>

// HDU 1050 Accepted 0MS

using namespace std;

int flag[201];

int main(){
    int t,n;
    int go, to;
    while(scanf("%d", &t) != EOF){
        for(int i = 0; i < t; i++){
            scanf("%d", &n);
            memset(flag, 0, sizeof(int)*201);
            for(int j = 0; j < n; j++){
                scanf("%d %d", &go, &to);
                if(go > to){
                    int temp;
                    temp = go; go = to; to = temp;
                }
                go = (go-1)/2;
                to = (to-1)/2;
                for(int k = go; k <= to; k++){
                    flag[k] += 10;
                }
            }
            printf("%d\n", *max_element(flag, flag+200));
        }
        break;
    }
    return 0;
}


/* error method */
/***************/
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int flag[200];

// int len[200];

// int ifselect[200];

// void sort_(int *go, int *to, int n){
//     int temp;
//     for(int i = n-1; i > 0; i--){
//         for(int j = 0; j < i; j++){
//             if(len[j] > len[j+1]){
//                 temp = go[j]; go[j] = go[j+1]; go[j+1] = temp;
//                 temp = to[j]; to[j] = to[j+1]; to[j+1] = temp;
//                 temp = len[j]; len[j] = len[j+1]; len[j+1] = temp;
//             }
//         }
//     }
// }


// void flagSet(int start, int end){
//     for(int i = start; i <= end; i++){
//         flag[i] = 1;
//     }
// }


// bool checkFlag(int start, int end){
//     for(int i = start; i <= end; i++){
//         if(flag[i] == 1) return 1;
//     }
//     return 0;
// }

// int minTableMoveTime(int *go, int *to, int n){
//     if(n == 1) return 10;
//     memset(flag, 0, sizeof(int)*200);
//     memset(ifselect, 0, sizeof(int)*200);
//     sort_(go, to, n);
//     int select = 0;
//     int time = 0;
//     int i = 0;
//     int checkflag;
//     flagSet(go[i], to[i]); ifselect[i] = 1; i++; select++;
//     while(select != n){
//         checkflag = checkFlag(go[i], to[i]);
//         if(checkflag == 0 && ifselect[i] != 1){
//             select++;
//             flagSet(go[i], to[i]);
//             ifselect[i] = 1;
//         }
//         // printf("%d %d -- ", i, checkflag);
//         // for(int j = 0; j < n; j++){
//         //     printf("%d ", ifselect[j]);
//         // }
//         i++;
//         // printf("\n");
//         if(i == n){
//             time += 10;
//             i = 0;
//             memset(flag, 0, sizeof(int)*200);
//         }
//     }

//     return time;
// }


// int main(){
//     int t,n;
//     int start[200], end[200];
//     int count;
//     while(scanf("%d", &t) != EOF){
//         getchar();
//         for(int _ = 0; _ < t; _++){
//             scanf("%d", &n);getchar();
//             for(int i = 0; i < n; i++){
//                 scanf("%d %d", &start[i], &end[i]);
//                 start[i] = (start[i]-1)/2;
//                 end[i] = (end[i]-1)/2;
//                 if(start[i] > end[i]){
//                     int temp;
//                     temp = start[i]; start[i] = end[i]; end[i] = temp;
//                 }
//                 len[i] = end[i] - start[i];
//                 getchar();
//             }
//             count = minTableMoveTime(start, end, n);
//             printf("%d\n", count);
//         }
//     }
// }