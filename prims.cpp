	int prims( int V, vector<vector<pair<int,int>>> adj )
	{
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int sum=0;
        vector<int> vis ( V, 0 );
 
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int wt=it.first;
            int node=it.second;
            if(vis[node]==1)
            continue;
            vis[node]=1;
            sum+=wt;
            
            for(auto i:adj[node])
            {
                int node1=i.first;
                int wt1=i.second;
                if(!vis[node1])
                {
                pq.push({wt1,node1});
                }
            }
        }
        return sum;
	}