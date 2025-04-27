class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& mat, int target) {
            int n = mat.size();
            int m = mat[0].size();
            if(target<mat[0][0] || target>mat[n-1][m-1]) return false;
            int row = 0;
            int sr = 0; int er = n-1;
            bool ans = false;
            while(sr<=er){
                int mid = (sr+er)/2;
                if(target<mat[mid][0]) er = mid-1;
                else if(target>mat[mid][m-1]) sr = mid+1;
                else{
                    row = mid;
                    break;
                }
            }
            int sc=0; int ec=m-1;
            while(sc<=ec){
                int mid = (sc+ec)/2;
                if(target<mat[row][mid]) ec = mid-1;
                else if(target>mat[row][mid]) sc = mid+1;
                else{
                    ans = true;
                    break;
                }
            }
            return ans;
        }
    };