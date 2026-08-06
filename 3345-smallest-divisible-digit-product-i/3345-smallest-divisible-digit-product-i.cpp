class Solution {
public:
    int smallestNumber(int n, int t) {

        while (true) {

            int product = 1;

            for (int x = n; x > 0; x /= 10)
                product *= (x % 10);

            if (product % t == 0)
                return n;

            n++;
        }
    }
};