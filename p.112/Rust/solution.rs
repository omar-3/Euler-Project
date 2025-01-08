fn is_increasing(num: u64) -> bool {
    let s = num.to_string();
    s.as_bytes().windows(2).all(|pair| pair[0] <= pair[1])
}

fn is_decreasing(num: u64) -> bool {
    let s = num.to_string();
    s.as_bytes().windows(2).all(|pair| pair[0] >= pair[1])
}

fn is_bouncy(num: u64) -> bool {
    !(is_increasing(num) || is_decreasing(num))
}

fn main() {
    let mut count_bouncy = 0u64;
    let mut n = 99u64;

    loop  {
        n += 1;
        if is_bouncy(n) {
            count_bouncy += 1;
        }

        if count_bouncy * 100 == 99 * n {
            println!("{}", n);
            break;
        }
    }
}
