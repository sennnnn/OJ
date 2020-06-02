
#define bool _Bool
#define true 1
#define false 0

bool isMatch(char * s, char * p){
    int len_s = len(s);
    int len_p = len(p);
    int i, j;
    bool flag[len_s+1][len_p+1];
    for(i = 0; i < len_s+1; i++)
        for(j = 0; j < len_p+1; j++){
            flag[i][j] = 0;
        }
    flag[len_s][len_p] = 1;
    bool temp;
    i = len_s; j = len_p; 
    for(; i >= 0 ; i--){
        for(j = len_p - 1; j >= 0; j--){
            temp = (s[i] && (s[i] == p[j] || p[j] == '.'));
            if(j + 1 < len_p && p[j+1] == '*'){
                flag[i][j] = flag[i][j+2] || temp && flag[i+1][j];
            }else flag[i][j] = (temp && flag[i+1][j+1]);
        }
    }
    return flag[0][0];
}