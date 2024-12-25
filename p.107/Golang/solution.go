package main

import (
  "bufio"
  "fmt"
  "os"
  "strconv"
  "strings"
  "sort"
)

type Edge struct {
  Weight int
  U int
  V int
}

type UnionFind struct {
  Parent []int
  Rank []int
}

func NewUnionFind(size int) *UnionFind {
  parent := make([]int, size)
  rank := make([]int, size)
  for i := range parent {
    parent[i] = i
  }
  return &UnionFind{Parent: parent, Rank: rank}
}

func (uf *UnionFind) Find(x int) int {
  if uf.Parent[x] != x {
    uf.Parent[x] = uf.Find(uf.Parent[x])
  }
  return uf.Parent[x]
}

func (uf *UnionFind) Union(x, y int) {
  rootX := uf.Find(x)
  rootY := uf.Find(y)

  if rootX != rootY {
    if uf.Rank[rootX] < uf.Rank[rootY] {
      uf.Parent[rootX] = rootY
    } else if uf.Rank[rootX] > uf.Rank[rootY] {
      uf.Parent[rootY] = rootX
    } else {
      uf.Parent[rootY] = rootX
      uf.Rank[rootX]++
    }
  }
}


type Graph struct {
  Vertices int
  Edges []Edge
}

func (g *Graph) AddEdge(u, v, weight int) {
  g.Edges = append(g.Edges, Edge{Weight: weight, U: u, V: v})
}

func (g *Graph) KruskalMST() int {
  sort.Slice(g.Edges, func (i, j int) bool {
    return g.Edges[i].Weight < g.Edges[j].Weight
  })


  uf := NewUnionFind(g.Vertices)
  mstWeight := 0

  for _, edge := range g.Edges {
    if uf.Find(edge.U) != uf.Find(edge.V) {
      uf.Union(edge.U, edge.V)
      mstWeight += edge.Weight
    }
  }

  return mstWeight
}

func (g *Graph) TotalWeight() int {
  total := 0
  for _, edge := range g.Edges {
    total += edge.Weight
  }
  return total
}

func ParseNetworkMatrix(filename string) (*Graph, error) {
  file, err := os.Open(filename)
  if err != nil {
    return nil, err
  }
  defer file.Close()

  scanner := bufio.NewScanner(file)
  var matrix [][]string

  for scanner.Scan() {
    line := strings.Split(scanner.Text(), ",")
    matrix = append(matrix, line)
  }

  if err := scanner.Err(); err != nil {
    return nil, err
  }

  vertices := len(matrix)
  graph := &Graph{Vertices: vertices}

  for i := 0; i < vertices; i++ {
    for j := i + 1; j < vertices; j++ {
      if matrix[i][j] != "-" {
        weight, err := strconv.Atoi(matrix[i][j])
        if err != nil {
          return nil, fmt.Errorf("Invalid weight at (%d, %d): %v", i, j, err)
        }
        graph.AddEdge(i, j, weight)
      }
    }
  }

  return graph, nil
}

func main() {
  filename := "0107_network.txt"

  graph, err := ParseNetworkMatrix(filename)
  if err != nil {
    fmt.Println("Error: ", err)
    return
  }

  originalWeight := graph.TotalWeight()
  mstWeight := graph.KruskalMST()
  savings := originalWeight - mstWeight

  fmt.Printf("Savings: %d\n", savings)
}
