
// Code


// Testcase
// Testcase
// Test Result
// 2976. Minimum Cost to Convert String I
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

// You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

// Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

// Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

 

// Example 1:

// Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
// Output: 28
// Explanation: To convert the string "abcd" to string "acbe":
// - Change value at index 1 from 'b' to 'c' at a cost of 5.
// - Change value at index 2 from 'c' to 'e' at a cost of 1.
// - Change value at index 2 from 'e' to 'b' at a cost of 2.
// - Change value at index 3 from 'd' to 'e' at a cost of 20.
// The total cost incurred is 5 + 1 + 2 + 20 = 28.
// It can be shown that this is the minimum possible cost.
// Example 2:

// Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
// Output: 12
// Explanation: To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1, followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. To change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.
// Example 3:

// Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
// Output: -1
// Explanation: It is impossible to convert source to target because the value at index 3 cannot be changed from 'd' to 'e'.



class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        vector<vector<pair<char, int>>> adj(
            26); // Adjacency list for 26 lowercase letters

        // Fill the adjacency list
         for (int i = 0; i < n; i++) {
         
            adj[original[i] - 'a'].push_back({changed[i], cost[i]});
        }


        // Distance matrix initialized to a large value
        vector<vector<int>> dist(26, vector<int>(26, 1e9));

        // Priority queue to perform Dijkstra's algorithm
        using P = pair<int, char>;
        priority_queue<P, vector<P>, greater<P>> pq;

        // Apply Dijkstra's algorithm for each character in the source string
        for (int i = 0; i < source.length(); i++) {
            if (source[i] != target[i]) {
                char s = source[i];
                dist[s - 'a'][s - 'a'] = 0;
                pq.push({0, s});

                while (!pq.empty()) {
                    int d = pq.top().first;
                    char node = pq.top().second;
                    pq.pop();

                    if (d > dist[s - 'a'][node - 'a'])
                        continue;

                    for (auto& it : adj[node - 'a']) {
                        char edge = it.first;
                        int w = it.second;

                        if (d + w < dist[s - 'a'][edge - 'a']) {
                            dist[s - 'a'][edge - 'a'] = d + w;
                            pq.push({dist[s - 'a'][edge - 'a'], edge});
                        }

                    }
                }
            }
        }

        //    for (int i = 0; i < adj.size(); ++i) {
        //     if (!adj[i].empty()) {
        //         cout << "Node " << char(i + 'a') << " is connected to:" <<
        //         endl; for (auto &p : adj[i]) {
        //             cout << p.first << " with cost " << p.second << endl;
        //         }
        //     }
        // }

        // Calculate the total minimum cost
        long long amount = 0;
        for (int i = 0; i < source.length(); i++) {
            if (source[i] != target[i]) {
                int cost = dist[source[i] - 'a'][target[i] - 'a'];
                if (cost == 1e9) {
                    return -1;
                }
                amount += cost;
            }
        }
        return amount;
    }
};