#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;
int n,a[N],b[N],visited[N][6];

void dfs(int note,int currf){
	if(note>n){
		for(int i=1;i<=n;i++) cout<<b[i]<<" ";
		exit(0);
	}
	if(visited[note][currf]) return;
	visited[note][currf] = 1;
	for(int f=1;f<=5;f++){
		if(a[note-1]<a[note] && currf<f){
			b[note]=f;
			dfs(note+1,f);
		}
		else if(a[note-1]>a[note] && currf>f){
			b[note]=f;
			dfs(note+1,f);
		}else if(a[note-1]==a[note] && currf!=f){
			b[note]=f;
			dfs(note+1,f);
		}
	}

}

int main() {
	// Your code goes here;
	cin>>n;
	a[0]=N;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(visited,0,sizeof(visited));
	dfs(1,6);
	cout<<-1<<endl;
	return 0;
}