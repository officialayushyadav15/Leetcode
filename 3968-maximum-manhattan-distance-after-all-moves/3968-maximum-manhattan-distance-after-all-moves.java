class Solution {
    public int maxDistance(String moves) {
        int horizontal = 0, underscore = 0, vertical = 0;
        for (char ch : moves.toCharArray()) {
            if (ch == 'L') horizontal--;
            else if (ch == 'D') vertical--;
            else if (ch == 'R') horizontal++;
            else if (ch == 'U') vertical++;
            else underscore++;
        }
        if (horizontal < 0) {
            horizontal = 0 - horizontal;
        }
        if (vertical < 0) {
            vertical = 0 - vertical;
        }
        return horizontal + vertical + underscore;
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/