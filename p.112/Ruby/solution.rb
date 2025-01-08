def digits_of(num)
  num == 0 ? [0] : num.digits.reverse
end

def is_increasing(num)
  digs = digits_of(num)
  digs.each_cons(2).all? { |a, b| a <= b }
end

def is_decreasing(num)
  digs = digits_of(num)
  digs.each_cons(2).all? { |a, b| a >= b }
end

def is_bouncy(num)
  !is_increasing(num) && !is_decreasing(num)
end

n = 99
bouncy_count = 0

loop do
  n += 1
  bouncy_count += 1 if is_bouncy(n)

  if bouncy_count * 100 == 99 * n
    puts n
    break
  end
end
