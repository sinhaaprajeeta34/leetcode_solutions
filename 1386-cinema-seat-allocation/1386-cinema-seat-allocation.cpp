class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows; // row -> bitmask of reserved seats (bits 2..9)

        for (auto& seat : reservedSeats) {
            int r = seat[0], c = seat[1];
            if (c >= 2 && c <= 9) {
                rows[r] |= (1 << c);
            }
        }

        // Correct masks (bit positions must match seat numbers exactly)
        const int leftMask   = (1<<2) | (1<<3) | (1<<4) | (1<<5); // seats 2,3,4,5  = 60
        const int middleMask = (1<<4) | (1<<5) | (1<<6) | (1<<7); // seats 4,5,6,7  = 240
        const int rightMask  = (1<<6) | (1<<7) | (1<<8) | (1<<9); // seats 6,7,8,9  = 960

        long long result = (long long)(n - (int)rows.size()) * 2;

        for (auto& [row, mask] : rows) {
            bool left   = (mask & leftMask)   == 0;
            bool middle = (mask & middleMask) == 0;
            bool right  = (mask & rightMask)  == 0;

            if (left && right) {
                result += 2;
            } else if (left || middle || right) {
                result += 1;
            }
        }

        return (int)result;
    }
};