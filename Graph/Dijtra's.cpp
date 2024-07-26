 
 ///////////// USING PRIORITY QUEUE  ///////////////////////////
 
 {
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> pq;
        vector<int> dist(n);
        
        for(int i=0; i<n; i++){
            dist[i] = 1e9;
        }
        
        dist[S] = 0;
        
        pq.push({0, S});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int edge = it[0];
                int w = it[1];
                
                if(w+dis < dist[node]){
                    dist[node] = w + dis;
                    pq.push({dist[node], edge});
                }
            }
        }
        return dist;
    }
};




////////////////////// Using SETS /////////////////////////



{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> pq;
        vector<int> dist(n);
        
        for(int i=0; i<n; i++){
            dist[i] = 1e9;
        }
        
        dist[S] = 0;
        
        pq.push({0, S});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int edge = it[0];
                int w = it[1];
                
                if(w+dis < dist[node]){
                    dist[node] = w + dis;
                    pq.push({dist[node], edge});
                }
            }
        }
        return dist;
    }
};
