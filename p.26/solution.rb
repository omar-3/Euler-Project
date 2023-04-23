DIGITS = 1000

def no_of_digits(number)
    Math.log10(number).to_int + 1
end

def solve(n)
    prev = 0
    cur = 1
    1.step do |i|
        return i if no_of_digits(cur) == n
        prev, cur = cur, cur + prev
    end
end


puts solve(DIGITS)