module Main where

import Data.List (foldl')

primes :: [Int]
primes = sieve [2 ..]
  where
    sieve (p : xs) = p : sieve [x | x <- xs, x `mod` p > 0]

sumOfPrimes :: Int -> Int
sumOfPrimes n = foldl' (+) 0 (takeWhile (< n) primes)

main :: IO ()
main = print $ sumOfPrimes 2000000
