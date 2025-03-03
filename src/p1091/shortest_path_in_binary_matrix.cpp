#include <queue>
#include <vector>

template <typename T>
using Row = std::vector<T>;

template <typename T>
using Grid = Row<Row<T>>;

struct Pair {
    int row, col;
    Pair(int row, int col) : row(row), col(col) {}

    Pair operator+(const Pair& rhs) {
        return Pair(row + rhs.row, col + rhs.col);
    }

    bool operator==(const Pair& rhs) const {
        return row == rhs.row && col == rhs.col;
    }
};

struct SubProblem {
    Pair pair;
    int length;

    SubProblem(Pair pair, int length) : pair(pair), length(length) {}
};

const Pair START = Pair(0, 0);

const std::vector<Pair> DIRECTIONS = {Pair(-1, -1), Pair(-1, 0), Pair(-1, 1),
                                      Pair(0, 1),   Pair(1, 1),  Pair(1, 0),
                                      Pair(1, -1),  Pair(0, -1)};

class Solution {
   public:
    int shortestPathBinaryMatrix(Grid<int>& grid) {
        if (isWall(grid, START)) {
            return -1;
        }

        if (START == end(grid)) {
            return 1;
        }

        Grid<bool> visited(grid.size(), Row<bool>(grid[0].size(), false));
        std::queue<SubProblem> queue;
        queue.push(SubProblem(START, 1));

        while (!queue.empty()) {
            SubProblem current = queue.front();
            queue.pop();
            visited[current.pair.row][current.pair.col] = true;

            if (current.pair == end(grid)) {
                return current.length;
            }

            for (Pair direction : DIRECTIONS) {
                Pair newPair = current.pair + direction;
                if (outOfBounds(grid, newPair) || isWall(grid, newPair) ||
                    isvisited(visited, newPair)) {
                    continue;
                }

                queue.push(SubProblem(newPair, current.length + 1));
            }
        }

        return -1;
    }

   private:
    bool outOfBounds(Grid<int>& grid, const Pair& pair) {
        return pair.row < 0 || pair.row >= grid.size() || pair.col < 0 ||
               pair.col >= grid[0].size();
    }

    bool isWall(Grid<int>& grid, const Pair& pair) {
        return grid[pair.row][pair.col] == 1;
    }

    bool isvisited(Grid<bool>& grid, const Pair& pair) {
        return grid[pair.row][pair.col];
    }

    bool isDestination(Grid<int>& grid, const Pair& pair) {
        return pair == end(grid);
    }

    Pair end(Grid<int>& grid) {
        return Pair(grid.size() - 1, grid[0].size() - 1);
    }
};
