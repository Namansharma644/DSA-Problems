class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
          vector<vector<int>>adj(numCourses);
          for(auto &it : prerequisites)
          {
              int u=it[0];
              int v=it[1];

              adj[u].push_back(v);
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
          int count=0;

          while(!q.empty())
          {
              int curr=q.front();
              q.pop();
              count++;

              for(auto &neighbor : adj[curr])
              {
                  indegree[neighbor]--;
                  if(indegree[neighbor]==0) q.push(neighbor);
              }
          }
          return (count==numCourses);
    }
};