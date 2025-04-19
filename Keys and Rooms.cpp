class Solution {
    public:
        int dfs(int node, vector<vector<int>>& rooms, vector<bool>& vis){
            vis[node] = true;
            int ans = 1;
            for(int child: rooms[node]){
                if(!vis[child]) ans += dfs(child,rooms,vis);
            }
            return ans;
        }
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            int n = rooms.size();
            vector<bool> vis(n,false);
            int ans=0;
            ans = dfs(0,rooms,vis);
            if(ans==n) return true;
            return false;
        }
    };