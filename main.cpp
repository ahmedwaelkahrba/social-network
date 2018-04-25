#include <bits/stdc++.h>
using namespace std;
class user;
deque <user> no;
int state;
int post_no_on_home; //that variable will be used in state  <certain post>
/////////////////////////////////////////////////////////////////////////////////////////////////////
struct comment
{
    int user_index;
    string user_name;
    string comment_content;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
struct like
{
    int user_index;
    string user_name;
    bool like=false;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
struct post
{
    int post_index;
    int user_index;
    string user_name;
    string post_content;
    deque <comment> post_comments;
    deque <like> post_likes;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
struct user
{
    int index;
    string user_name,password;
    deque <int> friends_index;
    deque <int> groups_index;
    deque <string> groups_name;
    deque <int> friend_requests;
    deque <string> friend_request_index;
    deque <post> home;
    deque <post> profile;
/////////////////////////////////////////////////////////////////////////////////////////////////////
    void post_on_home()
    {
        string extra;
        post tmp;
        printf("\n write your post \n");
        tmp.post_index = home.size();
        tmp.user_index = index;
        tmp.user_name = user_name;
        getline (cin,extra);
        getline(cin,tmp.post_content);
        home.push_back(tmp);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////
    void post_on_profile()
    {
        post tmp;
        string extra;
        printf("\n write your post \n");
        tmp.post_index = profile.size();
        tmp.user_index = index;
        tmp.user_name = user_name;
        getline (cin,extra);
        getline(cin,tmp.post_content);
        profile.push_back(tmp);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////
    int show_home()
    {
        int choice;
        user tmps;
        for (int i=0;i<home.size();++i)
        {
            (tmps.home).push_back(home[i]);
        }
        for (int i=0;i<friends_index.size();++i)
        {
            for (int j=0 ;j<(no[(friends_index[i])].home).size();++j)
            {
                (tmps.home).push_back((no[(friends_index[i])].home)[j]);
            }
        }
        for (int i=0;i<(tmps.home).size();++i)
        {
            cout<<"\n\n\npost no "<<i;
            cout<<"\n\nthis post is posted by <" <<(tmps.home)[i].user_name<<"> and his index ("<<(tmps.home)[i].user_index<<")";
            cout<<"\n\n     "<<(tmps.home)[i].post_content;
            cout<<"\n\n     ["<<((tmps.home)[i].post_likes).size()<<"] likes this post";
            cout<<"\n\n     comments";
            for (int j=0;j<((tmps.home)[i].post_comments).size();++j)
            {
                cout<<"\n\n";
                cout<<"   commented by <"<<((tmps.home)[i].post_comments)[j].user_name<<"> and his index ("<<((tmps.home)[i].post_comments)[j].user_index<<")";
                cout<<"\n\n     "<<((tmps.home)[i].post_comments)[j].comment_content;
            }
        }
        cout<<"\n\n\n1-refresh home  2-see my friend list  3- see my groups list\n";
        cout<<"4-see my friend requests link  5-make a post  6-react on a post 7-go to profile\n";
        while (1)
        {
            cin>>choice;
            if (choice==1) //refresh home
            {
                return 1;
            }
            else if (choice==2) //my friends list
            {
                return 6;
            }
            else if (choice==3) //my groups list
            {
                return 5;
            }
            else if (choice==4) //my friends request list
            {
                return 4;
            }
            else if  (choice==5) //make post
            {
                this->post_on_home();
                return 1;
            }
            else if (choice==6) //react on post
            {
                printf("\n choose number of post to react on\n");
                cin>>post_no_on_home; //used in certain post state
                return 7;
            }
            else if (choice==7) //go to profile
            {
                return 2;
            }
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////
    int show_my_profile()
    {
        int choice;
        for (int i=0;i<profile.size();++i)
        {
            cout<<"\n\n\npost no "<<i;
            cout<<"\n\nthis post is posted by <" <<profile[i].user_name<<"> and his index ("<<profile[i].user_index<<")";
            cout<<"\n\n     "<<profile[i].post_content;
            cout<<"\n\n     ["<<(profile[i].post_likes).size()<<"] likes this post";
            cout<<"\n\n     comments";
            for (int j=0;j<(profile[i].post_comments).size();++j)
            {
                cout<<"\n\n";
                cout<<"   commented by <"<<(profile[i].post_comments)[j].user_name<<"> and his index ("<<(profile[i].post_comments)[j].user_index<<")";
                cout<<"\n\n     "<<(profile[i].post_comments)[j].comment_content;
            }
        }
        cout<<"\n\n\n1-go to home  2-see my friend list  3- see my groups list";
        cout<<"\n4-see my friend requests link  5-make a post  6-refresh profile\n";
        while (1)
        {
            cin>>choice;
            if (choice==1) //go to home
            {
                return 1;
            }
            else if (choice==2) //see my friend list
            {
                return 6;
            }
            else if (choice==3) //see my group list
            {
                return 5;
            }
            else if (choice==4) //see my friendrequests list
            {
                return 4;
            }
            else if  (choice==5) //make a post
            {
                this->post_on_profile();
                return 2;
            }
            else if (choice==6) //refresh profile
            {
                return 2;
            }
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////
    int show_X_profile()
    {

    }
/////////////////////////////////////////////////////////////////////////////////////////////////////
    int show_friend_request()
    {

    }
/////////////////////////////////////////////////////////////////////////////////////////////////////
    int show_my_groups()
    {

    }
/////////////////////////////////////////////////////////////////////////////////////////////////////
    int show_my_friend_list()
    {

    }
/////////////////////////////////////////////////////////////////////////////////////////////////////
    int show_the_chosen_post_from_home(int chosen_post_index)
    {

    }
/////////////////////////////////////////////////////////////////////////////////////////////////////
    int show_my_group_page()
    {

    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
int show_program_users ()
{
    int tmp;
    for (int i=0 ; i<no.size();++i)
    {
        cout <<no[i].index<<"-"<<no[i].user_name<<"\n";
    }
        printf ("          ******1-login******       ******2-create new account******\nchoose (1) or (2)\n");
        cin>>tmp;
    return tmp;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
struct group
{
    int group_index;
    string group_name;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    //freopen ("i.txt","rt",stdin);
    int choice,index_of_user;
    string user_name,password;
/////////////////////////////////////////////////////////////////////////////////////////////////////
    while (1)
    {
        choice=show_program_users();
        if (choice==1)
        {
            string extra;
            printf("enter your no from the list above \n");
            cin>>index_of_user;
            printf ("enter_user_name:");
            getline(cin,extra);
            /**/re_enter_user_name2:/**/
            getline(cin,user_name);
            if (user_name==no[index_of_user].user_name)
            {
                printf("\nenter_password:");
                /**/re_enter_password2:/**/
                getline(cin,password);
                if (password == no[index_of_user].password)
                {
                    state=1;
                }
                else
                {
                    printf("\nwrong password\nre_enter password:");
                    goto re_enter_password2;
                }
            }
            else
            {
                printf("\nwrong user name\nre_enter user name:");
                goto re_enter_user_name2;
            }
            while (1)
            {
                if (state==1) //home page
                {
                   state=no[index_of_user].show_home();
                }
               else if (state==2) //my profile page
               {
                   state=no[index_of_user].show_my_profile();
               }
               else if (state==3)//someone profile
               {
                    state=no[index_of_user].show_X_profile();
               }
               else if (state==4)//friend requests page
               {
                   state=no[index_of_user].show_friend_request();
               }
               else if (state==5)//list of my groups
               {
                   state=no[index_of_user].show_my_groups();
               }
               else if (state==6)//list of my friends
               {
                   state=no[index_of_user].show_my_friend_list();
               }
               else if (state==7)//one post to react on
               {
                   state=no[index_of_user].show_the_chosen_post_from_home(post_no_on_home);
               }
               else if (state==8) //group page
               {
                   state=no[index_of_user].show_my_group_page();
               }
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////////////////
        else if (choice==2)
        {
            user tmp;
            string extra;
            printf ("enter_unique_user_name:");
            /**/re_enter_user_name:/**/
            getline(cin,extra);
            getline(cin,user_name);
            for (int i = 0 ; i< no.size();++i)
            {
                if (user_name == no[i].user_name)
                {
                    printf("that name is already taken ");
                   /**/ goto re_enter_user_name;/**/
                }
            }
            tmp.user_name = user_name;
            printf ("enter password:");
             getline(cin,password);
             tmp.password=password;
             tmp.index = no.size();
             no.push_back(tmp);
        }
/////////////////////////////////////////////////////////////////////////////////////////////////////
        else
        {
            printf ("\nplease enter no 1 or 2 only");
        }
    }
}
