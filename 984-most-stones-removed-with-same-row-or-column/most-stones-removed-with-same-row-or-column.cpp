class Solution {
    unordered_map<int, int> parent;

    int find(int x) {
        if (parent.count(x) == 0)
            parent[x] = x;
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        for (auto& stone : stones) {
            int row = stone[0];
            int col = ~stone[1]; // bitwise negation to avoid collision
            unite(row, col);
        }

        unordered_set<int> uniqueRoots;
        for (auto& stone : stones) {
            uniqueRoots.insert(find(stone[0]));
        }

        return stones.size() - uniqueRoots.size();
    }
};
