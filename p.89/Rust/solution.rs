use std::fs::File;
use std::io::{self, BufRead, BufReader};

fn roman_to_int(roman: &str) -> i32 {
    let mut total = 0;
    let mut prev_value = i32::MAX;

    let roman_values = |c| match c {
        'I' => 1,
        'V' => 5,
        'X' => 10,
        'L' => 50,
        'C' => 100,
        'D' => 500,
        'M' => 1000,
        _ => 0,
    };

    for c in roman.chars() {
        let value = roman_values(c);
        if value > prev_value {
            total += value - 2 * prev_value;
        } else {
            total += value;
        }
        prev_value = value;
    }
    total
}

fn int_to_minimal_roman(mut num: i32) -> String {
    let mappings = [
        (1000, "M"), (900, "CM"), (500, "D"), (400, "CD"),
        (100, "C"), (90, "XC"), (50, "L"), (40, "XL"),
        (10, "X"), (9, "IX"), (5, "V"), (4, "IV"), (1, "I"),
    ];

    let mut result = String::new();

    for &(value, symbol) in &mappings {
        while num >= value {
            result.push_str(symbol);
            num -= value;
        }
    }
    result
}

fn calculate_savings(filename: &str) -> io::Result<i32> {
    let file = File::open(filename)?;
    let reader = BufReader::new(file);
    let mut savings = 0;

    for line in reader.lines() {
        let roman = line?;
        let original_length = roman.len() as i32;
        let minimal_length = int_to_minimal_roman(roman_to_int(&roman)).len() as i32;
        savings += original_length - minimal_length;
    }

    Ok(savings)
}

fn main() -> io::Result<()> {
    let filename = "roman.txt";
    match calculate_savings(filename) {
        Ok(savings) => println!("Total characters saved: {}", savings),
        Err(e) => eprintln!("Error: {}", e),
    }
    Ok(())
}
