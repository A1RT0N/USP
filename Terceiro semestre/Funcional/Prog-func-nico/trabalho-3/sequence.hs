grstSeqRec :: (Ord a) => [a] -> Integer -> Integer -> Integer
grstSeqRec [] _ _ = 0
grstSeqRec [a] inc maxSec = max inc maxSec
grstSeqRec (l1 : l2 : ls) inc maxSec
    | l1 < l2 = grstSeqRec (l2 : ls) (inc + 1) maxSec
    | otherwise = grstSeqRec (l2 : ls) 1 $ max inc maxSec

getGrstSeq :: (Ord a) => [a] -> Integer
getGrstSeq l = grstSeqRec l 1 0

main :: IO ()
main = do
    line <- getLine
    let l :: (Read a, Num a) => [a]
        l = map read $ words line
    print $ getGrstSeq l