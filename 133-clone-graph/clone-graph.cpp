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
    private:
    void dfs(Node* curr,Node* node,vector<Node*>&vis){
        vis[node->val]=node;
        for(auto it:curr->neighbors){
            if(vis[it->val]==NULL){
              Node* x=new Node(it->val);
                (node->neighbors).push_back(x);
                dfs(it,x,vis);
            }
            else{
                (node->neighbors).push_back(vis[it->val]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
      if(node==NULL)
      return NULL;

      unordered_map<Node*,Node*>mp;
      queue<Node*>q;
      mp[node]=new Node(node->val);
      q.push(node);
      while(q.size()){
        Node* curr=q.front();
        q.pop();

        for(auto it:curr->neighbors){
            if(mp.find(it)==mp.end()){
                mp[it]=new Node(it->val);
                q.push(it);


            }
            mp[curr]->neighbors.push_back(mp[it]);
        }


      }
      return mp[node];




        
    }
};