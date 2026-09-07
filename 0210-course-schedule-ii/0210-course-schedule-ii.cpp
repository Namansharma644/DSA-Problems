class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
           vector<int>indegree(numCourses,0);
          vector<vector<int>>adj(numCourses);
          for(auto &it : prerequisites)
          {
              int u=it[0];
              int v=it[1];

              adj[v].push_back(u);
          }

          for(auto &it : adj)
          {
              for(auto &val : it)
              {
                  indegree[val]++;
              }
          }

          queue<int>q;
          for(int i=0; i<numCourses; i++)
          {
              if(indegree[i]==0)
              {
                  q.push(i);
              }
          }
          vector<int>topo;

          while(!q.empty())
          {
              int curr=q.front();
              q.pop();
              topo.push_back(curr);

              for(auto &neighbor : adj[curr])
              {
                  indegree[neighbor]--;
                  if(indegree[neighbor]==0) q.push(neighbor);
              }
          }

          if(topo.size()!=numCourses)
          {
            return {};
          }
          return topo;
    }

};