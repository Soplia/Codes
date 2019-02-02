#include <stdio.h>
//#include "single_list.h"
#include "cover.h"

//skills是技能集合S， people是选手集合 P， repeople返回的 包含所有技能，人员集合C
int cover(Set *skills, Set *people, Set *repeople)
{
    Set intersection;//存两人技能的交集 
    KSet *pset;
    ListElmt *member, *max_member;//max_member存技能最多的人 
    void *data;
    int max_size;//存技能最多的人 的技能数 

    set_init(repeople, 0, people->match, NULL);

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
