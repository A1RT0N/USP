// Já adiantar --> é o msm da semana passada


// matriz = new int [tamanho_matriz][tamanho_matriz];

//         public int[] lista_numeros_aleatórios_nao_repetidos;
//         public int tmp;
//         public int flag;

//         lista_numeros_aleatórios_nao_repetidos = new int [tamanho_matriz*tamanho_matriz];

//         Random random = new Random();

//         lista_numeros_aleatórios_nao_repetidos[0] = 0;

//         for(int i =1; i< tamanho_matriz*tamanho_matriz; i++){
//             lista_numeros_aleatórios_nao_repetidos[i] = -1;
//         }

//         for(int i = 0; i< tamanho_matriz*tamanho_matriz; i++){
//             this.tmp = random.nextInt(tamanho_matriz*tamanho_matriz-1);
//             this.flag = 1;
//             int j;
//             for(j = 0; lista_numeros_aleatórios_nao_repetidos[j] != -1; j++){
//                 if(this.tmp == lista_numeros_aleatórios_nao_repetidos[j]){
//                     flag = 0;
//                     break;
//                 }
//             }
//             if(this.flag != 0){
//                 lista_numeros_aleatórios_nao_repetidos[j] = this.tmp;
//             }
//         }

//         for(int i=0, k=0; i<tamanho_matriz; i++, k++){
//             for(int j=0; j<tamanho_matriz; j++){
//                 matriz[i][j] = lista_numeros_aleatórios_nao_repetidos[k];
//             }
//         }