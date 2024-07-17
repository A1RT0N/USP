import System.IO
import Control.Exception
import Control.DeepSeq
import Data.List (sortBy)
import Data.Ord (comparing)

processInput :: String -> [Int]
processInput input = map read (words input)

processNumberForEachLine :: String -> [Int]
processNumberForEachLine line = map read $ filter isInteger $ words $ map (\c -> if c == ',' then ' ' else c) line

isInteger :: String -> Bool
isInteger s = case reads s :: [(Int, String)] of
    [(val, "")] -> True
    _           -> False

safeRead :: String -> Int
safeRead s = case reads s of
    [(val, "")] -> val
    _           -> 0  -- ou qualquer valor default que faça sentido no seu contexto

-- funcao1: Sum the first element of each list where the third element is greater than n1
funcao1 :: (Num a, Ord a) => [[a]] -> a -> a 
funcao1 x n1 = sum $ map head $ filter (\p -> length p > 2 && p !! 2 > n1) x

-- funcao2: Sort by fourth element, take top n2, then sort by first element, take top n3, and sum the second element
funcao2 :: Int -> Int -> [[Int]] -> Int
funcao2 n2 n3 vectors =
    let sortedByFourth = take n2 $ sortBy (flip (comparing (\index -> index !! 3))) vectors
        sortedByFirst = take n3 $ sortBy (comparing (\index -> index !! 0)) sortedByFourth
    in sum $ map ((\index -> index !! 1)) sortedByFirst

-- funcao3: Sort by second element (as integer), take top n4, and concatenate the first elements
funcao3 :: [[String]] -> Int -> String
funcao3 xs n4 = 
    let sortedByFirstInt = sortBy (\a b -> compare (safeRead (a !! 1)) (safeRead (b !! 1))) (filter (\x -> isInteger (x !! 1)) xs)
        topN4Countries = take n4 sortedByFirstInt
    in unwords (map head topN4Countries)

main = do
    handle <- openFile "/mnt/data/dados.csv" ReadMode
    contents <- hGetContents handle
    evaluate $ force contents
    hClose handle

    input <- getLine

    let [n1, n2, n3, n4] = processInput input

    let processedLines = map (words . map (\c -> if c == ',' then ' ' else c)) (lines contents)
    let vetor_numeros = map processNumberForEachLine (lines contents)

    let resposta_1 = funcao1 vetor_numeros n1
    let resposta_2 = funcao2 n2 n3 vetor_numeros
    let resposta_3 = funcao3 processedLines n4

    print resposta_1 
    print resposta_2
    putStrLn resposta_3




import System.IO
import Control.Exception
import Control.DeepSeq
import Data.List (sortBy)
import Data.Ord (comparing)


processInput :: String -> [Int]
processInput input = map read (words (map (\c -> if c == ',' then ' ' else c) input))

processNumberForEachLine :: String -> [Int]
processNumberForEachLine line = map read $ filter isInteger $ words $ map (\c -> if c == ',' then ' ' else c) line

isInteger :: String -> Bool
isInteger s = case reads s :: [(Int, String)] of
    [(val, "")] -> True
    _           -> False

safeRead :: String -> Int
safeRead s = case reads s of
    [(val, "")] -> val
    _           -> 0  -- ou qualquer valor default que faça sentido no seu contexto


funcao1 :: (Num a, Ord a) => [[a]] -> a -> a 
funcao1 x n1 = sum $ map head $ filter (\p -> length p > 2 && p !! 2 > n1) x


funcao2 :: Int -> Int -> [[Int]] -> Int
funcao2 n2 n3 vectors =
    let sortedByFourth = take n2 $ sortBy (flip (comparing (\index -> index !! 3))) vectors
        sortedByFirst = take n3 $ sortBy (comparing (\index -> index !! 0)) sortedByFourth
    in sum $ map ((\index -> index !! 1)) sortedByFirst


funcao3 :: [[String]] -> Int -> String
funcao3 xs n4 = 
    let sortedByFirstInt = sortBy (\a b -> compare (safeRead (a !! 1)) (safeRead (b !! 1))) (filter (\x -> isInteger (x !! 1)) xs)
        topN4Countries = take n4 sortedByFirstInt
    in unwords (map head topN4Countries)




main = do
    handle <- openFile "dados.csv" ReadMode
    contents <- hGetContents handle
    evaluate $ force contents
    hClose handle

    input <- getLine

    let[n1,n2,n3,n4]= processInput input


    let processedLines = map (words . map (\c -> if c == ',' then ' ' else c)) (lines contents)

    let vetor_numeros =  map processNumberForEachLine (lines contents)

    let resposta_1 = funcao1 vetor_numeros n1

    let resposta_2 = funcao2 n2 n3 vetor_numeros

    let resposta_3 = funcao3 processedLines n4

    print resposta_1 
    print resposta_2
    putStrLn resposta_3







-- Faça UM programa, que leia uma linha com 4 inteiros separados por espaço. Sejam esses inteiros
-- n1, n2, n3 e n4. Ele deve imprimir as seguintes informações:
-- 1) A soma de "Active" de todos os países em que "Confirmed" é maior o igual que n1.
-- 2) Dentre os n2 países com maiores valores de "Active", a soma das "Deaths" dos n3 países
-- com menores valores de "Confirmed".
-- 3) Os n4 países com os maiores valores de "Confirmed". Os nomes devem estar em ordem
-- alfabética.
-- O programa deve ler um arquivo "dados.csv", que já estará disponível no run.codes no diretório
-- que o programa vai ser executado (não precisa inclui-lo no trabalho). Para teste, uma cópia do
-- arquivo está disponível em
-- https://drive.google.com/file/d/1n39FcIjQkYmGgngSRoYnZ0k5WrL5zAQZ/view?usp=sharing
-- As colunas do arquivo são: Country, Confirmed, Deaths, Recovery, Active.
