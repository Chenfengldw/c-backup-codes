class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.size()<t.size())return "";
        string tmp;
        vector<int> index;
        for(int i=0;i<s.size();++i){
            if(contain(t,s[i])){
                tmp+=s[i];
                index.push_back(i);
            }
        }
        //cout<<tmp.size();
        //cout<<tmp.size();
        vector<pair<int,int>> findIndex;
        //cout<<(1-3);
        if(tmp.size()<t.size())return "";
        for(int i=0;i<tmp.size()-t.size()+1;++i){
            //cout<<"in";
            bool find = true;
            for(int j=0;j<t.size();++j){
                if(!contain(t,tmp[i+j])){
                    find = false;
                    break;
                }
            }
            //cout<<find;
            if(find)findIndex.push_back(make_pair(index[i],index[i+t.size()-1]));
        }
        int min = 10000;
        int minIndex = 0;
        cout<<findIndex.size();
        for(int i=0;i<findIndex.size();++i){
            if(findIndex[i].second-findIndex[i].first<min){
                min = findIndex[i].second-findIndex[i].first;
                minIndex = i;
            }
        }

        if(findIndex.size()==0)return "";
        
        string result;
        for(int i=findIndex[minIndex].first;i<=findIndex[minIndex].second;++i){
            result+=s[i];
        }
        return result;
        
        
        
    }
    
    bool contain(string t ,char c){
        for(int i=0;i<t.size();++i){
            if(t[i]==c)return true;                              
        }
        return false;
    }
};