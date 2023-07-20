import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class p11 {

  public static void main(String[] args) {
    String fileName = "../input.txt";

    List<List<Integer>> matrix = new ArrayList<>();

    try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
      String line;
      while ((line = br.readLine()) != null) {
        String[] numberStrings = line.split("\\s+");

        List<Integer> row = Arrays.stream(numberStrings).map(Integer::parseInt).collect(Collectors.toList());

        matrix.add(row);
      }
    } catch (IOException e) {
      System.err.println("Error reading the input text");
    }
    
    int window_size = 4;
    int max_prod = Integer.MIN_VALUE; 

    for (List<Integer> row : matrix) {
      for (int i = 0; i < row.size() - window_size + 1; i++) {
        List<Integer> window = row.subList(i, i + window_size);
        Integer product = window.stream().reduce(1, (a, b) -> a * b);
        max_prod = Math.max(product, max_prod);
      }
    }
    System.out.println(max_prod);
  }

}
