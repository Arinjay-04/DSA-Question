// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
// Solved
// Medium
// Topics
// Companies
// Hint
// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional 
// and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

// Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold,
//  If there are multiple such cities, return the city with the greatest number.

// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.



class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<int>> v(n, vector<int> (n, 1e9));

        for(int i=0; i<n; i++){
            v[i][i] = 0;
        }

        // for(auto it :edges){
        //     v[it.first][it.second] = 1e9;
        // }
          vector<vector<pair<int, int>>> adj(n);

        for(auto it : edges ){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        for(int i=0; i<n; i++){
            pq.push({0, i});

            while(!pq.empty()){
                int dis = pq.top().first;
                int node = pq.top().second;
                pq.pop();

                 for(auto it : adj[node]){
                    int w = it.second;
                    int adjnode = it.first;

                    if(dis + w < v[i][adjnode]){
                        v[i][adjnode] = dis + w;
                        pq.push({ v[i][adjnode] , adjnode});
                    }
                 }
            }
        }

         for (int i = 0; i < n; ++i) {
        cout << "From city " << i << ": ";
        for (int j = 0; j < n; ++j) {
            cout << "To city " << j << " = " << v[i][j] << " ";
        }
        cout << endl;
    }

        vector<pair<int, int>> mp;

        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(v[i][j] <= distanceThreshold ){
                    count ++;
                }
            }
            mp.push_back({i, count});
        }
     sort(mp.begin(), mp.end(), [](const auto &a, const auto &b) {
            if (a.second < b.second) return true;
            if (a.second > b.second) return false;
            return a.first > b.first;  // When counts are equal, prefer larger index
        });

        // Return the city with the smallest number of reachable cities
        return mp[0].first;
    }
};