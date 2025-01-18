#include <stdio.h>
#include <string.h>

int main(){
    char s1[100];
    char s2[100];

    scanf("%s %s", s1, s2);

    int ns1 = strlen(s1);
    int ns2 = strlen(s2);

    char s3[ns1 + ns2 + 1];

    for (int i =0; i< ns1; i++){
        s3[i] = s1[i];
    }
    for (int i = ns1,j = 0; i < ns1 + ns2; i++, j++)
    {
        s3[i] = s2[j];
    }

    printf("%s", s3);
    return 0;
}