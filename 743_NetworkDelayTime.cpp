/*
743. Network Delay Time ::
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Note:
N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.
*/


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        typedef pair<int, int> pii;
        const int inf = 1e9;
        vector<pii> adj[N+5];
        for(vector<int> &vec : times){
            adj[vec[0]].push_back(pii(vec[1], vec[2]));
        }
        bool visited[N+5];
        memset(visited, false, sizeof visited);
        
        int dist[N+5];
        for(int i=1; i<=N; ++i){
            dist[i] = inf;
        }
        
        function<void(void)> dijkstra;
        dijkstra = [&] (void) -> void{
            dist[K] = 0;
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            pq.push(pii(0, K));
            while(!pq.empty()){
                pii nextNode = pq.top();
                pq.pop();
                int u = nextNode.second;
                     /*
                Check whether the extracted node from the priority queue is already visited or not. If
                it's already visited then continue otherwise mark the extracted node as visited
                and then explore it's neighbors.
                 */
                    if(visited[u]){
                        continue;
                    }
                    visited[u] = true;
                    for(pii pair : adj[u]){
                    int v = pair.first;
                    int w = pair.second;
                    if(dist[v] > dist[u] + w){
                            dist[v] = dist[u] + w;
                            pq.push(pii(dist[v], v));
                    }
                }
            }
        };
        
        dijkstra();
        
        int mx = 0;
        for (int i = 1; i <= N; ++i) {
            if (dist[i] >= inf){
                return -1;
            }
            mx = max<int>(mx, dist[i]);
        }
        return mx;
    }
};