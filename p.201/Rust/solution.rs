use std::collections::HashMap;

fn main() {
    let square_numbers: Vec<i32> = (1..=100).map(|x| x * x).collect();
    let subset_size = square_numbers.len() / 2;

    let mut sum_tracking: Vec<HashMap<i32, bool>> = vec![HashMap::new(); subset_size + 1];
    sum_tracking[0].insert(0, true);

    for &square in &square_numbers {
        for count in (0..subset_size).rev() {
            let current_sums: Vec<i32> = sum_tracking[count].keys().cloned().collect();
            for &existing_sum in &current_sums {
                let new_sum = square + existing_sum;
                let is_unique = !sum_tracking[count + 1].contains_key(&new_sum)
                    && *sum_tracking[count].get(&existing_sum).unwrap_or(&false);
                sum_tracking[count + 1].insert(new_sum, is_unique);
            }
        }
    }

    let unique_sum_total: i32 = sum_tracking[subset_size]
        .iter()
        .filter_map(|(&key, &value)| if value { Some(key) } else { None })
        .sum();

    println!("{}", unique_sum_total);
}
