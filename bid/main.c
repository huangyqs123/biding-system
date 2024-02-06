#include <time.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>
struct good//物品信息
{
    int  num;                //编号
    char name[20];           //名称
    char type[20];           //类别
    int  newold;             //成新(1-10)
    char miaosu[50];        //描述
    char owner[20];          //拥有者
    int  price;              //起拍价
    int  year;               //截至拍卖时间年
    int  month;              //截至拍卖时间月
    int  day;                //截至拍卖时间日
    char buyer[20];          //当前最高出价者
    int  maxprice;           //当前最高出价
    int  result;             //拍卖是否结束
    struct good *next;       //下一结点指针
};

struct user//用户信息
{
    char id[16];             //账号(15位数字+字母)
    char code[16];           //密码(15位数字+字母)
    struct user *next;       //下一结点指针
};

struct list//拍卖
{
    char name[20];//拍卖物品
    char buyer[20];//买家
    int  price;//拍卖价格
    int  result;//拍卖结果
    struct list *next;//下一结点指针
};
time_t t;//时间函数
char nowid[20];
int count=0;
int MainSystem();//主界面
int PageMenu();//系统菜单页面
int ItemManage();//物品管理函数
int Compare(int year1,int month1,int day1,int year2,int month2,int day2);//判断拍卖截止时间是否合法或已经截止
struct tm *nowtime;//时间函数
struct good *List1;//保存物品的链表
struct user *List2;//保存用户信息的链表
struct list *List3;//保存拍卖信息的链表
struct user *UserRegister(struct user *head);
struct user *UserEnter (struct user *head);//账户登录
struct user *LoadUser(struct user *head);//将文件中用户信息读入链表
struct list *LoadList(struct list *head);//将文件中竞拍信息读入链表
struct good *LoadGood(struct good *head);//将文件中物品信息读入链表
struct user *WriteUser (struct user *head);//将用户信息链表写入文件中
struct list *WriteList(struct list *head);//将拍卖信息链表写入文件中
struct good *WriteGood(struct good *head);//将物品信息链表写入文件中
struct good *ChangeCode(struct user *head);//修改密码函数
struct good *AddGood(struct good *head);//增加我的物品
struct good *DelGood(struct good *head);//删除我的物品
struct good *ChangeGood(struct good *head);//修改我的物品
struct good *ViewMy(struct good *head);//查看我的物品
struct good *ViewAll(struct good *head);//查看所有物品b
struct good *ViewNum(struct good *head);//根据编号查看物品
struct good *ViewName(struct good *head);//根据名字查看物品
struct good *ViewType(struct good *head);//根据类型查看物品
struct good *SearchGood(struct good *head);//根据单词组合查看物品
struct good *GoodBid(struct good *head);//开始竞拍
struct list *ViewBid(struct list *head);//查看我的竞拍详情


int main()
{
  LoadList(List3);//将文件中竞拍信息读入链表
  LoadUser(List2);//将文件中用户信息读入链表
  LoadGood(List1);//将文件中物品信息读入链表
  MainSystem();//主界面
  WriteList(List3);//将拍卖信息链表写入文件中
  WriteUser(List2);//将用户信息链表写入文件中
  WriteGood(List1);//将物品信息链表写入文件中
}

int MainSystem()
{
system("title 物品竞拍管理");
   time(&t);//获取时间
   nowtime=localtime(&t);//转化为本地时间
 printf("**********************************************************************************\n");
 printf("*|                                                                              |*\n");
 printf("*|    @@    @@     @@@@@@@@     @@           @@           @@@@@@@@@@     @@     |*\n");
 printf("*|    @@    @@     @@@@@@@@     @@           @@           @@      @@     @@     |*\n");
 printf("*|    @@    @@     @@           @@           @@           @@      @@     @@     |*\n");
 printf("*|    @@@@@@@@     @@@@@@@@     @@           @@           @@      @@     @@     |*\n");
 printf("*|    @@@@@@@@     @@@@@@@@     @@           @@           @@      @@     @@     |*\n");
 printf("*|    @@    @@     @@           @@           @@           @@      @@     @@     |*\n");
 printf("*|    @@    @@     @@@@@@@@     @@@@@@@@     @@@@@@@@     @@      @@            |*\n");
 printf("*|    @@    @@     @@@@@@@@     @@@@@@@@     @@@@@@@@     @@@@@@@@@@     @@     |*\n");
 printf("*|                                                                              |*\n");
 printf("*|                                                                              |*\n");
 printf("*|                             欢迎使用竞拍管理系统                             |*\n");
 printf("*|                                                                              |*\n");
 printf("*|                              请选择你的操作 :                                |*\n");
 printf("*|                                                                              |*\n");
 printf("*|                              【1】 创建新账户                                |*\n");
 printf("*|                                                                              |*\n");
 printf("*|                              【2】 登录系统                                  |*\n");
 printf("*|                                                                              |*\n");
 printf("*|                              【3】 退出系统                                  |*\n");
 printf("*|                                                                              |*\n");
 printf("*|                              【4】 帮助                                      |*\n");
 printf("*|                                                                              |*\n");
 printf("*|                     当前系统时间：%d年%d月%d日%02d:%02d:%02d                       |*\n",nowtime->tm_year+1900,nowtime->tm_mon+1,nowtime->tm_mday,nowtime->tm_hour,nowtime->tm_min,nowtime->tm_sec);
 printf("*|                                                                              |*\n");
 printf("**********************************************************************************\n");
    printf("请输入你需要的功能编号：(无需按回车键)\n");
    char n;
    n=getch();
    while(n<'0'||n>'4')
    {
        printf("你的输入有误,请重新输入\n");
        n=getch();
    }
    if(n=='3')
    {
    system("cls");
    printf("**********************************************************************************\n");
    printf("*                                                                                *\n");
    printf("*                                                                                *\n");
    printf("*    @@@@@@@@@@@   @@      @@          @@          @@@      @@   @@      @@      *\n");
    printf("*    @@@@@@@@@@@   @@      @@         @@@@         @@@@     @@   @@    @@        *\n");
    printf("*        @@@       @@      @@        @@  @@        @@ @@    @@   @@  @@          *\n");
    printf("*        @@@       @@@@@@@@@@       @@    @@       @@  @@   @@   @@@             *\n");
    printf("*        @@@       @@@@@@@@@@      @@@@@@@@@@      @@   @@  @@   @@@             *\n");
    printf("*        @@@       @@      @@     @@        @@     @@    @@ @@   @@  @@          *\n");
    printf("*        @@@       @@      @@    @@          @@    @@     @@@@   @@    @@        *\n");
    printf("*        @@@       @@      @@   @@            @@   @@      @@@   @@      @@      *\n");
    printf("*                                                                                *\n");
    printf("*                                   感谢使用                                     *\n");
    printf("*                                                                                *\n");
    printf("*                                 我们下次再见                                   *\n");
    printf("*                                                                                *\n");
    printf("**********************************************************************************\n");
        return 0;
    }
    else if(n=='1')
    {
        system("cls");
        UserRegister(List2);
    }
    else if(n=='2')
    {
        system("cls");
        UserEnter(List2);
    }
    else if(n=='4')
    {
        system("cls");
        Help();
    }
}

struct user *UserRegister(struct user *head)
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                                  用 户 注 册                                  |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    struct user *p,*temp;
    temp=(struct user*)malloc(sizeof(struct user));
    char id[16],code1[16];
    while(p!=0)
    {
        int i=0;
        p=head;
        printf("请输入用户名：  (最多15位,空格无效!)\n");
        while((id[i]=getch())!='\r')
        {
            if(id[i]!='\b'&&id[i]!=' '&&(id[i]<='9'&&id[i]>='0'||id[i]<='z'&&id[i]>='a'||id[i]<='Z'&&id[i]>='A'))
            {
                if(i<15)
                {
                    printf("%c",id[i]);
                    i++;
                }
            }
            else if(id[i]=='\b'&&i>0)
            {
                printf("\b \b");
                i--;
            }
        }
        id[i]='\0';
        while(p!=0)
        {
            if(strcmp(id,p->id)==0)
                break;
            p=p->next;
        }
        if(p!=0)
            printf("该用户名已被使用\n");
        else
            printf("该用户名可用\n");
    }
        int j=0;
        printf("请输入密码：                (最多15位,空格无效!)\n");
        while((code1[j]=getch())!='\r')
        {
            if(code1[j]!='\b'&&code1[j]!=' '&&(code1[j]<='9'&&code1[j]>='0'||code1[j]<='z'&&code1[j]>='a'||code1[j]<='Z'&&code1[j]>='A'))
            {
                if(j<15)
                {
                    printf("*");
                    j++;
                }
            }
            else if(code1[j]=='\b'&&j>0)
            {
                printf("\b \b");
                j--;
            }
        }
        code1[j]='\0';
    strcpy(temp->id,id);
    strcpy(temp->code,code1);
    temp->next=NULL;
    p=List2;
    if(p==0)//如果链表为空直接写入
        List2=temp;
    else//不为空则接着写入
    {
        while((p->next)!=0)
            p=p->next;
        p->next=temp;
    }
    printf("\n你的账号已注册成功,请选择操作\n");
    printf("***********************************************************************************\n");
    printf("1:登录系统  2:退出系统\n");
    char n;
    n=getch();
    while(n<'0'||n>'2')
    {
        printf("你的输入有误,请重新输入\n");
        n=getch();
    }
    if(n=='2')
        return 0;
    else if(n=='1')
    {
    system("cls");
    UserEnter(List2);
    }
}

struct user *UserEnter(struct user *head)
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                                  用 户 登 录                                  |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    int flag=0;
    struct user *p;
    char id[16],code[16];
    while(flag==0)
    {
        printf("请输入你的用户名：          (最多15位,空格无效!)                                                      \n");
        int i=0;
        while((id[i]=getch())!='\r')
        {
            if(id[i]!='\b'&&id[i]!=' '&&(id[i]<='9'&&id[i]>='0'||id[i]<='z'&&id[i]>='a'||id[i]<='Z'&&id[i]>='A'))
            {
                if(i<15)
                {
                    printf("%c",id[i]);
                    i++;
                }
            }
            else if(id[i]=='\b'&&i>0)
            {
                printf("\b \b");
                i--;
            }
        }
        id[i]='\0';
        p=head;
        while(p!=0)
        {
            if(strcmp(id,p->id)==0)
            {
                flag=1;
                break;
            }
            p=p->next;
        }
        if(flag==0)
            printf("(该用户名不存在)\n");
    }
    while(strcmp(p->code,code)!=0)
    {
        printf("\n请输入你的密码：            (最多18位,空格无效!)                                                      \n");
        int i=0;
        while((code[i]=getch())!='\r')
        {
            if(code[i]!='\b'&&code[i]!=' '&&(code[i]<='9'&&code[i]>='0'||code[i]<='z'&&code[i]>='a'||code[i]<='Z'&&code[i]>='A'))
            {
                if(i<18)
                {
                    printf("*");
                    i++;
                }
            }
            else if(code[i]=='\b'&&i>0)
            {
                printf("\b \b");
                i--;
            }
        }
        code[i]='\0';
        if(strcmp(p->code,code)!=0)
            printf("(输入密码错误请重新输入)");
    }
    strcpy(nowid,id);
    printf("\n登录成功,请按任意键进入系统菜单                                                 \n");
    printf("***********************************************************************************\n");
    getch();
    system("cls");
    PageMenu();
}

int PageMenu()
{
    printf("**********************************************************************************\n");
    printf("                                  尊敬的%s用户\n",nowid);
    printf("******************************欢迎来到系统菜单界面********************************\n");
    printf("*|                                                                              |*\n");
    printf("*|                                【0】退出登录                                 |*\n");
    printf("*|                                                                              |*\n");
    printf("*|                                【1】物品管理                                 |*\n");
    printf("*|                                                                              |*\n");
    printf("*|                                【2】修改密码                                 |*\n");
    printf("*|                                                                              |*\n");
    printf("**********************************************************************************\n");
    printf("请输入你需要的功能编号\n");
    char n;
    n=getch();
    while(n<'0'||n>'2')
    {
        printf("你的输入有误,请重新输入\n");
        n=getch();
    }
    if(n=='0')
    {
        system("cls");
        MainSystem();
    }
    else if(n=='1')
    {
        system("cls");
        ItemManage();
    }
    else if(n=='2')
    {
        system("cls");
        ChangeCode(List2);
    }

}
int Help()
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                             本系统由黄彦乔独家开发                            |*\n");
    printf("*|                   如果你在使用中遇到问题或者想获取系统的最新版本              |*\n");
    printf("*|                       以致电18126842292或添加客服qq2261645155                 |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                                  系统版本V1.0.0                               |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    printf("请按任意键返回系统主页\n");
    getch();
    system("cls");
    MainSystem();
}

struct good *ChangeCode(struct user *head)
{

    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                                  密 码 修 改                                  |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    int i;
    char oldcode[16],newcode[16];
    struct user *p;
    p=head;
    while(p!=0)
    {
        if(strcmp(p->id,nowid)==0)
        {
            while(strcmp(p->code,oldcode)!=0)
            {
                i=0;
                printf("请正确输入原密码：          (最多15位,空格无效!)\n");
                while((oldcode[i]=getch())!='\r')
                {
                    if(oldcode[i]!='\b'&&oldcode[i]!=' '&&(oldcode[i]<='9'&&oldcode[i]>='0'||oldcode[i]<='z'&&oldcode[i]>='a'||oldcode[i]<='Z'&&oldcode[i]>='A'))
                    {
                        if(i<15)
                        {
                            printf("*");
                            i++;
                        }
                    }
                    else if(oldcode[i]=='\b'&&i>0)
                    {
                        printf("\b \b");
                        i--;
                    }
                }
                oldcode[i]='\0';
                printf("\n");
                if(strcmp(p->code,oldcode)!=0)
                    printf("输入原密码错误请重新输入\n");
            }
            i=0;
            printf("请输入新密码：              (最多15位,空格无效!)\n");
            while((newcode[i]=getch())!='\r')
            {
                if(newcode[i]!='\b'&&newcode[i]!=' '&&(newcode[i]<='9'&&newcode[i]>='0'||newcode[i]<='z'&&newcode[i]>='a'||newcode[i]<='Z'&&newcode[i]>='A'))
                {
                    if(i<15)
                    {
                        printf("*");
                        i++;
                    }
                }
                else if(newcode[i]=='\b'&&i>0)
                {
                    printf("\b \b");
                    i--;
                }
            }
            newcode[i]='\0';
            strcpy(p->code,newcode);
            break;
        }
        p=p->next;
    }
    printf("\n密码修改成功\n");
    printf("请按任意键返回重新登陆\n");
    getch();
    system("cls");
    MainSystem();
}

int ItemManage()
{
    printf("***********************************************************************************\n");
    printf("                                 尊敬的%s用户\n",nowid);
    printf("*********************************************************************************|*\n");
    printf("*|                                                                               |*\n");
    printf("*|                              欢迎来到物品管理界面                             |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             【x】返回上一级菜单                               |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             【y】查看我的竞拍详情                             |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             【1】增加物品信息                                 |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             【2】删除物品信息                                 |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             【3】修改物品信息                                 |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             【4】查看自己物品信息                             |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             【5】查看所有物品信息                             |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             【6】按编号查看物品信息                           |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             【7】按名字查看物品信息                           |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             【8】按类别查看物品信息                           |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             【9】单词组合查询物品信息                         |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             【0】开始竞拍                                     |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    printf("请输入你需要的功能编号\n");
    char n;
    n=getch();
    while(n<'0'||n>'9'&&n!='x'&&n!='y')
    {
        printf("你的输入有误,请重新输入\n");
        n=getch();
    }
    if(n=='x')
    {
        system("cls");
        PageMenu();
    }
    else if(n=='y')
    {
        system("cls");
        ViewBid(List3);
    }
    else if(n=='1')
    {
        system("cls");
        AddGood(List1);
    }
    else if(n=='2')
    {
        system("cls");
        DelGood(List1);
    }
    else if(n=='3')
    {
        system("cls");
        ChangeGood(List1);
    }
    else if(n=='4')
    {
        system("cls");
        ViewMy(List1);
    }
    else if(n=='5')
    {
        system("cls");
        ViewAll(List1);
    }
    else if(n=='6')
    {
        system("cls");
        ViewNum(List1);
    }
    else if(n=='7')
    {
        system("cls");
        ViewName(List1);
    }
    else if(n=='8')
    {
        system("cls");
        ViewType(List3);
    }
    else if(n=='9')
    {
        system("cls");
     SearchGood(List1);
    }
    else if(n=='0')
    {
        system("cls");
        GoodBid(List1);
    }
}

struct good *AddGood(struct good *head)
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                                  添 加 物 品                                  |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    struct good *temp;
    temp=(struct good*)malloc(sizeof(struct good));
    temp->next=NULL;
    temp->num=++count;//下一次添加物品时编号+1
    printf("请输入物品的名称\n");
    scanf("%s",temp->name);
    printf("请输入物品的类别\n");
    scanf("%s",temp->type);
    printf("请输入你要增加物品的成新(请输入1-10)\n");
    while(temp->newold<1||temp->newold>10)
    {
        scanf("%d",&temp->newold);
        if(temp->newold<1||temp->newold>10)
            printf("你的输入有误,请重新输入\n");
    }
    printf("请输入你要增加的物品描述\n");
    scanf("%s",temp->miaosu);
    printf("请输入你要增加的物品起拍价\n");
    scanf("%d",&temp->price);
    while(temp->price<=0)
    {
      printf("本系统不支持白送或倒贴，请重新输入\n");
      scanf("%d",&temp->price);
    }
    while(Compare(temp->year,temp->month,temp->day,nowtime->tm_year+1900,nowtime->tm_mon+1,nowtime->tm_mday)==1)
    {
        printf("请输入你要增加的物品的物品竞拍截止时间(格式:xxxx xx xx)年 月 日\n");
        scanf("%d%d%d",&temp->year,&temp->month,&temp->day);
        if(Compare(temp->year,temp->month,temp->day,nowtime->tm_year+1900,nowtime->tm_mon+1,nowtime->tm_mday)==1)
            printf("你输入的截止竞拍时间不合理");
    }
    strcpy(temp->owner,nowid);
    strcpy(temp->buyer,nowid);
    temp->maxprice=temp->price;
    temp->result=0;
    struct good *p;
    p=List1;
    if(p==0)
        List1=temp;
    else
    {
        while(p->next!=0)
            p=p->next;
        p->next=temp;
    }
    printf("**********************************增加物品成功**************************************\n");
    fflush(stdin);//清空缓冲区以不影响后面数据读取
    printf("请按任意键返回物品管理界面(请勿直接关闭程序否则会导致物品信息无法保存)\n");
    getch();
    system("cls");
    ItemManage();
}

struct good *DelGood(struct good *head)
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                                  删 除 物 品                                  |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    printf("请输入你要删除的物品编号\n");
    int n;
    scanf("%d",&n);
    struct good *p1,*p2;
    p1=List1;
    while(p1!=0)
    {
        if(p1->num==n)
        {
            if(strcmp(p1->owner,nowid)!=0)
            {
                printf("不能删除他人的物品\n");
                break;
            }
            if(p1==List1)//如果是链表头
            {
                List1=p1->next;
                p2=List1;
                count--;
            }
            else
            {
                p2->next=p1->next;
                p2=p2->next;
                count--;
            }
            free(p1);
            break;
        }
        p2=p1,p1=p1->next;
    }
    if(p1==0)
        printf("没有找到你需要删除的物品\n");
    else if(strcmp(p1->owner,nowid)==0)
    {
        while(p2!=0)
        {
            p2->num--;
            p2=p2->next;
        }
    printf("**********************************删除物品成功**************************************\n");
    }
    fflush(stdin);
    printf("请按任意键返回物品管理界面\n");
    getch();
    system("cls");
    ItemManage();
}

struct good *ChangeGood(struct good *head)
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                                  修 改 物 品                                  |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    printf("请输入你要修改的物品编号\n");
    int n;
    scanf("%d",&n);
    struct good *p;
    p=List1;
    while(p!=0)
    {
        if(p->num==n)
        {
            if(strcmp(p->owner,nowid))
            {
                printf("不能修改别人的物品\n");
                break;
            }
            printf("请输入你要修改的物品起拍价\n");
            scanf("%d",&p->price);
                while(p->price<=0)
            {
            printf("本系统不支持白送或倒贴，请重新输入\n");
            scanf("%d",&p->price);
            }
            printf("请输入你要修改物品的成色(1-10成新)\n");
            scanf("%d",&p->newold);
            while(p->newold<1||p->newold>10)
            {
                printf("你的输入有误,请重新输入\n");
                scanf("%d",&p->newold);
            }
            printf("请输入你要修改物品的竞拍截止时间(xxxx xx xx)年 月 日\n");
            scanf("%d%d%d",&p->year,&p->month,&p->day);
            while(Compare(p->year,p->month,p->day,nowtime->tm_year+1900,nowtime->tm_mon+1,nowtime->tm_mday)==1)
            {
                printf("你输入的截止竞拍时间不合理,请重新输入\n");
                scanf("%d%d%d",&p->year,&p->month,&p->day);
            }
            printf("请输入你要修改的物品描述\n");
            scanf("%s",p->miaosu);
            break;
        }
        p=p->next;
    }
    if(p==0)
        printf("没有找到你需要修改的物品\n");
    else
    printf("**********************************修改物品成功**************************************\n");
    fflush(stdin);
    printf("请按任意键返回物品管理界面\n");
    getch();
    system("cls");
    ItemManage();
}

int Compare(int year1,int month1,int day1,int year2,int month2,int day2)//year1为截止拍卖时间，year2为现在时间
{
    if(year1<0||month1<1||month1>12||day1<1||day1>31)
        return 1;
    if(month1==4||month1==6||month1==9||month1==11)
        if(day1==31)
            return 1;
    if(month1==2)
    {
        if((year1%4==0&&year1%100!=0)||year1%400==0)
        {
            if(day1==31||day1==30)
                return 1;
        }
        else if(day1==31||day1==30||day1==29)
            return 1;
    }
    if(year1<year2||(year1==year2&&month1<month2)||(year1==year2&&month1==month2&&day1<day2))
        return 1;
    return 0;
}

struct good *ViewMy(struct good *head)
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                              个 人 物 品 清 单                                |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    int flag=0;
    struct good *p;
    p=head;
    while(p!=0)
    {
        if(strcmp(p->owner,nowid)==0)
        {
            if(p->result==0)
               {
               printf("编号:%-2d\n名字:%-10s\n类型:%-10s\n成新:%-2d成新\n描述:%-50s\n拥有者:%-10s\n起拍价:%-4d\n拍卖时间截止:%d:%d:%d\n当前拍卖者:%-10s\n当前拍卖价:%-4d 拍卖进行\n\n\n"
               ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
               }
            if(p->result==1)
               {printf("编号:%-2d 名字:%-10s 类型:%-10s 成新:%-2d成新\n描述:%-50s\n拥有者:%-10s\n起拍价:%-4d\n拍卖时间截止:%d:%d:%d\n当前拍卖者:%-10s\n当前拍卖价:%-4d 拍卖结束\n\n\n"
               ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
               }
               flag=1;
        }
        p=p->next;
    }
    if(flag==0)
    printf("你还没有物品哦\n");
    fflush(stdin);
    printf("请按任意键返回竞拍管理界面\n");
    getch();
    system("cls");
    ItemManage();
}

struct good *ViewAll(struct good *head)
{

    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                              所 有 物 品 清 单                                |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    struct good *p;
    p=head;
    if(p==0)
        printf("此系统还没有物品\n");
    while(p!=0)
    {
        if(p->result==0)
            printf("编号:%-2d 名字:%-10s 类型:%-10s 成新:%-2d成新\n描述:%-50s\n拥有者:%-10s\n起拍价:%-4d\n拍卖时间截止:%d:%d:%d\n当前拍卖者:%-10s\n当前拍卖价:%-4d 拍卖进行\n\n\n"
                   ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
        if(p->result==1)
            printf("编号:%-2d 名字:%-10s 类型:%-10s 成新:%-2d成新\n描述:%-50s\n拥有者:%-10s\n起拍价:%-4d\n拍卖时间截止:%d:%d:%d\n当前拍卖者:%-10s\n当前拍卖价:%-4d 拍卖结束\n\n\n"
                   ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
        p=p->next;
    }
    fflush(stdin);
    printf("请按任意键返回竞拍管理界面\n");
    getch();
    system("cls");
    ItemManage();
}

struct good *ViewNum(struct good *head)
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                          输 入 编 号 查 看 物 品                              |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    printf("%请输入你需要查看的物品信息的编号\n");
    int n;
    scanf("%d",&n);
    int flag=0;
    struct good *p;
    p=head;
    while(p!=0)
    {
        if(p->num==n)
        {
            if(p->result==0)
                printf("编号:%-2d 名字:%-10s 类型:%-10s 成新:%-2d成新\n描述:%-50s\n拥有者:%-10s\n起拍价:%-4d\n拍卖时间截止:%d:%d:%d\n当前拍卖者:%-10s\n当前拍卖价:%-4d 拍卖进行\n\n\n"
                       ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
            if(p->result==1)
                printf("编号:%-2d 名字:%-10s 类型:%-10s 成新:%-2d成新\n描述:%-50s\n拥有者:%-10s\n起拍价:%-4d\n拍卖时间截止:%d:%d:%d\n当前拍卖者:%-10s\n当前拍卖价:%-4d 拍卖结束\n\n\n"
                       ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
            flag=1;
        }
        p=p->next;
    }
    if(flag==0)
    printf("没有找到你需要的物品\n");
    fflush(stdin);
    printf("请按任意键返回物品管理界面\n");
    getch();
    system("cls");
    ItemManage();
}

struct good *ViewName(struct good *head)
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                          输 入 名 字 查 看 物 品                              |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    printf("%请输入你需要查看的物品信息的名字\n");
    char n[20];
    scanf("%s",&n);
    int flag=0;
    struct good *p;
    p=head;
    while(p!=0)
    {
        if(strcmp(p->name,n)==0)
        {
            if(p->result==0)
                printf("编号:%-2d 名字:%-10s 类型:%-10s 成新:%-2d成新\n描述:%-50s\n拥有者:%-10s\n起拍价:%-4d\n拍卖时间截止:%d:%d:%d\n当前拍卖者:%-10s\n当前拍卖价:%-4d 拍卖进行\n\n\n"
                       ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
            if(p->result==1)
                printf("编号:%-2d 名字:%-10s 类型:%-10s 成新:%-2d成新\n描述:%-50s\n拥有者:%-10s\n起拍价:%-4d\n拍卖时间截止:%d:%d:%d\n当前拍卖者:%-10s\n当前拍卖价:%-4d 拍卖结束\n\n\n"
                       ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
            flag=1;
        }
        p=p->next;
    }
    if(flag==0)
        printf("没有找到你需要的物品\n");
    fflush(stdin);
    printf("请按任意键返回竞拍管理界面\n");
    getch();
    system("cls");
    ItemManage();
}

struct good *ViewType(struct good *head)
{

    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                          输 入 类 型 查 看 物 品                              |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    printf("%请输入你需要查看的物品信息的类型\n");
    char n[20];
    scanf("%s",&n);
    int flag=0;
    struct good *p;
    p=head;
    while(p!=0)
    {
        if(strcmp(p->type,n)==0)
        {
            if(p->result==0)
                printf("编号:%-2d 名字:%-10s 类型:%-10s 成新:%-2d成新\n描述:%-50s\n拥有者:%-10s\n起拍价:%-4d\n拍卖时间截止:%d:%d:%d\n当前拍卖者:%-10s\n当前拍卖价:%-4d 拍卖进行\n\n"
                       ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
            if(p->result==1)
                printf("编号:%-2d 名字:%-10s 类型:%-10s 成新:%-2d成新\n描述:%-50s\n拥有者:%-10s\n起拍价:%-4d\n拍卖时间截止:%d:%d:%d\n当前拍卖者:%-10s\n当前拍卖价:%-4d 拍卖结束\n\n"
                       ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
            flag=1;
        }
        p=p->next;
    }
    if(flag==0)
        printf("该系统还没有此类型的物品\n");
    fflush(stdin);
    printf("请按任意键返回竞拍管理界面\n");
    getch();
    system("cls");
    ItemManage();
}

struct good *GoodBid(struct good *head)
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                               开 始 出 价 竞 拍                               |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    printf("请输入你要出价的物品编号\n");
    int n,maxprice=0;
    scanf("%d",&n);
    struct good *p;
    p=head;
    while(p!=0)
    {
        if(p->num==n)
        {
            if(strcmp(p->owner,nowid)==0)
            {
                printf("不能竞拍自己的物品！\n");
                break;
            }
            if(p->result==1)
            {
                printf("该物品已截止竞拍，看看其他商品吧！\n");
                break;
            }
            while(maxprice<=p->maxprice)
            {
                printf("请输入你的竞拍价\n");
                scanf("%d",&maxprice);
                if(maxprice<=p->maxprice)
                    printf("不能低于当前最高价,请重新输入！\n");
            }
            strcpy(p->buyer,nowid);
            p->maxprice=maxprice;
            struct list *temp;
            temp=(struct list*)malloc(sizeof(struct list));
            temp->next=NULL;
            strcpy(temp->name,p->name);
            strcpy(temp->buyer,p->buyer);
            temp->price=p->maxprice;
            temp->result=0;
            struct list *p;
            p=List3;
            if(p==0)
                List3=temp;
            else
            {
                while(p->next!=0)
                    p=p->next;
                p->next=temp;

            }
            break;
        }
        p=p->next;
    }
    if(p==0)
        printf("没有找到你要出价的物品\n");
    else if(strcmp(p->owner,nowid)&&p->result!=1)
        printf("出价成功\n");
    fflush(stdin);
    printf("请按任意键返回物品管理界面\n");
    getch();
    system("cls");
    ItemManage();
}

struct list *ViewBid(struct list *head)
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                                 竞 拍 详 情                                   |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    int flag=0;
    struct list *p;
    p=List3;
    while(p!=0)
    {
        if(strcmp(p->buyer,nowid)==0&&p->result==0)
        {
            printf("物品名字：%s 竞拍价格：%d 竞拍进行\n\n",p->name,p->price);
            flag=1;
        }
        if(strcmp(p->buyer,nowid)==0&&p->result==1)
        {
            printf("物品名字：%s 成交价格：%d 竞拍成功\n\n",p->name,p->price);
            flag=1;
        }
        if(strcmp(p->buyer,nowid)==0&&p->result==2)
        {
            printf("物品名字：%s 竞拍价格：%d 竞拍失败\n\n",p->name,p->price);
            flag=1;
        }
        p=p->next;
    }
    if(flag==0)
        printf("你还没有竞拍物品\n");
    fflush(stdin);
    printf("请按任意键返回竞拍管理界面\n");
    getch();
    system("cls");
    ItemManage();
}

struct good *SearchGood(struct good *head)
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                          输 入 关 键 字 查 看 物 品                           |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    printf("%请输入你需要查看的物品信息的名字\n");
    char n[20];
    scanf("%s",&n);
    int flag=0;
    struct good *p;
    p=head;
    while(p!=0)
    {
        if(strstr(p->name,n)!=NULL)
        {
            if(p->result==0)
                printf("编号:%-2d 名字:%-10s 类型:%-10s 成新:%-2d成新\n描述:%-50s\n拥有者:%-10s\n起拍价:%-4d\n拍卖时间截止:%d:%d:%d\n当前拍卖者:%-10s\n当前拍卖价:%-4d 拍卖进行\n\n\n"
                       ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
            if(p->result==1)
                printf("编号:%-2d 名字:%-10s 类型:%-10s 成新:%-2d成新\n描述:%-50s\n拥有者:%-10s\n起拍价:%-4d\n拍卖时间截止:%d:%d:%d\n当前拍卖者:%-10s\n当前拍卖价:%-4d 拍卖结束\n\n\n"
                       ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
            flag=1;
        }
        p=p->next;
    }
    if(flag==0)
        printf("没有找到你需要的物品\n");
    fflush(stdin);
    printf("请按任意键返回竞拍管理界面\n");
    getch();
    system("cls");
    ItemManage();
}

struct user *LoadUser(struct user *head)
{
    FILE *fp;
    fp=fopen("Data_User.txt","r");
    if(fp==0)
    {
        printf("打开文件错误\n");
        return 0;
    }
    char id[16],code[16];
    struct user *head0=NULL,*tail,*p;
    while(fscanf(fp,"%s%s",id,code)!=EOF)
    {
        p=(struct user*)malloc(sizeof(struct user));
        p->next=NULL;
        strcpy(p->id,id);
        strcpy(p->code,code);
        if(head0==0)
            head0=p;
        else
            tail->next=p;
        tail=p;
    }
    fclose(fp);
    List2=head0;
}

struct user *WriteUser(struct user *head)
{
    FILE *fp;
    fp=fopen("Data_User.txt","w");
    if(fp==0)
    {
        printf("打开文件失败");
        return 0;
    }
    struct user *p;
    p=head;
    while(p!=0)
    {
        fprintf(fp,"%-16s",p->id);
        fprintf(fp,"%-16s\n",p->code);
        p=p->next;
    }
}

struct list *LoadList(struct list *head)
{
    FILE*fp=fopen("Data_List.txt","r");
    if(!fp)
    {
        printf("打开文件错误\n");
        return 0;
    }
    char name[16],buyer[16];
    int price,result;
    struct list *head0=NULL,*tail,*p;
    while(fscanf(fp,"%s%s%d%d",name,buyer,&price,&result)!=EOF)
    {
        p=(struct list*)malloc(sizeof(struct list));
        p->next=NULL;
        strcpy(p->name,name);
        strcpy(p->buyer,buyer);
        p->price=price;
        p->result=result;

        if(head0==0)
            head0=p;
        else
            tail->next=p;
            tail=p;
    }
    fclose(fp);
    List3=head0;
}

struct list *WriteList(struct list *head)
{
    FILE *fp=fopen("Data_List.txt","w");
    if(fp==0)
    {
        printf("打开文件失败");
        return 0;
    }
    struct list *p;
    p=head;
    while(p!=0)
    {
        fprintf(fp,"%-16s",p->name);
        fprintf(fp,"%-16s",p->buyer);
        fprintf(fp,"%-5d",p->price);
        fprintf(fp,"%-5d\n",p->result);
        p=p->next;
    }
    fclose(fp);
}

struct good *LoadGood(struct good *head)
{
    time(&t);
    nowtime=localtime(&t);
    FILE*fp=fopen("Data_Good.txt","r");
    if(fp==0)
    {
        printf("打开文件错误\n");
        return 0;
    }
    int num,newold,price,year,month,day,maxprice,result;
    char name[20],type[20],miaosu[50],owner[20],buyer[20];
    struct good *head0=NULL,*tail,*p;
    while(fscanf(fp,"%d%s%s%d%s%s%d%d%d%d%s%d%d\n",&num,name,type,&newold,miaosu,owner,&price,&year,&month,&day,buyer,&maxprice,&result)!=EOF)
    {
        p=(struct good*)malloc(sizeof(struct good));
        strcpy(p->name,name);
        strcpy(p->type,type);
        strcpy(p->miaosu,miaosu);
        strcpy(p->owner,owner);
        strcpy(p->buyer,buyer);
        p->next=NULL;
        p->num=num;
        p->newold=newold;
        p->price=price;
        p->year=year;
        p->month=month;
        p->day=day;
        p->maxprice=maxprice;
        p->result=Compare(year,month,day,nowtime->tm_year+1900,nowtime->tm_mon+1,nowtime->tm_mday);
        if(p->result==1)
        {
            struct list *p1;
            p1=List3;
            while(p1!=0)
            {
                if(strcmp(p1->name,p->name)==0&&strcmp(p1->buyer,p->buyer)==0)//查看物品状态
                    p1->result=1;
                if(strcmp(p1->name,p->name)==0&&strcmp(p1->buyer,p->buyer)!=0)//物品已卖出
                    p1->result=2;
                p1=p1->next;
            }
        }
        count++;
        if(head0==0)
            head0=p;
        else
            tail->next=p;
        tail=p;
    }
    fclose(fp);
    List1=head0;
}

struct good *WriteGood(struct good *head)
{
    FILE *fp=fopen("Data_Good.txt","w");
    if(fp==0)
    {
        printf("打开文件失败");
        return 0;
    }
    struct good *p;
    p=head;
    while(p!=0)
    {
        fprintf(fp,"%-2d",p->num);
        fprintf(fp,"%-15s",p->name);
        fprintf(fp,"%-15s",p->type);
        fprintf(fp,"%-2d",p->newold);
        fprintf(fp,"%-50s",p->miaosu);
        fprintf(fp,"%-20s",p->owner);
        fprintf(fp,"%-5d",p->price);
        fprintf(fp,"%-5d%-3d%-3d%",p->year,p->month,p->day);
        fprintf(fp,"%-20s",p->buyer);
        fprintf(fp,"%-8d",p->maxprice);
        fprintf(fp,"%-2d\n",p->result);
        p=p->next;
    }
}
