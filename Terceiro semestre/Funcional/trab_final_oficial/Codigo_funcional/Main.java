package Codigo_funcional;
import java.io.*;
import java.nio.file.*;
import java.util.*;
import java.util.stream.Collectors;

import Main;

public class Main {

    // Função que separa uma string em uma lista de strings, usando vírgula como delimitador
    public static List<String> splitByComma(String str) {
        return Arrays.asList(str.split(","));
    }

    // Função que processa a entrada do usuário transformando uma string em uma lista de inteiros
    public static List<Integer> processInput(String input) {
        return Arrays.stream(input.split("\\s+"))
                     .map(Integer::parseInt)
                     .collect(Collectors.toList());
    }

    // Função que processa uma lista de listas de strings, convertendo elementos específicos em inteiros
    public static List<List<Integer>> processList(List<List<String>> list) {
        return list.stream()
                   .map(sublist -> sublist.subList(1, sublist.size()).stream()
                                          .map(Integer::parseInt)
                                          .collect(Collectors.toList()))
                   .collect(Collectors.toList());
    }

    // Função que calcula a soma dos valores de ("Active") onde o valor de ("Confirmed") é maior ou igual a n1
    public static int funcao1(List<List<Integer>> x, int n1) {
        return x.stream()
                .filter(p -> p.get(0) > n1)
                .mapToInt(p -> p.get(3))
                .sum();
    }

    // Função que calcula a soma dos valores ("Deaths") dentre os n2 maiores valores de ("Active") e n3 menores valores de ("Confirmed")
    public static int funcao2(int n2, int n3, List<List<Integer>> vectors) {
        List<List<Integer>> sortedByFourth = vectors.stream()
                                                    .sorted(Comparator.comparingInt((List<Integer> l) -> l.get(3)).reversed())
                                                    .limit(n2)
                                                    .collect(Collectors.toList());
        List<List<Integer>> sortedByFirst = sortedByFourth.stream()
                                                          .sorted(Comparator.comparingInt(l -> l.get(0)))
                                                          .limit(n3)
                                                          .collect(Collectors.toList());
        return sortedByFirst.stream()
                            .mapToInt(l -> l.get(1))
                            .sum();
    }

    // Função que, dado uma lista de listas de strings, ordena ela em ordem alfabética e pega os n4 países com os maiores valores de "Confirmed"
    public static List<String> funcao3(List<List<String>> lst, int n4) {
        return lst.stream()
                  .sorted(Comparator.comparingInt((List<String> l) -> Integer.parseInt(l.get(1))).reversed())
                  .limit(n4)
                  .map(l -> l.get(0))
                  .collect(Collectors.toList());
    }

    // Função principal (main)
    public static void main(String[] args) throws IOException {
        // Lê o arquivo CSV
        List<String> lines = Files.readAllLines(Paths.get("dados.csv"));

        // Processa o conteúdo do arquivo
        List<List<String>> processedLines = lines.stream()
                                                 .map(Main::splitByComma)
                                                 .collect(Collectors.toList());

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
        List<String> resposta3 = funcao3(processedLines, n4);

        // Imprime as respostas
        System.out.println(resposta1);
        System.out.println(resposta2);
        Collections.sort(resposta3);
        resposta3.forEach(System.out::println);
    }
}
