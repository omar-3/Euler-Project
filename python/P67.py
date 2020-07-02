# preparing the data
TRIANGLE = list()

with open('P67data.txt') as FILE:
    line = FILE.readline()
    while line:
        TRIANGLE.append([int(number) for number in line.split()])
        line = FILE.readline()

def solve():
    for i in range(len(TRIANGLE) - 2 , -1 , -1):
        for j in range(len(TRIANGLE[i])):
            TRIANGLE[i][j] += max(TRIANGLE[i + 1][j], TRIANGLE[i + 1][j + 1])

if __name__ == "__main__":      
    solve()
    print(TRIANGLE[0][0])