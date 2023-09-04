var Triangle = /** @class */ (function () {
  function Triangle(points) {
    this.points = points;
  }
  Triangle.parse = function (line) {
    var coords = line
      .split(",")
      .map(Number)
      .reduce(function (result, value, index) {
        if (index % 2 === 0) {
          // @ts-ignore
          result.push([value]);
        } else {
          result[result.length - 1].push(value);
        }
        return result;
      }, []);
    if (coords.length !== 3) {
      throw new Error("Invalid input: ".concat(line));
    }
    return new Triangle(coords);
  };
  Triangle.prototype.area = function () {
    var _a = this.points,
      _b = _a[0],
      x1 = _b[0],
      y1 = _b[1],
      _c = _a[1],
      x2 = _c[0],
      y2 = _c[1],
      _d = _a[2],
      x3 = _d[0],
      y3 = _d[1];
    return 0.5 * Math.abs((x1 - x3) * (y2 - y1) - (x1 - x2) * (y3 - y1));
  };
  Triangle.prototype.originInTriangle = function () {
    var t1 = new Triangle([[0, 0], this.points[1], this.points[2]]);
    var t2 = new Triangle([[0, 0], this.points[0], this.points[1]]);
    var t3 = new Triangle([[0, 0], this.points[0], this.points[2]]);
    return this.area() === t1.area() + t2.area() + t3.area();
  };
  return Triangle;
})();
var count = 0;
var lines = require("fs")
  .readFileSync("../0102_triangles.txt", "utf8")
  .split("\n");
for (var _i = 0, lines_1 = lines; _i < lines_1.length; _i++) {
  var line = lines_1[_i];
  try {
    var triangle = Triangle.parse(line);
    if (triangle.originInTriangle()) {
      count++;
    }
  } catch (e) {
    console.error("Error: ".concat(e.message));
  }
}
console.log(count);
