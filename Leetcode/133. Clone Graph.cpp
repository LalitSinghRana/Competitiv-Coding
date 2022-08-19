/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> m;
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        if(m.find(node->val) != m.end()) return m[node->val];
        
        Node* a = new Node(node->val);
        m[a->val] = a;
        
        for(int i=0; i<node->neighbors.size(); i++) {
            a->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        
        return a;
    } 
};
