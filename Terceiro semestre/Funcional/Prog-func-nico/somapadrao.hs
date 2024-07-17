soma :: [Integer] -> Integer

soma [] = 0
-- soma l = (head l) + (soma (tail l)) Mas não é assim que se faz
soma (x:xs) = x + soma xs

soma2 :: Num a => [a] -> a
soma2 l = foldl (+) 0 l

saltapares :: [a] -> [a]
saltapares [] = []
saltapares [x] = [x]
saltapares (x1:_:xs) = x1:(saltapares xs)

main :: IO()

main = do
    let s = soma [1,2,3,4,5,6,7]
    print s
    let j = saltapares [1,2,3,4,5,6,7]
    print j
