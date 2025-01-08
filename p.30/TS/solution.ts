const digitPowers: number[] = Array.from({ length: 10 }, (_, d) => d ** 5);

function sumOfFifthPowersOfDigits(num: number): number {
  let sum = 0;
  let temp = num;

  while (temp > 0) {
    const digit = temp % 10;
    sum += digitPowers[digit];
    temp = Math.floor(temp / 10);
  }

  return sum;
}

function sumOfFifthPowerNumbers(): number {
  let total = 0;

  for (let n = 2; n <= 999_999; n++) {
    if (n === sumOfFifthPowersOfDigits(n)) {
      total += n;
    }
  }

  return total;
}

function main(): void {
  const answer = sumOfFifthPowerNumbers();
  console.log(answer);
}

main();
