    #include<bits/stdc++.h>
    using namespace std;
    map<char,int>mp;
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        int sl=0;
        char a=' ';
        vector<char>v;
        for(auto x :mp)
        {
            if(x.second%2==1)
            {
                sl++;
                a=x.first;
            }
            else    v.push_back(x.first);
        }
        if(sl>1)
        {
            cout<<"NO SOLUTION";
            return 0;
        }
        else{
            string kq="";
            for(int i=0;i<v.size();i++)
            {
                int slg=mp[v[i]]/2;
                while(slg>0)
                {
                    kq+=v[i];
                    slg--;
                }
            }
            string c=kq;
            reverse(c.begin(),c.end());
            if(a==' ') kq+=c;
            else {
                    string h;
                int z=mp[a];
                while(z>0)
                {
                    h+=a;
                    z--;
                }
                kq+=h+c;

            }
            cout<<kq;
        }

    }
