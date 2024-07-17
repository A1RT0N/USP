import Data.List
import Data.Ord

data ArvoreBB a = Folha | No a (ArvoreBB a) (ArvoreBB a)

{-
 - O segundo Aluno representa um construtor, como dentro do da definição não importa repetir, podemos repetir o nome
-}
data Aluno = Aluno{ 
    nome :: String, 
    curso :: String, 
    media :: Float 
} deriving (Show, Eq, Read, Ord) -- Tenta colocar aluno na classe show automaticamente
-- Para colocar uma implementaçao manual, coloque instance
-- O Read padrão define que a leitura tem que ser especificamente Aluno{nome = "..", ...}

a1 = Aluno{nome = "Adenilso", curso = "BCC", media = 9.5}
a2 = Aluno{nome = "Kayane", curso = "BSI", media = 9.6}
a3 = a1{media = 9.0} -- Forma de atualizar a struct
vAl = [a1, a2, a3]

numNos :: ArvoreBB a -> Integer
numNos Folha = 0
numNos (No _ av1 av2) = (numNos av1) + (numNos av2) + 1

main = do
    putStrLn "hi"
    putStrLn $ show a3
    print $ nome a1
    putStrLn $ show $ a1 == a2
    putStrLn $ show $ vAl
    putStrLn $ show $ sum $ map media $ vAl
    putStrLn $ show $ sum $ map media $ filter ((== "BSI").curso) $ vAl
    putStrLn $ show $ sortBy (flip $ comparing media) vAl
