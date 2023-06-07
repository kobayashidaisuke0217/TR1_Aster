#include "Astar.h"
#include"Novice.h"
bool isValid(int x, int y, int width, int height) {
    //進行先がマップ内かどうか
    return (x >= 0 && x < width && y >= 0 && y < height);
}

int calcH(int x, int y, int targetX, int targetY) {
    // マンハッタン距離を使ったヒューリスティック関数
    return std::abs(x - targetX) + std::abs(y - targetY);
}

std::vector<Node*> findPath(const std::vector<std::vector<int>>& grid, int startX, int startY, int targetX, int targetY) {
   //マップの幅
    int width =(int) grid[0].size();
    int height =(int) grid.size();
    
    std::vector<std::vector<bool>> visited(width, std::vector<bool>(height, false));
    std::priority_queue<Node*, std::vector<Node*>, Astar> openList;
    //スタート位置
    Node* startNode = new Node(startX, startY, 0, calcH(startX, startY, targetX, targetY), nullptr);
    openList.push(startNode);

    while (!openList.empty()) {
        Node* current = openList.top();
        openList.pop();

        if (current->x == targetX && current->y == targetY) {
            // 目的地に到達した場合、パスを構築して返す
            std::vector<Node*> path;
            while (current != nullptr) {
                path.push_back(current);
                current = current->parent;
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        visited[current->x][current->y] = true;

        // 上下左右の移動
        int dx[] = { 0, 0, -1, 1 };
        int dy[] = { -1, 1, 0, 0 };

        for (int i = 0; i < 4; i++) {
            int nextX = current->x + dx[i];
            int nextY = current->y + dy[i];

            if (isValid(nextX, nextY, width, height) && !visited[nextX][nextY]) {
                if (grid[nextY][nextX] == 1) {
                    int g = current->g + 1;
                    int h = calcH(nextX, nextY, targetX, targetY);
                    Node* nextNode = new Node(nextX, nextY, g, h, current);
                    openList.push(nextNode);
                    visited[nextX][nextY] = true;
                }
                else if (grid[nextY][nextX] == 2) {
                    int g = current->g + 3;
                    int h = calcH(nextX, nextY, targetX, targetY);
                    Node* nextNode = new Node(nextX, nextY, g, h, current);
                    openList.push(nextNode);
                    visited[nextX][nextY] = true;
                }
            }
        }
    }

    return std::vector<Node*>();
}
