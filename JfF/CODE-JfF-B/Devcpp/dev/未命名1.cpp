/*
__________________________________________________
3.0版本
1.修改学生记录的数据结构。            
2.各课程可以自定义名称和数量。        
3.增加了密码功能。                    
4.把界面函数与功能函数彻底分开。
5.更改了一些界面。                   
6.进一步优化代码。                    
7.解决函数调用导致无法释放内存的问题。
8.函数归类，函数调用有序清晰。
9.可将学生成绩表快速生成html文件。
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
    float score;//分数
    struct node1 *sc_next;//指向下一科成绩
}sc;
typedef struct node2{//学生记录
    struct node2 *st_next;//指向下一个学生记录
    int num;//编号
    char name[7];//姓名
    long snum;//学号
    int rank;//名次
    float average;//平均分
    sc *sc_next;//指向成绩
}st;

typedef struct node3{
    int num;//编号
    char course[9];//课程名称
    struct node3 *co_next;//指向下一个课程
}co;
 
st *S=NULL;//学生记录指针
co *C=NULL;//课程指针
int Course_count=0;//课程数
int Student_count=0;//学生记录数
char Password[8]={0};//将密码从硬盘入内存即该变量
int static Student_sortord=0;//学生记录排序  0按学号排  1按分数排
int Pass_grade=60;//合格成绩
 
void welcome_interface(int c){//欢迎界面
//  system("cls");
    puts("\n\n\n\n\n");
    puts("\t\t ________________________________________________ ");
    puts("\t\t|                                                |");
    puts("\t\t|                                                |");
    puts("\t\t|   计算机系11网络1班学生成绩管理系统            |");
    puts("\t\t|                                                |");
    puts("\t\t|                        --计算机系网络1班LR     |");
    puts("\t\t|________________________________________________|");
    puts("\t\t|                                                |");
    printf("\t\t|   ");
    if(c==1)
        printf("→");
    else
        printf("  ");
    printf("[进入]  ");
    if(c==2)
        printf("→");
    else
        printf("  ");
    printf("[退出]  ");
    if(c==3)
        printf("→");
    else
        printf("  ");
    printf("[设置]  ");
    if(c==4)
        printf("→");
    else
        printf("  ");
    puts("[关于]       |");
    puts("\t\t|________________________________________________|");
    printf("\n\t\t（提示：按方向键选择，按回车确定选择！）");
}
int welcome(){//欢迎
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
void num(){//学生记录编号
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
void average(){//学生记录平均分
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
void rank(){//记录名次编号
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
    while(s1!=NULL){//清除所有名次 0可以用标识是否排过名 下面算法需要
        s1->rank=0;
        s1=s1->st_next;
    }
    while(break_){//逻辑值 判断是否所有学生记录都赋名次
        s1=S;
        break_=0;
        if(max!=NULL&&max->rank!=0)//保存上一个指针 判断相邻的名次是否并列时使用
            prior=max;
        max=S;
        while(s1!=NULL){//遍历所有学生记录
            if(s1->rank==0){//只遍历那些未赋名次的学生记录
                max=(max->rank==0&&max->average>s1->average)?max:s1;//未赋名次才能做为max
                break_=1;
            }
            s1=s1->st_next;
        }
        if(break_&&max->rank==0)//排名
            max->rank=rank++;
        if(prior!=NULL&&prior->average==max->average)//并列排名
            max->rank=prior->rank;
    }
}
st *rank_sort(st *head){//名次排序
    st *s1=NULL,*max=NULL;
    s1=head;
    max=head;
    if(head==NULL)
        return head;
    while(s1->st_next!=NULL){//找出average最大的即max节点
        s1=s1->st_next;
        if(max->average<s1->average)
            max=s1;
    }
    s1->st_next=head;//形成环形链表
    while(s1->st_next!=max)//找出指向max节点的节点 让它指向NULL
        s1=s1->st_next;
    s1->st_next=NULL;
    head=max;
    head->st_next=rank_sort(head->st_next);//递归调用 一次找出max节点
    return head;
}
st *snum_sort(st *head){//学号排序
    st *s1=NULL,*min=NULL;
    s1=head;
    min=head;
    if(head==NULL)
        return head;
    while(s1->st_next!=NULL){//找出average最大的即max节点
        s1=s1->st_next;
        if(min->snum>s1->snum)
            min=s1;
    }
    s1->st_next=head;//形成环形链表
    while(s1->st_next!=min)//找出指向max节点的节点 让它指向NULL
        s1=s1->st_next;
    s1->st_next=NULL;
    head=min;
    head->st_next=snum_sort(head->st_next);//递归调用 一次找出max节点
    return head;
}
void fprintf_student(){//学生记录写入硬盘
    st *s1=NULL;
    sc *sc1=NULL;
    FILE *f=NULL;
    s1=S;
    f=fopen("student.dat","wt");
    if(s1!=NULL){
        while(s1!=NULL){//学生信息写入硬盘
            fprintf(f,"%s %ld %d %f",s1->name,s1->snum,s1->rank,s1->average);
            sc1=s1->sc_next;
            while(sc1!=NULL){//课程成绩写入硬盘
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
void fscanf_student(){//学生记录写入内存
    int n=1;
    int get_course_count(co*);
    st *s1=NULL,*s2=NULL;
    sc *sc1=NULL,*sc2=NULL;
    co *c1=NULL;
    FILE *f=NULL;
    s1=S;
    Course_count=get_course_count(C);
    f=fopen("student.dat","rb");
    if(f==NULL){//第一种情况 无文件
        f=fopen("student.dat","wt");
        fclose(f);
        return;
        }
    if(fgetc(f)==EOF)//第二种情况 空文件
        return;
    rewind(f);//fgetc(f)移动了f指针指向文件位置 让f复位
    while(!feof(f)){//第三种情况 非空文件
        if(S==NULL){//无头结点的第二种情况 空白记录
            S=(st *)malloc(sizeof(st));
            s1=S;
            fscanf(f,"%s %ld %d %f",s1->name,&s1->snum,&s1->rank,&s1->average);
            s1->sc_next=NULL;
            s1->st_next=NULL;
            sc1=s1->sc_next;
            c1=C;
            while(c1!=NULL){//各课程成绩写入
                sc2=(sc *)malloc(sizeof(sc));
                if(s1->sc_next==NULL){//判断是否第一个课程成绩
                    s1->sc_next=sc2;//让sc_next指向第一个课程成绩
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
        else{//无头结点的第二种情况 非空白记录
            s2=(st *)malloc(sizeof(st));
            fscanf(f,"%s %ld %d %f",s2->name,&s2->snum,&s2->rank,&s2->average);
            s2->sc_next=NULL;
            s2->st_next=NULL;
            s1->st_next=s2;
            s1=s2;
            c1=C;
            while(c1!=NULL){//各课程成绩写入
                sc2=(sc *)malloc(sizeof(sc));
                if(s1->sc_next==NULL){//判断是否第一个课程成绩
                    s1->sc_next=sc2;//让sc_next指向第一个课程成绩
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
    s2=S;//解决feof(f)函数会多读一行 free最后多余的内存单元
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
void delete_score(int c){//删除课程对应的学生记录
    int i=0;
    st *s1=NULL;
    sc *sc1=NULL,*sc2=NULL;
    s1=S;
    while(s1!=NULL){
        sc1=s1->sc_next;
        i=c-1;
        if(c==1){//第一种情况 删除第一课程
            sc2=sc1;
            s1->sc_next=sc2->sc_next;
            free(sc2);
        }
        else{//第二种情况 删除非第一课程
            while(--i)//查找释放的内存单位的前一单位
                sc1=sc1->sc_next; 
            sc2=sc1->sc_next;//释放的内存单位
            sc1->sc_next=sc2->sc_next;
            free(sc2);
        }
        s1=s1->st_next;
    }
}
void insert_score(int c){//新建课程对应的学生记录
    st *s1=NULL;
    sc *sc1=NULL,*sc2=NULL;
    if(S==NULL)//无学生记录
        return;
    s1=S;
    while(s1!=NULL){//第一种情况 每条学生记录无课程记录
        if(s1->sc_next==NULL){
            sc2=(sc *)malloc(sizeof(sc));
            sc2->score=0;
            sc2->sc_next=NULL;
            s1->sc_next=sc2;
        }
        else{//第二种情况 每条学生记录有课程记录
            sc1=s1->sc_next;
            while(sc1->sc_next!=NULL)//找每条学生记录课程记录的最后内存单位
                sc1=sc1->sc_next;
            sc2=(sc *)malloc(sizeof(sc));
            sc2->score=0;
            sc2->sc_next=NULL;
            sc1->sc_next=sc2;
        }
        s1=s1->st_next;
    }
}
int check_snum(long snum){//检测学号是否重复
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
int insert_student(){//新建学生记录
    int i=0;
    long snum;
    char t[50]={0};
    st *s1,*s2;
    co *c1;
    sc *sc1,*sc2;
    system("cls");
    s1=S;
    c1=C;
    if(S==NULL){//第一种情况 学生记录为空
        s2=(st *)malloc(sizeof(st));
        S=s2;
        }
    else{//第二种情况 学生记录不为空
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
    printf("请输入学生姓名：");
    scanf("%s",t);
    for(i=0;i<6;i++){//异常处理 防止字符串字符溢出
        s1->name[i]=t[i];
    }
    s1->name[6]='\0';
    while(1){
        printf("请输入学号：");
        scanf("%ld",&snum);
        if(snum<10000||snum>99999){
            printf("\n（提示：学号输入有误，学号范围为（10000-99999），按任意键重新输入！）");
            fflush(stdin);
            getch();
            printf("\n\n");
            continue;
        }
        if(check_snum(snum)){
            printf("\n（提示：学号输入有误，学号为学生记录主码，不得重复，按任意键重新输入！）");
            fflush(stdin);
            getch();
            printf("\n\n");
            continue;
        }
        s1->snum=snum;
        break;
    }
    while(c1!=NULL){//各课程成绩输入
        sc2=(sc *)malloc(sizeof(sc));
        if(s1->sc_next==NULL){//开辟第一个课程 让sc_next指向第一个课程
            s1->sc_next=sc2;
            sc1=sc2;
        }
        else{
            sc1->sc_next=sc2;
            sc1=sc2;
        }
        while(1){//每个课程成绩输入
            printf("请输入%s成绩：",c1->course);
            scanf("%f",&sc2->score);
            if(sc2->score>=0&&sc2->score<=100)
                break;
            printf("\n（提示：分数输入有误，分数范围为（0-100），按任意键重新输入！）");
            fflush(stdin);
            getch();
            printf("\n\n");
        }
        sc2->sc_next=NULL;
        c1=c1->co_next;
    }
    printf("\n（提示：新建学生记录成功，按任意键继续！）");
    getch();
    return student__;
}
void update_student_interface(int c){//修改学生记录界面1
    int i=0;
    co *c1=NULL;
    st *s1=NULL;
    sc *sc1=NULL;
    s1=S;
//    system("cls");
    puts("\n\n\n\n\n");
    printf("\t _________________________________");
    for(i=0;i<Course_count;i++){//根据课程数绘制表格顶部横线
        printf("___________");
    }
    printf("\n");
    printf("\t|  姓名  |  学号  | 名次 | 平均分 |");
    c1=C;
    while(c1!=NULL){
        printf(" %-8s |",c1->course);//输出课程名次
        c1=c1->co_next;
    }
    printf("\n");
    printf("\t|---------------------------------");
    for(i=0;i<Course_count;i++){//根据课程数绘制表格中部横线
        printf("-----------");
    }
    printf("|\n");
    while(s1!=NULL){//输出学生记录
        if(c==s1->num)
            printf("      →");
        else
            printf("        ");
        printf("| %-6s | %-6d | %-4d | %-6.2f |",s1->name,s1->snum,s1->rank,s1->average);
        sc1=s1->sc_next;
        while(sc1!=NULL){//输课程成绩
            printf(" %-8.2f |",sc1->score);
            sc1=sc1->sc_next;
        }
        s1=s1->st_next;
        printf("\n");
    }
    printf("\t|_________________________________");
    for(i=0;i<Course_count;i++){//根据课程数绘制表格底部横线
        printf("___________");
    }
    printf("|\n");
    printf("\n\t（提示：按方向键选择，按回车确定选择！）");
}
void update_student_interface_(int c){//修改学生记录界面2
    int i=3;
    co *c1;
    c1=C;
 //   system("cls");
    printf("\n\n\n");
    if(c==1)
        printf("\t\t\t→");
    else
        printf("\t\t\t  ");
    printf("[姓名]\n\n");
    if(c==2)
        printf("\t\t\t→");
    else
        printf("\t\t\t  ");
    printf("[学号]\n\n");
    while(c1!=NULL){
        if(c==c1->num+2)
            printf("\t\t\t→");
        else
            printf("\t\t\t  ");
        printf("[%s分数]\n\n",c1->course);
        c1=c1->co_next;
    }
    if(c==Course_count+3)
        printf("\t\t\t→");
    else
        printf("\t\t\t  ");
    puts("[返回]\n");
    printf("\n\t\t（提示：按方向键选择，按回车确定选择！）");
     
}
int update_student(){//修改学生记录
    int c=1,c1=1,i=0;
    long snum=0;
    char t[50];
    char ch=0;
    st *s1=NULL,*s2=NULL;
    sc *sc1=NULL;
    co *co1=NULL;
    num();
    if(S==NULL){
        printf("\n\n\t（提示：当前没设置学生记录，无法修改学生记录，请按任意键返回！）",c);
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
    printf("\n\n\t（提示：选择第%d条学生记录，按回车确定修改，按任意键取消选择！）",c);
    ch=getch();
    if(ch!='\r')
        return student__;
    fflush(stdin);
    ch=0;
    while(1){
        if(c1==Course_count+4)//超过学号+姓名+课程数
            c1=1;
        if(c1==0)
            c1=Course_count+3;//学号+姓名+课程数
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
    while(s1!=NULL){//让s2指向选中的学生记录
        if(s1->num==c){
            s2=s1;
            break;
        }
        s1=s1->st_next;
    }
    if(c1==1){//修改姓名
        printf("请输入学生姓名：");
        scanf("%s",t);
        for(i=0;i<6;i++){//异常处理 防止字符串字符溢出
            s2->name[i]=t[i];
        }
        s2->name[6]='\0';
        printf("\n（提示：修改学生记录成功，按任意键继续！）");
        getch();
        return student__;
    }
    if(c1==2){//修改学号
        while(1){
        printf("请输入学号：");
        scanf("%ld",&snum);
        if(snum<10000||snum>99999){
            printf("\n（提示：学号输入有误，学号范围为（10000-99999），按任意键重新输入！）");
            fflush(stdin);
            getch();
            printf("\n\n");
            continue;
        }
        if(check_snum(snum)&&s1->snum!=snum){//第二条件 修改相同学号 不提示重复
            printf("\n（提示：学号输入有误，学号为学生记录主码，不得重复，按任意键重新输入！）");
            fflush(stdin);
            getch();
            printf("\n\n");
            continue;
        }
        s1->snum=snum;
        break;
    }
        printf("\n（提示：修改学生记录成功，按任意键继续！）");
        getch();
        return student__;
    }
    sc1=s2->sc_next;
    co1=C;
    for(i=1;i<c1-2;i++){
        sc1=sc1->sc_next;//让sc1指向选中的学生记录课程
        co1=co1->co_next;//co1指向选中的课程记录
    }
    while(1){//每个课程成绩输入
            printf("请输入%s成绩：",co1->course);
            scanf("%f",&sc1->score);
            if(sc1->score>=0&&sc1->score<=100)
                break;
            printf("\n（提示：分数输入有误，分数范围为（0-100），按任意键重新输入！）");
            fflush(stdin);
            getch();
            printf("\n\n");
        }
    printf("\n（提示：修改学生记录成功，按任意键继续！）");
    getch();
    return student__;
 
}
void delete_student_interface(int c){//删除学生记录界面
    int i=0;
    co *c1=NULL;
    st *s1=NULL;
    sc *sc1=NULL;
    s1=S;
  //  system("cls");
    puts("\n\n\n\n\n");
    printf("\t _________________________________");
    for(i=0;i<Course_count;i++){//根据课程数绘制表格顶部横线
        printf("___________");
    }
    printf("\n");
    printf("\t|  姓名  |  学号  | 名次 | 平均分 |");
    c1=C;
    while(c1!=NULL){
        printf(" %-8s |",c1->course);//输出课程名次
        c1=c1->co_next;
    }
    printf("\n");
    printf("\t|---------------------------------");
    for(i=0;i<Course_count;i++){//根据课程数绘制表格中部横线
        printf("-----------");
    }
    printf("|\n");
    while(s1!=NULL){//输出学生记录
        if(c==s1->num)
            printf("      →");
        else
            printf("        ");
        printf("| %-6s | %-6d | %-4d | %-6.2f |",s1->name,s1->snum,s1->rank,s1->average);
        sc1=s1->sc_next;
        while(sc1!=NULL){//输课程成绩
            printf(" %-8.2f |",sc1->score);
            sc1=sc1->sc_next;
        }
        s1=s1->st_next;
        printf("\n");
    }
    printf("\t|_________________________________");
    for(i=0;i<Course_count;i++){//根据课程数绘制表格底部横线
        printf("___________");
    }
    printf("|\n");
    printf("\n\t（提示：按方向键选择，按回车确定选择！）");
}
int delete_student(){//删除学生记录
    int c=1,i=0;
    int snum=0;
    char ch=0;
    st *s1=NULL,*s2=NULL;
    num();
    if(S==NULL){
        printf("\n\n\t（提示：当前没有学生记录，无法删除学生记录，请按任意键返回！）",c);
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
    printf("\n\n\t（提示：选择第%d条学生记录，按回车确定删除，按任意键取消选择！）",c);
    ch=getch();
    if(ch!='\r')
        return student__;
    system("cls");
    s1=S;
    if(c==1){//删除第一条记录
        S=S->st_next;
        snum=s1->snum;
        free(s1);
        printf("\n（提示：删除学号为%d的学生记录成功，按任意键继续！）",snum);
        getch();
        return student__;
    }
    for(i=2;i<c;i++){
        s1=s1->st_next;//s1指向要删除的学生记录的前节点
    }
    s2=s1->st_next;//s2指向要删除的学生记录
    s1->st_next=s2->st_next;//绕过要删除的学生记录
    snum=s2->snum;
    free(s2);
    printf("\n（提示：删除学号为%d的学生记录成功，按任意键继续！）",snum);
    getch();
    return student__;
}
void select_student_interface(int c){//查询学生记录界面
    system("cls");
    printf("\n\n\n");
    if(c==1)
        printf("\t\t\t→");
    else
        printf("\t\t\t  ");
    printf("[按姓名查询]\n\n\n");
    if(c==2)
        printf("\t\t\t→");
    else
        printf("\t\t\t  ");
    printf("[按学号查询]\n\n\n");
    if(c==3)
        printf("\t\t\t→");
    else
        printf("\t\t\t  ");
    printf("[统计信息]\n\n\n");
    if(c==4)
        printf("\t\t\t→");
    else
        printf("\t\t\t  ");
    printf("[返回]\n\n\n");
}
void select_name(char name[]){//查询学生记录姓名
    int i=1,b=0;
    st *s1=NULL;
    co *c1=NULL;
    sc *sc1=NULL;
    s1=S;
    system("cls");
    printf("查询结果如下：\n\n\n");
    while(s1!=NULL){
        c1=C;
        if(!strcmp(s1->name,name)){
            b=1;
            printf("___________________\n");
            printf("学生记录%d\n",i++);
            printf("姓  名：%s\n",s1->name);
            printf("学  号：%ld\n",s1->snum);
            printf("名  次：%d\n",s1->rank);
            printf("平均分：%.2f\n",s1->average);
            sc1=s1->sc_next;
            while(sc1!=NULL&&c1!=NULL){
                printf("%s：",c1->course);
                printf("%.2f\n",sc1->score);
                c1=c1->co_next;
                sc1=sc1->sc_next;
            }
        printf("___________________\n");
        }
        s1=s1->st_next;
    }
    if(b==0)
        printf("（提示：找不到该学生记录！）");
    printf("\n\n（提示：按任意键继续！）");
    getch();
}
void select_snum(long snum){//查询学生记录学号
    int i=1,b=0;
    st *s1=NULL;
    co *c1=NULL;
    sc *sc1=NULL;
    s1=S;
    system("cls");
    printf("查询结果如下：\n\n\n");
    while(s1!=NULL){
        c1=C;
        if(s1->snum==snum){
            b=1;
            printf("___________________\n");
            printf("学生记录%d\n",i++);
            printf("姓  名：%s\n",s1->name);
            printf("学  号：%ld\n",s1->snum);
            printf("名  次：%d\n",s1->rank);
            printf("平均分：%.2f\n",s1->average);
            sc1=s1->sc_next;
            while(sc1!=NULL&&c1!=NULL){
                printf("%s：",c1->course);
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
        printf("（提示：找不到该学生记录！）");
    printf("\n\n（提示：按任意键继续！）");
    getch();
}
int statistics_student(){//统计学生记录信息
    int n,all=0,pass=0;
    float average=0;
    st *s1=NULL;
    sc *sc1=NULL;
    co *c1=NULL;
    s1=S;
    if(C==NULL||S==NULL){
        printf("（提示：没有学生记录或课程记录！）");
        printf("\n\n（提示：按任意键继续！）");
        return student__;
        getch();
    }
    printf("统计信息：\n\n\n");
    while(s1!=NULL){
        n=0;
        sc1=s1->sc_next;
        while(sc1!=NULL){
            if(sc1->score>=Pass_grade)//判断课程是否合格
                n++;
            if(n==Course_count)//所有课程合格
                pass++;
            sc1=sc1->sc_next;
        }
        average+=s1->average;
        all++;
        s1=s1->st_next;
    }
    average/=all;
    printf("所有学生人数为%d，所有课程合格人数为%d，所有课程平均分为%.2f。\n\n",all,pass,average);
    c1=C;
     while(c1!=NULL){
        s1=S;
        pass=0;
        average=0;
        while(s1!=NULL){
            sc1=s1->sc_next;
            n=c1->num;
            while(sc1->sc_next!=NULL&&--n)//找出课程
                sc1=sc1->sc_next;
            if(sc1->score>=Pass_grade)
                pass++;
            average+=sc1->score;
            s1=s1->st_next;
        }
        average/=all;
        printf("%s合格人数为%d，平均分为%.2f。\n\n",c1->course,pass,average);
        c1=c1->co_next;
    }
    printf("\n\n（提示：按任意键继续！）");
    getch();
    return student__;
}
 
int select_student(){//查询学生记录
    int c=1;
    long snum=0;
    char ch=0,name[7]={0};
    if(S==NULL){
        printf("\n\n\t（提示：当前没设置学生记录，无法查询，请按任意键返回！）");
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
        printf("请输入查询的学生记录姓名：");
        scanf("%s",name);
        select_name(name);
    }
    if(c==2){
        system("cls");
        printf("请输入查询的学生记录学号：");
        scanf("%d",&snum);
        select_snum(snum);
    }
    if(c==3){
        system("cls");
        statistics_student();
    }
    return student__;
}
void student_interface(int c){//学生记录界面
    int i=0;
    co *c1=NULL;
    st *s1=NULL;
    sc *sc1=NULL;
    s1=S;
    system("cls");
    puts("\n\n\n\n\n");
    printf("\t _________________________________");
    for(i=0;i<Course_count;i++){//根据课程数绘制表格顶部横线
        printf("___________");
    }
    printf("\n");
    printf("\t|  姓名  |  学号  | 名次 | 平均分 |");
    c1=C;
    while(c1!=NULL){
        printf(" %-8s |",c1->course);//输出课程名次
        c1=c1->co_next;
    }
    printf("\n");
    printf("\t|---------------------------------");
    for(i=0;i<Course_count;i++){//根据课程数绘制表格中部横线
        printf("-----------");
    }
    printf("|\n");
    while(s1!=NULL){//输出学生记录
        printf("\t| %-6s | %-6d | %-4d | %-6.2f |",s1->name,s1->snum,s1->rank,s1->average);
        sc1=s1->sc_next;
        while(sc1!=NULL){//输课程成绩
            printf(" %-8.2f |",sc1->score);
            sc1=sc1->sc_next;
        }
        s1=s1->st_next;
        printf("\n");
    }
    printf("\t|_________________________________");
    for(i=0;i<Course_count;i++){//根据课程数绘制表格底部横线
        printf("___________");
    }
    printf("|\n\n\t");
    if(c==1) 
        printf("→");
    else
        printf("  ");
    printf("[新建]  ");
    if(c==2)
        printf("→");
    else
        printf("  ");
    printf("[修改]  ");
    if(c==3)
        printf("→");
    else
        printf("  ");
    printf("[删除]  ");
    if(c==4)
        printf("→");
    else
        printf("  ");
    printf("[查询]  ");
    if(c==5)
        printf("→");
    else
        printf("  ");
    printf("[生成表格]  ");
    if(c==6)
        printf("→");
    else
        printf("  ");
    printf("[返回]  ");
    printf("\n\n\t（提示：按方向键选择，按回车确定选择！）");
}
int student(){//学生记录操作
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
void fprintf_course(){//把课程参数写入硬盘
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
void fscanf_course(){//把课程参数写入内存
    FILE *f;
    co *c1,*c2;
    c1=C;
    f=fopen("course.dat","rb");
    if(f==NULL){//第一种情况 无文件
        f=fopen("course.dat","wt");
        fclose(f);
        return;
    }
    if(fgetc(f)==EOF){//第二种情况 空文件
        fclose(f);
        return;
    }
    rewind(f);//fgetc(f)移动了f指针指向文件位置 让f复位
    while(!feof(f)){//第三种情况 非空文件
        if(C==NULL){//无头结点的第二种情况 空白记录
            C=(co *)malloc(sizeof(co));
            fscanf(f,"%d%s",&C->num,C->course);
            C->co_next=NULL;
            c1=C;
        }
        else{//无头结点的第二种情况 非空白记录 
            c2=(co *)malloc(sizeof(co));
            c1->co_next=c2;
            c1=c1->co_next;
            fscanf(f,"%d%s",&c2->num,&c2->course);
        }
    }
    c2->co_next=NULL;
    c2=C;//解决feof(f)函数会多读一行 free最后多余的内存单元
    while(c2->co_next!=NULL){
        c1=c2;
        c2=c2->co_next;
    }
    free(c2);
    c1->co_next=NULL;
}
void re__course_num(){//课程重新编号
    int i=1;
    co *c1=NULL;
    c1=C;
    while(c1!=NULL){
    c1->num=i;
    i++;
    c1=c1->co_next;
    }
}
int get_course_count(co *c1){//获取课程数
    int i=0;
    while(c1!=NULL){
        i++;
        c1=c1->co_next;
    }
    return i;
}
void course_interface(int c){//设置课程界面 参数决定界面
    co *c1=NULL;
    c1=C;
      system("cls");
      puts("\n\n\n\n");
      puts("\t\t\t   _________________");
      puts("\t\t\t  |课程编号|课程名称|");
      puts("\t\t\t  |-----------------|");
      while(c1!=NULL){
        printf("\t\t\t  |    %-4d|%-8s|\n",c1->num,c1->course);
        c1=c1->co_next;
    }
    puts("\t\t\t  |_________________|");
    printf("\n\t\t");
    if(c==1) 
        printf("→");
    else
        printf("  ");
    printf("[新建]  ");
    if(c==2)
        printf("→");
    else
        printf("  ");
    printf("[修改]  ");
    if(c==3)
        printf("→");
    else
        printf("  ");
    printf("[删除]  ");
    if(c==4)
        printf("→");
    else
        printf("  ");
    printf("[返回]  ");
    printf("\n\n\t\t（提示：按方向键选择，按回车确定选择！）");
}
int course(){//课程记录操作
    int c=1;
    char ch=0;
    Course_count=get_course_count(C);
    re__course_num();//重新排课程记录编号
    fprintf_course();//删除成功 写入硬盘
    fprintf_student();//删除成功 写入硬盘
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
int insert_course(){//新建课程记录
    int i=0;
    char t[50]={0};
    co* c1=NULL,*c2=NULL;
    system("cls");
    Course_count=get_course_count(C);
    if(C==NULL){
        C=(co *)malloc(sizeof(co));
        C->num=1;
          printf("请输入新建课程名称：");
        scanf("%s",t);
        for(i=0;i<8;i++){//异常处理 防止字符串字符溢出
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
        printf("请输入新建课程名称：");
        scanf("%s",t);
        for(i=0;i<8;i++){//异常处理 防止字符串字符溢出
            c2->course[i]=t[i];
        }
        c2->course[8]='\0';
        c2->co_next=NULL;
        c1->co_next=c2;
        insert_score(Course_count+1);
    }
    printf("\n\t\t（提示：新建课程记录成功，请按任意键返回！）");
    getch();
    return course__; 
}
void settings_interface(int c){//设置界面
    system("cls");
    puts("\n\n\n\n\n");
    puts("\t\t ________________________________________________ ");
    puts("\t\t|                                                |");
    if(c==1)
        printf("\t\t|               →");
    else
        printf("\t\t|                 ");
    puts("[课程]                         |");
    puts("\t\t|                                                |");
    if(c==2)
        printf("\t\t|               →");
    else
        printf("\t\t|                 ");
    puts("[学生记录排序]                 |");
    puts("\t\t|                                                |");
    if(c==3)
        printf("\t\t|               →");
    else
        printf("\t\t|                 ");
    puts("[合格分数]                     |");
    puts("\t\t|                                                |");
    if(c==4)
        printf("\t\t|               →");
    else
        printf("\t\t|                 ");
    puts("[密码]                         |");
    puts("\t\t|                                                |");
    if(c==5)
        printf("\t\t|               →");
    else
        printf("\t\t|                 ");
    puts("[返回]                         |");
    puts("\t\t|________________________________________________|");
    printf("\n\t\t（提示：按方向键选择，按回车确定选择！）");
}
int settings(){//设置
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
void update_course_interface(int c){//修改课程记录界面
    co *c1=NULL;
    c1=C;
    system("cls");
    puts("\n\n\n\n");
    puts("\t\t\t   _________________");
    puts("\t\t\t  |课程编号|课程名称|");
    puts("\t\t\t  |-----------------|");
    if(C==NULL)
        puts("\t\t\t  | 当前没设置课程！|");
    else{
        while(c1!=NULL){
            printf("\t\t\t");
            if(c==c1->num)
                printf("→");
            else
                printf("  ");
            printf("|    %-4d|%-8s|\n",c1->num,c1->course);
            c1=c1->co_next;
        }
    }
    puts("\t\t\t  |_________________|");
    printf("\n\n\t\t（提示：按方向键选择，按回车确定选择，按ESC取消返回！）");
}
int update_course(){//修改课程记录
    int c=1,i=0;
    char t[50]={0};
    co *c1=NULL;
    char ch=0;
    if(C==NULL){
        printf("\n\n\t\t（提示：当前没设置课程，无法修改课程记录，请按任意键返回！）",c);
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
    printf("\n\n\t\t（提示：选择课程编号为%d，按回车确定修改，按任意键取消选择！）",c);
    ch=getch();
    if(ch!='\r')
        return course__;
    c1=C;
    while(c1!=NULL){
        if(c1->num==c){
            system("cls");
            printf("选择课程编号为%d，请输入修改课程名称：",c);
            scanf("%s",t);
            for(i=0;i<8;i++){//异常处理 防止字符串字符溢出
                c1->course[i]=t[i];
            }
            c1->course[8]='\0';
            break;
        }
        c1=c1->co_next;
    }
    fprintf_course();//修改成功 写入硬盘
    printf("\n\t\t（提示：修改课程记录成功，请按任意键返回！）");
    getch();
    return course__;
}
void delete_course_interface(int c){//删除课程记录界面
    co *c1=NULL;
    c1=C;
    system("cls");
    puts("\n\n\n\n");
    puts("\t\t\t   _________________");
    puts("\t\t\t  |课程编号|课程名称|");
    puts("\t\t\t  |-----------------|");
    if(C==NULL)
        puts("\t\t\t  | 当前没设置课程！|");
    else{
        while(c1!=NULL){
            printf("\t\t\t");
            if(c==c1->num)
                printf("→");
            else
                printf("  ");
            printf("|    %-4d|%-8s|\n",c1->num,c1->course);
            c1=c1->co_next;
        }
    }
    puts("\t\t\t  |_________________|");
    puts("\n\n\t\t（提示：按方向键选择，按回车确定选择，按ESC取消返回！）");
}
int delete_course(){//删除课程记录
    int c=1;
    co *c1=NULL,*c2=NULL;
    char ch=0;
    if(C==NULL){
        printf("\n\n\t\t（提示：当前没设置课程，无法删除课程记录，请按任意键返回！）",c);
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
    printf("\n\t\t（提示：是否删除编号为%d的课程，按回车确定，按任意键取消！）",c);
    ch=getch();
    if(ch!='\r')
        return course__;
    c1=C;
    if(c==1){//删除课程记录第一种情况 删除第一个记录
        C=c1->co_next;
        free(c1);
    }
    else{
        while(c1!=NULL){//删除课程记录第二种情况 删除非第一个记录
            if(c==c1->num){
                c2->co_next=c1->co_next;
                free(c1);
                break;
            }
            c2=c1;
            c1=c1->co_next;
        }
    }
    delete_score(c);//删除课程对应的学记录并释放内存
    printf("\n\n\t\t（提示：删除编号为%d的课程记录成功，请按任意键返回！）",c);
    getch();
    return course__;
}
void fprintf_settings_parameter(){//设置参数写入硬盘
    FILE *f=NULL;
    f=fopen("settings.dat","wt");
    fprintf(f,"%d %d",Student_sortord,Pass_grade);
    fclose(f);
}
void fscanf_settings_parameter(){//设置参数写入内存
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
      printf("\n\n当前排序设置为：");
      Student_sortord?printf("按名次进行排序\n\n\n"):printf("按学号进行排序\n\n\n");
    if(c==1) 
        printf("→");
    else
        printf("  ");
    printf("[按学号进行排序]  ");
    if(c==2)
        printf("→");
    else
        printf("  ");
    printf("[按名次进行排序]  ");
    if(c==3)
        printf("→");
    else
        printf("  ");
    printf("[返回]  ");
    printf("\n\n\n（提示：按方向键选择，按回车确定选择，按Esc退出！）");
}
int student_sortord(){//学生记录排序方式
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
    printf("\n\n\n（提示：设置成功，按任意键继续！）");
    getch();
    return student_sortord__;
}
void pass_grade_interface(int c){
    system("cls");
      printf("\n\n当前合格分数为：");
      printf("%d\n\n\n",Pass_grade);
    if(c==1) 
        printf("→");
    else
        printf("  ");
    printf("[修改]  ");
    if(c==2)
        printf("→");
    else
        printf("  ");
    printf("[返回]  ");
    printf("\n\n\n（提示：按方向键选择，按回车确定选择，按Esc退出！）");
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
        printf("请输入设置更改合格分数：");
        scanf("%d",&Pass_grade);
        fprintf_settings_parameter();
        printf("\n\n\n（提示：设置成功，按任意键继续！）");
        getch();
        return pass_grade__;
    }
    if(c==2)
        return settings__;
    return 0;
}
void exit_program_interface(){//退出程序界面
    system("cls");
    puts("\n\n\n\n\n");
    puts("\t\t ________________________________________________ ");
    puts("\t\t|                                                |");
    puts("\t\t|                                                |");
    puts("\t\t|   学生成绩管理系统已退出！                     |");
    puts("\t\t|                                                |");
    puts("\t\t|                    请按任意键关闭窗口。        |");
    puts("\t\t|                                                |");
    puts("\t\t|________________________________________________|");
    puts("\n\n\n\n\n\n");
}
int exit_program(){//退出程序
    system("color 8f");
    exit_program_interface();
    exit(0);
}
void densification(char cleartext[]){//加密
    int i=0;
    char t[8]={0};
    for(i=0;i<8;i++){//加密方式1：每位加自己的元素下标
        t[i]=cleartext[i]+i;
    }
    for(i=0;i<8;i++){//加密方式2：所有元素倒序
        cleartext[i]=t[7-i];
    }
}
void decrypt(char ciphertext[]){//解密
    int i=0;
    char t[8]={0};
    for(i=0;i<8;i++){
        t[i]=ciphertext[7-i];//解开加密方式2
    }
    for(i=0;i<8;i++){
        ciphertext[i]=t[i]-i;//解开加密方式1
    }
}
void fprintf_password(char password[]){//密码加密写入硬盘
    FILE *p=NULL;
    int i=0;
    densification(password);
    p=fopen("password.dat","wt");
    for(i=0;i<8;i++){
        fprintf(p,"%d ", password[i]);//以ASCII将密文写入硬盘
    }
    fclose(p);
}
int proofread_password(char password1[],char password2[]){//校对两个密码
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
void fscanf_password(char password[]){//密码解密写入内存
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
        fscanf(p,"%d ",&password[i]);//以ASCII将明文写入内存
    }
    decrypt(password); 
    fclose(p);
}
int decide_password(){//检测是否有空密码
    char temp[8]={0};
    fscanf_password(Password);
    return proofread_password(Password,temp);
}
void scanf_password_interface(char password[]){//输入密码界面
    int i=0;
    system("cls");
    puts("\n\n\n\n\n");
    puts("\t\t ________________________________________________ ");
    puts("\t\t|                                                |");
    puts("\t\t|                                                |");
    puts("\t\t|                                                |");
    printf("\t\t|         请输入密码:");
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
    printf("\n\t\t（提示：按回车确定输入，按Esc退出学生成绩管理系统！）");
}
int scanf_password(){//输入密码
    int x=0;
    char ch=0,password[8]={0};//ASCII为0，代表空。
    while(1){
        if(x<=0)//防止密码数小于0
            x=0;
        if(x>=8)//防止密码数大于8
            x=8;
        scanf_password_interface(password);
        fflush(stdin);
        ch=getch();
        if(ch=='\r') 
            break;
        if(ch==Esc)
            return exit_program__;
        if(ch==Backspace&&x>0)//x>0防止数组越界 
            password[--x]=0;//删除第x-1个密码
        if(x==8)
            continue;
        if((ch>='0'&&ch<='9')||(ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
            password[x++]=ch;//储存第x个密码
        else
            continue;
}
    fscanf_password(Password);//将密码读到内存
    if(ch=='\r'){
        if(proofread_password(password,Password))//原始密码验证
            return welcome__;
        else{
            system("color cf");
            printf("\a\n\n\t\t（提示：密码输入错误，请按任意键返回！）\n");
            getch();
            return scanf_password__;
        }
    }
    return 2;
}
void settings_password_interface(int y,char password[][8]){//设置密码界面
    int i=0,j=0;
    FILE *p=NULL;
    p=fopen("password.dat","rb");//检测是否有原始密码
    if(p==NULL||decide_password()){
        j=1;//没有原始密码 不显示第0行
        y-=1;//没有第0行 不用输完打√
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
            printf("请输入原始密码:");
        if(j==1)
            printf("请输入修改密码:");
        if(j==2)
            printf("请输入确认密码:");
        for(i=0;i<8;i++){
            if(password[j][i]!=0)
                printf(" *");
            else
                printf(" _");
        }
        if(y>0){
            printf("√");
            y--;
        }
        else
            printf("  ");
        puts("        |");
    }
    puts("\t\t|                                                |");
    puts("\t\t|                                                |");
    puts("\t\t|________________________________________________|");
    printf("\n\t\t（提示：按回车确定输入，按Esc退出设置密码！）");
}
int settings_password(){//设置密码
    int x=0,y=0;
    char ch,password[3][8]={0};//ASCII为0 代表空 0行表示原始密码 1行表示修密码 3行表示确认密码
    FILE *p=NULL;
    p=fopen("password.dat","rb");//检测是否有原始密码
    if(p==NULL||decide_password())
        y=1;
    while(1){
        if(x<=0)//防止密码数小于8
            x=0;
        if(x>=8)//防止密码数大于8
            x=8;
        settings_password_interface(y,password);
        fflush(stdin);
        ch=getch();
        if(ch=='\r'){
            y++;
            x=0;//换行输入密码
        }
        if(ch=='\r'&&y==3)
            break;
        if(ch==Esc) 
            return settings__;
        if(ch==Backspace&&x>0)//x>0防止数组越界 
            password[y][--x]=0;//删除第y行第x-1个密码
        if(x==8)
            continue;
        if((ch>='0'&&ch<='9')||(ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
            password[y][x++]=ch;//储存第y行第x个密码
        else
            continue;
  }
    settings_password_interface(y,password);
    fflush(stdin);
    fscanf_password(Password);//将密码读到内存
    if(p==NULL||proofread_password(password[0],Password)){//原始密码验证
        if(proofread_password(password[1],password[2])){//修改密码与确认密码验证
            fprintf_password(password[1]);
            printf("\n\n\t\t（提示：密码修改成功，按任意键返回！）");
            getch();
        }
        else{
            printf("\n\n\t\t（提示：修改密码和确认密码输入不一致，按任意键返回！）");
            getch();
            return settings_password__;
        }
    }
    else{
        printf("\n\n\t\t（提示：原始密码输入错误，按任意键返回！）");
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
        printf("\n\n\t（提示：当前没学生记录，无法生成表格，请按任意键返回！）");
        getch();
        return student__;
    }
    f=fopen("student.html","wt");
    fprintf(f,"<table border=\"1\" bordercolor=\"#0066FF\" cellspacing=\"0\"  font-size:30px><tr bgcolor=\"#FF0000\"><td>姓名</td><td>学号</td><td>名次</td><td>平均分</td>");
    while(c1!=NULL){
        fprintf(f,"<td>%s</td>",c1->course);
        c1=c1->co_next;
    }
    fprintf(f,"</tr>");
    if(s1!=NULL){
        while(s1!=NULL){//学生信息写入硬盘
            fprintf(f,"<tr>");
            fprintf(f,"<td>%s</td><td>%ld</td><td>%d</td><td>%.2f</td>",s1->name,s1->snum,s1->rank,s1->average);
            sc1=s1->sc_next;
            while(sc1!=NULL){//课程成绩写入硬盘
                fprintf(f,"<td>%.2f</td>",sc1->score);
                sc1=sc1->sc_next;
            }
            fprintf(f,"</tr>");
            s1=s1->st_next;
        }
        fprintf(f,"</table>");
        fclose(f);
        printf("\n\n\t（提示：生成表格已打开，关闭表格继续操作！）");
        system("student.html");
    }
    return student__;
}
void about_interface(){//关于界面
    system("cls");
    puts("_________________________________________________");
    puts("3.0版本:");
    puts("\n1.修改学生记录的数据结构。");
    puts("\n2.各课程可以自定义名称和数量。 ");
    puts("\n3.增加了密码功能。");
    puts("\n4.把界面函数与功能函数分开。");
    puts("\n5.更改了一些界面。");
    puts("\n6.进一步优化代码。");
    puts("\n7.解决函数调用导致无法释放内存的问题。");
    puts("\n8.对函数分类，函数调用有序清晰。");
    puts("\n9.可将学生成绩表快速生成html文件。");
    puts("_________________________________________________");
    puts("\n\n\t\t\t        所有代码由空白写起。——计算机系网络1班LR");
    printf("\n\t（提示：按任意键返回！）");
}
int about(){//关于
    system("color 1f");
    about_interface();
    getch();
    return welcome__;
}
void function_call(int c){//控制函数的调用 解决内存无法释放问题
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
 
int main(){//来自brboy.cn，搬红砖的小男孩
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
    if(decide_password()){//检查是否没设置密码或为空密码
        function_call(0);
    }
    else{
        function_call(341);//提示密码
    }
    function_call(0);
    return 0;
}
//程序运行的过程都在funciton_call函数中调用，功能函数中的return，可以返回下一个调用的功能函数，界面//函数直接由功能函数调用。

