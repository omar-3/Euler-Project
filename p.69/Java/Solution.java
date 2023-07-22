import java.util.*;
import java.util.stream.*;
import java.util.function.*;

public class Solution {
  public static List<Integer> primeFactors(int n) {
    var factors = new ArrayList<Integer>();
    for (var i = 2; i <= Math.sqrt(n); i++) {
      while (n % i == 0) {
        factors.add(i);
        n /= i;
      }
    }
    if (n > 1) {
      factors.add(n);
    }
    return factors;
  }

  public static double totientFunction(int n, List<Integer> factors) {
    return factors.stream()
        .distinct()
        .mapToDouble(factor -> (1.0 - 1.0 / factor))
        .reduce(n, (subtotal, factor) -> subtotal * factor);
  }

  public static void main(String[] args) {
    var maxRatio = IntStream.rangeClosed(2, 1_0)
        .boxed()
        .parallel()
        .map(i -> {
          var factors = primeFactors(i);
          var totientValue = 1.0 / totientFunction(i, factors);
          return Map.entry(i, totientValue);
        })
        .max(Map.Entry.comparingByValue())
        .orElseThrow();
    System.out.println(maxRatio.getKey());
  }
}
