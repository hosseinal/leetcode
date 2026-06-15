class Solution {
public:
    vector<string> results{};
    void generator(string s, int max,int current_left, int current_right){

        if(current_left == max && current_right == max){
            results.push_back(s);
        }
        
        if(current_left > max) return;
        generator(s+"(",max,current_left+1,current_right);

        if(current_right > max) return;
        if(current_right >= current_left) return;
        generator(s+")",max,current_left,current_right+1);

    }
    vector<string> generateParenthesis(int n) {
        generator("",n,0,0);
        return results;
    }
};

