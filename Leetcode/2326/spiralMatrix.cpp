class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode *temp = head;
        vector<vector<int>> res(m, vector<int>(n,-1));
        int c = 0;
        int r = 1;
        int i = 0;
        int j = -1;
        
        bool shift = 1;
        
        while(temp){
            if(shift){
                if(c%2 == 0){
                    int count = 0;
                    while(temp && count<(n-c)){
                        j++;
                        res[i][j] = temp->val;
                        temp    = temp->next;
                        count++;
                    }
                    c++;
                }
                else{
                    int count = 0;
                    while(temp && count<(n-c)){
                        j--;
                        res[i][j] = temp->val;
                        temp = temp->next;
                        count++;
                    }
                    c++;
                }
            }
            else{
                if(r%2 != 0){
                    int count = 0;
                    while(temp && count<(m-r)){
                        i++;
                        res[i][j] = temp->val;
                        temp = temp->next;
                        count++;
                    }
                    r++;
                }
                else{
                    int count = 0;
                    while(temp && count<(m-r)){
                        i--;
                        res[i][j] = temp->val;
                        temp = temp->next;
                        count++;
                    }
                    r++;
                }
            }
            shift = !shift;
        }
        return res;
    }
};
