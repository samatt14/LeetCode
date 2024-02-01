class Solution {
public:
    bool isMatch(string s, string p) {
        // this is a dynamic programming problem
        int numRows = s.length();
        int numCols = p.length();

        bool dp[numRows + 1][numCols + 1]; 

        //if both are empty, they match
        if(numRows == 0 && numCols == 0) {
            return true;
        }
        //else, if string is not empty but the pattern is, they do NOT match
        if(numCols == 0) {
            return false;
        }

        //if both are empty, they match
        dp[0][0] = true;

        //initialize everything but the first square to false
        for(int i = 1; i < numCols + 1; i++){
            dp[0][i] = false;
        }

        for(int i = 1; i < numRows + 1; i++){
            dp[i][0] = false;
        }

        for(int i = 1; i < numCols + 1; i++){
            for(int j = 1; j < numRows + 1; j++){
                dp[j][i] = false;
            }
        }

        //check if pattern includes "*"
        for (int i = 2; i < numCols + 1; i++) {
            if (p.at(i - 1) == '*') {
                //assign "true" to whereever there is a wildcard
                dp[0][i] = dp[0][i - 2];
            }
        }

        for (int i = 1; i < numRows + 1; i++) {
            for (int j = 1; j < numCols + 1; j++) {
                //if the characters are the same or pattern contains a "."
                if (s.at(i - 1) == p.at(j - 1) || p.at(j - 1) == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                //else, if the pattern contains a wildcard
                else if (j > 1 && p.at(j - 1) == '*') {
                    dp[i][j] = dp[i][j - 2];
                    //and the previous char matches or is a "."
                    if (p.at(j - 2) == '.' || p.at(j - 2) == s.at(i - 1)) {
                        dp[i][j] = dp[i][j] | dp[i - 1][j];
                    }
                }
            }
        }
        return dp[numRows][numCols];
    }
};
