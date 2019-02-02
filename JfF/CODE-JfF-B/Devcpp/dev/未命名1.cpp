/*
__________________________________________________
3.0�汾
1.�޸�ѧ����¼�����ݽṹ��            
2.���γ̿����Զ������ƺ�������        
3.���������빦�ܡ�                    
4.�ѽ��溯���빦�ܺ������׷ֿ���
5.������һЩ���档                   
6.��һ���Ż����롣                    
7.����������õ����޷��ͷ��ڴ�����⡣
8.�������࣬������������������
9.�ɽ�ѧ���ɼ����������html�ļ���
__________________________________________________*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define Up 72
#define Down 80
#define Left 75
#define Right 77
#define Esc 27
#define Backspace 8
#define welcome__ 0
#define student__ 1
#define insert_student__ 11
#define update_student__ 12
#define delete_student__ 13
#define select_student__ 14
#define exit_program__ 2
#define settings__ 3
#define course__ 31
#define student_sortord__ 32
#define pass_grade__ 33
#define insert_course__ 311
#define update_course__ 312
#define delete_course__ 313
#define settings_password__ 34
#define create_table__ 35
#define scanf_password__ 341
#define about__ 4
 
typedef struct node1{
    float score;//����
    struct node1 *sc_next;//ָ����һ�Ƴɼ�
}sc;
typedef struct node2{//ѧ����¼
    struct node2 *st_next;//ָ����һ��ѧ����¼
    int num;//���
    char name[7];//����
    long snum;//ѧ��
    int rank;//����
    float average;//ƽ����
    sc *sc_next;//ָ��ɼ�
}st;

typedef struct node3{
    int num;//���
    char course[9];//�γ�����
    struct node3 *co_next;//ָ����һ���γ�
}co;
 
st *S=NULL;//ѧ����¼ָ��
co *C=NULL;//�γ�ָ��
int Course_count=0;//�γ���
int Student_count=0;//ѧ����¼��
char Password[8]={0};//�������Ӳ�����ڴ漴�ñ���
int static Student_sortord=0;//ѧ����¼����  0��ѧ����  1��������
int Pass_grade=60;//�ϸ�ɼ�
 
void welcome_interface(int c){//��ӭ����
//  system("cls");
    puts("\n\n\n\n\n");
    puts("\t\t ________________________________________________ ");
    puts("\t\t|                                                |");
    puts("\t\t|                                                |");
    puts("\t\t|   �����ϵ11����1��ѧ���ɼ�����ϵͳ            |");
    puts("\t\t|                                                |");
    puts("\t\t|                        --�����ϵ����1��LR     |");
    puts("\t\t|________________________________________________|");
    puts("\t\t|                                                |");
    printf("\t\t|   ");
    if(c==1)
        printf("��");
    else
        printf("  ");
    printf("[����]  ");
    if(c==2)
        printf("��");
    else
        printf("  ");
    printf("[�˳�]  ");
    if(c==3)
        printf("��");
    else
        printf("  ");
    printf("[����]  ");
    if(c==4)
        printf("��");
    else
        printf("  ");
    puts("[����]       |");
    puts("\t\t|________________________________________________|");
    printf("\n\t\t����ʾ���������ѡ�񣬰��س�ȷ��ѡ�񣡣�");
}
int welcome(){//��ӭ
    int c=1;
    char ch=0;
    while(1){
        if(c==5)
            c=1;
        if(c==0)
            c=4;
        welcome_interface(c);
        fflush(stdin);
        ch=getch();
        if(ch=='\r')
            break;
        if(ch==Left)
            c-=1;
        if(ch==Right)
            c+=1;
    }
    switch(c){
        case 1:
            return student__;
        case 2:
            return exit_program__;
        case 3:
            return settings__; 
        case 4:
            return about__;
        default:
            break;
    }
    return 0;
}
void num(){//ѧ����¼���
    int num=1;
    st *s1=NULL;
    if(S==NULL)
        return;
    s1=S;
    while(s1!=NULL){
        s1->num=num++;
        s1=s1->st_next;
    }
    Student_count=num-1;
}
void average(){//ѧ����¼ƽ����
    float sum=0.0;
    st *s1=NULL;
    sc *sc1=NULL;
    s1=S;
    if(S==NULL)
        return;
    if(C==NULL){
        while(s1!=NULL){
            s1->average=0;
            s1=s1->st_next;
        }
        return;
    }
    while(s1!=NULL){
        sum=0;
        sc1=s1->sc_next;
        while(sc1!=NULL){
            sum+=sc1->score;
            sc1=sc1->sc_next;
        }
        s1->average=sum/Course_count;
        s1=s1->st_next;
    }
}
void rank(){//��¼���α��
    int rank=1,break_=1;
    st *s1=NULL,*max=NULL,*prior=NULL;
    if(S==NULL)
        return;
    s1=S;
    if(C==NULL){
        while(s1!=NULL){
            s1->rank=0;
            s1=s1->st_next;
        }
        return;
    }
    while(s1!=NULL){//����������� 0�����ñ�ʶ�Ƿ��Ź��� �����㷨��Ҫ
        s1->rank=0;
        s1=s1->st_next;
    }
    while(break_){//�߼�ֵ �ж��Ƿ�����ѧ����¼��������
        s1=S;
        break_=0;
        if(max!=NULL&&max->rank!=0)//������һ��ָ�� �ж����ڵ������Ƿ���ʱʹ��
            prior=max;
        max=S;
        while(s1!=NULL){//��������ѧ����¼
            if(s1->rank==0){//ֻ������Щδ�����ε�ѧ����¼
                max=(max->rank==0&&max->average>s1->average)?max:s1;//δ�����β�����Ϊmax
                break_=1;
            }
            s1=s1->st_next;
        }
        if(break_&&max->rank==0)//����
            max->rank=rank++;
        if(prior!=NULL&&prior->average==max->average)//��������
            max->rank=prior->rank;
    }
}
st *rank_sort(st *head){//��������
    st *s1=NULL,*max=NULL;
    s1=head;
    max=head;
    if(head==NULL)
        return head;
    while(s1->st_next!=NULL){//�ҳ�average���ļ�max�ڵ�
        s1=s1->st_next;
        if(max->average<s1->average)
            max=s1;
    }
    s1->st_next=head;//�γɻ�������
    while(s1->st_next!=max)//�ҳ�ָ��max�ڵ�Ľڵ� ����ָ��NULL
        s1=s1->st_next;
    s1->st_next=NULL;
    head=max;
    head->st_next=rank_sort(head->st_next);//�ݹ���� һ���ҳ�max�ڵ�
    return head;
}
st *snum_sort(st *head){//ѧ������
    st *s1=NULL,*min=NULL;
    s1=head;
    min=head;
    if(head==NULL)
        return head;
    while(s1->st_next!=NULL){//�ҳ�average���ļ�max�ڵ�
        s1=s1->st_next;
        if(min->snum>s1->snum)
            min=s1;
    }
    s1->st_next=head;//�γɻ�������
    while(s1->st_next!=min)//�ҳ�ָ��max�ڵ�Ľڵ� ����ָ��NULL
        s1=s1->st_next;
    s1->st_next=NULL;
    head=min;
    head->st_next=snum_sort(head->st_next);//�ݹ���� һ���ҳ�max�ڵ�
    return head;
}
void fprintf_student(){//ѧ����¼д��Ӳ��
    st *s1=NULL;
    sc *sc1=NULL;
    FILE *f=NULL;
    s1=S;
    f=fopen("student.dat","wt");
    if(s1!=NULL){
        while(s1!=NULL){//ѧ����Ϣд��Ӳ��
            fprintf(f,"%s %ld %d %f",s1->name,s1->snum,s1->rank,s1->average);
            sc1=s1->sc_next;
            while(sc1!=NULL){//�γ̳ɼ�д��Ӳ��
                fprintf(f," %f",sc1->score);
                sc1=sc1->sc_next;
            }
            fprintf(f,"\n");
            s1=s1->st_next;
        }
        fclose(f);
    }
    return;
}
void fscanf_student(){//ѧ����¼д���ڴ�
    int n=1;
    int get_course_count(co*);
    st *s1=NULL,*s2=NULL;
    sc *sc1=NULL,*sc2=NULL;
    co *c1=NULL;
    FILE *f=NULL;
    s1=S;
    Course_count=get_course_count(C);
    f=fopen("student.dat","rb");
    if(f==NULL){//��һ����� ���ļ�
        f=fopen("student.dat","wt");
        fclose(f);
        return;
        }
    if(fgetc(f)==EOF)//�ڶ������ ���ļ�
        return;
    rewind(f);//fgetc(f)�ƶ���fָ��ָ���ļ�λ�� ��f��λ
    while(!feof(f)){//��������� �ǿ��ļ�
        if(S==NULL){//��ͷ���ĵڶ������ �հ׼�¼
            S=(st *)malloc(sizeof(st));
            s1=S;
            fscanf(f,"%s %ld %d %f",s1->name,&s1->snum,&s1->rank,&s1->average);
            s1->sc_next=NULL;
            s1->st_next=NULL;
            sc1=s1->sc_next;
            c1=C;
            while(c1!=NULL){//���γ̳ɼ�д��
                sc2=(sc *)malloc(sizeof(sc));
                if(s1->sc_next==NULL){//�ж��Ƿ��һ���γ̳ɼ�
                    s1->sc_next=sc2;//��sc_nextָ���һ���γ̳ɼ�
                    sc1=sc2;
                }
                else{
                    sc1->sc_next=sc2;
                    sc1=sc2;
                }
                fscanf(f,"%f",&sc2->score);
                sc2->sc_next=NULL;
                c1=c1->co_next;
            }
        }
        else{//��ͷ���ĵڶ������ �ǿհ׼�¼
            s2=(st *)malloc(sizeof(st));
            fscanf(f,"%s %ld %d %f",s2->name,&s2->snum,&s2->rank,&s2->average);
            s2->sc_next=NULL;
            s2->st_next=NULL;
            s1->st_next=s2;
            s1=s2;
            c1=C;
            while(c1!=NULL){//���γ̳ɼ�д��
                sc2=(sc *)malloc(sizeof(sc));
                if(s1->sc_next==NULL){//�ж��Ƿ��һ���γ̳ɼ�
                    s1->sc_next=sc2;//��sc_nextָ���һ���γ̳ɼ�
                    sc1=sc2;
                }
                else{
                    sc1->sc_next=sc2;
                    sc1=sc2;
                }
                fscanf(f,"%f",&sc2->score);
                sc2->sc_next=NULL;
                c1=c1->co_next;
            }
        }
    }
    s2=S;//���feof(f)��������һ�� free��������ڴ浥Ԫ
    while(s2->st_next!=NULL){
        s1=s2;
        s2=s2->st_next;
    }
    sc1=s2->sc_next;
    free(s2);
    s1->st_next=NULL;
    while(sc1!=NULL){
        sc2=sc1;
        sc1=sc1->sc_next;
        free(sc2);
    }
}
void delete_score(int c){//ɾ���γ̶�Ӧ��ѧ����¼
    int i=0;
    st *s1=NULL;
    sc *sc1=NULL,*sc2=NULL;
    s1=S;
    while(s1!=NULL){
        sc1=s1->sc_next;
        i=c-1;
        if(c==1){//��һ����� ɾ����һ�γ�
            sc2=sc1;
            s1->sc_next=sc2->sc_next;
            free(sc2);
        }
        else{//�ڶ������ ɾ���ǵ�һ�γ�
            while(--i)//�����ͷŵ��ڴ浥λ��ǰһ��λ
                sc1=sc1->sc_next; 
            sc2=sc1->sc_next;//�ͷŵ��ڴ浥λ
            sc1->sc_next=sc2->sc_next;
            free(sc2);
        }
        s1=s1->st_next;
    }
}
void insert_score(int c){//�½��γ̶�Ӧ��ѧ����¼
    st *s1=NULL;
    sc *sc1=NULL,*sc2=NULL;
    if(S==NULL)//��ѧ����¼
        return;
    s1=S;
    while(s1!=NULL){//��һ����� ÿ��ѧ����¼�޿γ̼�¼
        if(s1->sc_next==NULL){
            sc2=(sc *)malloc(sizeof(sc));
            sc2->score=0;
            sc2->sc_next=NULL;
            s1->sc_next=sc2;
        }
        else{//�ڶ������ ÿ��ѧ����¼�пγ̼�¼
            sc1=s1->sc_next;
            while(sc1->sc_next!=NULL)//��ÿ��ѧ����¼�γ̼�¼������ڴ浥λ
                sc1=sc1->sc_next;
            sc2=(sc *)malloc(sizeof(sc));
            sc2->score=0;
            sc2->sc_next=NULL;
            sc1->sc_next=sc2;
        }
        s1=s1->st_next;
    }
}
int check_snum(long snum){//���ѧ���Ƿ��ظ�
    int b=0;
    st *s1=NULL;
    s1=S;
    while(s1!=NULL){
        if(s1->snum==snum)
            b=1;
        s1=s1->st_next;
    }
    return b;
}
int insert_student(){//�½�ѧ����¼
    int i=0;
    long snum;
    char t[50]={0};
    st *s1,*s2;
    co *c1;
    sc *sc1,*sc2;
    system("cls");
    s1=S;
    c1=C;
    if(S==NULL){//��һ����� ѧ����¼Ϊ��
        s2=(st *)malloc(sizeof(st));
        S=s2;
        }
    else{//�ڶ������ ѧ����¼��Ϊ��
        while(s1->st_next!=NULL)
            s1=s1->st_next;
        s2=(st *)malloc(sizeof(st));
        s1->st_next=s2;
    }
    s2->st_next=NULL;
    s2->sc_next=NULL;
    s2->rank=0;
    s2->num=0;
    s2->average=0;
    s1=s2;
    printf("������ѧ��������");
    scanf("%s",t);
    for(i=0;i<6;i++){//�쳣���� ��ֹ�ַ����ַ����
        s1->name[i]=t[i];
    }
    s1->name[6]='\0';
    while(1){
        printf("������ѧ�ţ�");
        scanf("%ld",&snum);
        if(snum<10000||snum>99999){
            printf("\n����ʾ��ѧ����������ѧ�ŷ�ΧΪ��10000-99999������������������룡��");
            fflush(stdin);
            getch();
            printf("\n\n");
            continue;
        }
        if(check_snum(snum)){
            printf("\n����ʾ��ѧ����������ѧ��Ϊѧ����¼���룬�����ظ�����������������룡��");
            fflush(stdin);
            getch();
            printf("\n\n");
            continue;
        }
        s1->snum=snum;
        break;
    }
    while(c1!=NULL){//���γ̳ɼ�����
        sc2=(sc *)malloc(sizeof(sc));
        if(s1->sc_next==NULL){//���ٵ�һ���γ� ��sc_nextָ���һ���γ�
            s1->sc_next=sc2;
            sc1=sc2;
        }
        else{
            sc1->sc_next=sc2;
            sc1=sc2;
        }
        while(1){//ÿ���γ̳ɼ�����
            printf("������%s�ɼ���",c1->course);
            scanf("%f",&sc2->score);
            if(sc2->score>=0&&sc2->score<=100)
                break;
            printf("\n����ʾ�������������󣬷�����ΧΪ��0-100������������������룡��");
            fflush(stdin);
            getch();
            printf("\n\n");
        }
        sc2->sc_next=NULL;
        c1=c1->co_next;
    }
    printf("\n����ʾ���½�ѧ����¼�ɹ������������������");
    getch();
    return student__;
}
void update_student_interface(int c){//�޸�ѧ����¼����1
    int i=0;
    co *c1=NULL;
    st *s1=NULL;
    sc *sc1=NULL;
    s1=S;
//    system("cls");
    puts("\n\n\n\n\n");
    printf("\t _________________________________");
    for(i=0;i<Course_count;i++){//���ݿγ������Ʊ�񶥲�����
        printf("___________");
    }
    printf("\n");
    printf("\t|  ����  |  ѧ��  | ���� | ƽ���� |");
    c1=C;
    while(c1!=NULL){
        printf(" %-8s |",c1->course);//����γ�����
        c1=c1->co_next;
    }
    printf("\n");
    printf("\t|---------------------------------");
    for(i=0;i<Course_count;i++){//���ݿγ������Ʊ���в�����
        printf("-----------");
    }
    printf("|\n");
    while(s1!=NULL){//���ѧ����¼
        if(c==s1->num)
            printf("      ��");
        else
            printf("        ");
        printf("| %-6s | %-6d | %-4d | %-6.2f |",s1->name,s1->snum,s1->rank,s1->average);
        sc1=s1->sc_next;
        while(sc1!=NULL){//��γ̳ɼ�
            printf(" %-8.2f |",sc1->score);
            sc1=sc1->sc_next;
        }
        s1=s1->st_next;
        printf("\n");
    }
    printf("\t|_________________________________");
    for(i=0;i<Course_count;i++){//���ݿγ������Ʊ��ײ�����
        printf("___________");
    }
    printf("|\n");
    printf("\n\t����ʾ���������ѡ�񣬰��س�ȷ��ѡ�񣡣�");
}
void update_student_interface_(int c){//�޸�ѧ����¼����2
    int i=3;
    co *c1;
    c1=C;
 //   system("cls");
    printf("\n\n\n");
    if(c==1)
        printf("\t\t\t��");
    else
        printf("\t\t\t  ");
    printf("[����]\n\n");
    if(c==2)
        printf("\t\t\t��");
    else
        printf("\t\t\t  ");
    printf("[ѧ��]\n\n");
    while(c1!=NULL){
        if(c==c1->num+2)
            printf("\t\t\t��");
        else
            printf("\t\t\t  ");
        printf("[%s����]\n\n",c1->course);
        c1=c1->co_next;
    }
    if(c==Course_count+3)
        printf("\t\t\t��");
    else
        printf("\t\t\t  ");
    puts("[����]\n");
    printf("\n\t\t����ʾ���������ѡ�񣬰��س�ȷ��ѡ�񣡣�");
     
}
int update_student(){//�޸�ѧ����¼
    int c=1,c1=1,i=0;
    long snum=0;
    char t[50];
    char ch=0;
    st *s1=NULL,*s2=NULL;
    sc *sc1=NULL;
    co *co1=NULL;
    num();
    if(S==NULL){
        printf("\n\n\t����ʾ����ǰû����ѧ����¼���޷��޸�ѧ����¼���밴��������أ���",c);
        getch();
        return student__;
    }
    while(1){
        if(c==Student_count+1)
            c=1;
        if(c==0)
            c=Student_count;
        update_student_interface(c);
        fflush(stdin);
        if(ch=='\r')
            break;
        if(ch==Esc)
            return student__;
        ch=getch();
        if(ch==Up)
            c-=1;
        if(ch==Down)
            c+=1;
    }
    printf("\n\n\t����ʾ��ѡ���%d��ѧ����¼�����س�ȷ���޸ģ��������ȡ��ѡ�񣡣�",c);
    ch=getch();
    if(ch!='\r')
        return student__;
    fflush(stdin);
    ch=0;
    while(1){
        if(c1==Course_count+4)//����ѧ��+����+�γ���
            c1=1;
        if(c1==0)
            c1=Course_count+3;//ѧ��+����+�γ���
        update_student_interface_(c1);
        fflush(stdin);
        if(ch=='\r')
            break;
        ch=getch();
        if(ch==Up)
            c1-=1;
        if(ch==Down)
            c1+=1;
    }
 //   system("cls");
    if(c1==Course_count+3)
        return student__;
    s1=S;
    while(s1!=NULL){//��s2ָ��ѡ�е�ѧ����¼
        if(s1->num==c){
            s2=s1;
            break;
        }
        s1=s1->st_next;
    }
    if(c1==1){//�޸�����
        printf("������ѧ��������");
        scanf("%s",t);
        for(i=0;i<6;i++){//�쳣���� ��ֹ�ַ����ַ����
            s2->name[i]=t[i];
        }
        s2->name[6]='\0';
        printf("\n����ʾ���޸�ѧ����¼�ɹ������������������");
        getch();
        return student__;
    }
    if(c1==2){//�޸�ѧ��
        while(1){
        printf("������ѧ�ţ�");
        scanf("%ld",&snum);
        if(snum<10000||snum>99999){
            printf("\n����ʾ��ѧ����������ѧ�ŷ�ΧΪ��10000-99999������������������룡��");
            fflush(stdin);
            getch();
            printf("\n\n");
            continue;
        }
        if(check_snum(snum)&&s1->snum!=snum){//�ڶ����� �޸���ͬѧ�� ����ʾ�ظ�
            printf("\n����ʾ��ѧ����������ѧ��Ϊѧ����¼���룬�����ظ�����������������룡��");
            fflush(stdin);
            getch();
            printf("\n\n");
            continue;
        }
        s1->snum=snum;
        break;
    }
        printf("\n����ʾ���޸�ѧ����¼�ɹ������������������");
        getch();
        return student__;
    }
    sc1=s2->sc_next;
    co1=C;
    for(i=1;i<c1-2;i++){
        sc1=sc1->sc_next;//��sc1ָ��ѡ�е�ѧ����¼�γ�
        co1=co1->co_next;//co1ָ��ѡ�еĿγ̼�¼
    }
    while(1){//ÿ���γ̳ɼ�����
            printf("������%s�ɼ���",co1->course);
            scanf("%f",&sc1->score);
            if(sc1->score>=0&&sc1->score<=100)
                break;
            printf("\n����ʾ�������������󣬷�����ΧΪ��0-100������������������룡��");
            fflush(stdin);
            getch();
            printf("\n\n");
        }
    printf("\n����ʾ���޸�ѧ����¼�ɹ������������������");
    getch();
    return student__;
 
}
void delete_student_interface(int c){//ɾ��ѧ����¼����
    int i=0;
    co *c1=NULL;
    st *s1=NULL;
    sc *sc1=NULL;
    s1=S;
  //  system("cls");
    puts("\n\n\n\n\n");
    printf("\t _________________________________");
    for(i=0;i<Course_count;i++){//���ݿγ������Ʊ�񶥲�����
        printf("___________");
    }
    printf("\n");
    printf("\t|  ����  |  ѧ��  | ���� | ƽ���� |");
    c1=C;
    while(c1!=NULL){
        printf(" %-8s |",c1->course);//����γ�����
        c1=c1->co_next;
    }
    printf("\n");
    printf("\t|---------------------------------");
    for(i=0;i<Course_count;i++){//���ݿγ������Ʊ���в�����
        printf("-----------");
    }
    printf("|\n");
    while(s1!=NULL){//���ѧ����¼
        if(c==s1->num)
            printf("      ��");
        else
            printf("        ");
        printf("| %-6s | %-6d | %-4d | %-6.2f |",s1->name,s1->snum,s1->rank,s1->average);
        sc1=s1->sc_next;
        while(sc1!=NULL){//��γ̳ɼ�
            printf(" %-8.2f |",sc1->score);
            sc1=sc1->sc_next;
        }
        s1=s1->st_next;
        printf("\n");
    }
    printf("\t|_________________________________");
    for(i=0;i<Course_count;i++){//���ݿγ������Ʊ��ײ�����
        printf("___________");
    }
    printf("|\n");
    printf("\n\t����ʾ���������ѡ�񣬰��س�ȷ��ѡ�񣡣�");
}
int delete_student(){//ɾ��ѧ����¼
    int c=1,i=0;
    int snum=0;
    char ch=0;
    st *s1=NULL,*s2=NULL;
    num();
    if(S==NULL){
        printf("\n\n\t����ʾ����ǰû��ѧ����¼���޷�ɾ��ѧ����¼���밴��������أ���",c);
        getch();
        return student__;
    }
    while(1){
        if(c==Student_count+1)
            c=1;
        if(c==0)
            c=Student_count;
        update_student_interface(c);
        fflush(stdin);
        if(ch=='\r')
            break;
        if(ch==Esc)
            return student__;
        ch=getch();
        if(ch==Up)
            c-=1;
        if(ch==Down)
            c+=1;
    }
    system("color c");
    printf("\n\n\t����ʾ��ѡ���%d��ѧ����¼�����س�ȷ��ɾ�����������ȡ��ѡ�񣡣�",c);
    ch=getch();
    if(ch!='\r')
        return student__;
    system("cls");
    s1=S;
    if(c==1){//ɾ����һ����¼
        S=S->st_next;
        snum=s1->snum;
        free(s1);
        printf("\n����ʾ��ɾ��ѧ��Ϊ%d��ѧ����¼�ɹ������������������",snum);
        getch();
        return student__;
    }
    for(i=2;i<c;i++){
        s1=s1->st_next;//s1ָ��Ҫɾ����ѧ����¼��ǰ�ڵ�
    }
    s2=s1->st_next;//s2ָ��Ҫɾ����ѧ����¼
    s1->st_next=s2->st_next;//�ƹ�Ҫɾ����ѧ����¼
    snum=s2->snum;
    free(s2);
    printf("\n����ʾ��ɾ��ѧ��Ϊ%d��ѧ����¼�ɹ������������������",snum);
    getch();
    return student__;
}
void select_student_interface(int c){//��ѯѧ����¼����
    system("cls");
    printf("\n\n\n");
    if(c==1)
        printf("\t\t\t��");
    else
        printf("\t\t\t  ");
    printf("[��������ѯ]\n\n\n");
    if(c==2)
        printf("\t\t\t��");
    else
        printf("\t\t\t  ");
    printf("[��ѧ�Ų�ѯ]\n\n\n");
    if(c==3)
        printf("\t\t\t��");
    else
        printf("\t\t\t  ");
    printf("[ͳ����Ϣ]\n\n\n");
    if(c==4)
        printf("\t\t\t��");
    else
        printf("\t\t\t  ");
    printf("[����]\n\n\n");
}
void select_name(char name[]){//��ѯѧ����¼����
    int i=1,b=0;
    st *s1=NULL;
    co *c1=NULL;
    sc *sc1=NULL;
    s1=S;
    system("cls");
    printf("��ѯ������£�\n\n\n");
    while(s1!=NULL){
        c1=C;
        if(!strcmp(s1->name,name)){
            b=1;
            printf("___________________\n");
            printf("ѧ����¼%d\n",i++);
            printf("��  ����%s\n",s1->name);
            printf("ѧ  �ţ�%ld\n",s1->snum);
            printf("��  �Σ�%d\n",s1->rank);
            printf("ƽ���֣�%.2f\n",s1->average);
            sc1=s1->sc_next;
            while(sc1!=NULL&&c1!=NULL){
                printf("%s��",c1->course);
                printf("%.2f\n",sc1->score);
                c1=c1->co_next;
                sc1=sc1->sc_next;
            }
        printf("___________________\n");
        }
        s1=s1->st_next;
    }
    if(b==0)
        printf("����ʾ���Ҳ�����ѧ����¼����");
    printf("\n\n����ʾ�����������������");
    getch();
}
void select_snum(long snum){//��ѯѧ����¼ѧ��
    int i=1,b=0;
    st *s1=NULL;
    co *c1=NULL;
    sc *sc1=NULL;
    s1=S;
    system("cls");
    printf("��ѯ������£�\n\n\n");
    while(s1!=NULL){
        c1=C;
        if(s1->snum==snum){
            b=1;
            printf("___________________\n");
            printf("ѧ����¼%d\n",i++);
            printf("��  ����%s\n",s1->name);
            printf("ѧ  �ţ�%ld\n",s1->snum);
            printf("��  �Σ�%d\n",s1->rank);
            printf("ƽ���֣�%.2f\n",s1->average);
            sc1=s1->sc_next;
            while(sc1!=NULL&&c1!=NULL){
                printf("%s��",c1->course);
                printf("%.2f\n",sc1->score);
                c1=c1->co_next;
                sc1=sc1->sc_next;
            }
        printf("___________________\n");
        break;
        }
        s1=s1->st_next;
    }
    if(b==0)
        printf("����ʾ���Ҳ�����ѧ����¼����");
    printf("\n\n����ʾ�����������������");
    getch();
}
int statistics_student(){//ͳ��ѧ����¼��Ϣ
    int n,all=0,pass=0;
    float average=0;
    st *s1=NULL;
    sc *sc1=NULL;
    co *c1=NULL;
    s1=S;
    if(C==NULL||S==NULL){
        printf("����ʾ��û��ѧ����¼��γ̼�¼����");
        printf("\n\n����ʾ�����������������");
        return student__;
        getch();
    }
    printf("ͳ����Ϣ��\n\n\n");
    while(s1!=NULL){
        n=0;
        sc1=s1->sc_next;
        while(sc1!=NULL){
            if(sc1->score>=Pass_grade)//�жϿγ��Ƿ�ϸ�
                n++;
            if(n==Course_count)//���пγ̺ϸ�
                pass++;
            sc1=sc1->sc_next;
        }
        average+=s1->average;
        all++;
        s1=s1->st_next;
    }
    average/=all;
    printf("����ѧ������Ϊ%d�����пγ̺ϸ�����Ϊ%d�����пγ�ƽ����Ϊ%.2f��\n\n",all,pass,average);
    c1=C;
     while(c1!=NULL){
        s1=S;
        pass=0;
        average=0;
        while(s1!=NULL){
            sc1=s1->sc_next;
            n=c1->num;
            while(sc1->sc_next!=NULL&&--n)//�ҳ��γ�
                sc1=sc1->sc_next;
            if(sc1->score>=Pass_grade)
                pass++;
            average+=sc1->score;
            s1=s1->st_next;
        }
        average/=all;
        printf("%s�ϸ�����Ϊ%d��ƽ����Ϊ%.2f��\n\n",c1->course,pass,average);
        c1=c1->co_next;
    }
    printf("\n\n����ʾ�����������������");
    getch();
    return student__;
}
 
int select_student(){//��ѯѧ����¼
    int c=1;
    long snum=0;
    char ch=0,name[7]={0};
    if(S==NULL){
        printf("\n\n\t����ʾ����ǰû����ѧ����¼���޷���ѯ���밴��������أ���");
        getch();
        return student__;
    }
    while(1){
        if(c==5)
            c=1;
        if(c==0)
            c=4;
        select_student_interface(c);
        fflush(stdin);
        if(getch()=='\r')
            break;
        ch=getch();
        if(ch==Up)
            c-=1;
        if(ch==Down)
            c+=1;
    }
    if(c==1){
        system("cls");
        printf("�������ѯ��ѧ����¼������");
        scanf("%s",name);
        select_name(name);
    }
    if(c==2){
        system("cls");
        printf("�������ѯ��ѧ����¼ѧ�ţ�");
        scanf("%d",&snum);
        select_snum(snum);
    }
    if(c==3){
        system("cls");
        statistics_student();
    }
    return student__;
}
void student_interface(int c){//ѧ����¼����
    int i=0;
    co *c1=NULL;
    st *s1=NULL;
    sc *sc1=NULL;
    s1=S;
    system("cls");
    puts("\n\n\n\n\n");
    printf("\t _________________________________");
    for(i=0;i<Course_count;i++){//���ݿγ������Ʊ�񶥲�����
        printf("___________");
    }
    printf("\n");
    printf("\t|  ����  |  ѧ��  | ���� | ƽ���� |");
    c1=C;
    while(c1!=NULL){
        printf(" %-8s |",c1->course);//����γ�����
        c1=c1->co_next;
    }
    printf("\n");
    printf("\t|---------------------------------");
    for(i=0;i<Course_count;i++){//���ݿγ������Ʊ���в�����
        printf("-----------");
    }
    printf("|\n");
    while(s1!=NULL){//���ѧ����¼
        printf("\t| %-6s | %-6d | %-4d | %-6.2f |",s1->name,s1->snum,s1->rank,s1->average);
        sc1=s1->sc_next;
        while(sc1!=NULL){//��γ̳ɼ�
            printf(" %-8.2f |",sc1->score);
            sc1=sc1->sc_next;
        }
        s1=s1->st_next;
        printf("\n");
    }
    printf("\t|_________________________________");
    for(i=0;i<Course_count;i++){//���ݿγ������Ʊ��ײ�����
        printf("___________");
    }
    printf("|\n\n\t");
    if(c==1) 
        printf("��");
    else
        printf("  ");
    printf("[�½�]  ");
    if(c==2)
        printf("��");
    else
        printf("  ");
    printf("[�޸�]  ");
    if(c==3)
        printf("��");
    else
        printf("  ");
    printf("[ɾ��]  ");
    if(c==4)
        printf("��");
    else
        printf("  ");
    printf("[��ѯ]  ");
    if(c==5)
        printf("��");
    else
        printf("  ");
    printf("[���ɱ��]  ");
    if(c==6)
        printf("��");
    else
        printf("  ");
    printf("[����]  ");
    printf("\n\n\t����ʾ���������ѡ�񣬰��س�ȷ��ѡ�񣡣�");
}
int student(){//ѧ����¼����
    int c=1;
    char ch=0;
//    Course_count=get_course_count(C);
    average();
    rank();
    if(Student_sortord)
        S=rank_sort(S);
    else
        S=snum_sort(S);
    fprintf_student();
    while(1){
        if(c==7)
            c=1;
        if(c==0)
            c=6;
        fflush(stdin);
        student_interface(c);
        fflush(stdin);
        ch=getch();
        if(ch=='\r')
            break;
        if(ch==Left)
            c-=1;
        if(ch==Right)
            c+=1;
    }
    switch(c){
        case 1:
            return insert_student__;
            break;
        case 2:
            return update_student__;
            break;
        case 3:
            return delete_student__;
            break;
        case 4:
            return select_student__;
            break;
        case 5:
            return create_table__;
            break;
        case 6:
            return welcome__;
            break;
        default:
            break;
    }
    return 0;
}
void fprintf_course(){//�ѿγ̲���д��Ӳ��
    FILE *f=NULL;
    co *c1=NULL;
    c1=C;
    f=fopen("course.dat","wt");
    while(c1!=NULL){
        fprintf(f,"%d %s\n",c1->num,c1->course);
        c1=c1->co_next;
    }
    if(C==NULL)
        f=fopen("course.dat","wt");
    fclose(f);
}
void fscanf_course(){//�ѿγ̲���д���ڴ�
    FILE *f;
    co *c1,*c2;
    c1=C;
    f=fopen("course.dat","rb");
    if(f==NULL){//��һ����� ���ļ�
        f=fopen("course.dat","wt");
        fclose(f);
        return;
    }
    if(fgetc(f)==EOF){//�ڶ������ ���ļ�
        fclose(f);
        return;
    }
    rewind(f);//fgetc(f)�ƶ���fָ��ָ���ļ�λ�� ��f��λ
    while(!feof(f)){//��������� �ǿ��ļ�
        if(C==NULL){//��ͷ���ĵڶ������ �հ׼�¼
            C=(co *)malloc(sizeof(co));
            fscanf(f,"%d%s",&C->num,C->course);
            C->co_next=NULL;
            c1=C;
        }
        else{//��ͷ���ĵڶ������ �ǿհ׼�¼ 
            c2=(co *)malloc(sizeof(co));
            c1->co_next=c2;
            c1=c1->co_next;
            fscanf(f,"%d%s",&c2->num,&c2->course);
        }
    }
    c2->co_next=NULL;
    c2=C;//���feof(f)��������һ�� free��������ڴ浥Ԫ
    while(c2->co_next!=NULL){
        c1=c2;
        c2=c2->co_next;
    }
    free(c2);
    c1->co_next=NULL;
}
void re__course_num(){//�γ����±��
    int i=1;
    co *c1=NULL;
    c1=C;
    while(c1!=NULL){
    c1->num=i;
    i++;
    c1=c1->co_next;
    }
}
int get_course_count(co *c1){//��ȡ�γ���
    int i=0;
    while(c1!=NULL){
        i++;
        c1=c1->co_next;
    }
    return i;
}
void course_interface(int c){//���ÿγ̽��� ������������
    co *c1=NULL;
    c1=C;
      system("cls");
      puts("\n\n\n\n");
      puts("\t\t\t   _________________");
      puts("\t\t\t  |�γ̱��|�γ�����|");
      puts("\t\t\t  |-----------------|");
      while(c1!=NULL){
        printf("\t\t\t  |    %-4d|%-8s|\n",c1->num,c1->course);
        c1=c1->co_next;
    }
    puts("\t\t\t  |_________________|");
    printf("\n\t\t");
    if(c==1) 
        printf("��");
    else
        printf("  ");
    printf("[�½�]  ");
    if(c==2)
        printf("��");
    else
        printf("  ");
    printf("[�޸�]  ");
    if(c==3)
        printf("��");
    else
        printf("  ");
    printf("[ɾ��]  ");
    if(c==4)
        printf("��");
    else
        printf("  ");
    printf("[����]  ");
    printf("\n\n\t\t����ʾ���������ѡ�񣬰��س�ȷ��ѡ�񣡣�");
}
int course(){//�γ̼�¼����
    int c=1;
    char ch=0;
    Course_count=get_course_count(C);
    re__course_num();//�����ſγ̼�¼���
    fprintf_course();//ɾ���ɹ� д��Ӳ��
    fprintf_student();//ɾ���ɹ� д��Ӳ��
    while(1){
        if(c==5)
            c=1;
        if(c==0)
            c=4;
        course_interface(c);
        fflush(stdin);
        if(ch=='\r')
            break;
        ch=getch();
        if(ch==Left)
            c-=1;
        if(ch==Right)
            c+=1;
    }
    switch(c){
        case 1:
            return insert_course__;
            break;
        case 2:
            return update_course__;
            break;
        case 3:
            return delete_course__;
            break;
        case 4:
            return settings__;
            break;
        default:
            break;
    }
    return 0;
}
int insert_course(){//�½��γ̼�¼
    int i=0;
    char t[50]={0};
    co* c1=NULL,*c2=NULL;
    system("cls");
    Course_count=get_course_count(C);
    if(C==NULL){
        C=(co *)malloc(sizeof(co));
        C->num=1;
          printf("�������½��γ����ƣ�");
        scanf("%s",t);
        for(i=0;i<8;i++){//�쳣���� ��ֹ�ַ����ַ����
            C->course[i]=t[i];
        }
        C->course[8]='\0';
        C->co_next=NULL;
        insert_score(1);
    }
    else{
        c1=C;
        while(c1->co_next!=NULL)
            c1=c1->co_next;
        c2=(co *)malloc(sizeof(co));
        c2->num=Course_count+1;
        printf("�������½��γ����ƣ�");
        scanf("%s",t);
        for(i=0;i<8;i++){//�쳣���� ��ֹ�ַ����ַ����
            c2->course[i]=t[i];
        }
        c2->course[8]='\0';
        c2->co_next=NULL;
        c1->co_next=c2;
        insert_score(Course_count+1);
    }
    printf("\n\t\t����ʾ���½��γ̼�¼�ɹ����밴��������أ���");
    getch();
    return course__; 
}
void settings_interface(int c){//���ý���
    system("cls");
    puts("\n\n\n\n\n");
    puts("\t\t ________________________________________________ ");
    puts("\t\t|                                                |");
    if(c==1)
        printf("\t\t|               ��");
    else
        printf("\t\t|                 ");
    puts("[�γ�]                         |");
    puts("\t\t|                                                |");
    if(c==2)
        printf("\t\t|               ��");
    else
        printf("\t\t|                 ");
    puts("[ѧ����¼����]                 |");
    puts("\t\t|                                                |");
    if(c==3)
        printf("\t\t|               ��");
    else
        printf("\t\t|                 ");
    puts("[�ϸ����]                     |");
    puts("\t\t|                                                |");
    if(c==4)
        printf("\t\t|               ��");
    else
        printf("\t\t|                 ");
    puts("[����]                         |");
    puts("\t\t|                                                |");
    if(c==5)
        printf("\t\t|               ��");
    else
        printf("\t\t|                 ");
    puts("[����]                         |");
    puts("\t\t|________________________________________________|");
    printf("\n\t\t����ʾ���������ѡ�񣬰��س�ȷ��ѡ�񣡣�");
}
int settings(){//����
    int c=1;
    char ch=0;
    while(1){
        if(c==6)
            c=1;
        if(c==0)
            c=5;
        settings_interface(c);
        fflush(stdin);
        if(getch()=='\r')
            break;
        ch=getch();
        if(ch==Up)
            c-=1;
        if(ch==Down)
            c+=1;
    }
    switch(c){
        case 1:
            return course__;
            break;
        case 2:
            return student_sortord__;
            break; 
        case 3:
            return pass_grade__;
            break; 
        case 4:
            return settings_password__;
            break;
        case 5:
            return welcome__;
            break;
        default:
            break;
    }
    return 0;
}
void update_course_interface(int c){//�޸Ŀγ̼�¼����
    co *c1=NULL;
    c1=C;
    system("cls");
    puts("\n\n\n\n");
    puts("\t\t\t   _________________");
    puts("\t\t\t  |�γ̱��|�γ�����|");
    puts("\t\t\t  |-----------------|");
    if(C==NULL)
        puts("\t\t\t  | ��ǰû���ÿγ̣�|");
    else{
        while(c1!=NULL){
            printf("\t\t\t");
            if(c==c1->num)
                printf("��");
            else
                printf("  ");
            printf("|    %-4d|%-8s|\n",c1->num,c1->course);
            c1=c1->co_next;
        }
    }
    puts("\t\t\t  |_________________|");
    printf("\n\n\t\t����ʾ���������ѡ�񣬰��س�ȷ��ѡ�񣬰�ESCȡ�����أ���");
}
int update_course(){//�޸Ŀγ̼�¼
    int c=1,i=0;
    char t[50]={0};
    co *c1=NULL;
    char ch=0;
    if(C==NULL){
        printf("\n\n\t\t����ʾ����ǰû���ÿγ̣��޷��޸Ŀγ̼�¼���밴��������أ���",c);
        getch();
        return course__;
    }
    while(1){
        if(c==Course_count+1)
            c=1;
        if(c==0)
            c=Course_count;
        update_course_interface(c);
        fflush(stdin);
        if(ch=='\r')
            break;
        if(ch==Esc)
            return course__;
        ch=getch();
        if(ch==Up)
            c-=1;
        if(ch==Down)
            c+=1;
    }
    printf("\n\n\t\t����ʾ��ѡ��γ̱��Ϊ%d�����س�ȷ���޸ģ��������ȡ��ѡ�񣡣�",c);
    ch=getch();
    if(ch!='\r')
        return course__;
    c1=C;
    while(c1!=NULL){
        if(c1->num==c){
            system("cls");
            printf("ѡ��γ̱��Ϊ%d���������޸Ŀγ����ƣ�",c);
            scanf("%s",t);
            for(i=0;i<8;i++){//�쳣���� ��ֹ�ַ����ַ����
                c1->course[i]=t[i];
            }
            c1->course[8]='\0';
            break;
        }
        c1=c1->co_next;
    }
    fprintf_course();//�޸ĳɹ� д��Ӳ��
    printf("\n\t\t����ʾ���޸Ŀγ̼�¼�ɹ����밴��������أ���");
    getch();
    return course__;
}
void delete_course_interface(int c){//ɾ���γ̼�¼����
    co *c1=NULL;
    c1=C;
    system("cls");
    puts("\n\n\n\n");
    puts("\t\t\t   _________________");
    puts("\t\t\t  |�γ̱��|�γ�����|");
    puts("\t\t\t  |-----------------|");
    if(C==NULL)
        puts("\t\t\t  | ��ǰû���ÿγ̣�|");
    else{
        while(c1!=NULL){
            printf("\t\t\t");
            if(c==c1->num)
                printf("��");
            else
                printf("  ");
            printf("|    %-4d|%-8s|\n",c1->num,c1->course);
            c1=c1->co_next;
        }
    }
    puts("\t\t\t  |_________________|");
    puts("\n\n\t\t����ʾ���������ѡ�񣬰��س�ȷ��ѡ�񣬰�ESCȡ�����أ���");
}
int delete_course(){//ɾ���γ̼�¼
    int c=1;
    co *c1=NULL,*c2=NULL;
    char ch=0;
    if(C==NULL){
        printf("\n\n\t\t����ʾ����ǰû���ÿγ̣��޷�ɾ���γ̼�¼���밴��������أ���",c);
        getch();
        return course__;
    }
    while(1){
        if(c==Course_count+1)
            c=1;
        if(c==0)
            c=Course_count;
        delete_course_interface(c);
        fflush(stdin);
        if(ch=='\r')
            break;
        if(ch==Esc)
            return course__;
        ch=getch();
        if(ch==Up)
            c-=1;
        if(ch==Down)
            c+=1;
    }
    system("color c");
    printf("\n\t\t����ʾ���Ƿ�ɾ�����Ϊ%d�Ŀγ̣����س�ȷ�����������ȡ������",c);
    ch=getch();
    if(ch!='\r')
        return course__;
    c1=C;
    if(c==1){//ɾ���γ̼�¼��һ����� ɾ����һ����¼
        C=c1->co_next;
        free(c1);
    }
    else{
        while(c1!=NULL){//ɾ���γ̼�¼�ڶ������ ɾ���ǵ�һ����¼
            if(c==c1->num){
                c2->co_next=c1->co_next;
                free(c1);
                break;
            }
            c2=c1;
            c1=c1->co_next;
        }
    }
    delete_score(c);//ɾ���γ̶�Ӧ��ѧ��¼���ͷ��ڴ�
    printf("\n\n\t\t����ʾ��ɾ�����Ϊ%d�Ŀγ̼�¼�ɹ����밴��������أ���",c);
    getch();
    return course__;
}
void fprintf_settings_parameter(){//���ò���д��Ӳ��
    FILE *f=NULL;
    f=fopen("settings.dat","wt");
    fprintf(f,"%d %d",Student_sortord,Pass_grade);
    fclose(f);
}
void fscanf_settings_parameter(){//���ò���д���ڴ�
    FILE *f=NULL;
    f=fopen("settings.dat","rb");
    if(f==NULL){
        f=fopen("settings.dat","wt");
        fprintf(f,"%d %d",Student_sortord,Pass_grade);
        fclose(f);
    }
    else{
        fscanf(f,"%d %d",&Student_sortord,&Pass_grade);
        fclose(f);
    }
}
void student_sortord_interface(int c){
    system("cls");
      printf("\n\n��ǰ��������Ϊ��");
      Student_sortord?printf("�����ν�������\n\n\n"):printf("��ѧ�Ž�������\n\n\n");
    if(c==1) 
        printf("��");
    else
        printf("  ");
    printf("[��ѧ�Ž�������]  ");
    if(c==2)
        printf("��");
    else
        printf("  ");
    printf("[�����ν�������]  ");
    if(c==3)
        printf("��");
    else
        printf("  ");
    printf("[����]  ");
    printf("\n\n\n����ʾ���������ѡ�񣬰��س�ȷ��ѡ�񣬰�Esc�˳�����");
}
int student_sortord(){//ѧ����¼����ʽ
    int c=1;
    char ch=0;
    while(1){
        if(c==4)
            c=1;
        if(c==0)
            c=3;
        student_sortord_interface(c);
        fflush(stdin);
        if(ch=='\r')
            break;
        ch=getch();
        if(ch==Left)
            c-=1;
        if(ch==Right)
            c+=1;
    }
    switch(c){
        case 1:
            Student_sortord=0;
            break;
        case 2:
            Student_sortord=1;
            break;
        case 3:
            return settings__;
            break;
        default:
            break;
    }
    fprintf_settings_parameter();
    if(Student_sortord)
        S=rank_sort(S);
    else
        S=snum_sort(S);
    printf("\n\n\n����ʾ�����óɹ������������������");
    getch();
    return student_sortord__;
}
void pass_grade_interface(int c){
    system("cls");
      printf("\n\n��ǰ�ϸ����Ϊ��");
      printf("%d\n\n\n",Pass_grade);
    if(c==1) 
        printf("��");
    else
        printf("  ");
    printf("[�޸�]  ");
    if(c==2)
        printf("��");
    else
        printf("  ");
    printf("[����]  ");
    printf("\n\n\n����ʾ���������ѡ�񣬰��س�ȷ��ѡ�񣬰�Esc�˳�����");
}
int pass_grade(){
    int c=1;
    char ch=0;
    while(1){
        if(c==3)
            c=1;
        if(c==0)
            c=2;
        pass_grade_interface(c);
        fflush(stdin);
        if(ch=='\r')
            break;
        ch=getch();
        if(ch==Left)
            c-=1;
        if(ch==Right)
            c+=1;
    }
    if(c==1){
        system("cls");
        printf("���������ø��ĺϸ������");
        scanf("%d",&Pass_grade);
        fprintf_settings_parameter();
        printf("\n\n\n����ʾ�����óɹ������������������");
        getch();
        return pass_grade__;
    }
    if(c==2)
        return settings__;
    return 0;
}
void exit_program_interface(){//�˳��������
    system("cls");
    puts("\n\n\n\n\n");
    puts("\t\t ________________________________________________ ");
    puts("\t\t|                                                |");
    puts("\t\t|                                                |");
    puts("\t\t|   ѧ���ɼ�����ϵͳ���˳���                     |");
    puts("\t\t|                                                |");
    puts("\t\t|                    �밴������رմ��ڡ�        |");
    puts("\t\t|                                                |");
    puts("\t\t|________________________________________________|");
    puts("\n\n\n\n\n\n");
}
int exit_program(){//�˳�����
    system("color 8f");
    exit_program_interface();
    exit(0);
}
void densification(char cleartext[]){//����
    int i=0;
    char t[8]={0};
    for(i=0;i<8;i++){//���ܷ�ʽ1��ÿλ���Լ���Ԫ���±�
        t[i]=cleartext[i]+i;
    }
    for(i=0;i<8;i++){//���ܷ�ʽ2������Ԫ�ص���
        cleartext[i]=t[7-i];
    }
}
void decrypt(char ciphertext[]){//����
    int i=0;
    char t[8]={0};
    for(i=0;i<8;i++){
        t[i]=ciphertext[7-i];//�⿪���ܷ�ʽ2
    }
    for(i=0;i<8;i++){
        ciphertext[i]=t[i]-i;//�⿪���ܷ�ʽ1
    }
}
void fprintf_password(char password[]){//�������д��Ӳ��
    FILE *p=NULL;
    int i=0;
    densification(password);
    p=fopen("password.dat","wt");
    for(i=0;i<8;i++){
        fprintf(p,"%d ", password[i]);//��ASCII������д��Ӳ��
    }
    fclose(p);
}
int proofread_password(char password1[],char password2[]){//У����������
    int i=0;
    for(i=0;i<8;i++){
        if(password1[i]!=password2[i])
            break;
    }
        if(i<8)
            return 0;
        else
            return 1;
}
void fscanf_password(char password[]){//�������д���ڴ�
    int i=0;
    FILE *p=NULL;
    p=fopen("password.dat","rb");
    if(p==NULL){
    p=fopen("password.dat","wt");
    fprintf_password(password);
    fclose(p);
    return;
    }
    for(i=0;i<8;i++){
        fscanf(p,"%d ",&password[i]);//��ASCII������д���ڴ�
    }
    decrypt(password); 
    fclose(p);
}
int decide_password(){//����Ƿ��п�����
    char temp[8]={0};
    fscanf_password(Password);
    return proofread_password(Password,temp);
}
void scanf_password_interface(char password[]){//�����������
    int i=0;
    system("cls");
    puts("\n\n\n\n\n");
    puts("\t\t ________________________________________________ ");
    puts("\t\t|                                                |");
    puts("\t\t|                                                |");
    puts("\t\t|                                                |");
    printf("\t\t|         ����������:");
    for(i=0;i<8;i++){
        if(password[i]!=0)
            printf(" *");
        else
            printf(" _");
    }
    puts("            |");
    puts("\t\t|                                                |");
    puts("\t\t|                                                |");
    puts("\t\t|________________________________________________|");
    printf("\n\t\t����ʾ�����س�ȷ�����룬��Esc�˳�ѧ���ɼ�����ϵͳ����");
}
int scanf_password(){//��������
    int x=0;
    char ch=0,password[8]={0};//ASCIIΪ0������ա�
    while(1){
        if(x<=0)//��ֹ������С��0
            x=0;
        if(x>=8)//��ֹ����������8
            x=8;
        scanf_password_interface(password);
        fflush(stdin);
        ch=getch();
        if(ch=='\r') 
            break;
        if(ch==Esc)
            return exit_program__;
        if(ch==Backspace&&x>0)//x>0��ֹ����Խ�� 
            password[--x]=0;//ɾ����x-1������
        if(x==8)
            continue;
        if((ch>='0'&&ch<='9')||(ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
            password[x++]=ch;//�����x������
        else
            continue;
}
    fscanf_password(Password);//����������ڴ�
    if(ch=='\r'){
        if(proofread_password(password,Password))//ԭʼ������֤
            return welcome__;
        else{
            system("color cf");
            printf("\a\n\n\t\t����ʾ��������������밴��������أ���\n");
            getch();
            return scanf_password__;
        }
    }
    return 2;
}
void settings_password_interface(int y,char password[][8]){//�����������
    int i=0,j=0;
    FILE *p=NULL;
    p=fopen("password.dat","rb");//����Ƿ���ԭʼ����
    if(p==NULL||decide_password()){
        j=1;//û��ԭʼ���� ����ʾ��0��
        y-=1;//û�е�0�� ����������
    }
    system("cls");
    puts("\n\n\n\n");
    puts("\t\t ________________________________________________ ");
    puts("\t\t|                                                |");
    puts("\t\t|                                                |");
    puts("\t\t|                                                |");
    for(;j<3;j++){
        printf("\t\t|       ");
        if(j==0)
            printf("������ԭʼ����:");
        if(j==1)
            printf("�������޸�����:");
        if(j==2)
            printf("������ȷ������:");
        for(i=0;i<8;i++){
            if(password[j][i]!=0)
                printf(" *");
            else
                printf(" _");
        }
        if(y>0){
            printf("��");
            y--;
        }
        else
            printf("  ");
        puts("        |");
    }
    puts("\t\t|                                                |");
    puts("\t\t|                                                |");
    puts("\t\t|________________________________________________|");
    printf("\n\t\t����ʾ�����س�ȷ�����룬��Esc�˳��������룡��");
}
int settings_password(){//��������
    int x=0,y=0;
    char ch,password[3][8]={0};//ASCIIΪ0 ����� 0�б�ʾԭʼ���� 1�б�ʾ������ 3�б�ʾȷ������
    FILE *p=NULL;
    p=fopen("password.dat","rb");//����Ƿ���ԭʼ����
    if(p==NULL||decide_password())
        y=1;
    while(1){
        if(x<=0)//��ֹ������С��8
            x=0;
        if(x>=8)//��ֹ����������8
            x=8;
        settings_password_interface(y,password);
        fflush(stdin);
        ch=getch();
        if(ch=='\r'){
            y++;
            x=0;//������������
        }
        if(ch=='\r'&&y==3)
            break;
        if(ch==Esc) 
            return settings__;
        if(ch==Backspace&&x>0)//x>0��ֹ����Խ�� 
            password[y][--x]=0;//ɾ����y�е�x-1������
        if(x==8)
            continue;
        if((ch>='0'&&ch<='9')||(ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
            password[y][x++]=ch;//�����y�е�x������
        else
            continue;
  }
    settings_password_interface(y,password);
    fflush(stdin);
    fscanf_password(Password);//����������ڴ�
    if(p==NULL||proofread_password(password[0],Password)){//ԭʼ������֤
        if(proofread_password(password[1],password[2])){//�޸�������ȷ��������֤
            fprintf_password(password[1]);
            printf("\n\n\t\t����ʾ�������޸ĳɹ�������������أ���");
            getch();
        }
        else{
            printf("\n\n\t\t����ʾ���޸������ȷ���������벻һ�£�����������أ���");
            getch();
            return settings_password__;
        }
    }
    else{
        printf("\n\n\t\t����ʾ��ԭʼ����������󣬰���������أ���");
        getch();
        return settings_password__;
    }
    return settings__;
}
int create_table(){
    FILE *f=NULL;
    st *s1=NULL;
    sc *sc1=NULL;
    co *c1=NULL;
    int i=0,j=0;
    char *table=NULL;
    s1=S;
    c1=C;
    if(S==NULL){
        printf("\n\n\t����ʾ����ǰûѧ����¼���޷����ɱ���밴��������أ���");
        getch();
        return student__;
    }
    f=fopen("student.html","wt");
    fprintf(f,"<table border=\"1\" bordercolor=\"#0066FF\" cellspacing=\"0\"  font-size:30px><tr bgcolor=\"#FF0000\"><td>����</td><td>ѧ��</td><td>����</td><td>ƽ����</td>");
    while(c1!=NULL){
        fprintf(f,"<td>%s</td>",c1->course);
        c1=c1->co_next;
    }
    fprintf(f,"</tr>");
    if(s1!=NULL){
        while(s1!=NULL){//ѧ����Ϣд��Ӳ��
            fprintf(f,"<tr>");
            fprintf(f,"<td>%s</td><td>%ld</td><td>%d</td><td>%.2f</td>",s1->name,s1->snum,s1->rank,s1->average);
            sc1=s1->sc_next;
            while(sc1!=NULL){//�γ̳ɼ�д��Ӳ��
                fprintf(f,"<td>%.2f</td>",sc1->score);
                sc1=sc1->sc_next;
            }
            fprintf(f,"</tr>");
            s1=s1->st_next;
        }
        fprintf(f,"</table>");
        fclose(f);
        printf("\n\n\t����ʾ�����ɱ���Ѵ򿪣��رձ�������������");
        system("student.html");
    }
    return student__;
}
void about_interface(){//���ڽ���
    system("cls");
    puts("_________________________________________________");
    puts("3.0�汾:");
    puts("\n1.�޸�ѧ����¼�����ݽṹ��");
    puts("\n2.���γ̿����Զ������ƺ������� ");
    puts("\n3.���������빦�ܡ�");
    puts("\n4.�ѽ��溯���빦�ܺ����ֿ���");
    puts("\n5.������һЩ���档");
    puts("\n6.��һ���Ż����롣");
    puts("\n7.����������õ����޷��ͷ��ڴ�����⡣");
    puts("\n8.�Ժ������࣬������������������");
    puts("\n9.�ɽ�ѧ���ɼ����������html�ļ���");
    puts("_________________________________________________");
    puts("\n\n\t\t\t        ���д����ɿհ�д�𡣡��������ϵ����1��LR");
    printf("\n\t����ʾ������������أ���");
}
int about(){//����
    system("color 1f");
    about_interface();
    getch();
    return welcome__;
}
void function_call(int c){//���ƺ����ĵ��� ����ڴ��޷��ͷ�����
    while(1){
        system("color 2");
        fflush(stdin);
        switch(c){
            case 0:
                c=welcome();
                break;
            case 1:
                c=student();
                break;
            case 11:
                c=insert_student();
                break;
            case 12:
                c=update_student();
                break;
            case 13:
                c=delete_student();
                break;
            case 14:
                c=select_student();
                break;
            case 2:
                c=exit_program();
                break;
            case 3:
                c=settings();
                break;
            case 31:
                c=course();
                break;
            case 32:
                c=student_sortord();
                break;
            case 33:
                c=pass_grade();
                break;
            case 311:
                c=insert_course();
                break;
            case 312:
                c=update_course();
                break;
            case 313:
                c=delete_course();
                break;
            case 34:
                c=settings_password();
                break;
            case 35:
                c=create_table();
                break;
            case 341:
                c=scanf_password();
                break;
            case 4:
                c=about();
                break;
           default:
               break;
        }
    }
}
 
int main(){//����brboy.cn�����ש��С�к�
    fscanf_password(Password);
    fscanf_settings_parameter();
    fscanf_course();
    fscanf_student();
    if(Student_sortord){
        S=rank_sort(S);
    }
    else{
        S=snum_sort(S);
    }
    if(decide_password()){//����Ƿ�û���������Ϊ������
        function_call(0);
    }
    else{
        function_call(341);//��ʾ����
    }
    function_call(0);
    return 0;
}
//�������еĹ��̶���funciton_call�����е��ã����ܺ����е�return�����Է�����һ�����õĹ��ܺ���������//����ֱ���ɹ��ܺ������á�

