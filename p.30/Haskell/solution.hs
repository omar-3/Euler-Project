module Main where

digitPowers :: [Int]
digitPowers = [ d^5 | d <- [0..9] ]

digits :: Int -> [Int]
digits 0 = [0]
digits n = reverse (go n [])
    where
        go 0 acc = acc
        go x acc =
            let (q, r) = x `divMod` 10
                in go q (r : acc)

isSumOfFifthPowers :: Int -> Bool
isSumOfFifthPowers n =
    let ds = digits n
        sumPowers = sum [ digitPowers !! d | d <- ds]
    in sumPowers == n

main :: IO ()
main = do
    let validNumbers = [ n | n <- [2..999999], isSumOfFifthPowers n]
    let answer = sum validNumbers
    print answer

