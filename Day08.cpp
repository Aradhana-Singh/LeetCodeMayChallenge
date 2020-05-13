/*Check If It Is a Straight Line

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
Check if these points make a straight line in the XY plane.*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()==2) return true;
        double sx = coordinates[1][0] - coordinates[0][0];
        double sy = coordinates[1][1] - coordinates[0][1];
        double slope = sy/sx;
        for(int i = 2; i<coordinates.size(); i++){
            sx = coordinates[i][0] - coordinates[i-1][0];
            sy = coordinates[i][1] - coordinates[i-1][1];
            if(slope != sy/sx) return false;
        }
        return true;
    }
};