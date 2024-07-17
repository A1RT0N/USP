-- Qualquer expressão ou parte de expressão em haskell tem um tipo

-- Em py tem Integer e Int 

-- Haskell é fortemente tipado

-- SISTEMAS DE TIPOS:

-- f x y = x+y

-- Classe de tipo

-- Num é uma classe de tipo: representa todos os tipos que consegue fazer operação aritmética


-- 5 :: Int
-- 5 :: Integer
-- 5 :: Rational
-- '5' :: Char
-- [5,5] :: [Int]

-- f x = x + x
-- classe de tipo
-- Num
-- construtores
-- Int
-- [Int]
-- [Char]
-- [[Int]]

-- 5 :: (Num a) => a
-- [3,5] :: (Num a) => [a]

-- g :: Int -> Integer
-- [Int] -> Int
-- [[Int] -> Int] -> [[Int]]

-- Int -> Int -> [Int]  -- Função que, dado um inteiro, retorna uma função que, dado um inteiro, retorna uma lista de inteiro

f x y = x+y

f :: (Num a) => a -> a -> a




m x y = x + 3

-- m:: (Num a) => a -> (b -> a)


Int -> Int -> Int
Int -> Int -> [Int]

(Int -> Int) -> Int X
Int -> (Int -> [Int] x)

f :: (Num a) => a -> a -> a

(f 3 5) :: (Num a) => a
(f 3) :: (Num a) => a -> a

h = f 1
h :: (Num a) => a -> a
h 6
h 41


n x y = x

n:: b -> a ->b

p x y = 42

p :: (Num c) => a -> b -> c
 -- ou 

p :: (Num a, Num c) => a -> b -> c 

g x y = x + 3
f x y = x + y

g :: (Eq a) => a -> a -> Bool
f :: (Num a, Ord a) => a -> a -> Bool
f x = x > 5


[] :: [a]

x = [5, 8]   ::      (Num a) => [a]
y = 3        ::     (Num a) => a

(y : x) :: (Num a) => [a]

(:) :: a -> [a] -> [a]
(:) :: (Num a) => a -> [a] -> [a]


mapa [] = []
mapa (x:xs) = (2*x):(mapa xs)
mapa :: Num a => [a] -> [a]

 -- Def do map

map f [] = []
map f (x: xs) = (f x) : (map f xs)

map:: (b->c) => [b] -> [c]

-- -------------


mult2 x = 2*x

mapa l = map mult2 l 

mapa l = map(\x->2*x)l -- mais direto

mapa map(\x -> 2*x)


-- --------------

m x y = x + 3

(1;0)(1)

g x y = x = y
9 : (f q q) = a → a → Bool
f x y = x + y
Σ: (Num a, Ord a) => a → a → Bool
δ x = x > 5

