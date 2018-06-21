//UVA12096 集合栈计算机 
    #include<cstdio>
    #include<iostream>
    #include<algorithm>//set_union等函数定义在这里 
    #include<vector>
    #include<set>
    #include<map>
    #include<stack>
    
    #define ALL(x) x.begin(),x.end()
    #define INS(x) inserter(x,x.begin()) //注意宏的括号和inserter 
    
    using namespace std;
    
    typedef set<int> Set;
    map<Set,int> IDCache;
    vector<Set> setCache;
    int t,n;
    char cmd[10];
    int getID(Set s){
        if(IDCache.count(s))return IDCache[s];
        setCache.push_back(s);  //将新集合加入Setcache 
        return IDCache[s]=setCache.size()-1;//将ID加入map ，同时返回新分配的ID值 
    }
    
    int main(){
        scanf("%d",&t);
        while(t--){
            scanf("%d",&n);
//            setCache.clear(); 
            stack<int> s;
            while(n--){
                scanf(" %s",&cmd);
                if(cmd[0]=='P')s.push(getID(Set()));
                else if(cmd[0]=='D')s.push(s.top());
                else{
                    Set s1=setCache[s.top()];s.pop();
                    Set s2=setCache[s.top()];s.pop();
                    Set x;
                    if(cmd[0]=='U')set_union(ALL(s1),ALL(s2),INS(x));
                    if(cmd[0]=='I')set_intersection(ALL(s1),ALL(s2),INS(x));
                    if(cmd[0]=='A'){ x=s2; x.insert(getID(s1)); }
                    s.push(getID(x));
                }
                printf("%d\n",setCache[s.top()].size());
            }
            puts("***");
        }
    }