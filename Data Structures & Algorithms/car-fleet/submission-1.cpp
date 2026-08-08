class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;  // Use double to prevent integer division issues
        vector<pair<int, int>> vec;

        // Store positions and speeds in a vector of pairs
        for (int i = 0; i < position.size(); i++) {
            vec.push_back(make_pair(position[i], speed[i]));
        }

        // Sort in decreasing order of position
        sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;  // Change < to > for descending order
        });

        // Initialize the stack with the last car's time
        double t = (double)(target - vec[0].first) / vec[0].second;
        st.push(t);

        // Traverse the cars in sorted order
        for (int i = 1; i < vec.size(); i++) {
            double t = (double)(target - vec[i].first) / vec[i].second;
            if (t > st.top()) {  // Only push if the car doesn't join an existing fleet
                st.push(t);
            }
        }

        return st.size();
    }
};