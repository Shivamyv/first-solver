class DSU{
    public:
        vector<int>parent,sze;
        DSU(int n)
    {
        parent.resize(n);
        sze.resize(n,1);
        for(int i=0;i<n;i++)
            {
                parent[i]=i;
            }
    }
    int find(int i)
    {
        if(parent[i]==i)return i;
        else return parent[i]=find(parent[i]);
    }
    void Union(int i,int j)
    {
        int pari = find(i);
        int parj = find(j);
        if(pari!=parj)
            {
                if(sze[pari]<sze[parj])
                {
                    swap(pari,parj);
                }
                parent[parj]=pari;
                sze[pari]+=sze[parj];
            }
    }

};



class Solution {
public:
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        unordered_map<int,int>mapx,mapy;
        for(int i=0;i<n;i++)
            {
                int x = points[i][0];
                int y = points[i][1];
                if(mapx.count(x))
                {
                    dsu.Union(i,mapx[x]);
                }
                else
                {
                    mapx[x]=i;
                }
                if(mapy.count(y))
                {
                    dsu.Union(i,mapy[y]);
                }
                else
                {
                    mapy[y]=i;
                }
            }
        vector<int>comp;
        for(int i=0;i<n;i++)
            {
                if(dsu.parent[i]==i)
                {
                    comp.push_back(dsu.sze[i]);
                }
            }
        sort(comp.begin(),comp.end(),greater<int>());
        if(comp.size()>1)
        {
            return comp[0]+comp[1]+1;
        }
        else return comp[0]+1;
    }
};