def is_increasing(num):
    s = str(num)
    return all(s[i] <= s[i+1] for i in range(len(s) - 1))

def is_decreasing(num):
    s = str(num)
    return all(s[i] >= s[i+1] for i in range(len(s) - 1))

def is_bouncy(num):
    return not (is_decreasing(num) or is_increasing(num))

count_bouncy = 0
n = 99
while True:
    n += 1
    if is_bouncy(n):
        count_bouncy += 1
    if (count_bouncy * 100) == 99 * n:
        print(n)
        break
