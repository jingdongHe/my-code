    #include <iostream>  
    using namespace std;  
    #define M 500  
    int n;  
    long max;  
    struct enode{  
        int e;  
        long d;  
        enode *next;  
        enode(int ee,long dd){  
            e=ee;d=dd;next=NULL;  
        };  
    }*vex[M];  
    void pre(){  
        cin>>n;  
        int s,e;  
        long d;  
        for(int i=0;i<n-1;i++){  
            cin>>s>>e>>d;  
            enode *temp=new enode(e,d);  
            temp->next=vex[s];  
            vex[s]=temp;  
            temp=new enode(s,d);  
            temp->next=vex[e];  
            vex[e]=temp;  
        }  
    }  
    void dfs(long temp,int v,bool visited[]){  
        visited[v]=true;  
        for(enode *t=vex[v];t;t=t->next)  
            if(!visited[t->e]){  
                if(max<temp+t->d) max=temp+t->d;  
                dfs(temp+t->d,t->e,visited);  
            }  
    }  
    long count(){  
        return 10*max+(1+max)*max/2;  
    }  
    void solve(){  
        for(int i=1;i<=n;i++){  
            bool *vis=new bool[n];  
            memset(vis,0,n);  
            dfs(0,i,vis);  
        }  
    //  cout<<max<<endl;  
        cout<<count()<<endl;  
    }  
    int main(){  
        pre();  
        solve();  
        return 0;  
    }  