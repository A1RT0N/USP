main :: IO () {-Tipo de função nao puro que retorna nada-}
f :: (Num a) => a -> a {-Em funcional a ordem da definicao das coisas nao importa, entao posso definir f depois da main-}
f x = x + 1

h :: (Num a) => a -> a -> b -> a
h x y z = x + y

w1 = sum [1..100]
w2 = sum [1..]

main = do
    putStrLn "Hello"
    putStrLn "W"
    {- let dummy = getLine -> estou definindo dummy como a funcao getline, ok pois estou definindo nomes; usar algo puro com algo impuro -}
    l <- getLine {- Executa getLine e coloca o resultado em l -> nao e funcional; l retorna um valor constante, l vira constante-}
    let v = read l 
    let     x = f v
            y = x * 2
    let c1 = h x y w2
    let str = show c1

    putStrLn str
