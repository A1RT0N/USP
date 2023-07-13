#include <stdio.h>
#include <stdlib.h>

//Função linha que descobre qual a linha da jogada atual através dee uma conta matemática
int lin(n){
    int r;
    r = (n / 3) * 3;
    return(r);
}

//Função coluna que descobre qual a coluna da jogada atual através dee uma conta matemática
int col(n){
    int r;
    r = n % 3;
    return(r);
}

int main(){

    //Definindo as variáveis
    //tab: O tabuleiro grande
    //jogo:O tabuleiro geral
    //versao: A versão na qual o jogador escolheu, sendo elas Jogador x Jogador ou Jogador x Computador
    //c: um contador
    //l: um valor que salva qual jogador ganhou
    //i: o valor da rodada
    //j: o valor da primeira dimensão da matriz tab[][], que representa o tabuleiro a ser jogado. Também representa a posição no array jogo[].
    //k: representa o valor da posição na segunda dimensão da matriz tab[][], que representa a casa no tabuleiro
    //qual_jog: valor que representa qual o jogador jogando na rodada
    char tab[9][9], jogo[9];
    int versao, c, l, i, j, k, qual_jog;

    printf("\n               :::::::::  :::::::::: ::::    ::::         :::     ::: ::::::::::: ::::    ::: :::::::::   ::::::::   \n");
    printf("               :+:    :+: :+:        +:+:+: :+:+:+        :+:     :+:     :+:     :+:+:   :+: :+:    :+: :+:    :+:  \n");
    printf("               +:+    +:+ +:+        +:+ +:+:+ +:+        +:+     +:+     +:+     :+:+:+  +:+ +:+    +:+ +:+    +:+  \n");
    printf("               +#++:++#+  +#++:++#   +#+  +:+  +#+        +#+     +:+     +#+     +#+ +:+ +#+ +#+    +:+ +#+    +:+  \n");
    printf("               +#+    +#+ +#+        +#+       +#+         +#+   +#+      +#+     +#+  +#+#+# +#+    +#+ +#+    +#+  \n");
    printf("               #+#    #+# #+#        #+#       #+#          #+#+#+#       #+#     #+#   #+#+# #+#    #+# #+#    #+#    \n");
    printf("               #########  ########## ###       ###            ###     ########### ###    #### #########   ########   \n\n");
    printf("                                                    +-+ +-+   +-+ +-+ +-+ +-+ +-+\n");
    printf("                                                    |A| |O|   |S| |U| |P| |E| |R|\n");
    printf("                                                    +-+ +-+   +-+ +-+ +-+ +-+ +-+\n\n");
    printf("  888888  .d88888b.   .d8888b.   .d88888b.      8888888b.   .d88888b.             d8888  .d8888b.  8888888 888       .d88888b.  \n");
    printf("     88b d88P   Y88b d88P  Y88b d88P   Y88b     888   Y88b d88P   Y88b           d88888 d88P  Y88b   888   888      d88P   Y88b \n");
    printf("     888 888     888 888    888 888     888     888    888 888     888          d88P888 Y88b.        888   888      888     888 \n");
    printf("     888 888     888 888        888     888     888    888 888     888         d88P 888   Y888b.     888   888      888     888 \n");
    printf("     888 888     888 888  88888 888     888     888    888 888     888        d88P  888      Y88b.   888   888      888     888 \n");
    printf("     888 888     888 888    888 888     888     888    888 888     888       d88P   888        888   888   888      888     888 \n");
    printf("     88P Y88b. .d88P Y88b  d88P Y88b. .d88P     888  .d88P Y88b. .d88P      d8888888888 Y88b  d88P   888   888      Y88b. .d88P \n");
    printf("     888   Y88888P     Y8888P88   Y88888P       8888888P     Y88888P       d88P     888   Y8888P   8888888 88888888   Y88888P   \n");
    printf("   .d88P    \n");
    printf(" .d88P  \n");
    printf("888P      \n");
    printf("                                                                                               Por Iara Lie (@Loe_Fuk)   \n");
    printf("                                                                                                 e Joao Pedro (@01_Batudo)\n\n\n");
    printf("                                                       Escolha o modo de jogo:\n");
    printf("                                                   [1] 1 Jogador [2] 2 Jogadores\n\n\n");
    printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("|O Ultimate tic-tac-toe consiste em uma variaçao do famoso tic-tac-toe, tambem conhecido como jogo da velha. O objetivo e fazer|\n");
    printf("|uma sequencia de tres simbolos iguais no tabuleiro geral, porem, diferentemente do jogo tradicional, no Ultimate tic-tac-toe, |\n");
    printf("|um quadrante do tabuleiro geral e conquistado pelo jogador apos o mesmo vencer o jogo da velha no tabuleiro grande, que       |\n");
    printf("|representa o quadrante selecionado. O tabuleiro e formado por nove quadrantes, enumerados como no tabuleiro grande, em que    |\n");
    printf("|representa um jogo da velha interior, conforme apresentado no tabuleiro geral.                                                |\n");
    printf("|cada um deles. Dois jogadores (Jogador 1 e Jogador 2) alternam suas jogadas, com o Jogador 1 representado pelo simbolo X e o  |\n");
    printf("|Jogador 2 pelo simbolo O. Em cada rodada, um jogador escolhe um quadrante do tabuleiro geral e inicia a jogada no jogo da     |\n");
    printf("|velha do quadrante correspondente, no jogo interior. O quadrante escolhido para a jogada, dentro desse mesmo quadrante        |\n");
    printf("|interior, determina o quadrante do tabuleiro geral a ser jogado pelo proximo jogador. Quando um jogo interior e vencido, o    |\n");
    printf("|jogador vencedor ganha o seu simbolo no quadrante do tabuleiro geral. O jogo termina quando um jogador vencer o jogo da velha |\n");
    printf("|do tabuleiro geral, com uma sequência de tres simbolos iguais.                                                                |\n");
    printf("|                                                                                                                   Bom jogo S2|\n");
    printf("+------------------------------------------------------------------------------------------------------------------------------+\n\n\n");

    //Perguntando qual a versão do jogo. Se for a versão 1, começa o jogo modo 1 jogadores, e se for a versão 2, começa a versão 2 jogadores
    //Enquanto a versão nao for ou 1 ou 2 o usuário irá ficar colocando a versão até acertar
    do{
        scanf("%d", &versao);
    }while(versao < 1 || versao > 2);

    //Limpa a tela
    system("cls");

    if(versao == 1){
        printf("Desculpe! Versao nao disponivel!");
        return(0);
    }

    //Cria um contador para zerar o tabuleiro grande e o tabuleiro geral
    for(j = 0; j < 9; j++){
        for(k = 0; k < 9; k++){
            tab[j][k] = ' ';
            jogo[j] = ' ';
        }
    }

    //Imprime o mapa do tabuleiro grande (9x9) e do tabuleiro geral (3x3)
    //O tabuleiro geral é o tabuleiro na qual será marcado uma casa quando alguém ganhar em um tabuleiro do tabuleiro grande
    printf("Tabuleiro Grande: \n");
    printf(" 1 | 2 | 3 || 1 | 2 | 3 || 1 | 2 | 3 \n");
    printf("---+---+---||---+---+---||---+---+---\n");
    printf(" 4 | 5 | 6 || 4 | 5 | 6 || 4 | 5 | 6 \n");
    printf("---+---+---||---+---+---||---+---+---\n");
    printf(" 7 | 8 | 9 || 7 | 8 | 9 || 7 | 8 | 9 \n");
    printf("===========||===========||===========\n");
    printf(" 1 | 2 | 3 || 1 | 2 | 3 || 1 | 2 | 3 \n");
    printf("---+---+---||---+---+---||---+---+---\n");
    printf(" 4 | 5 | 6 || 4 | 5 | 6 || 4 | 5 | 6 \n");
    printf("---+---+---||---+---+---||---+---+---\n");
    printf(" 7 | 8 | 9 || 7 | 8 | 9 || 7 | 8 | 9 \n");
    printf("===========||===========||===========\n");
    printf(" 1 | 2 | 3 || 1 | 2 | 3 || 1 | 2 | 3 \n");
    printf("---+---+---||---+---+---||---+---+---\n");
    printf(" 4 | 5 | 6 || 4 | 5 | 6 || 4 | 5 | 6 \n");
    printf("---+---+---||---+---+---||---+---+---\n");
    printf(" 7 | 8 | 9 || 7 | 8 | 9 || 7 | 8 | 9 \n\n");

    printf("Tabuleiro Geral: \n");
    printf(" 1 | 2 | 3 \n");
    printf("---+---+---\n");
    printf(" 4 | 5 | 6 \n");
    printf("---+---+---\n");
    printf(" 7 | 8 | 9 \n\n");

    //Pede para o jogador 1 escolher o tabuleiro onde ele quer começar
    //Enquanto ele n escolher um tabuleiro valido, ele tera que inserir denovo
    //Tiramos 1 do numero digitado para ficar entre 0 e 8
    do{
    printf("Jogador 1, escolha o tabuleiro para comecar!!\n");
    scanf("%d", &j);
    j = j-1;
    }while(j < 0 || j > 8);


    //Cria um contador para as rodadas. Sendo 81 a última rodada. Se passar disso e ninguem ganhar, deu velha
    for(i = 1; i < 82; i++){
        //Imprime a rodada atual e o tabuleiro atual
        //Já que o usuário insere um número de 1 a 9, e a gente trabalha com números entre 0 e 8, inserimos 1 para mostrar para o usuário e logo em seguida retiramos 1 para voltar ao normal
        j = j+1;
        printf("Rodada atual: %d\n", i);
        printf("Tabuleiro atual: %d\n\n", j);
        j = j-1;

        //Calcula de quem é a vez. Se o resto da divisão da rodada for 1, é a vez do jogador 1. Se não (se o resto for 0), é a vez do jogador 2.
        if(i % 2 == 1){
            qual_jog = 1;
        } else {
            qual_jog = 2;
        }

        //confere se o valor das casas é vazio. Se todas as casas naquele tabuleiro estiverem cheias, ele pede para o jogador escolher qual tabuleiro ele quer jogar
        //Zera o valor de c, para ver se o tabuleiro que ele escolheu está vazio. Se não, pede para ele escolher denovo
        for(c = 0; c < 9 && tab[j][c] != ' '; c++){
            if(c == 8){
                do{
                printf("Jogador 1, escolha qualquer tabuleiro!!\n");
                scanf("%d", &j);
                j = j-1;
                }while(j < 0 || j > 8);
                c = 0;
            }
        }

        //Pede para o jogador atual digitar a casa na qual quer jogar
        //Enquanto ele n escolher uma casa valida (ser maior que 0, menor que 8 e ela estiver vazia), ele tera que inserir denovo
        do{
            printf("Jogador %d, escolha a casa: \n", qual_jog);
            scanf("%d", &k);
            k = k-1;
        }while(k < 0 || k > 8 || tab[j][k] != ' ');

        //Limpa a tela
        system("cls");

        //Insere um X na casa se for a vez do jogador 1 e um 0 na casa se for a vez do jogador 2
        if(qual_jog == 1){
                tab[j][k] = 'X';
            } else {
                tab[j][k] = 'O';
            }

        //Confere as linhas, colunas e diagonais da casa para ver se elas não são iguais.
        //Se forem, marca um X ou O (depende do jogador da vez) no tabuleiro geral na casa equivalente a esse tabuleiro
        //As checagens são conferidas de forma que é checado apenas as linhas, colunas e diagonais da casa jogada
        if(tab[j][lin(k)] != ' ' && tab[j][lin(k)] == tab[j][lin(k) + 1] && tab[j][lin(k) + 1] == tab[j][lin(k) + 2]){
            if(jogo[j] == ' '){
                if(qual_jog == 1){
                    jogo[j] = 'X';
                } else {
                    jogo[j] = 'O';
                }
            }
        }

        if(tab[j][col(k)] != ' ' && tab[j][col(k)] == tab[j][col(k) + 3] && tab[j][col(k) + 3] == tab[j][col(k) + 6]){
            if(jogo[j] == ' '){
                if(qual_jog == 1){
                    jogo[j] = 'X';
                } else {
                    jogo[j] = 'O';
                }
            }
        }

        if(tab[j][4] != ' ' && (tab[j][0] == tab[j][4] && tab[j][4] == tab[j][8]) || (tab[j][4] != ' ' && tab[j][2] == tab[j][4] && tab[j][4] == tab[j][6])){
            if(jogo[j] == ' '){
                if(qual_jog == 1){
                    jogo[j] = 'X';
                } else {
                    jogo[j] = 'O';
                }
            }
        }

        //Imprime o tabuleiro grande e o geral com as jogadas feitas até agora
        printf("Tabuleiro Grande: \n");
        printf(" %c | %c | %c || %c | %c | %c || %c | %c | %c \n", tab[0][0], tab[0][1], tab[0][2], tab[1][0], tab[1][1], tab[1][2], tab[2][0], tab[2][1], tab[2][2]);
        printf("---+---+---||---+---+---||---+---+---\n");
        printf(" %c | %c | %c || %c | %c | %c || %c | %c | %c \n", tab[0][3], tab[0][4], tab[0][5], tab[1][3], tab[1][4], tab[1][5], tab[2][3], tab[2][4], tab[2][5]);
        printf("---+---+---||---+---+---||---+---+---\n");
        printf(" %c | %c | %c || %c | %c | %c || %c | %c | %c \n", tab[0][6], tab[0][7], tab[0][8], tab[1][6], tab[1][7], tab[1][8], tab[2][6], tab[2][7], tab[2][8]);
        printf("===========||===========||===========\n");
        printf(" %c | %c | %c || %c | %c | %c || %c | %c | %c \n", tab[3][0], tab[3][1], tab[3][2], tab[4][0], tab[4][1], tab[4][2], tab[5][0], tab[5][1], tab[5][2]);
        printf("---+---+---||---+---+---||---+---+---\n");
        printf(" %c | %c | %c || %c | %c | %c || %c | %c | %c \n", tab[3][3], tab[3][4], tab[3][5], tab[4][3], tab[4][4], tab[4][5], tab[5][3], tab[5][4], tab[5][5]);
        printf("---+---+---||---+---+---||---+---+---\n");
        printf(" %c | %c | %c || %c | %c | %c || %c | %c | %c \n", tab[3][6], tab[3][7], tab[3][8], tab[4][6], tab[4][7], tab[4][8], tab[5][6], tab[5][7], tab[5][8]);
        printf("===========||===========||===========\n");
        printf(" %c | %c | %c || %c | %c | %c || %c | %c | %c \n", tab[6][0], tab[6][1], tab[6][2], tab[7][0], tab[7][1], tab[7][2], tab[8][0], tab[8][1], tab[8][2]);
        printf("---+---+---||---+---+---||---+---+---\n");
        printf(" %c | %c | %c || %c | %c | %c || %c | %c | %c \n", tab[6][3], tab[6][4], tab[6][5], tab[7][3], tab[7][4], tab[7][5], tab[8][3], tab[8][4], tab[8][5]);
        printf("---+---+---||---+---+---||---+---+---\n");
        printf(" %c | %c | %c || %c | %c | %c || %c | %c | %c \n\n", tab[6][6], tab[6][7], tab[6][8], tab[7][6], tab[7][7], tab[7][8], tab[8][6], tab[8][7], tab[8][8]);

        printf("Tabuleiro Geral: \n");
        printf(" %c | %c | %c \n", jogo[0], jogo[1], jogo[2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c \n", jogo[3], jogo[4], jogo[5]);
        printf("---+---+---\n");
        printf(" %c | %c | %c \n\n", jogo[6], jogo[7], jogo[8]);

        //Compara se algum jogador ganhou no tabuleiro geral. Se sim, salva quem é esse jogador numa variável L
        if(jogo[lin(j)] != ' ' && jogo[lin(j)] == jogo[lin(j) + 1] && jogo[lin(j) + 1] == jogo[lin(j) + 2]){
            l = qual_jog;
        }

        if(jogo[col(j)] != ' ' && jogo[col(j)] == jogo[col(j) + 3] && jogo[col(j) + 3] == jogo[col(j) + 6]){
            l = qual_jog;
        }

        if((jogo[4] != ' ' && jogo[0] == jogo[4] && jogo[4] == jogo[8]) || (jogo[4] != ' ' && jogo[2] == jogo[4] && jogo[4] == jogo[6])){
            l = qual_jog;
        }

        //Muda o jogo para o tabuleiro equivalente a casa escolhida pelo jogador
        j = k;

        //Se o jogador 1 tiver ganhado, imprime uma frase de vitória para ele e encerra o jogo
        if(l == 1){
            printf(":::::::::      :::     :::::::::      :::     :::::::::  :::::::::: ::::    :::  ::::::::  ::: ::: \n");
            printf(":+:    :+:   :+: :+:   :+:    :+:   :+: :+:   :+:    :+: :+:        :+:+:   :+: :+:    :+: :+: :+: \n");
            printf("+:+    +:+  +:+   +:+  +:+    +:+  +:+   +:+  +:+    +:+ +:+        :+:+:+  +:+ +:+        +:+ +:+ \n");
            printf("+#++:++#+  +#++:++#++: +#++:++#:  +#++:++#++: +#++:++#+  +#++:++#   +#+ +:+ +#+ +#++:++#++ +#+ +#+ \n");
            printf("+#+        +#+     +#+ +#+    +#+ +#+     +#+ +#+    +#+ +#+        +#+  +#+#+#        +#+ +#+ +#+ \n");
            printf("#+#        #+#     #+# #+#    #+# #+#     #+# #+#    #+# #+#        #+#   #+#+# #+#    #+#         \n");
            printf("###        ###     ### ###    ### ###     ### #########  ########## ###    ####  ########  ### ### \n");
            printf("     +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+   +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ \n");
            printf("     |J| |O| |G| |A| |D| |O| |R|   |1|   |G| |A| |N| |H| |O| |U|   |U| |M|   |G| |A| |T| |O| \n");
            printf("     +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+   +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ \n");
            printf("                                                       .::\n");
            printf("                                         .:.          .:^^:\n");
            printf("                                        .:^^:...:::^:..:^^:.\n");
            printf("                                        ..:^::.:^^^^:..:::..\n");
            printf("                                         ...:...............\n");
            printf("                                         .....::::....:^:...\n");
            printf("                                          ::::^!^^::.:~~^...\n");
            printf("                                           ^^::^~~^:::::...\n");
            printf("                                           :::..:^~^::::..\n");
            printf("                                     ..::........:::.....:\n");
            printf("                                  ::^^^^:....:..........:^.\n");
            printf("                                :^^^::.:::.::::::.......:~:\n");
            printf("                               :^^^::....:::::::........:~:\n");
            printf("                             .:^^^::......:::::.........::\n");
            printf("                             :^^^^::........::::........:.\n");
            printf("                            .:^^^::..........:::.........\n");
            printf("                            .:^^::.......................\n");
            printf("         :.                 .^^::........::.............\n");
            printf("        .:.:.              .^^:::.........:........:....\n");
            printf("         ..::.             ..:::::::................:...\n");
            printf("          :::::...         ...:::::^:::.............::.:.\n");
            printf("           ...:::::::::::...........................::::.\n");
            printf("              ..............................:::........:::.\n");
            printf("                   ..........      .     ......   ...:..:\n");

            return(0);
        }

        //Se o jogador 2 tiver ganhado, imprime uma frase de vitória para ele e encerra o jogo
        if(l == 2){
            printf(":::::::::      :::     :::::::::      :::     :::::::::  :::::::::: ::::    :::  ::::::::  ::: ::: \n");
            printf(":+:    :+:   :+: :+:   :+:    :+:   :+: :+:   :+:    :+: :+:        :+:+:   :+: :+:    :+: :+: :+: \n");
            printf("+:+    +:+  +:+   +:+  +:+    +:+  +:+   +:+  +:+    +:+ +:+        :+:+:+  +:+ +:+        +:+ +:+ \n");
            printf("+#++:++#+  +#++:++#++: +#++:++#:  +#++:++#++: +#++:++#+  +#++:++#   +#+ +:+ +#+ +#++:++#++ +#+ +#+ \n");
            printf("+#+        +#+     +#+ +#+    +#+ +#+     +#+ +#+    +#+ +#+        +#+  +#+#+#        +#+ +#+ +#+ \n");
            printf("#+#        #+#     #+# #+#    #+# #+#     #+# #+#    #+# #+#        #+#   #+#+# #+#    #+#         \n");
            printf("###        ###     ### ###    ### ###     ### #########  ########## ###    ####  ########  ### ### \n");
            printf("     +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+   +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ \n");
            printf("     |J| |O| |G| |A| |D| |O| |R|   |2|   |G| |A| |N| |H| |O| |U|   |U| |M|   |G| |A| |T| |O| \n");
            printf("     +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+   +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ \n");
            printf("                                                       .::\n");
            printf("                                         .:.          .:^^:\n");
            printf("                                        .:^^:...:::^:..:^^:.\n");
            printf("                                        ..:^::.:^^^^:..:::..\n");
            printf("                      MEOW               ...:...............\n");
            printf("                                         .....::::....:^:...\n");
            printf("                                          ::::^!^^::.:~~^...\n");
            printf("                                           ^^::^~~^:::::...\n");
            printf("                                           :::..:^~^::::..\n");
            printf("                                     ..::........:::.....:\n");
            printf("                                  ::^^^^:....:..........:^.\n");
            printf("                                :^^^::.:::.::::::.......:~:\n");
            printf("                               :^^^::....:::::::........:~:\n");
            printf("                             .:^^^::......:::::.........::\n");
            printf("                             :^^^^::........::::........:.\n");
            printf("                            .:^^^::..........:::.........\n");
            printf("                            .:^^::.......................\n");
            printf("         :.                 .^^::........::.............\n");
            printf("        .:.:.              .^^:::.........:........:....\n");
            printf("         ..::.             ..:::::::................:...\n");
            printf("          :::::...         ...:::::^:::.............::.:.\n");
            printf("           ...:::::::::::...........................::::.\n");
            printf("              ..............................:::........:::.\n");
            printf("                   ..........      .     ......   ...:..:\n");

            return(0);
        }

        //Compara para ver se todas as casas do tabuleiro geral foram ocupadas e ninguém ganhou. Assim, imprime uma mensagem de velha e encerra o código
         for(c = 0; c < 9 && jogo[c] != ' '; c++){
            if(c == 8){
                printf("'########::'##::::'##:'########:'########::::::::::'########::'########:'##::::'##::::'##::::'##:'########:'##:::::::'##::::'##::::'###::::\n");
                printf(" ##.... ##: ##:::: ##:... ##..::..... ##::::::::::: ##.... ##: ##.....:: ##:::: ##:::: ##:::: ##: ##.....:: ##::::::: ##:::: ##:::'## ##:::\n");
                printf(" ##:::: ##: ##:::: ##:::: ##:::::::: ##:::::::::::: ##:::: ##: ##::::::: ##:::: ##:::: ##:::: ##: ##::::::: ##::::::: ##:::: ##::'##:. ##::\n");
                printf(" ########:: ##:::: ##:::: ##::::::: ##::::'####:::: ##:::: ##: ######::: ##:::: ##:::: ##:::: ##: ######::: ##::::::: #########:'##:::. ##:\n");
                printf(" ##.....::: ##:::: ##:::: ##:::::: ##::::: ####:::: ##:::: ##: ##...:::: ##:::: ##::::. ##:: ##:: ##...:::: ##::::::: ##.... ##: #########:\n");
                printf(" ##:::::::: ##:::: ##:::: ##::::: ##::::::. ##::::: ##:::: ##: ##::::::: ##:::: ##:::::. ## ##::: ##::::::: ##::::::: ##:::: ##: ##.... ##:\n");
                printf(" ##::::::::. #######::::: ##:::: ########:'##:::::: ########:: ########:. #######:::::::. ###:::: ########: ########: ##:::: ##: ##:::: ##:\n");
                return(0);
            }
        }

    }

    //Se acabar as rodadas e ninguém ganhar, imprime uma mensagem de velha
    printf("'########::'##::::'##:'########:'########::::::::::'########::'########:'##::::'##::::'##::::'##:'########:'##:::::::'##::::'##::::'###::::\n");
    printf(" ##.... ##: ##:::: ##:... ##..::..... ##::::::::::: ##.... ##: ##.....:: ##:::: ##:::: ##:::: ##: ##.....:: ##::::::: ##:::: ##:::'## ##:::\n");
    printf(" ##:::: ##: ##:::: ##:::: ##:::::::: ##:::::::::::: ##:::: ##: ##::::::: ##:::: ##:::: ##:::: ##: ##::::::: ##::::::: ##:::: ##::'##:. ##::\n");
    printf(" ########:: ##:::: ##:::: ##::::::: ##::::'####:::: ##:::: ##: ######::: ##:::: ##:::: ##:::: ##: ######::: ##::::::: #########:'##:::. ##:\n");
    printf(" ##.....::: ##:::: ##:::: ##:::::: ##::::: ####:::: ##:::: ##: ##...:::: ##:::: ##::::. ##:: ##:: ##...:::: ##::::::: ##.... ##: #########:\n");
    printf(" ##:::::::: ##:::: ##:::: ##::::: ##::::::. ##::::: ##:::: ##: ##::::::: ##:::: ##:::::. ## ##::: ##::::::: ##::::::: ##:::: ##: ##.... ##:\n");
    printf(" ##::::::::. #######::::: ##:::: ########:'##:::::: ########:: ########:. #######:::::::. ###:::: ########: ########: ##:::: ##: ##:::: ##:\n");

    //Encerra o código
    return(0);

}