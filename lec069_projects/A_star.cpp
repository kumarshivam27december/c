// astar_oop.cpp
// Single-file C++ program demonstrating OOP + a "hard" algorithm (A* pathfinding).
// Compile: g++ -std=c++17 astar_oop.cpp -O2 -o astar
// Run: ./astar

#include <bits/stdc++.h>
using namespace std;

/*
 OOP concepts used:
 - Encapsulation: classes Grid, SearchAlgorithm, AStar keep data & functions together.
 - Inheritance & Polymorphism: SearchAlgorithm (abstract) -> AStar (concrete).
 - RAII: no raw resource allocations; use STL containers and smart pointers if needed.
 - Operator overloading: Point equality and printing.
 - Single-responsibility: small classes with clear roles.
*/

// ----- Basic point struct -----
struct Point {
    int r, c;
    Point() : r(0), c(0) {}
    Point(int rr, int cc) : r(rr), c(cc) {}
    bool operator==(Point const& o) const { return r == o.r && c == o.c; }
    bool operator!=(Point const& o) const { return !(*this == o); }
};

// custom hash for unordered containers
struct PointHash {
    size_t operator()(Point const& p) const noexcept {
        return (static_cast<size_t>(p.r) << 32) ^ static_cast<size_t>(p.c);
    }
}

;

// easy print helper
ostream& operator<<(ostream& os, Point const& p) {
    os << "(" << p.r << "," << p.c << ")";
    return os;
}

// ----- Grid class: encapsulates map + helpers -----
class Grid {
private:
    int rows, cols;
    vector<string> cells; // '.' walkable, '#' obstacle

public:
    Grid(int r, int c) : rows(r), cols(c), cells(r, string(c, '.')) {}

    // create from vector<string>
    Grid(vector<string> layout) {
        rows = (int)layout.size();
        cols = rows ? (int)layout[0].size() : 0;
        cells = layout;
    }

    bool inBounds(Point p) const {
        return p.r >= 0 && p.r < rows && p.c >= 0 && p.c < cols;
    }

    bool isWalkable(Point p) const {
        return inBounds(p) && cells[p.r][p.c] != '#';
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void setObstacle(Point p) {
        if (inBounds(p)) cells[p.r][p.c] = '#';
    }

    char at(Point p) const {
        if (!inBounds(p)) return '?';
        return cells[p.r][p.c];
    }

    void set(Point p, char ch) {
        if (inBounds(p)) cells[p.r][p.c] = ch;
    }

    void print() const {
        for (auto &row : cells) cout << row << "\n";
    }
};

// ----- Abstract base class for search algorithms -----
class SearchAlgorithm {
public:
    virtual ~SearchAlgorithm() = default;
    // returns a vector of Points representing path from start to goal (inclusive)
    virtual vector<Point> findPath(const Grid& grid, Point start, Point goal) = 0;
};

// ----- A* implementation -----
class AStar : public SearchAlgorithm {
public:
    // 4-directional moves (up, down, left, right). Add diagonals if you want.
    const vector<pair<int,int>> moves = {{-1,0},{1,0},{0,-1},{0,1}};

    // Manhattan heuristic
    static int heuristic(Point a, Point b) {
        return abs(a.r - b.r) + abs(a.c - b.c);
    }

    struct Node {
        Point p;
        int g; // cost from start
        int f; // g + h
        Node(Point pp, int gg, int ff) : p(pp), g(gg), f(ff) {}
    };

    // comparator for priority_queue (min-heap by f then g)
    struct Cmp {
        bool operator()(Node const& a, Node const& b) const {
            if (a.f != b.f) return a.f > b.f;
            return a.g < b.g; // tie-breaker: prefer larger g (optional)
        }
    };

    // find path using A*
    vector<Point> findPath(const Grid& grid, Point start, Point goal) override {
        if (!grid.isWalkable(start) || !grid.isWalkable(goal)) return {};

        unordered_map<Point, Point, PointHash> cameFrom;
        unordered_map<Point, int, PointHash> gScore;
        auto key = [](Point p){ return p; };

        priority_queue<Node, vector<Node>, Cmp> openPQ;
        unordered_set<Point, PointHash> openSet;
        unordered_set<Point, PointHash> closedSet;

        gScore[start] = 0;
        int h0 = heuristic(start, goal);
        openPQ.emplace(start, 0, h0);
        openSet.insert(start);

        while (!openPQ.empty()) {
            Node cur = openPQ.top(); openPQ.pop();
            Point u = cur.p;

            // If this node already processed via a better path, skip
            if (closedSet.find(u) != closedSet.end()) continue;
            openSet.erase(u);
            closedSet.insert(u);

            if (u == goal) {
                return reconstructPath(cameFrom, start, goal);
            }

            for (auto &mv : moves) {
                Point v(u.r + mv.first, u.c + mv.second);
                if (!grid.isWalkable(v) || closedSet.find(v) != closedSet.end()) continue;

                int tentative_g = gScore[u] + 1; // uniform weight = 1
                auto it = gScore.find(v);
                if (it == gScore.end() || tentative_g < it->second) {
                    cameFrom[v] = u;
                    gScore[v] = tentative_g;
                    int f = tentative_g + heuristic(v, goal);
                    openPQ.emplace(v, tentative_g, f);
                    openSet.insert(v);
                }
            }
        }

        // no path found
        return {};
    }

private:
    vector<Point> reconstructPath(unordered_map<Point, Point, PointHash> const& cameFrom, Point start, Point goal) {
        vector<Point> path;
        Point cur = goal;
        path.push_back(cur);
        while (cur != start) {
            auto it = cameFrom.find(cur);
            if (it == cameFrom.end()) { // can't reconstruct
                return {};
            }
            cur = it->second;
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

// ----- Small utility to print path on grid ----- 
Grid overlayPath(Grid g, const vector<Point>& path, char mark='*') {
    for (auto &p : path) {
        if (g.isWalkable(p))
            g.set(p, mark);
    }
    return g;
}

// ----- Demo usage in main -----
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example map: '.' walkable, '#' obstacle
    vector<string> layout = {
        "..................",
        ".####....#####....",
        ".#..#....#...#....",
        ".#..#....#...#....",
        ".#..######...#....",
        ".#...........#....",
        ".#########..#....#",
        "...........#.....#",
        ".#########.#.#####",
        ".................."
    };

    Grid grid(layout);
    cout << "Original grid:\n";
    grid.print();
    cout << "\n";

    Point start(0,0);
    Point goal(9,18);

    cout << "Start: " << start << " Goal: " << goal << "\n\n";

    // Demonstrate polymorphism: treat AStar as SearchAlgorithm pointer
    unique_ptr<SearchAlgorithm> solver = make_unique<AStar>();
    vector<Point> path = solver->findPath(grid, start, goal);

    if (path.empty()) {
        cout << "No path found.\n";
        return 0;
    }

    cout << "Path length (nodes): " << path.size() << "\n";
    cout << "Path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i + 1 < path.size()) cout << " -> ";
    }
    cout << "\n\n";

    // Overlay path and print
    Grid shown = overlayPath(grid, path, '*');
    cout << "Grid with path (*) overlay:\n";
    shown.print();

    return 0;
}
