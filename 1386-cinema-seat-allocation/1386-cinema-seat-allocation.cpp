class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        long long ans = 0;
        unordered_set<int> st;
        unordered_map<int, vector<int>> h;
        for (auto& x : reservedSeats) {
            int row = x[0];
            int seat = x[1];
            st.insert(row);
            if (h.find(row) == h.end())  h[row] = vector<int>(10, 0);
            h[row][seat - 1] = 1;
        }
        for (auto& [row, seats] : h) {
            // seats 2,3,4,5
            if (seats[1] == 0 && seats[2] == 0 && seats[3] == 0 && seats[4] == 0) {
                ans++;
                seats[1] = 1;
                seats[2] = 1;
                seats[3] = 1;
                seats[4] = 1;
            }
            // seats 4,5,6,7
            if (seats[3] == 0 && seats[4] == 0 && seats[5] == 0 && seats[6] == 0) {
                ans++;
                seats[3] = 1;
                seats[4] = 1;
                seats[5] = 1;
                seats[6] = 1;
            }
            // seats 6,7,8,9
            if (seats[5] == 0 && seats[6] == 0 && seats[7] == 0 &&
                seats[8] == 0) {
                ans++;
                seats[5] = 1;
                seats[6] = 1;
                seats[7] = 1;
                seats[8] = 1;
            }
        }
        //for vacant rows
        ans += 2LL * (n - h.size());
        return ans;
    }
};