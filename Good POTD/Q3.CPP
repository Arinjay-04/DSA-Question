// 703. Kth Largest Element in a Stream

class KthLargest {
    private:
    priority_queue<int, vector<int>, greater<int>> pq;
public:
  int k1;
    KthLargest(int k, vector<int>& nums) {
        this->k1 = k; 
        for(int num : nums){
            add(num);
        }
    }
    
    int add(int val) {
        if(pq.size() < k1){
            pq.push(val);
        }else if(val > pq.top()){
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }
};


// Basically keep a priority queue of size k when ever you get a larger element than the top just pop the top 
// and add the largest element in min heap and return the top;


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */