/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* dfs(vector<vector<int>>& grid, int size, int row, int col) {
        bool allSame = true;
        for (int i = 0 ; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[row][col] != grid[row + i][col + j]) {
                    allSame = false;
                }
            }
        }

        if (allSame) {
            return new Node(grid[row][col], true);
        }

        int newSize = size / 2;
        Node* topLeft = dfs(grid, newSize, row, col);
        Node* topRight = dfs(grid, newSize, row, newSize + col);
        Node* botLeft = dfs(grid, newSize, row + newSize, col);
        Node* botRight = dfs(grid, newSize, row + newSize, col + newSize);
        return new Node(true, false, topLeft, topRight, botLeft, botRight);
    }

    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, grid.size(), 0, 0);
    }
};