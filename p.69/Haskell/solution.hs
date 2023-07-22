import Data.List
import Data.Ord

primeFactors :: Integer -> Integer -> [Integer]
primeFactors _ 1 = []
primeFactors d n
  | n `mod` d == 0 = d : primeFactors (d + 1) (n `div` (product (replicate count d)))
  | otherwise = primeFactors (d + 1) n
  where
    count = length (takeWhile (\x -> x `mod` d == 0) (iterate (`div` d) n))

totient :: Integer -> Double
totient n = 1 / product [(1 - 1 / fromIntegral p) | p <- primeFactors 2 n]

main :: IO ()
main = print $ maximumBy (\a b -> compare (totient a) (totient b)) [2 .. 1000000]
