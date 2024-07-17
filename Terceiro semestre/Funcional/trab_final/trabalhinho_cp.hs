import System.IO
import Control.Exception
import Control.DeepSeq
import Data.List (sortBy)
import Data.Ord (comparing)


processInput :: String -> [Int]
processInput input = map read (words (map (\c -> if c == ',' then ' ' else c) input))

processLine :: String -> [Int]
processLine line = map read $ filter isInteger $ words $ map (\c -> if c == ',' then ' ' else c) line


isInteger :: String -> Bool
isInteger s = case reads s :: [(Int, String)] of
    [(val, "")] -> True
    _           -> False

funcao1 :: (Num a, Ord a) => [[a]] -> a -> a 
funcao1 x n1 = sum $ map head $ filter (\p -> length p > 2 && p !! 2 > n1) x


-- Função principal que realiza os passos descritos
funcao2 :: Int -> Int -> [[Int]] -> Int
funcao2 n2 n3 vectors =
    let sortedByFourth = take n2 $ sortBy (flip (comparing (\index -> index !! 3))) vectors
        sortedByFirst = take n3 $ sortBy (comparing (\index -> index !! 0)) sortedByFourth
    in sum $ map ((\index -> index !! 1)) sortedByFirst



main = do
    handle <- openFile "dados.csv" ReadMode
    contents <- hGetContents handle
    evaluate $ force contents
    hClose handle

    input <- getLine

    let[n1,n2,n3,n4]= processInput input

    let vetor_numerico = map processLine (lines contents)

    let resposta_1 = funcao1 vetor_numerico n1

    let resposta_2 = funcao2 n2 n3 vetor_numerico

    print resposta_2





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

