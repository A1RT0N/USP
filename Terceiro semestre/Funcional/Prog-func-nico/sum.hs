main :: IO ()
main = do
    l1 <- getLine
    l2 <- getLine
    let x :: Integer
        x = read l1
    let y :: Integer
        y = read l2
    let z = add x y
    let str = show z
    putStrLn str

add :: (Num a) => a -> a -> a
add x y = x + y
