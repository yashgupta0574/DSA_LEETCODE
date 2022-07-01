class Solution
{
    public:
        int m, n, col;
    void changecol(vector<vector < int>> &image, int sr, int sc, int color)
    {
        if (sr >= m || sr < 0 || sc >= n || sc < 0 || image[sr][sc] != col) return;
        image[sr][sc] = color;
        changecol(image, sr + 1, sc, color);
        changecol(image, sr - 1, sc, color);
        changecol(image, sr, sc + 1, color);
        changecol(image, sr, sc - 1, color);
    }
    vector<vector < int>> floodFill(vector<vector < int>> &image, int sr, int sc, int color)
    {
        m = image.size(), n = image[0].size();
        col = image[sr][sc];
        if(col==color) return image;
        changecol(image, sr, sc, color);
        return image;
    }
};