class Solution
{
    public:
        int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
        {
            int dx = -ax1, dy = -ay1;
            ax2 += dx;
            ax1 += dx;
            ay1 += dy;
            ay2 += dy;
            bx2 += dx;
            bx1 += dx;
            by1 += dy;
            by2 += dy;
            if (bx2 <= 0 || by1 >= ay2 || bx1 >= ax2 || by2 <= 0) return (ax2 - ax1) *(ay2 - ay1) + (bx2 - bx1) *(by2 - by1);
            int a, b, c, d;
            a = max(0, bx1);
            b = min(ax2, bx2);
            c = max(0, by1);
            d = min(ay2, by2);
            return (ax2 - ax1) *(ay2 - ay1) + (bx2 - bx1) *(by2 - by1) - (b - a) *(d - c);
        }
};