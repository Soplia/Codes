#include <stdio.h>
//#include "single_list.h"
#include "cover.h"

//skills�Ǽ��ܼ���S�� people��ѡ�ּ��� P�� repeople���ص� �������м��ܣ���Ա����C
int cover(Set *skills, Set *people, Set *repeople)
{
    Set intersection;//�����˼��ܵĽ��� 
    KSet *pset;
    ListElmt *member, *max_member;//max_member�漼�������� 
    void *data;
    int max_size;//�漼�������� �ļ����� 

    set_init(repeople, 0, people->match, NULL);

    while((set_size(skills) > 0) && (set_size(people) >0))
    {
        max_size=0;

        //�ҵ��ִ���Ա�У����������� 
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
        //���ҵ������ݴ���pset���ٴ��뼯��repeople
        pset = (KSet *)list_data(max_member); 
        set_insert(repeople, pset);

        //�Ƶ����������Ա 
        set_remove(people, (void **)&pset);
        //���ܼ�����ȥ���Ѿ��õ����˵ļ��� 
        for(member = list_head( &((KSet *)list_data(max_member))->set);member != NULL;member=list_next(member))
        {
            data = list_data(member);
            set_remove(skills, (void **)&data);
        }
        //set_remove�Ѿ����˲���Ҫsset->size = sset->size - max_size;
        //pset->size--;
        return 0;
    }
}
