import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Função que separa uma string em uma lista de strings, usando vírgula como delimitador
    public static List<String> splitByComma(String str) {
        return Arrays.asList(str.split(","));
    }

    // Função que processa a entrada do usuário transformando uma string em uma lista de inteiros
    public static List<Integer> processInput(String input) {
        String [] tmp = input.split(" ");
        List<Integer> retorno = new ArrayList<>();
        for(int i=0; i<tmp.length; i++){
            retorno.add(Integer.parseInt(tmp[i]));
        }
        return retorno;
    }

    // Função que processa uma lista de listas de strings, convertendo elementos específicos em inteiros
    public static List<List<Integer>> processList(List<List<String>> list) {
        List<List<Integer>> retorno = new ArrayList<>();
        for(int i =0; i< list.size(); i++){
            List<Integer> sublista = new ArrayList<>();
            for(int j =1 ; j<list.get(i).size(); j++){
                sublista.add(Integer.parseInt(list.get(i).get(j)));
            }
            retorno.add(sublista);
        }

        return retorno;
    }

    // Função que calcula a soma dos valores de ("Active") onde o valor de ("Confirmed") é maior ou igual a n1
    public static int funcao1(List<List<Integer>> x, int n1) {
        int retorno = 0;
        for (List<Integer> sublist : x) {
            if(sublist.get(0) > n1){
                retorno += sublist.get(3);
            }
        }

        return retorno;
    }


    // As colunas do arquivo são: Country, Confirmed, Deaths, Recovery, Active.

    // Função que calcula a soma dos valores ("Deaths") dentre os n2 maiores valores de ("Active") e n3 menores valores de ("Confirmed")
    public static int funcao2(int n2, int n3, List<List<Integer>> vectors) {
        // Copia a lista original para não modificar os dados de entrada
        List<List<Integer>> sortedByFourth = new ArrayList<>(vectors);
        
        // Ordena pelo quarto elemento em ordem decrescente
        Collections.sort(sortedByFourth, new Comparator<List<Integer>>() {
            @Override
            public int compare(List<Integer> l1, List<Integer> l2) {
                return Integer.compare(l2.get(3), l1.get(3));
            }
        });
        
        // Limita a lista aos n2 maiores
        if (sortedByFourth.size() > n2) {
            sortedByFourth = sortedByFourth.subList(0, n2);
        }

        
        // Ordena a lista resultante pelo primeiro elemento em ordem crescente
        Collections.sort(sortedByFourth, new Comparator<List<Integer>>() {
            @Override
            public int compare(List<Integer> l1, List<Integer> l2) {
                return Integer.compare(l1.get(0), l2.get(0));
            }
        });
        
        // Limita a lista resultante aos n3 menores
        if (sortedByFourth.size() > n3) {
            sortedByFourth = sortedByFourth.subList(0, n3);
        }

        
        // Calcula a soma dos valores do segundo elemento (índice 1) de cada sub-lista
        int sum = 0;
        for (List<Integer> list : sortedByFourth) {
            sum += list.get(1);
        }
        
        return sum;
    }

    // Função que, dado uma lista de listas de strings, ordena ela em ordem alfabética e pega os n4 países com os maiores valores de "Confirmed"
    public static String funcao3(List<List<String>> list, int n4) {
        List<List<String>> sortedBySecond = new ArrayList<>(list);
        
        // Ordena pelo quarto elemento em ordem decrescente
        Collections.sort(sortedBySecond, new Comparator<List<String>>() {
            @Override
            public int compare(List<String> l1, List<String> l2) {
                return Integer.compare(Integer.parseInt(l2.get(1)), Integer.parseInt(l1.get(1)));
            }
        });

        // Limita a lista aos n2 maiores
        if (sortedBySecond.size() > n4) {
            sortedBySecond = sortedBySecond.subList(0, n4);
        }

        // Ordena pelo país em ordem crescente
        Collections.sort(sortedBySecond, new Comparator<List<String>>() {
            @Override
            public int compare(List<String> l1, List<String> l2) {
                return l1.get(0).compareTo(l2.get(0));
            }
        });

        StringBuilder construtor = new StringBuilder();

        for (int i = 0; i < sortedBySecond.size(); i++) {
            List<String> sublista = sortedBySecond.get(i);

            construtor.append(sublista.get(0));
            // Colocando na formatação correta
            if (i != sortedBySecond.size() - 1) {
                construtor.append("\n");
            }
        }

        return construtor.toString();
    }

    // Função principal (main)
    public static void main(String[] args) throws IOException {
        // Lê o arquivo CSV
        List<String> lines = Files.readAllLines(Paths.get("dados.csv"));
        
        List<List<String>> processedLines = new ArrayList<>();

        for (String linha : lines) {
            processedLines.add(splitByComma(linha));
        }
        

        // Lê a linha de entrada do usuário
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        scanner.close();

        // Processa a entrada do usuário
        List<Integer> inputValues = processInput(input);

        
        int n1 = inputValues.get(0);
        int n2 = inputValues.get(1);
        int n3 = inputValues.get(2);
        int n4 = inputValues.get(3);

        // Calcula a primeira resposta usando a função "funcao1"
        int resposta1 = funcao1(processList(processedLines), n1);

        // Calcula a segunda resposta usando a função "funcao2"
        int resposta2 = funcao2(n2, n3, processList(processedLines));

        // Calcula a terceira resposta, ordenando os resultados e pegando o primeiro elemento de cada sublista
        String resposta3 = funcao3(processedLines, n4);

        // Imprime as respostas
        System.out.println(resposta1);
        System.out.println(resposta2);
        System.out.println(resposta3);        
    }
}
