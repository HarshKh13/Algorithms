class Solution {
    public:
        vector<vector<int>> ans;
        void func(int node, vector<vector<int>>& graph, vector<int> path){
            path.push_back(node);
            if(node == graph.size()-1){
                ans.push_back(path);
                return;
            }
            for(int child: graph[node]){
                func(child,graph,path);
            }
            path.pop_back();
        }
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int> path;
            func(0,graph,path);
            return ans;
        }
    };