#include <algorithm>

bool compare(pair<int,int> a,pair<int,int> b){
	if(a.first!=b.first) return a.first<b.first;
	else return a.second<b.second;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
	int ce=-1;
	vector<pair<int,int>> t;
	for(int i=0;i<end.size();i++){
		t.push_back({end[i],i+1});
	}
	sort(t.begin(),t.end(),&compare);
	vector<int> ans;
	for(pair<int,int> i:t){
		if(start[i.second-1]>ce){
			ans.push_back(i.second);
			ce=i.first;
		}
	}
	return ans;
}