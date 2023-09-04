def triangle_area(x1, y1, x2, y2, x3, y3):
    return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))


def origin_in_triangle(x1, y1, x2, y2, x3, y3):
    total_area = triangle_area(x1, y1, x2, y2, x3, y3)
    area1 = triangle_area(0, 0, x1, y1, x2, y2)
    area2 = triangle_area(0, 0, x2, y2, x3, y3)
    area3 = triangle_area(0, 0, x1, y1, x3, y3)
    return total_area == area1 + area2 + area3


def solve():
    with open("../0102_triangles.txt") as file:
        triangles = [[*map(int, line.split(","))] for line in file]
        return sum(origin_in_triangle(*triangle) for triangle in triangles)


if __name__ == "__main__":
    print(solve())
