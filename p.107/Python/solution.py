class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.edges = []

    def add_edge(self, u, v, weight):
        if weight != -1:
            self.edges.append((weight, u, v))

    def find(self, parent, i):
        if parent[i] != i:
            parent[i] = self.find(parent, parent[i])
        return parent[i]
    
    def union(self, parent, rank, x, y):
        root_x = self.find(parent, x)
        root_y = self.find(parent, y)
        if root_x != root_y:
            if rank[root_x] < rank[root_y]:
                parent[root_x] = root_y
            elif rank[root_x] > rank[root_y]:
                parent[root_y] = root_x
            else:
                parent[root_y] = root_x
                rank[root_x] += 1

    def kruskal_mst(self):
        self.edges.sort()
        parent = [i for i in range(self.V)]
        rank = [0] * self.V

        mst_weight = 0
        mst_edges = []

        for weight, u, v in self.edges:
            if self.find(parent, u) != self.find(parent, v):
                self.union(parent, rank, u, v)
                mst_weight += weight
                mst_edges.append((u, v, weight))
        return mst_weight

def parse_network_matrix(filename):
    with open(filename, 'r') as file:
        lines = file.readlines()
        matrix = [line.strip().split(',') for line in lines]
        
    n = len(matrix)
    g = Graph(n)

    for i in range(n):
        for j in range(i + 1, n):
            weight = int(matrix[i][j] if matrix[i][j] != '-' else -1)
            g.add_edge(i, j, weight)
    return g

def calculate_max_savings(filename):
    g = parse_network_matrix(filename)
    original_weight = sum(edge[0] for edge in g.edges)
    mst_weight = g.kruskal_mst()
    savings = original_weight - mst_weight
    print(savings)


if __name__ == "__main__":
    calculate_max_savings("0107_network.txt")
