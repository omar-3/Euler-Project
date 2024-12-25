import java.io.File
import java.util.PriorityQueue

data class Edge(val weight: Int, val u: Int, val v: Int) : Comparable<Edge> {
  override fun compareTo(other: Edge): Int = this.weight.compareTo(other.weight)
}

class UnionFind(private val size: Int) {
  private val parent = IntArray(size) { it }
  private val rank = IntArray(size) { 0 }

  fun find(x: Int): Int {
    if (parent[x] != x) {
      parent[x] = find(parent[x])
    }
    return parent[x]
  }

  fun union(x: Int, y: Int) {
    val rootX = find(x)
    val rootY = find(y)

    if (rootX != rootY) {
      when {
        rank[rootX] < rank[rootY] -> parent[rootX] = rootY
        rank[rootY] > rank[rootX] -> parent[rootY] = rootX
        else -> {
          parent[rootY] = rootX
          rank[rootX] += 1
        }
      }
    }
  }
}


class Graph(private val vertices: Int) {
  private val edges = mutableListOf<Edge>()

  fun addEdge(u: Int, v: Int, weight: Int) {
    edges.add(Edge(weight, u, v))
  }

  fun kruskalMST(): Int {
    edges.sort()

    val unionFind = UnionFind(vertices)
    var mstWeight = 0

    for (edge in edges) {
      if (unionFind.find(edge.u) != unionFind.find(edge.v)) {
        unionFind.union(edge.u, edge.v)
        mstWeight += edge.weight
      }
    }

    return mstWeight
  }

  fun totalWeight(): Int = edges.sumOf { it.weight }
}

fun parseNetworkMatrix(filename: String): Graph {
  val lines = File(filename).readLines()
  val size = lines.size
  val graph = Graph(size)

  lines.forEachIndexed { i, line ->
    line.split(",").forEachIndexed { j, value ->
      if (j < i && value != "-") {
        graph.addEdge(i, j, value.toInt())
      }
    }
  }

  return graph
}

fun main() {
  val filename = "0107_network.txt"


  val graph = parseNetworkMatrix(filename)
  val originalWeight = graph.totalWeight()
  val mstWeight = graph.kruskalMST()
  val savings = originalWeight - mstWeight

  println("Maximum Savings: $savings")
}
