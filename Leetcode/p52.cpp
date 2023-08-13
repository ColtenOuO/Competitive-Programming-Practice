class Solution {
public:
    int b[10][10];
    int totalNQueens(int n) {
        int ans = 0;
    	vector<int> a(n);
			for(int i=0;i<n;i++) a[i] = i;
    	do
    	{
            for(int i=0;i<n;i++)
            {
                for(int k=0;k<n;k++) b[i][k] = 0;
            }
    		for(int i=0;i<n;i++) b[i][a[i]] = 1;
    		
    		bool ok = 1;
    		for(int i=0;i<n;i++)
    		{
    			for(int k=0;k<n;k++)
    			{
    				if( b[i][k] == 1 )
    				{
    					for(int j1=i-1,j2=k-1;j1>=0&&j2>=0;j1--,j2--) if( b[j1][j2] == 1 ) ok = 0;
						for(int j1=i+1,j2=k-1;j1<n&&j2>=0;j1++,j2--) if( b[j1][j2] == 1 ) ok = 0;
						for(int j1=i-1,j2=k+1;j1>=0&&j2<n;j1--,j2++) if( b[j1][j2] == 1 ) ok = 0;
						for(int j1=i+1,j2=k+1;j1<n&&j2<n;j1++,j2++) if( b[j1][j2] == 1 ) ok = 0;
    				}
    				
    				if( ok == 0 ) break;
    			}
    			if( ok == 0 ) break;
    		}
    		
    		if( ok == 1 )
    		{
    			ans++;
    		}
    		
    	}while(next_permutation(a.begin(),a.end()));   
        
        return ans;
    }
};