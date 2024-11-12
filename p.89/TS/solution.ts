import * as fs from 'fs';
import * as readline from 'readline';


function romanToInt(roman: string): number {
  const romanValues: {[key: string]: number} = {
    'I': 1, 'V': 5, 'X': 10, 'L': 50,
    'C': 100, 'D': 500, 'M': 1000
  };

  let total = 0;
  let prevValue = Infinity;

  for (const char of roman) {
    const value = romanValues[char];
    if (value > prevValue) {
      total += value - 2 * prevValue;
    } else {
      total += value
    }
    prevValue = value;
  }

  return total
}


function intToMinimalRoman(num: number): string {
  const mappings: Array<[number, string]> = [
    [1000, 'M'], [900, 'CM'], [500, 'D'], [400, 'CD'],
    [100, 'C'], [90, 'XC'], [50, 'L'], [40, 'XL'],
    [10, 'X'], [9, 'IX'], [5, 'V'], [4, 'IV'], [1, 'I']
  ];

  let result = '';
  for (const [value, numeral] of mappings) {
    while (num >= value) {
      result += numeral
      num -= value
    }
  }

  return result
}

async function calculateSavings(filename: string): Promise<number> {
  const fileStream = fs.createReadStream(filename);
  const rl = readline.createInterface({
    input: fileStream,
    crlfDelay: Infinity
  });

  let savings = 0;

  for await (const line of rl) {
    const roman = line.trim();
    const originalLength = roman.length;
    const minimalLength = intToMinimalRoman(romanToInt(roman)).length;
    savings += originalLength - minimalLength;
  }

  return savings;
}

const filename = 'roman.txt';
calculateSavings(filename)
  .then(savings => console.log(`Total characters saved: ${savings}`))
  .catch(error => console.error(`Error: ${error.message}`));
