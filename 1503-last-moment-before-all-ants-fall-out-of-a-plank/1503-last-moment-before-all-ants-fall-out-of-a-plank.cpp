class Solution
{
    public:
        int getLastMoment(int n, vector<int> &left, vector<int> &right)
        {
            if (right.size() == 0) return* max_element(left.begin(), left.end());
            else if (left.size() == 0) return n - *min_element(right.begin(), right.end());
            return max(*max_element(left.begin(), left.end()), n - *min_element(right.begin(), right.end()));
        }
};