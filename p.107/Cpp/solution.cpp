#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <numeric>
#include <stdexcept>

struct Edge {
  int weight, u, v;

  bool operator<(const Edge& other) const {
    return weight < other.weight;
  }
};

class UnionFind {
public:
  UnionFind(int size) : parent(size), rank(size, 0) {
    std::iota(parent.begin(), parent.end(), 0);
  }

  int find(int x) {
    if (parent[x] != x)  {
      parent[x] = this->find(parent[x]);
    }
    return parent[x];
  }

  void unite(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);

    if (root_x != root_y) {
      if (rank[root_x] < rank[root_y]) {
        parent[root_x] = root_y;
      } else if (rank[root_x] > rank[root_y]) {
        parent[root_y] = root_x;
      } else {
        parent[root_y] = root_x;
        ++rank[root_x];
      }
    }
  }

private:
  std::vector<int> parent;
  std::vector<int> rank;
};

class Graph {
public:
  Graph(int vertices): vertices(vertices) {}

  void addEdge(int u, int v, int weight) {
    edges.push_back({weight, u, v});
  }

  int kruskalMST() {
    std::sort(edges.begin(), edges.end());

    UnionFind uf(vertices);
    int mst_weight = 0;

    for (const auto& edge: edges) {
      if (uf.find(edge.u) != uf.find(edge.v)) {
        uf.unite(edge.u, edge.v);
        mst_weight += edge.weight;
      }
    }

    return mst_weight;
  }

  int totalWeight() const {
    int total = 0;
    for (const auto& edge: edges) {
      total += edge.weight;
    }
    return total;
  }

private:
  int vertices;
  std::vector<Edge> edges;
};

Graph parseNetworkMatrix(const std::string& filename) {
  std::ifstream file(filename);
  if (!file) {
    throw std::runtime_error("Failed to open file: " + filename);
  }

  std::vector<std::vector<std::string>> matrix;
  std::string line;

  while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::vector<std::string> row;
    std::string cell;

    while (std::getline(ss, cell, ',')) {
      row.push_back(cell);
    }

    matrix.push_back(row);
  }

  int vertices = matrix.size();
  Graph graph(vertices);

  for (int i = 0; i < vertices; ++i) {
    for (int j = i + 1; j < vertices; j++) {
      if (matrix[i][j] != "-") {
        int weight = std::stoi(matrix[i][j]);
        graph.addEdge(i, j, weight);
      }
    }
  }

  return graph;
}


int main() {
    const std::string filename = "0107_network.txt";

    try {
        Graph graph = parseNetworkMatrix(filename);

        int original_weight = graph.totalWeight();
        int mst_weight = graph.kruskalMST();
        int savings = original_weight - mst_weight;

        std::cout << "Maximum Savings: " << savings << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
