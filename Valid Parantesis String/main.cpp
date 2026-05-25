class Solution {
public:
    bool checkValidString(string s) {
        vector<int> left_parantesis;
        vector<int> star_parantesis;

        for (int i = 0; i < s.size(); i++ ){
            if(s[i]=='('){
                left_parantesis.push_back(i);  
            }
            else if(s[i]==')'){
                if(left_parantesis.size() > 0){
                    left_parantesis.pop_back();
                }
                else if(star_parantesis.size() > 0){
                    star_parantesis.pop_back();
                }
                else{
                    return false;
                }
            }
            else{
                star_parantesis.push_back(i);
            }
        }

        while(left_parantesis.size() > 0 && star_parantesis.size() > 0){
            int leftIndex = left_parantesis.back();
            int starIndex = star_parantesis.back();

            if(leftIndex < starIndex){
                left_parantesis.pop_back();
                star_parantesis.pop_back();
            }
            else{
                return false;
            }
        }

        if (left_parantesis.size() > 0){
            return false;
        }

        return true;
    }
};
