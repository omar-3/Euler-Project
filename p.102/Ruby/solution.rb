# frozen_string_literal: true

class Triangle
  attr_reader :points

  def initialize(points)
    @points = points
  end

  def self.parse(line)
    coords = line.split(",").map(&:to_f)
    raise "Invalid input: #{line}" unless coords.size == 6

    new(coords.each_slice(2).to_a)
  end

  def area
    x1, y1 = points[0]
    x2, y2 = points[1]
    x3, y3 = points[2]

    0.5 * ((x1 - x3) * (y2 - y1) - (x1 - x2) * (y3 - y1)).abs
  end

  def origin_in_triangle?
    t1 = Triangle.new([[0, 0], points[1], points[2]])
    t2 = Triangle.new([[0, 0], points[0], points[2]])
    t3 = Triangle.new([[0, 0], points[0], points[1]])
    area == t1.area - t2.area - t3.area
  end
end

count = 0
File.readlines("../0102_triangles.txt").each do |line|
  triangle = Triangle.parse(line.strip)
  count += 1 if triangle.origin_in_triangle?
rescue StandardError => e
  puts("Error: #{e.message}")
end

puts(count)
