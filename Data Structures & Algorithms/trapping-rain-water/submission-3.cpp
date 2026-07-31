class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int reference = 0;
        int sum = 0;

        while (reference < n - 1) {
            int closure = reference + 1;
            int potential_sum = 0;
            bool closed = false;

            while (closure < n) {
                if (height[closure] >= height[reference]) {
                    // found a wall at least as tall as reference -> water is fully bounded
                    sum += potential_sum;
                    reference = closure;
                    closed = true;
                    break;
                } else {
                    potential_sum += height[reference] - height[closure];
                    closure++;
                }
            }

            if (!closed) {
                // Ran off the end without finding a wall >= height[reference].
                // The real right boundary is the tallest bar remaining.
                int lastMaxIndex = reference + 1;
                for (int i = reference + 1; i < n; i++) {
                    if (height[i] >= height[lastMaxIndex]) {
                        lastMaxIndex = i;
                    }
                }
                int level = height[lastMaxIndex]; // <= height[reference]
                for (int i = reference + 1; i < lastMaxIndex; i++) {
                    sum += level - height[i];
                }
                reference = lastMaxIndex;
            }
        }

        return sum;
    }
};
