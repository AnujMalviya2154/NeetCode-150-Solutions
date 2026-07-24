class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> points;

    CountSquares() {}

    void add(vector<int> point) {
        points[point[0]][point[1]]++;
    }

    int count(vector<int> point) {

        int x = point[0];
        int y = point[1];
        int ans = 0;

        for (auto &[nx, ys] : points) {

            if (nx == x)
                continue;

            int d = abs(nx - x);

            // Upper diagonal
            if (points[nx].count(y + d) && points[x].count(y + d))
                ans += ys[y + d] * points[nx][y] * points[x][y + d];

            // Lower diagonal
            if (points[nx].count(y - d) && points[x].count(y - d))
                ans += ys[y - d] * points[nx][y] * points[x][y - d];
        }

        return ans;
    }
};