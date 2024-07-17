main = do
    putStrLn $ show $ f 3 [8,2,5,7,2,1]
    putStrLn $ show $ conc [2,3] [4,8]



f :: (Num a, Eq a) =: a -> [b] -> b  -- Retorna b pq ele é a cabeça da lista
-- f :: (Num a, Eq a) =: a -> [a] -> a -- Isso é mais restritivo que o primeiro.
f 0 (x:_) = x
f n (_:xs) = f (n-1) xs
-- Isso pega o nésimo elemento da lista

conc :: [a] -> [a] -> [a]
conc [] l = l
conc (x:xs) l = x : (conc xs l)


tak :: (Num a, Eq a) => a -> [b] -> [b]
tak 0 _ = []   -- Pegar zero elementos da lista é pegar uma lista vazia
tak n (x:xs) = x:(f (n-1) xs) 
-- Pega as primeiras n elementos de array

mapa :: (a->b) -> [a] -> [b]
mapa _ [] = []
mapa g (x:xs) = (g x): (mapa g xs)

-- t é um teste que dado um inteiro, retorna bool (necessário por causa da guarda)
filtro _ [] = []
filtro t (x:xs)
    |   t x = x:c
    |   otherwise = c
    where   
        c = filtro t xs


-- concatenar com f infixo
[] `f` l = l
(x:xs) `f` l = x:(xs `f` l)

pertence :: (Eq a) => a -> [a] -> Bool
_ `pertence` [] = False
x `pertence` (y:ys)
    |   x == y = True
    |   otherwise = x `pertence` ys

-- tudo que é prefixo pode virar infixo e vice versa -- depende da natureza das funções (ex: mod é infixo)

-- infixo vira prefixo com () e prefixo vira infixo com `` => crase


f = mapa (*10) -- dado um número, multiplica ele por 10
