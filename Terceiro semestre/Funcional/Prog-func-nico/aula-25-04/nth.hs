nth :: (Eq a, Num a) => a -> [b] -> b -- Preciso colocar Eq pois tenho que comparar ele com 0
-- nth :: (Eq a, Num a) => a -> [a] -> a -- Tipo mais restrito
nth 0 (x:_) = x
nth n (_:xs) = nth (n-1) xs

main = do
    -- $ é uma função
    {-
    f $ x = f x -> $ é uma função infix (não preciso usar parênteses)
    só pode ser usado com uma função e um valor
    -}
    putStrLn $ show $ nth 3 "abcde" -- Vamos usar o $ para fazer alguma coisa legal
    -- putStrLn $ show $ nth 3 [3,4,5,1,2,3,4]