/* 
	Problem Number - 733. Flood Fill
	Problem Link - https://leetcode.com/problems/flood-fill/
	
	Submitted By - Devesh Kumar
	Time complexity - O()
	Space complexity - O()

*/ 
class Solution {
public:
    int fill(vector<vector<int>>& image, int sr, int sc, int color,int &target)

{

    if(sr>=0&&sr<image.size()&&sc>=0&& sc<image[0].size())

    {

        if(image[sr][sc]==target)

        {
            image[sr][sc]=color;

            fill(image, sr-1, sc, color,target);

            fill(image, sr, sc-1, color, target);

            fill(image, sr+1, sc, color, target);

            fill(image,sr, sc+1, color, target);

            return 0;

        }
}
        return -1;

    

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color

){
        int target=image[sr][sc];
 fill(image,sr,sc,color,target);
       return image;
    }
};
