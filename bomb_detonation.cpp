#include <bits/stdc++.h> 
#include <list>
#include <utility>
#include<algorithm>

using namespace std;

int BFS(int m, int n, int p1 ,int p2 ){
    int arr[m][n], count = 0, a ,b;
    memset(arr, 0, sizeof(arr[0][0]) * m * n);
    list< pair<int,int> > check;
    check.push_front(make_pair(p1,p2));
    arr[p1][p2] = 1;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
    }
        cout<<endl;
        
    while( !check.empty() ){
        
        pair<int,int> x = check.back();
        check.pop_back();
        const int a = x.first ,b = x.second;
        
        if(a-1 >= 0 && arr[a-1][b] == 0){
            check.push_front(make_pair(a-1,b));
            arr[a-1][b] = arr[a][b] + 1;
        }
        if(a+1 < m && arr[a+1][b] == 0){
            check.push_front(make_pair(a+1,b));
            arr[a+1][b] = arr[a][b] + 1;
        }
        if(b-1 >= 0 && arr[a][b-1] == 0){
            check.push_front(make_pair(a,b-1));
            arr[a][b-1] = arr[a][b] + 1;
        }
        if(b+1 < n && arr[a][b+1] == 0){
            check.push_front(make_pair(a,b+1));
            arr[a][b+1] = arr[a][b] + 1;
        }
        
        for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
        }
        cout<<endl;
    }
    return  max(arr[0][0] , max(arr[0][n-1],max(arr[m-1][0],arr[m-1][n-1])));
    
}

int main() {
	int m,n,p1,p2;
	cin>>m>>n;
	cin>>p1>>p2;
	cout<<BFS(m,n,p1,p2);
	return 0;
}
