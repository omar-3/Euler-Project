import re

FILE = open('./P22data.txt')
names = sorted([re.sub('\W','',c) for c in FILE.read().split(',')])

total = 0

scoring = lambda name : sum([ord(c) - ord('A') + 1 for c in name])

for index, name in enumerate(names, 1):
    total += index * scoring(name)

print(total)