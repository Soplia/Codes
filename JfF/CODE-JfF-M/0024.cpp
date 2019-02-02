#include <iostream>
#include <list>
#include <set>
using namespace std;

typedef set<int> Set;
//���Ͻṹ�� 
typedef struct _KSet
{
    void *key;  //ÿһ�����ϵ���� 
    Set *set;  //ÿһ�����ϰ�����Ԫ�ص���� 
}KSet;

//��������ڵ� 
typedef struct _ListElmt
{
    void *data;    //������ָ��һ��KSet 
    struct _ListElmt *next; //ָ����ָ����һ���ڵ� 
}ListElmt;



//skills�� Ҫ�����ǵļ���S�� people�� �����Ӽ��ϵ���ż��ϣ� repeople�� ������� 
int cover(Set *skills, Set *people, Set *repeople)
{
    Set intersection; //�������ϵĽ��� 
    KSet *pset;
    ListElmt *member, *max_member; //����Ԫ�����ļ��� 
    void *data;
    int max_size; //����Ԫ�����ļ��ϵ�Ԫ�ظ��� 
	
    //set_init(repeople, 0, people->match, NULL);
    cout<<"Hello World"<<endl;
    
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

int main()
{
	return 0;
}
