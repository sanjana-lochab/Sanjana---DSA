class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        // Store reserved seats as bitmasks
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            mp[row] |= (1 << (col - 1));
        }

        int left  = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4);
        int middle = (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);
        int right = (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8);

        // Rows with no reservations can always fit 2 groups
        int ans = (n - mp.size()) * 2;

        // Process only rows having reservations
        for (auto &[row, mask] : mp) {

            bool leftAvailable = (mask & left) == 0;
            bool middleAvailable = (mask & middle) == 0;
            bool rightAvailable = (mask & right) == 0;

            if (leftAvailable && rightAvailable) {
                ans += 2;
            }
            else if (leftAvailable || middleAvailable || rightAvailable) {
                ans += 1;
            }
        }

        return ans;

    }
};