# include <stdio.h>
void mover(int, char, char, char);

int main(){
    mover(11, 'O', 'T', 'D');
    return 0;
}

void mover(int n, char orig, char temp, char dest){
    if(n==1){
        printf("Mova o disco 1 da haste %c para a haste %c\n", orig, dest);
    } else{
        mover(n-1,orig,dest,temp);
        printf("Mova o disco %d da haste %c para a haste %c\n", n, orig,dest);
        mover(n-1,temp,orig,dest);
    }
}