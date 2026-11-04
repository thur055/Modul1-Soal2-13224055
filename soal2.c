#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

typedef struct Paket {
    int index;
    char key[10];
    char data[10];
} Paket;

char* strinv(char *str){
    int len = strlen(str);
    char *newline = (char*)malloc(sizeof(char)*len);
    int j = 0;
    for (int i = len - 1; i >= 0; i--){
        newline[j] = str[i];
        j++;
    }
    newline[len] = '\0';
    //printf("%s\n", newline);
    return newline;
}

void sortpaketindex(Paket *P, int N){
    Paket temp;
    for(int i = 0; i<N; i++){
        for (int j = i; j < N; j++){
            if (P[i].index > P[j].index){
                temp = P[i];
                P[i] = P[j];
                P[j] = temp;
            }
        }
    }
}

int main (){
    int N;
    char key[10];
    char newline[10];
    scanf("%d %s", &N, key);
    int count = 0;
    Paket P[N];
    for (int i = 0; i<N; i++){
        scanf("%d %s %s", &(P[i].index), P[i].key, newline);
        strcpy(P[i].data, strinv(newline));
        if (strcmp(P[i].key, key) != 0){
            P[i].index = 999;
            count++;
        }
    }
    int panjang = 0;
    sortpaketindex(P, N);
    if (count == N){
        printf("000");
    }
    else{
        for(int j = 0; j<N-count-1;j++){
            printf("%s ", P[j].data);
            panjang += strlen(P[j].data);
        }
        printf("%s", P[N-count-1].data);
        panjang += strlen(P[N-count-1].data);
        printf("\n");
        printf("LENGTH %d", panjang);
    }
    
   /*
   char key[10], newline[10];
   scanf("%s", key);
   strcpy(newline, strinv(key));
   printf("%s\n", newline);*/
}
