#include <iostream>
#include <list>
#include <set>
using namespace std;

typedef set<int> Set;
//集合结构体 
typedef struct _KSet
{
    void *key;  //每一个集合的序号 
    Set *set;  //每一个集合包含的元素的序号 
}KSet;

//集合链表节点 
typedef struct _ListElmt
{
    void *data;    //数据域指向一个KSet 
    struct _ListElmt *next; //指针域指向下一个节点 
}ListElmt;



//skills是 要被覆盖的集合S， people是 各个子集合的序号集合， repeople是 结果集合 
int cover(Set *skills, Set *people, Set *repeople)
{
    Set intersection; //存两集合的交集 
    KSet *pset;
    ListElmt *member, *max_member; //集合元素最多的集合 
    void *data;
    int max_size; //集合元素最多的集合的元素个数 
	
    //set_init(repeople, 0, people->match, NULL);
    cout<<"Hello World"<<endl;
    
    while((set_size(skills) > 0) && (set_size(people) >0))
    {
        max_size=0;

        //找到现存人员中，技能最多的人 
        for(member = list_head(people);member != NULL;member=list_next(member))
        {
            if(set_intersection(&intersection, (KSet *)list_data(member)->set, skills)!=0)
                return -1;

            if(set_size(&intersection) > max)
            {
                max_member = member;
                max_size = set_size(&intersection);
            }

        }
        //把找到的人暂存入pset，再存入集合repeople
        pset = (KSet *)list_data(max_member); 
        set_insert(repeople, pset);

        //移掉已入组的人员 
        set_remove(people, (void **)&pset);
        //技能集合中去掉已经拿掉的人的技能 
        for(member = list_head( &((KSet *)list_data(max_member))->set);member != NULL;member=list_next(member))
        {
            data = list_data(member);
            set_remove(skills, (void **)&data);
        }
        //set_remove已经减了不需要sset->size = sset->size - max_size;
        //pset->size--;
        return 0;
    }
}

int main()
{
	return 0;
}
