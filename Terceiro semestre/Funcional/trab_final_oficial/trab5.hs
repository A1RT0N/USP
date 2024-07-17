-- Nome - nUSP dos integrantes:

-- Ayrton da Costa Ganem Filho - 14560190
-- Enzo Tonon Morente - 14568476
-- Letícia Barbosa Neves - 14588659

import System.IO    --Biblioteca para entrada e saída
import Control.Exception    --Biblioteca para lazy (evalute $ foce contents)
import Control.DeepSeq
import Data.List (sortBy)   --Biblioteca para ordenar vetor
import Data.Ord (comparing)     --Biblioteca para a função comparing para comparar string lexicograficamente

--Funcao que separa uma string em uma lista de strings, usando virgula como delimitador
splitByComma :: String -> [String]
splitByComma [] = [""]
splitByComma (c:cs)
    | c == ','  = "" : rest
    | otherwise = (c : head rest) : tail rest
  where
    rest = splitByComma cs

--Funcao que processa a entrada do usuario transformando uma string em uma lista de inteiros
processInput :: String -> [Int]
processInput input = map read (words input)

--Funcao que processa uma lista de listas de strings, convertendo elementos especificos em inteiros
processList :: [[String]] -> [[Int]]
processList = map (extractAndConvert . drop 1)
  where
    extractAndConvert :: [String] -> [Int]
    extractAndConvert strs = map read strs

--Funcao que calcula a soma dos valores de ("Active") onde o valor de ("Confirmed") eh maior ou igual a n1
funcao1 :: [[Int]] -> Int -> Int 
funcao1 x n1 = sum $ map (!! 3) $ filter (\p -> head p > n1) x

--Funcao que calcula a soma dos valores ("Deaths") dentre os n2 maiores valores de ("Active") e n3 menores valores de ("Confirmed")
funcao2 :: Int -> Int -> [[Int]] -> Int
funcao2 n2 n3 vectors =
    let sortedByFourth = take n2 $ sortBy (flip (comparing (\index -> index !! 3))) vectors
        sortedByFirst = take n3 $ sortBy (comparing (\index -> index !! 0)) sortedByFourth
    in sum $ map ((\index -> index !! 1)) sortedByFirst

--Funcao que, dado uma lista de listas de strings, ordena ela em ordem alfabetica e pega os n4 paises com os maiores valores de "Confirmed"
funcao3 :: [[String]] -> Int -> [[String]]
funcao3 lst n4 = take n4 $ sortBy (flip (comparing (read . (!! 1) :: [String] -> Int))) lst

--Funcao para imprimir uma lista de strings
printStrings :: [String] -> IO ()
printStrings [] = return ()
printStrings (x:xs) = do
    putStrLn x
    printStrings xs

--Funcao principal (main)
main = do
    --Abre o arquivo csv no modo leitura
    handle <- openFile "dados.csv" ReadMode
    --Pega o conteudo de todo o arquivo
    contents <- hGetContents handle
    --Lida com a questao do "lazy" para mexer com o arquivo
    evaluate $ force contents
    --Fecha o arquivo
    hClose handle

    --Le a linha de entrada do usuario
    input <- getLine

    --Processa a entrada do usuario com a funcao "processInput"
    let [n1, n2, n3, n4] = processInput input

    ---Divide o conteudo do arquivo em linhas e colunas
    let processedLines = map (splitByComma) (lines contents)

    --Calcula a primeira resposta usando a funcao "funcao1"
    let resposta_1 = funcao1 (processList processedLines) n1

    --Calcula a segunda resposta usando a funcao "funcao2"
    let resposta_2 = funcao2 n2 n3 (processList processedLines)

    --Calcula a terceira resposta, ordenando os resultados e pegando o primeiro elemento de cada sublista
    let resposta_3 = sortBy (comparing id) (map (head) (funcao3 processedLines n4))

    --Imprime as respostas
    print resposta_1
    print resposta_2
    printStrings resposta_3



