import System.IO    -- Biblioteca para entrada e saída
import Control.Exception    -- Biblioteca para lazy (evalute $ foce contents)
import Control.DeepSeq
import Data.List (sortBy)   -- Biblioteca para ordenar vetor
import Data.Ord (comparing)     -- Biblioteca para a função comparing para comparar string lexicograficamente


splitByComma :: String -> [String]
splitByComma [] = [""]
splitByComma (c:cs)
    | c == ','  = "" : rest
    | otherwise = (c : head rest) : tail rest
  where
    rest = splitByComma cs

-- Função que processa a entrada do usuário
processInput :: String -> [Int]
processInput input = map read (words input)


processList :: [[String]] -> [[Int]]
processList = map (extractAndConvert . drop 1)
  where
    extractAndConvert :: [String] -> [Int]
    extractAndConvert strs = map read strs


-- Item 1 do trabalho (TÁ DANDO PROBLEMA, O NÚMERO TÁ MENOR DO QUE DEVIA)
funcao1 :: [[Int]] -> Int -> Int 
funcao1 x n1 = sum $ map (!! 3) $ filter (\p -> head p > n1) x


funcao2 :: Int -> Int -> [[Int]] -> Int
funcao2 n2 n3 vectors =
    let sortedByFourth = take n2 $ sortBy (flip (comparing (\index -> index !! 3))) vectors
        sortedByFirst = take n3 $ sortBy (comparing (\index -> index !! 0)) sortedByFourth
    in sum $ map ((\index -> index !! 1)) sortedByFirst

funcao3 :: [[String]] -> Int -> [[String]]
funcao3 lst n4 = take n4 $ sortBy (flip (comparing (read . (!! 1) :: [String] -> Int))) lst

printStrings :: [String] -> IO ()
printStrings [] = return ()
printStrings (x:xs) = do
    putStrLn x
    printStrings xs

main = do
    handle <- openFile "dados.csv" ReadMode
    contents <- hGetContents handle
    evaluate $ force contents
    hClose handle

    input <- getLine

    let [n1, n2, n3, n4] = processInput input

    let processedLines = map (splitByComma) (lines contents)

    let resposta_1 = funcao1 (processList processedLines) n1

    let resposta_2 = funcao2 n2 n3 (processList processedLines)

    let resposta_3 = sortBy (comparing id) (map (head) (funcao3 processedLines n4))


    print resposta_1
    print resposta_2
    printStrings resposta_3



