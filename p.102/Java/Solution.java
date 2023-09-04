import java.nio.file.*;
import java.util.*;
import java.util.stream.*;

class Solution {
  public static void main(String[] args) {
    try {
      Path path = Paths.get("../0102_triangles.txt");
      List<String> lines = Files.readAllLines(path);
      long count = lines.stream()
                       .map(Triangle::parse)
                       .filter(Optional::isPresent)
                       .map(Optional::get)
                       .filter(Triangle::originInTriangle)
                       .count();
      System.out.println(count);
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}

class Triangle {
  private final List<double[]> points;
  public Triangle(List<double[]> points) { this.points = points; }
  public static Optional<Triangle> parse(String line) {
    String[] parts = line.split(",");
    if (parts.length != 6) {
      System.err.println("Invalid input: " + line);
      return Optional.empty();
    }
    List<double[]> points =
        IntStream.range(0, 3)
            .mapToObj(i
                      -> new double[] {Double.parseDouble(parts[2 * i]),
                                       Double.parseDouble(parts[2 * i + 1])})
            .collect(Collectors.toList());

    return Optional.of(new Triangle(points));
  }

  public double area() {
    double[] p1 = points.get(0);
    double[] p2 = points.get(1);
    double[] p3 = points.get(2);

    return 0.5 * Math.abs((p1[0] - p3[0]) * (p2[1] - p1[1]) -
                          (p1[0] - p2[0]) * (p3[1] - p1[1]));
  }

  public boolean originInTriangle() {
    Triangle t1 = new Triangle(
        Arrays.asList(new double[] {0, 0}, points.get(1), points.get(2)));
    Triangle t2 = new Triangle(
        Arrays.asList(new double[] {0, 0}, points.get(0), points.get(2)));
    Triangle t3 = new Triangle(
        Arrays.asList(new double[] {0, 0}, points.get(0), points.get(1)));
    return this.area() == t1.area() + t2.area() + t3.area();
  }
}
