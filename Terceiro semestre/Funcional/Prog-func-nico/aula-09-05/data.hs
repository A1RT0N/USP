data Sexo = M | F -- Criação de tipo, em que ele pode ser ou m ou f
data DiaDaSemana = Dom | Seg | Ter | Qua | Qui | Sex | Sab -- Cada elemento é um construtor, então consigo colocar parâmetros diferentes nele
    deriving (Show, Eq, Enum)

felicidade :: DiaDaSemana -> Integer
felicidade Sex = 10
felicidade Sab = 15
felicidade Qui = 20
felicidade Dom = 8
felicidade _ = 5

teste = [Dom .. Qua] -- Isso vem do Enum, que me permite enumerar as coisas

main = do
    putStrLn "hi"
    putStrLn $ show $ felicidade Dom
    putStrLn $ show Dom
    print teste
