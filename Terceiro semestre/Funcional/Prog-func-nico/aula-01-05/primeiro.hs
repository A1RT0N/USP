primeiro :: (Show a) => [a] -> Either a String -- Tipo composto
primeiro [] = Right "Nao ha elementos"
primeiro (x:_) = Left x

main = do
    putStrLn $ either show id $ primeiro [4,5,6,7]