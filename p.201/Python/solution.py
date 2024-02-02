from typing import Dict, List

total_number = 100
square_numbers = [i**2 for i in range(1, total_number + 1)]
subset_size = total_number // 2

# Keeps tracks of the uniquness of the sums for each subset size
sum_tracking : List[Dict[int, bool]] = [{} for _ in range(subset_size + 1)]

# You can ONLY get sum of 0 uniquely by adding zero elements
sum_tracking[0][0] = True 

for square in square_numbers:
    for count in range(subset_size - 1, -1, -1):
        current_sums = list(sum_tracking[count].keys())
        for existing_sum in current_sums:
            new_sum = existing_sum + square
            sum_tracking[count + 1][new_sum] = \
                    (new_sum not in sum_tracking[count + 1] and sum_tracking[count].get(existing_sum, False))

unique_sum_total = sum(key for key in sum_tracking[subset_size] if sum_tracking[subset_size][key])
print(unique_sum_total)
