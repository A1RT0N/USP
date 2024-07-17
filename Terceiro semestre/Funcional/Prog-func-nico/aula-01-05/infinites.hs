y = 1:y

-- s n = n:s (n+1)
s = let
        ss n = n:ss (n+1)
    in
        ss 1

-- Peneira de eratosteles
primos = let
        b (x:xs) = x:b (filter ((/= 0).(`mod` x)) xs)
    in
        b [2..]

iter :: a -> (a -> a) -> [a]
iter b f = b:iter (f b) f

main = do
    -- putStrLn $ show y
    -- putStrLn $ show $ s
    putStrLn $ show $ sum $ takeWhile (< 1000) primos

    putStrLn $ show $ dropWhile (< 50) $ takeWhile (< 100) $ primos

    print $ take 10 $ iter 1 (* 2)
    print $ take 10 $ iter 1 (+ 1)
    print $ sum $ take 10 $ iter 1 (* 2)
    
    print $ sum $ takeWhile (< 1000000) $ iter 1 (* 3)