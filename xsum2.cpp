class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x)  {
        vector <long long> result;
        int start=0;
        int end=k;
        long long cnt=0;
        unordered_map <long long,long long> tmp;
        vector <pair<long long,long long>> rank;
        for(int i=start;i<end;i++)
        {
            tmp[nums[i]]++;   
        }
        for(auto &a:tmp)
        {
            rank.push_back({a.first,a.second});
        }

        // sort(rank.begin(),rank.end(),[](auto &a,auto &b){
        //     return a.second!=b.second?a.second>b.second:a.first>b.first;
        // });
        int take=min(x,(int)rank.size());
        nth_element(rank.begin(),rank.begin()+take,rank.end(),[](auto &a,auto &b){
            return a.second!=b.second?a.second>b.second:a.first>b.first;
        });
        for(int i=0;i<take;i++)
        {
            cnt+=rank[i].first*rank[i].second;
        }
        result.push_back(cnt);
        while(end<nums.size())
        {
            cnt=0;
            tmp[nums[start]]--;
            tmp[nums[end]]++;
            rank.clear();
            for(auto &a:tmp)
            {
                rank.push_back({a.first,a.second});
            }
            // sort(rank.begin(),rank.end(),[](auto &a,auto &b){
            // return a.second!=b.second?a.second>b.second:a.first>b.first;
            // });
            int take=min(x,(int)rank.size());
            nth_element(rank.begin(),rank.begin()+take,rank.end(),[](auto &a,auto &b){
            return a.second!=b.second?a.second>b.second:a.first>b.first;
            });
            for(int i=0;i<take;i++)
            {
                cnt+=rank[i].first*rank[i].second;
            }
            result.push_back(cnt);
            start++;
            end++;
        }
        return result;
    }
};