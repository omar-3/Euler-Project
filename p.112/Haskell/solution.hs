module Main where

main :: IO ()
main = print solve

solve :: Int
solve = go 99 0
    where
        go :: Int -> Int -> Int
        go n bCount
            | n < 100   = go 100 0
            | bCount * 100 == 99 * n
                = n
            | otherwise
                = let nextBCount = if isBouncy (n + 1) then bCount + 1 else bCount
                  in go (n + 1) nextBCount

isBouncy :: Int -> Bool
isBouncy n =
    let ds = digitsOf n
    in not (isIncreasing ds || isDecreasing ds)

isIncreasing :: [Int] -> Bool
isIncreasing ds = and (zipWith (<=) ds (tail ds))

isDecreasing :: [Int] -> Bool
isDecreasing ds = and (zipWith (>=) ds (tail ds))

digitsOf :: Int -> [Int]
digitsOf 0 = [0]
digitsOf x = reverse (go x)
    where
        go 0 = []
        go y = (y `mod` 10) : go (y `div` 10)
