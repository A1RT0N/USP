reduce :: (b-> a -> a) -> a -> [b] -> a
reduce _ base [] = base
reduce op base (x:xs) = op x $ reduce op base xs

soma :: (Num a) => [a] -> a
soma = reduce (+) 0

produto = reduce (*) 1

concatenar = reduce (++) ""

mapa f = reduce ((:).f)

main = do
    putStrLn $ show $ reduce (+) 0 [1,2,3,4,5,6]
    print (reduce (:) [3,4,5] [1,2,3])
    putStrLn $ show $ mapa (+ 2) 0 ([1,2,3]::[Integer])