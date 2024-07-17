#include <stdio.h>

void fill_col(int col, int m, int n, int res[][n]);
void fill_line(int line, int m, int n, int res[][n]);
void set_open_seats(int m, int n, int res[][n]);
void print_matrix(int m, int n, int mat[][n]);
void set_used_seats(int m, int n, int res[][n]);
int check_if_open_seats(int m, int n, int res[][n]);

void fill_col(int col, int m, int n, int res[][n]) {
    for(int j = 0; j < m; j++) {
        res[j][col] = 'x';
    }
}

void fill_line(int line, int m, int n, int res[][n]) {
    for(int i = 0; i < n; i++) {
        res[line][i] = 'x';
    }
}

void set_open_seats(int m, int n, int res[][n]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            res[i][j] = 'o';
        }
    }
}

void set_used_seats(int m, int n, int res[][n]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            char curr;
            scanf(" %c", &curr);
            if(curr == 'c') {
                fill_col(j, m, n, res);
                fill_line(i, m, n, res);
            }
            if(curr == 'f') {
                res[i][j] = 'x';
            }
        }
    }
}

void print_matrix(int m, int n, int mat[][n]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
}

int check_if_open_seats(int m, int n, int res[][n]) {
    int count = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(res[i][j] == 'o') {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int res[m][n];

    set_open_seats(m, n, res);
    set_used_seats(m, n, res);

    if(check_if_open_seats(m, n, res))
        print_matrix(m, n, res);
    else
        printf("Eh um dia triste para os mono Yasuo\n");
    
    return 0;
}