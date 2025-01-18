#include <stdio.h>

int main()
{
    int faces, freq = 0;
    int v[6] = {0,0,0,0,0,0};
    while (scanf("%d", &faces) != EOF){
        switch(faces){
            case 1: v[0]++;
                break;
            case 2: v[1]++;
                break;
            case 3: v[2]++;
                break;
            case 4: v[3]++;
                break;
            case 5: v[4]++;
                break;
            case 6: v[5]++;
                break;
        } 
    }
    for (int i =0; i<6; i++){
        if (freq < v[i]){
            freq = v[i];
        }
        
    }
    for (int j = 0; j<6; j++){
        if (v[j] == freq){
            printf("%d\n", j+1);
        }
    }
    printf("%d", freq);

    return 0;
}
