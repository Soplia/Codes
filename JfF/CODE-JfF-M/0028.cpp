#include<stdio.h>
void movedisc(unsigned n,char fromneedle,char toneedle,char usingneedle);
int i=0;
void main()
{
   unsigned n;
   printf("please enter the number of disc:");
   scanf("%d",&n);               /*����Nֵ*/
   printf("\\tneedle:\\ta\\t b\\t c\\n");
   movedisc(n,\\'a\\',\\'c\\',\\'b\\');  /*��A�Ͻ���B��N�������ƶ���C��*/
   printf("\\t Total: %d\\n",i);
}
void movedisc(unsigned n,char fromneedle,char toneedle,char usingneedle)
{
   if(n>0)
   {
      movedisc(n-1,fromneedle,usingneedle,toneedle);
                     /*��fromneedle�Ͻ���toneedle��N-1�������ƶ���usingneedle��*/
      ++i;
      tch(fromneedle)     /*��fromneedle �ϵ�һ�������Ƶ�toneedle��*/
      {
         case \'a\':tch(toneedle)
                   {
                        case \'b\': printf("\\t[%d]:\\t%2d.........>%2d\\n",i,n,n);
                           break;
                        case \'c\': printf("\\t[%d]:\\t%2d...............>%2d\\n",i,n,n);
                           break;
                   }
                  break;
         case \'b\':tch(toneedle)
                  {
                     case \'a\': printf("\\t[%d]:\\t%2d<...............>%2d\\n",i,n,n);
                        break;
                     case \'c\': printf("\\t[%d]:\\t        %2d........>%2d\\n",i,n,n);
                        break;
                  }
                  break;
         case \'c\':tch(toneedle)
                  {
                     case \'a\': printf("\\t[%d]:\\t%2d<............%2d\\n",i,n,n);
                        break;
                     case \'b\': printf("\\t[%d]:\\t%2d<........%2d\\n",i,n,n);
                        break;
                  }
                  break;
         }
         movedisc(n-1,usingneedle,toneedle,fromneedle);
               /*��usingneedle�Ͻ���fromneedle��N-1�������ƶ���toneedle��*/
      }
} 
