import Data.List 

{- 
    Implementação para obtenção de lista de primos pela Peneira de Eratóstenes obtida de https://wiki.haskell.org/Prime_numbers#Guarded 
    Como era um problema bem definido, decidi pegar a função da wiki
-}

primeInterval :: (Ord a, Num a, Enum a) => a -> a -> [a]
primeInterval start end = dropWhile (< start) $ 2:eratos [3,5..end]
    where
        eratos [] = []
        eratos (x:xs) = x : eratos(xs \\ [x*x, x*x+x..end])

getDists :: Num a => [a] -> [a]
getDists [] = []
getDists [a] = []
getDists (x:y:xs) = (y-x) : getDists (y:xs)

main::IO()

main = do
    lineBegin <- getLine
    let begin = read lineBegin
    lineEnd <- getLine
    let end = read lineEnd
    
    let res = foldr max 0 (getDists (primeInterval begin end))
    print res
