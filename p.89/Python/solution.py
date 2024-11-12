import math

def roman_to_int(roman):
    roman_values = {'I': 1, 
                    'V': 5, 
                    'X': 10, 
                    'L': 50, 
                    'C': 100, 
                    'D': 500, 
                    'M': 1000}
    value = 0
    total = 0
    prev_value = math.inf
    for char in roman:
        value = roman_values[char]
        if value > prev_value:
            total -= prev_value * 2
        prev_value = value
        total += value
    return total


def int_to_roman(num):
    int_to_roman_mappings = [
        (1000, 'M'), (900, 'CM'), (500, 'D'), (400, 'CD'),
        (100, 'C'), (90, 'XC'), (50, 'L'), (40, 'XL'),
        (10, 'X'), (9, 'IX'), (5, 'V'), (4, 'IV'), (1, 'I')
    ]
    result = []
    for value, numeral in int_to_roman_mappings:
        count = num // value
        result.append(numeral * count)
        num -= value * count
    return ''.join(result)

with open('roman.txt') as file:
    numeral = file.read().strip().splitlines()

savings = 0
for roman in numeral:
    original_length = len(roman)
    minimal_length = len(int_to_roman(roman_to_int(roman)))
    savings += original_length - minimal_length

print(f"Total characters is {savings}")
