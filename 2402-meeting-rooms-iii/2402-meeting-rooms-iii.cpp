class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        vector<int> usage(n, 0);
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> free;
        for (int i = 0; i < n; ++i) free.push(i);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

        for (const auto& mt : meetings) {
            long long start = mt[0], end = mt[1];
            while (!busy.empty() && busy.top().first <= start) {
                free.push(busy.top().second);
                busy.pop();
            }
            if (!free.empty()) {
                int room = free.top(); free.pop();
                busy.emplace(end, room);
                usage[room]++;
            } else {
                auto [finishTime, room] = busy.top(); busy.pop();
                long long duration = end - start;
                busy.emplace(finishTime + duration, room);
                usage[room]++;
            }
        }

        int mostUsedRoom = 0;
        for (int i = 1; i < n; ++i) {
            if (usage[i] > usage[mostUsedRoom]) {
                mostUsedRoom = i;
            }
        }

        return mostUsedRoom;
    }
};
