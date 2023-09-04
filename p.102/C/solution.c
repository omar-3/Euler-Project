#include <math.h>
#include <stdio.h>

double triangle_area(double x1, double y1, double x2, double y2, double x3,
                     double y3) {
  return 0.5 * fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

int origin_in_triangle(double x1, double y1, double x2, double y2, double x3,
                       double y3) {
  double total_area = triangle_area(x1, y1, x2, y2, x3, y3);
  double area1 = triangle_area(0, 0, x1, y1, x2, y2);
  double area2 = triangle_area(0, 0, x2, y2, x3, y3);
  double area3 = triangle_area(0, 0, x1, y1, x3, y3);
  return total_area == area1 + area2 + area3;
}

int main() {
  FILE *file = fopen("../0102_triangles.txt", "r");
  if (file == NULL) {
    fprintf(stderr, "Could not open file\n");
    return 1;
  }

  double x1, y1, x2, y2, x3, y3;
  int count = 0;
  while (fscanf(file, "%lf,%lf,%lf,%lf,%lf,%lf", &x1, &y1, &x2, &y2, &x3,
                &y3) == 6) {
    if (origin_in_triangle(x1, y1, x2, y2, x3, y3)) {
      count++;
    }
  }
  fprintf(stdout, "%d\n", count);

  fclose(file);
  return 0;
}
