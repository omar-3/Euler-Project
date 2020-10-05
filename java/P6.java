import java.util.*;
import java.util.stream.IntStream;

public class P6 {
    public static void main(String[] args) {
        System.out.println(solve(100));
    }

    private static int solve(int N) {
        int[] elements = IntStream.range(1, N).toArray();
        int i = 0;
        int SUM = 0;
        while (i < elements.length - 1) {
            int j = i + 1;
            while (j < elements.length) {
                SUM += 2 * elements[i] * elements[j];
                j += 1;
            }
            i += 1;
        }
        return SUM;
    }
}