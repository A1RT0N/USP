-- Coloque os tipos nas coisas

main :: IO ()   -- o IO marca um tipo

-- main = putStrln "Hello World"

main = do     -- Só funções impuras usam do, por causa da imperativo.
    putStrLn "Hello"
    putStrLn "W"

    l <- getLine  -- l é constante e impura

    -- let v :: Integer
    let v = read l

    -- let dummy = getLine   Isso dá errado

    -- O let faz o mostra que é algo puro dentro de uma funcao impura (no caso, o da main)

    let x = f v  --- Seja x f (41) 
    let y = x*2

    let str = show y

    putStrLn str

f :: (Num a) => a -> a
f x = x +1


-- Em haskell vc nunca vai ter um função pura supreeendementemente virando algo impuro


h:: (Num a, Ord a) => a->a->a->

h x y z = if x>10
          then y
          else z

w1 = sum [1..100]

w2 = sum [1..]