fn build_digit_powers() -> [u32; 10] {
    let mut arr = [0; 10];
    for d in 0u32..10u32 {
        arr[d as usize] = d.pow(5);
    }
    arr
}

fn is_sum_of_fifth_powers(n: u32, digit_powers: &[u32; 10]) -> bool {
    let mut temp = n;
    let mut sum = 0;
    while temp > 0 {
        sum += digit_powers[(temp % 10) as usize];
        temp /= 10;
    }
    sum == n
}

fn main() {
    let digit_powers = build_digit_powers();

    let answer: u64 = (2..=999_999)
        .filter(|&x| is_sum_of_fifth_powers(x, &digit_powers))
        .map(|x| x as u64)
        .sum();

    println!("{}", answer);
}
