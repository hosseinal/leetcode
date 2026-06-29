class Solution {
public:
    string minimizeResult(string expression) {

        int p = 0;
        string e = expression;
        for(int i = 0 ; i < e.size(); i++){
            if (e[i] == '+') {
                p = i;
                break;
            }
        }


        string left = e.substr(0,p);
        string right = e.substr(p+1);

        int min = INT_MAX;
        string minstr = "";
        for(int i = 0 ;  i < left.size(); i++){
            for(int j = 1 ; j <= right.size(); j++){
                
                string ll = left.substr(0,i);
                string l = left.substr(i);
                string r = right.substr(0,j);
                string rr = right.substr(j);


                int lli = (!ll.empty())? stoi(ll):1;
                int li = (!l.empty())? stoi(l):1;
                int ri = (!r.empty())? stoi(r):1;
                int rri = (!rr.empty())? stoi(rr):1;

                if ((lli * (li + ri) * rri) < min){
                    min = (lli * (li + ri) * rri);
                    minstr = ll +"(" +l +"+"+r+")"+rr;
                }

            }

        }

        return minstr;
        
    }
};

