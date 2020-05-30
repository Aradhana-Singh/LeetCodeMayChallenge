//K Closest Points to Origin
class Solution {
public:
    static bool comp(pair <int,int> p , pair <int,int> q){
        return p.second < q.second;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int,int>>  distance;
        int var;
        for(int i = 0; i<points.size(); i++){
            var = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            distance.push_back(make_pair(i,var));
        }
        sort(distance.begin() , distance.end() , comp);
        
        vector<vector<int>> res;
        int i = 0;
        while(K--){
            res.push_back({points[distance[i].first][0],points[distance[i].first][1]});
            i++;
        }
        return res;
    }
};