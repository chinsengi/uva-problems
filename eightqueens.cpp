void search(int cur){
    if(cur == n) tot++;
    else for(int i = 0; i < n; i++){
        int ok = 1;
        c[cur] = i;
        for(int j = 0; j < cur; j++)
            if(c[cur] == c[j]||c[cur] + cur == c[j] + j||c[cur]- cur == c[j]-j)
                {ok = 0; break;}
        if(ok) search(cur+1);
    }
}
