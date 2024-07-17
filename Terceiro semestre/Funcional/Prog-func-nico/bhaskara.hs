bhaskara :: Float -> Float -> Float -> [Float]
bhaskara a b c
    | delta > 0 = [(-b + delta**(0.5))/(2*a), (-b - delta**(0.5))/(2*a)]
    | delta = 0 = [-b/(2*a)]
    | otherwise = []
    where delta = b**2 - 4*a*c

bmi :: Float -> Float -> String
bmi h w
    | val < 20 = "Abaixo"
    | val < 30 = "Normal"
    | val < 35 = "Sobrepeso"
    | val < 40 = "Obeso I"
    | otherwise = "Obeso II"
    where val = w / (h*h)

main :: IO ()

main = do
    print "BMI: "
    l <- getLine
    let h :: Float
        h = read l
    l <- getLine
    let w :: Float
        w = read l
    print (bmi h w)

    print "Bhaskara: "
    l <- getLine
    let a :: Float
        a = read l
