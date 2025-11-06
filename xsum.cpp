class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector <int> result; 
        unordered_map <int,int> tmp;
        int start=0;
        int n=nums.size();
        int end=k;
        //priority_queue <int> pq;
        vector <pair<int,int>> ranking;
        int count=0;
        for(int i=start;i<k;i++)
        {
            tmp[nums[i]]++;
        }
        for(auto &a:tmp)
        {
            ranking.push_back({a.first,a.second});
        }
        sort(ranking.begin(),ranking.end(),[](auto &a,auto &b){
            return a.second!=b.second?a.second>b.second:a.first>b.first;
        });
        int take=min(x,(int)ranking.size());
        for(int i=0;i<take;i++)
        {
            count+=ranking[i].first*ranking[i].second;
        }
        result.push_back(count);
        while(end<n)
        {
            count=0;
            tmp[nums[start]]--;
            tmp[nums[end]]++;
            ranking.clear();
            for(auto &a:tmp)
        {
            ranking.push_back({a.first,a.second});
        }
            sort(ranking.begin(),ranking.end(),[](auto &a,auto &b){
                return a.second!=b.second?a.second>b.second:a.first>b.first;
        });
            int take=min(x,(int)ranking.size());
            for(int i=0;i<take;i++)
            {
                count+=ranking[i].first*ranking[i].second;
            }
            result.push_back(count);
            start++;
            end++;
        }
        return result;
    }
};