main :: IO ()

main = do 
    
    l1 <- getLine
    l2 <- getLine
    let x :: Integer
    x = read l1

    let y :: Integer
    y = read l1

    let z = add x y

    let str = show z

    putStrLn str

add :: (Num a) => a -> a -> add
add x y = x + y

-- strict e nao strint

-- nao strict é legal trabalhar com SO q eh lazy

-- nao strict calcula o valor que vc passou na função se necessário (diferente de C)