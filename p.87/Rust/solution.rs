use std::collections::HashSet;

fn generate_primes(limit: usize) -> Vec<usize> {
    let mut sieve = vec![true; limit];
    sieve[0] = false;
    sieve[1] = false;

    for i in 2..((limit as f64).sqrt() as usize) {
        if sieve[i] {
            for multiple in (i * i..limit).step_by(i) {
                sieve[multiple] = false;
            }
        }
    }

    sieve
        .iter()
        .enumerate()
        .filter(|&(_, &is_prime)| is_prime)
        .map(|(num, _)| num)
        .collect()
}

fn count_expressible_numbers(limit: usize) -> usize {
     let primes = generate_primes(limit);

     let prime_squares: Vec<u128> = primes
        .iter()
        .map(|&p| (p as u128) * (p as u128))
        .filter(|&n| n < limit as u128)
        .collect();

    let prime_cubes: Vec<u128> = primes
        .iter()
        .map(|&p| (p as u128) * (p as u128) * (p as u128))
        .filter(|&n| n < limit as u128)
        .collect();

    let prime_fourths: Vec<u128> = primes
        .iter()
        .map(|&p| (p as u128) * (p as u128) * (p as u128) * (p as u128))
        .filter(|&n| n < limit as u128)
        .collect();

    let mut expressible_numbers = HashSet::new();

    for &square in &prime_squares {
        for &cube in &prime_cubes {
            if square + cube >= limit as u128 {
                break;
            }
            for &fourth in &prime_fourths {
                let total = square + cube + fourth;
                if total < limit as u128 {
                    expressible_numbers.insert(total);
                } else {
                    break;
                }
            }
        }
    }

    expressible_numbers.len()}

fn main() {
    let limit = 50_000_000;
    let result = count_expressible_numbers(limit);
    println!("{}", result);
}
