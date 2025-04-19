class Solution {
    public:
        bool func(int node, vector<int> graph[], vector<int>& color, int c){
            color[node] = c;
            bool ans = true;
            for(int child: graph[node]){
                if(color[child] == -1){
                    ans &= func(child,graph,color,1-c);
                }
                else{
                    if(color[child] == c) ans = false;
                }
            }
            return ans;
        }
        bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
            vector<int> graph[n];
            for(auto conn: dislikes){
                graph[conn[0]-1].push_back(conn[1]-1);
                graph[conn[1]-1].push_back(conn[0]-1);
            }
            vector<int> color(n,-1);
            bool ans = true;
            for(int i=0;i<n;i++){
                if(color[i] == -1){
                    ans &= func(i,graph,color,0);
                }
            }
            return ans;
        }
    };