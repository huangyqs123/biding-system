#include <time.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>
struct good//��Ʒ��Ϣ
{
    int  num;                //���
    char name[20];           //����
    char type[20];           //���
    int  newold;             //����(1-10)
    char miaosu[50];        //����
    char owner[20];          //ӵ����
    int  price;              //���ļ�
    int  year;               //��������ʱ����
    int  month;              //��������ʱ����
    int  day;                //��������ʱ����
    char buyer[20];          //��ǰ��߳�����
    int  maxprice;           //��ǰ��߳���
    int  result;             //�����Ƿ����
    struct good *next;       //��һ���ָ��
};

struct user//�û���Ϣ
{
    char id[16];             //�˺�(15λ����+��ĸ)
    char code[16];           //����(15λ����+��ĸ)
    struct user *next;       //��һ���ָ��
};

struct list//����
{
    char name[20];//������Ʒ
    char buyer[20];//���
    int  price;//�����۸�
    int  result;//�������
    struct list *next;//��һ���ָ��
};
time_t t;//ʱ�亯��
char nowid[20];
int count=0;
int MainSystem();//������
int PageMenu();//ϵͳ�˵�ҳ��
int ItemManage();//��Ʒ������
int Compare(int year1,int month1,int day1,int year2,int month2,int day2);//�ж�������ֹʱ���Ƿ�Ϸ����Ѿ���ֹ
struct tm *nowtime;//ʱ�亯��
struct good *List1;//������Ʒ������
struct user *List2;//�����û���Ϣ������
struct list *List3;//����������Ϣ������
struct user *UserRegister(struct user *head);
struct user *UserEnter (struct user *head);//�˻���¼
struct user *LoadUser(struct user *head);//���ļ����û���Ϣ��������
struct list *LoadList(struct list *head);//���ļ��о�����Ϣ��������
struct good *LoadGood(struct good *head);//���ļ�����Ʒ��Ϣ��������
struct user *WriteUser (struct user *head);//���û���Ϣ����д���ļ���
struct list *WriteList(struct list *head);//��������Ϣ����д���ļ���
struct good *WriteGood(struct good *head);//����Ʒ��Ϣ����д���ļ���
struct good *ChangeCode(struct user *head);//�޸����뺯��
struct good *AddGood(struct good *head);//�����ҵ���Ʒ
struct good *DelGood(struct good *head);//ɾ���ҵ���Ʒ
struct good *ChangeGood(struct good *head);//�޸��ҵ���Ʒ
struct good *ViewMy(struct good *head);//�鿴�ҵ���Ʒ
struct good *ViewAll(struct good *head);//�鿴������Ʒb
struct good *ViewNum(struct good *head);//���ݱ�Ų鿴��Ʒ
struct good *ViewName(struct good *head);//�������ֲ鿴��Ʒ
struct good *ViewType(struct good *head);//�������Ͳ鿴��Ʒ
struct good *SearchGood(struct good *head);//���ݵ�����ϲ鿴��Ʒ
struct good *GoodBid(struct good *head);//��ʼ����
struct list *ViewBid(struct list *head);//�鿴�ҵľ�������


int main()
{
  LoadList(List3);//���ļ��о�����Ϣ��������
  LoadUser(List2);//���ļ����û���Ϣ��������
  LoadGood(List1);//���ļ�����Ʒ��Ϣ��������
  MainSystem();//������
  WriteList(List3);//��������Ϣ����д���ļ���
  WriteUser(List2);//���û���Ϣ����д���ļ���
  WriteGood(List1);//����Ʒ��Ϣ����д���ļ���
}

int MainSystem()
{
system("title ��Ʒ���Ĺ���");
   time(&t);//��ȡʱ��
   nowtime=localtime(&t);//ת��Ϊ����ʱ��
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
 printf("*|                             ��ӭʹ�þ��Ĺ���ϵͳ                             |*\n");
 printf("*|                                                                              |*\n");
 printf("*|                              ��ѡ����Ĳ��� :                                |*\n");
 printf("*|                                                                              |*\n");
 printf("*|                              ��1�� �������˻�                                |*\n");
 printf("*|                                                                              |*\n");
 printf("*|                              ��2�� ��¼ϵͳ                                  |*\n");
 printf("*|                                                                              |*\n");
 printf("*|                              ��3�� �˳�ϵͳ                                  |*\n");
 printf("*|                                                                              |*\n");
 printf("*|                              ��4�� ����                                      |*\n");
 printf("*|                                                                              |*\n");
 printf("*|                     ��ǰϵͳʱ�䣺%d��%d��%d��%02d:%02d:%02d                       |*\n",nowtime->tm_year+1900,nowtime->tm_mon+1,nowtime->tm_mday,nowtime->tm_hour,nowtime->tm_min,nowtime->tm_sec);
 printf("*|                                                                              |*\n");
 printf("**********************************************************************************\n");
    printf("����������Ҫ�Ĺ��ܱ�ţ�(���谴�س���)\n");
    char n;
    n=getch();
    while(n<'0'||n>'4')
    {
        printf("�����������,����������\n");
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
    printf("*                                   ��лʹ��                                     *\n");
    printf("*                                                                                *\n");
    printf("*                                 �����´��ټ�                                   *\n");
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
    printf("*|                                  �� �� ע ��                                  |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    struct user *p,*temp;
    temp=(struct user*)malloc(sizeof(struct user));
    char id[16],code1[16];
    while(p!=0)
    {
        int i=0;
        p=head;
        printf("�������û�����  (���15λ,�ո���Ч!)\n");
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
            printf("���û����ѱ�ʹ��\n");
        else
            printf("���û�������\n");
    }
        int j=0;
        printf("���������룺                (���15λ,�ո���Ч!)\n");
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
    if(p==0)//�������Ϊ��ֱ��д��
        List2=temp;
    else//��Ϊ�������д��
    {
        while((p->next)!=0)
            p=p->next;
        p->next=temp;
    }
    printf("\n����˺���ע��ɹ�,��ѡ�����\n");
    printf("***********************************************************************************\n");
    printf("1:��¼ϵͳ  2:�˳�ϵͳ\n");
    char n;
    n=getch();
    while(n<'0'||n>'2')
    {
        printf("�����������,����������\n");
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
    printf("*|                                  �� �� �� ¼                                  |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    int flag=0;
    struct user *p;
    char id[16],code[16];
    while(flag==0)
    {
        printf("����������û�����          (���15λ,�ո���Ч!)                                                      \n");
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
            printf("(���û���������)\n");
    }
    while(strcmp(p->code,code)!=0)
    {
        printf("\n������������룺            (���18λ,�ո���Ч!)                                                      \n");
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
            printf("(���������������������)");
    }
    strcpy(nowid,id);
    printf("\n��¼�ɹ�,�밴���������ϵͳ�˵�                                                 \n");
    printf("***********************************************************************************\n");
    getch();
    system("cls");
    PageMenu();
}

int PageMenu()
{
    printf("**********************************************************************************\n");
    printf("                                  �𾴵�%s�û�\n",nowid);
    printf("******************************��ӭ����ϵͳ�˵�����********************************\n");
    printf("*|                                                                              |*\n");
    printf("*|                                ��0���˳���¼                                 |*\n");
    printf("*|                                                                              |*\n");
    printf("*|                                ��1����Ʒ����                                 |*\n");
    printf("*|                                                                              |*\n");
    printf("*|                                ��2���޸�����                                 |*\n");
    printf("*|                                                                              |*\n");
    printf("**********************************************************************************\n");
    printf("����������Ҫ�Ĺ��ܱ��\n");
    char n;
    n=getch();
    while(n<'0'||n>'2')
    {
        printf("�����������,����������\n");
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
    printf("*|                             ��ϵͳ�ɻ����Ƕ��ҿ���                            |*\n");
    printf("*|                   �������ʹ������������������ȡϵͳ�����°汾              |*\n");
    printf("*|                       ���µ�18126842292����ӿͷ�qq2261645155                 |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                                  ϵͳ�汾V1.0.0                               |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    printf("�밴���������ϵͳ��ҳ\n");
    getch();
    system("cls");
    MainSystem();
}

struct good *ChangeCode(struct user *head)
{

    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                                  �� �� �� ��                                  |*\n");
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
                printf("����ȷ����ԭ���룺          (���15λ,�ո���Ч!)\n");
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
                    printf("����ԭ�����������������\n");
            }
            i=0;
            printf("�����������룺              (���15λ,�ո���Ч!)\n");
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
    printf("\n�����޸ĳɹ�\n");
    printf("�밴������������µ�½\n");
    getch();
    system("cls");
    MainSystem();
}

int ItemManage()
{
    printf("***********************************************************************************\n");
    printf("                                 �𾴵�%s�û�\n",nowid);
    printf("*********************************************************************************|*\n");
    printf("*|                                                                               |*\n");
    printf("*|                              ��ӭ������Ʒ�������                             |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             ��x��������һ���˵�                               |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             ��y���鿴�ҵľ�������                             |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             ��1��������Ʒ��Ϣ                                 |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             ��2��ɾ����Ʒ��Ϣ                                 |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             ��3���޸���Ʒ��Ϣ                                 |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             ��4���鿴�Լ���Ʒ��Ϣ                             |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             ��5���鿴������Ʒ��Ϣ                             |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             ��6������Ų鿴��Ʒ��Ϣ                           |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             ��7�������ֲ鿴��Ʒ��Ϣ                           |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             ��8�������鿴��Ʒ��Ϣ                           |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             ��9��������ϲ�ѯ��Ʒ��Ϣ                         |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                             ��0����ʼ����                                     |*\n");
    printf("*|                                                                               |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    printf("����������Ҫ�Ĺ��ܱ��\n");
    char n;
    n=getch();
    while(n<'0'||n>'9'&&n!='x'&&n!='y')
    {
        printf("�����������,����������\n");
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
    printf("*|                                  �� �� �� Ʒ                                  |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    struct good *temp;
    temp=(struct good*)malloc(sizeof(struct good));
    temp->next=NULL;
    temp->num=++count;//��һ�������Ʒʱ���+1
    printf("��������Ʒ������\n");
    scanf("%s",temp->name);
    printf("��������Ʒ�����\n");
    scanf("%s",temp->type);
    printf("��������Ҫ������Ʒ�ĳ���(������1-10)\n");
    while(temp->newold<1||temp->newold>10)
    {
        scanf("%d",&temp->newold);
        if(temp->newold<1||temp->newold>10)
            printf("�����������,����������\n");
    }
    printf("��������Ҫ���ӵ���Ʒ����\n");
    scanf("%s",temp->miaosu);
    printf("��������Ҫ���ӵ���Ʒ���ļ�\n");
    scanf("%d",&temp->price);
    while(temp->price<=0)
    {
      printf("��ϵͳ��֧�ְ��ͻ���������������\n");
      scanf("%d",&temp->price);
    }
    while(Compare(temp->year,temp->month,temp->day,nowtime->tm_year+1900,nowtime->tm_mon+1,nowtime->tm_mday)==1)
    {
        printf("��������Ҫ���ӵ���Ʒ����Ʒ���Ľ�ֹʱ��(��ʽ:xxxx xx xx)�� �� ��\n");
        scanf("%d%d%d",&temp->year,&temp->month,&temp->day);
        if(Compare(temp->year,temp->month,temp->day,nowtime->tm_year+1900,nowtime->tm_mon+1,nowtime->tm_mday)==1)
            printf("������Ľ�ֹ����ʱ�䲻����");
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
    printf("**********************************������Ʒ�ɹ�**************************************\n");
    fflush(stdin);//��ջ������Բ�Ӱ��������ݶ�ȡ
    printf("�밴�����������Ʒ�������(����ֱ�ӹرճ������ᵼ����Ʒ��Ϣ�޷�����)\n");
    getch();
    system("cls");
    ItemManage();
}

struct good *DelGood(struct good *head)
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                                  ɾ �� �� Ʒ                                  |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    printf("��������Ҫɾ������Ʒ���\n");
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
                printf("����ɾ�����˵���Ʒ\n");
                break;
            }
            if(p1==List1)//���������ͷ
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
        printf("û���ҵ�����Ҫɾ������Ʒ\n");
    else if(strcmp(p1->owner,nowid)==0)
    {
        while(p2!=0)
        {
            p2->num--;
            p2=p2->next;
        }
    printf("**********************************ɾ����Ʒ�ɹ�**************************************\n");
    }
    fflush(stdin);
    printf("�밴�����������Ʒ�������\n");
    getch();
    system("cls");
    ItemManage();
}

struct good *ChangeGood(struct good *head)
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                                  �� �� �� Ʒ                                  |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    printf("��������Ҫ�޸ĵ���Ʒ���\n");
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
                printf("�����޸ı��˵���Ʒ\n");
                break;
            }
            printf("��������Ҫ�޸ĵ���Ʒ���ļ�\n");
            scanf("%d",&p->price);
                while(p->price<=0)
            {
            printf("��ϵͳ��֧�ְ��ͻ���������������\n");
            scanf("%d",&p->price);
            }
            printf("��������Ҫ�޸���Ʒ�ĳ�ɫ(1-10����)\n");
            scanf("%d",&p->newold);
            while(p->newold<1||p->newold>10)
            {
                printf("�����������,����������\n");
                scanf("%d",&p->newold);
            }
            printf("��������Ҫ�޸���Ʒ�ľ��Ľ�ֹʱ��(xxxx xx xx)�� �� ��\n");
            scanf("%d%d%d",&p->year,&p->month,&p->day);
            while(Compare(p->year,p->month,p->day,nowtime->tm_year+1900,nowtime->tm_mon+1,nowtime->tm_mday)==1)
            {
                printf("������Ľ�ֹ����ʱ�䲻����,����������\n");
                scanf("%d%d%d",&p->year,&p->month,&p->day);
            }
            printf("��������Ҫ�޸ĵ���Ʒ����\n");
            scanf("%s",p->miaosu);
            break;
        }
        p=p->next;
    }
    if(p==0)
        printf("û���ҵ�����Ҫ�޸ĵ���Ʒ\n");
    else
    printf("**********************************�޸���Ʒ�ɹ�**************************************\n");
    fflush(stdin);
    printf("�밴�����������Ʒ�������\n");
    getch();
    system("cls");
    ItemManage();
}

int Compare(int year1,int month1,int day1,int year2,int month2,int day2)//year1Ϊ��ֹ����ʱ�䣬year2Ϊ����ʱ��
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
    printf("*|                              �� �� �� Ʒ �� ��                                |*\n");
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
               printf("���:%-2d\n����:%-10s\n����:%-10s\n����:%-2d����\n����:%-50s\nӵ����:%-10s\n���ļ�:%-4d\n����ʱ���ֹ:%d:%d:%d\n��ǰ������:%-10s\n��ǰ������:%-4d ��������\n\n\n"
               ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
               }
            if(p->result==1)
               {printf("���:%-2d ����:%-10s ����:%-10s ����:%-2d����\n����:%-50s\nӵ����:%-10s\n���ļ�:%-4d\n����ʱ���ֹ:%d:%d:%d\n��ǰ������:%-10s\n��ǰ������:%-4d ��������\n\n\n"
               ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
               }
               flag=1;
        }
        p=p->next;
    }
    if(flag==0)
    printf("�㻹û����ƷŶ\n");
    fflush(stdin);
    printf("�밴��������ؾ��Ĺ������\n");
    getch();
    system("cls");
    ItemManage();
}

struct good *ViewAll(struct good *head)
{

    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                              �� �� �� Ʒ �� ��                                |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    struct good *p;
    p=head;
    if(p==0)
        printf("��ϵͳ��û����Ʒ\n");
    while(p!=0)
    {
        if(p->result==0)
            printf("���:%-2d ����:%-10s ����:%-10s ����:%-2d����\n����:%-50s\nӵ����:%-10s\n���ļ�:%-4d\n����ʱ���ֹ:%d:%d:%d\n��ǰ������:%-10s\n��ǰ������:%-4d ��������\n\n\n"
                   ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
        if(p->result==1)
            printf("���:%-2d ����:%-10s ����:%-10s ����:%-2d����\n����:%-50s\nӵ����:%-10s\n���ļ�:%-4d\n����ʱ���ֹ:%d:%d:%d\n��ǰ������:%-10s\n��ǰ������:%-4d ��������\n\n\n"
                   ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
        p=p->next;
    }
    fflush(stdin);
    printf("�밴��������ؾ��Ĺ������\n");
    getch();
    system("cls");
    ItemManage();
}

struct good *ViewNum(struct good *head)
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                          �� �� �� �� �� �� �� Ʒ                              |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    printf("%����������Ҫ�鿴����Ʒ��Ϣ�ı��\n");
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
                printf("���:%-2d ����:%-10s ����:%-10s ����:%-2d����\n����:%-50s\nӵ����:%-10s\n���ļ�:%-4d\n����ʱ���ֹ:%d:%d:%d\n��ǰ������:%-10s\n��ǰ������:%-4d ��������\n\n\n"
                       ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
            if(p->result==1)
                printf("���:%-2d ����:%-10s ����:%-10s ����:%-2d����\n����:%-50s\nӵ����:%-10s\n���ļ�:%-4d\n����ʱ���ֹ:%d:%d:%d\n��ǰ������:%-10s\n��ǰ������:%-4d ��������\n\n\n"
                       ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
            flag=1;
        }
        p=p->next;
    }
    if(flag==0)
    printf("û���ҵ�����Ҫ����Ʒ\n");
    fflush(stdin);
    printf("�밴�����������Ʒ�������\n");
    getch();
    system("cls");
    ItemManage();
}

struct good *ViewName(struct good *head)
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                          �� �� �� �� �� �� �� Ʒ                              |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    printf("%����������Ҫ�鿴����Ʒ��Ϣ������\n");
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
                printf("���:%-2d ����:%-10s ����:%-10s ����:%-2d����\n����:%-50s\nӵ����:%-10s\n���ļ�:%-4d\n����ʱ���ֹ:%d:%d:%d\n��ǰ������:%-10s\n��ǰ������:%-4d ��������\n\n\n"
                       ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
            if(p->result==1)
                printf("���:%-2d ����:%-10s ����:%-10s ����:%-2d����\n����:%-50s\nӵ����:%-10s\n���ļ�:%-4d\n����ʱ���ֹ:%d:%d:%d\n��ǰ������:%-10s\n��ǰ������:%-4d ��������\n\n\n"
                       ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
            flag=1;
        }
        p=p->next;
    }
    if(flag==0)
        printf("û���ҵ�����Ҫ����Ʒ\n");
    fflush(stdin);
    printf("�밴��������ؾ��Ĺ������\n");
    getch();
    system("cls");
    ItemManage();
}

struct good *ViewType(struct good *head)
{

    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                          �� �� �� �� �� �� �� Ʒ                              |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    printf("%����������Ҫ�鿴����Ʒ��Ϣ������\n");
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
                printf("���:%-2d ����:%-10s ����:%-10s ����:%-2d����\n����:%-50s\nӵ����:%-10s\n���ļ�:%-4d\n����ʱ���ֹ:%d:%d:%d\n��ǰ������:%-10s\n��ǰ������:%-4d ��������\n\n"
                       ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
            if(p->result==1)
                printf("���:%-2d ����:%-10s ����:%-10s ����:%-2d����\n����:%-50s\nӵ����:%-10s\n���ļ�:%-4d\n����ʱ���ֹ:%d:%d:%d\n��ǰ������:%-10s\n��ǰ������:%-4d ��������\n\n"
                       ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
            flag=1;
        }
        p=p->next;
    }
    if(flag==0)
        printf("��ϵͳ��û�д����͵���Ʒ\n");
    fflush(stdin);
    printf("�밴��������ؾ��Ĺ������\n");
    getch();
    system("cls");
    ItemManage();
}

struct good *GoodBid(struct good *head)
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                               �� ʼ �� �� �� ��                               |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    printf("��������Ҫ���۵���Ʒ���\n");
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
                printf("���ܾ����Լ�����Ʒ��\n");
                break;
            }
            if(p->result==1)
            {
                printf("����Ʒ�ѽ�ֹ���ģ�����������Ʒ�ɣ�\n");
                break;
            }
            while(maxprice<=p->maxprice)
            {
                printf("��������ľ��ļ�\n");
                scanf("%d",&maxprice);
                if(maxprice<=p->maxprice)
                    printf("���ܵ��ڵ�ǰ��߼�,���������룡\n");
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
        printf("û���ҵ���Ҫ���۵���Ʒ\n");
    else if(strcmp(p->owner,nowid)&&p->result!=1)
        printf("���۳ɹ�\n");
    fflush(stdin);
    printf("�밴�����������Ʒ�������\n");
    getch();
    system("cls");
    ItemManage();
}

struct list *ViewBid(struct list *head)
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                                 �� �� �� ��                                   |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    int flag=0;
    struct list *p;
    p=List3;
    while(p!=0)
    {
        if(strcmp(p->buyer,nowid)==0&&p->result==0)
        {
            printf("��Ʒ���֣�%s ���ļ۸�%d ���Ľ���\n\n",p->name,p->price);
            flag=1;
        }
        if(strcmp(p->buyer,nowid)==0&&p->result==1)
        {
            printf("��Ʒ���֣�%s �ɽ��۸�%d ���ĳɹ�\n\n",p->name,p->price);
            flag=1;
        }
        if(strcmp(p->buyer,nowid)==0&&p->result==2)
        {
            printf("��Ʒ���֣�%s ���ļ۸�%d ����ʧ��\n\n",p->name,p->price);
            flag=1;
        }
        p=p->next;
    }
    if(flag==0)
        printf("�㻹û�о�����Ʒ\n");
    fflush(stdin);
    printf("�밴��������ؾ��Ĺ������\n");
    getch();
    system("cls");
    ItemManage();
}

struct good *SearchGood(struct good *head)
{
    printf("***********************************************************************************\n");
    printf("*|                                                                               |*\n");
    printf("*|                          �� �� �� �� �� �� �� �� Ʒ                           |*\n");
    printf("*|                                                                               |*\n");
    printf("***********************************************************************************\n");
    printf("%����������Ҫ�鿴����Ʒ��Ϣ������\n");
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
                printf("���:%-2d ����:%-10s ����:%-10s ����:%-2d����\n����:%-50s\nӵ����:%-10s\n���ļ�:%-4d\n����ʱ���ֹ:%d:%d:%d\n��ǰ������:%-10s\n��ǰ������:%-4d ��������\n\n\n"
                       ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
            if(p->result==1)
                printf("���:%-2d ����:%-10s ����:%-10s ����:%-2d����\n����:%-50s\nӵ����:%-10s\n���ļ�:%-4d\n����ʱ���ֹ:%d:%d:%d\n��ǰ������:%-10s\n��ǰ������:%-4d ��������\n\n\n"
                       ,p->num,p->name,p->type,p->newold,p->miaosu,p->owner,p->price,p->year,p->month,p->day,p->buyer,p->maxprice);
            flag=1;
        }
        p=p->next;
    }
    if(flag==0)
        printf("û���ҵ�����Ҫ����Ʒ\n");
    fflush(stdin);
    printf("�밴��������ؾ��Ĺ������\n");
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
        printf("���ļ�����\n");
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
        printf("���ļ�ʧ��");
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
        printf("���ļ�����\n");
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
        printf("���ļ�ʧ��");
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
        printf("���ļ�����\n");
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
                if(strcmp(p1->name,p->name)==0&&strcmp(p1->buyer,p->buyer)==0)//�鿴��Ʒ״̬
                    p1->result=1;
                if(strcmp(p1->name,p->name)==0&&strcmp(p1->buyer,p->buyer)!=0)//��Ʒ������
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
        printf("���ļ�ʧ��");
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
