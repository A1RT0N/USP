import Data.List
import Data.Ord

main = do
    putStrLn "Hello"
    putStrLn $ show $ felicidade Dom
    putStrLn $ show $ a1
    putStrLn $ show $ [Sex .. Seg]
    putStrLn $ nome a1
    putStrLn $ show $ sum $ map $ medio $ filter (\a -> (curso a) == "BSI") arr
    putStrLn $ show $ sum $ map $ medio $ filter ((== "BSI").curso) $ arr
    putStrLn $ show $ sortBy (comparing media) arr -- SortBY caso não queira colocar ord em Aluno
    putStrLn $ show $ sortBy (flip $ comparing media) arr

data Sexo = M | F
data DiaSemana = Dom | Seg | Ter | Qua | Qui | Sex | Sab
    deriving(Show, Eq, Read, Ord)

-- data ArvoreBB = Folha | No Integer ArvoreBB ArvoreBB
data ArvoreBB a = Folha | No a (ArvoreBB a) (ArvoreBB a)
-- Struct: 
data Aluno = Aluno {nome :: String, curso :: String, media :: Float} -- Pode-se reusar o nome
    deriving(Show) -- Coloque o aluno na classe Show -> automaticamente sabe imprimir

-- nome é uma função que dado um Aluno, retorna String

a1 = Aluno {{nome = "Adenilso", curso = "BCC", media = 9.5}}
a2 = Aluno {{nome = "Joao", curso = "BSI", media = 9}}

arr = [a1,a2]

felicidade :: DiaSemana -> Integer
felicidade Sex = 10
felicidade Sab = 15
felicidade Dom = 9
felicidade _ = 5

numNos :: ArvoreBB a -> Integer
numNos Folha = 0
numNos (No _ av1 av2) = ((numNos av1) + (numNos av2 )+ 1) 
