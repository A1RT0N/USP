-- take é a função que representa isso
tak :: (Eq a, Num a) => a -> [b] -> [b]
-- tak :: (Num a) => a -> [b] -> [b]
-- tak :: (Eq a, Num a, Ord a) => a -> [b] -> [b]
tak 0 _ = []
tak n (x:xs) = x:tak (n-1) xs

main = do
    putStrLn $ show $ tak 2 [3,2,5,1,2,5]