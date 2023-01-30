-- Defining fibonacci sequence as an infinite list
fib = 0 : scanl (+) 1 fib

-- defining number of digits
digits = 1000

-- main function

main = putStrLn $ show $ length $ takeWhile (< 10^(digits-1)) fib