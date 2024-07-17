fatorial :: Int -> Int
fatorial 0 = 1 -- Caso base
fatorial n = n * fatorial (n - 1) -- Caso recursivo


somador :: Int -> Float
somador n = fromIntegral (n * (n + 1)) / 2




main :: IO ()
main = print(somador 2)