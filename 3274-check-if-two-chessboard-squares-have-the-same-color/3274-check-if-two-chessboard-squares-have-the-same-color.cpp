class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int c1_1 = int(coordinate1[0]-'a')+1;
        int c1_2 = int(coordinate1[1]);
        int c2_1 = int(coordinate2[0]-'a')+1;
        int c2_2 = int(coordinate2[1]);
        if((c1_1+c1_2)%2 == 0 && (c2_1+c2_2)%2 == 0){
            return true;
        }
        else if((c1_1+c1_2)%2 != 0 && (c2_1+c2_2)%2 != 0){
            return true;
        }
        return false;
    }
};