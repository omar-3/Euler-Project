use std::cmp::Ordering;
use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

#[derive(Debug, Eq, PartialEq)]
struct Edge {
    weight: u32,
    u: usize,
    v: usize,
}

impl Ord for Edge {
    fn cmp(&self, other: &Self) -> Ordering {
        self.weight.cmp(&other.weight)
    }
}

impl PartialOrd for Edge {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

struct UnionFind {
    parent: Vec<usize>,
    rank: Vec<usize>,
}

impl UnionFind {
    fn new(size: usize) -> Self {
        UnionFind {
            parent: (0..size).collect(),
            rank: vec![0; size],
        }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.parent[x] != x {
            self.parent[x] = self.find(self.parent[x]);
        }
        self.parent[x]
    }

    fn union(&mut self, x: usize, y: usize) {
        let root_x = self.find(x);
        let root_y = self.find(y);

        if root_x != root_y {
            if self.rank[root_x] < self.rank[root_y] {
                self.parent[root_x] = root_y;
            } else if self.rank[root_y] < self.rank[root_x] {
                self.parent[root_y] = root_x;
            } else {
                self.parent[root_y] = root_x;
                self.rank[root_x] += 1;
            }
        }
    }
}

struct Graph {
    vertices: usize,
    edges: Vec<Edge>,
}

impl Graph {
    fn new(vertices: usize) -> Self {
        Self {
            vertices,
            edges: Vec::new(),
        }
    }

    fn add_edge(&mut self, u: usize, v: usize, weight: u32) {
        self.edges.push(Edge { weight, u, v });
    }

    fn kruskal_mst(&mut self) -> u32 {
        self.edges.sort_unstable();

        let mut uf = UnionFind::new(self.vertices);
        let mut mst_weight = 0;

        for edge in &self.edges {
            if uf.find(edge.u) != uf.find(edge.v) {
                uf.union(edge.u, edge.v);
                mst_weight += edge.weight;
            }
        }
        mst_weight
    }
}

fn parse_network_matrix<P: AsRef<Path>>(filename: P) -> io::Result<Graph> {
    let file = File::open(filename)?;
    let reader = io::BufReader::new(file);

    let mut matrix: Vec<Vec<Option<u32>>> = Vec::new();

    for line in reader.lines() {
        let row = line?
            .split(',')
            .map(|s| s.parse::<u32>().ok())
            .collect::<Vec<Option<u32>>>();
        matrix.push(row);
    }

    let vertices = matrix.len();
    let mut graph = Graph::new(vertices);

    for i in 0..vertices {
        for j in (i+1)..vertices {
            if let Some(weight) = matrix[i][j] {
                graph.add_edge(i, j, weight);
            }
        }
    }
    Ok(graph)
}

fn main() -> io::Result<()> {
    let filename = "0107_network.txt";
    let mut graph = parse_network_matrix(filename)?;

    let original_weight: u32 = graph.edges.iter().map(|e| e.weight).sum();
    let mst_weight = graph.kruskal_mst();
    let savings = original_weight - mst_weight;

    println!("{}", savings);

    Ok(())
}
