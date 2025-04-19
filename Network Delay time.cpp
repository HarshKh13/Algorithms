class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            vector<vector<pair<int,int>>> graph(n);
            for(auto connection: times){
                graph[connection[0]-1].push_back(make_pair(connection[1]-1,connection[2]));
            }
            vector<int> distance(n,INT_MAX);
            distance[k-1] = 0;
            set<pair<int,int>> st;
            st.insert(make_pair(0,k-1));
            while(st.size()>0){
                auto pair = *st.begin();
                int dist = pair.first;
                int node = pair.second;
                st.erase(st.begin());
                for(auto child_pair: graph[node]){
                    int child = child_pair.first;
                    int child_dist = child_pair.second;
                    if(dist+child_dist<distance[child]){
                        distance[child] = dist+child_dist;
                        st.insert(make_pair(distance[child],child));
                    }
                }
            }
            int ans = 0;
            for(int i=0;i<n;i++){
                ans = max(ans,distance[i]);
            }
            if(ans==INT_MAX) ans = -1;
            return ans;
        }
    };