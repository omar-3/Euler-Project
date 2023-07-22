import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {

  public static void main(String[] args) {
    System.out.println(sum(primeSieve(2000_000)));
  }

  public static long sum(List<Integer> list) {
    return list.stream().mapToLong(Integer::longValue).sum();
  }

  public static List<Integer> primeSieve(int n) {
    var sieve = new ArrayList<>(Collections.nCopies(n, true));
    sieve.set(0, false);
    sieve.set(1, false);

    for (var elem = 2; elem * elem <= n; elem++) {
      if (sieve.get(elem)) {
        for (var multiply = elem * elem; multiply < n; multiply += elem) {
          sieve.set(multiply, false);
        }
      }
    }

    return IntStream.range(0, n)
        .filter(elem -> sieve.get(elem))
        .boxed()
        .collect(Collectors.toList());
  }
}
