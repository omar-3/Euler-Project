type Point = [number, number];

class Triangle {
  constructor(private points: Point[]) {}

  static parse(line: string): Triangle {
    const coords = line
      .split(",")
      .map(Number)
      .reduce<Point[]>((result, value, index) => {
        if (index % 2 === 0) {
          // @ts-ignore
          result.push([value]);
        } else {
          result[result.length - 1].push(value);
        }
        return result;
      }, []);
    if (coords.length !== 3) {
      throw new Error(`Invalid input: ${line}`);
    }
    return new Triangle(coords);
  }

  area(): number {
    const [[x1, y1], [x2, y2], [x3, y3]] = this.points;
    return 0.5 * Math.abs((x1 - x3) * (y2 - y1) - (x1 - x2) * (y3 - y1));
  }

  originInTriangle(): boolean {
    const t1 = new Triangle([[0, 0], this.points[1], this.points[2]]);
    const t2 = new Triangle([[0, 0], this.points[0], this.points[1]]);
    const t3 = new Triangle([[0, 0], this.points[0], this.points[2]]);
    return this.area() === t1.area() + t2.area() + t3.area();
  }
}

let count = 0;
const lines = require("fs")
  .readFileSync("../0102_triangles.txt", "utf8")
  .split("\n");

for (const line of lines) {
  try {
    const triangle = Triangle.parse(line);
    if (triangle.originInTriangle()) {
      count++;
    }
  } catch (e) {
    console.error(`Error: ${e.message}`);
  }
}
console.log(count);
