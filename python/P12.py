from common import num_divisors
from itertools import count

triangle_num = 0

for i in count(1):
    triangle_num += i
    num_of_divs = num_divisors(triangle_num)
    if num_of_divs > 500:
        print(triangle_num)
        break