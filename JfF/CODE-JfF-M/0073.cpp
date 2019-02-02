#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
/*
 * ȫ�ֲ���
 * p�����ɵĴ�����
 * g��p���ظ�
 * y��g^d�η�
 * d��˽Կ
 */
mpz_t p,g,y,d;
/*
 * C1,C2 ���ĵ�������
 * m ����
 */
mpz_t C1, C2;
mpz_t m;
/*
 * ʹ����gmp�⣬������һЩ��������
 * �����жϣ�
 * int mpz_probab_prime_p (mpz_t n, int reps)
 * �ж� n �Ƿ�Ϊ����,�� n ȷ���������򷵻� 2,��� n �Ǹ������� (������ȫ
 * ȷ��) ��ô���� 1,������� n ȷ���Ǻ�����ô���� 0��
 * �������������һЩ�Գ�,Ȼ������ Miller-Rabin ���������б�reps ������
 * �����б������ٴ�,5 �� 10 �ǽϺ������ֵ,����ε��б���Լ�С��������
 * ��Ϊ���������Ŀ��ܡ�
 * ���� Miller-Rabin �б���������Ƶ��б���ɵĸ����б���ܸ�Ϊ�����б�
 * ʧ�ܵ�������֪���Ǻ���,����ͨ���б��������������Ҳ�����Ǻ�����ֻ��
 * �������ĺ�������ͨ���б�,���ͨ���б����һ�㶼����Ϊ��������
 *
 * �����������
 * void mpz_urandomb(mpz_t rop,gmp_randstate_t state,unsigned long int n) [����]
 * ����һ�����ȷֲ��� 0 �� 2^n ? 1(����) ��Χ�ڵ����������
 * �ڼ����������֮ǰ�����ȵ���ĳ�� gmp_randinit �����Ա��� state ���г�ʼ����
 *
 * ���״̬��ʼ����
 * void gmp_randinit_default (gmp_randstate_t state)  [����]
 * ��Ĭ���㷨��ʼ�� state�������ٶ��������֮���Ȩ��,����û������Ҫ���
 * Ӧ��ʹ������
 * 
 * ���룺bits
 * ���������һ����Χ��0~2^n - 1 ���������
 */
void random_prime(unsigned long int bits){
  gmp_randstate_t state;
  gmp_randinit_default(state);
  mpz_init(p);
  while(1){
    mpz_urandomb(p,state,bits);
    if(mpz_probab_prime_p(p,10) != 0)return;
  }
  return;
}
/*
 * ��ԭ�����㷨
 * int mpz_init_set_str (mpz_t rop, char *str, int base) ��ֵ
 * void mpz_add (mpz_t rop, mpz_t op1, mpz_t op2) rop = op1 + op2
 * ���룺p
 * �����p���ظ�
 */
void root_nums(){
  const char* str = "1";
  const char* str2 = "2";
  mpz_t a,b,c;
  mpz_init(a);
  mpz_init(b);
  mpz_init(c);
  mpz_init_set_str(b,str,10);// b = 1; b��Ϊ�ۼӵ�ֵ
  mpz_init_set_str(a,str2,10);// a = 2;�൱���ۼ���
  mpz_init_set_str(c,str2,10);// c = a;���ڼ���
  const int tempNum = 100;
  mpz_t temp[tempNum];
  for(int i = 0 ; i < tempNum ; i++){
    mpz_init(temp[i]);
  }
  int i,tempLength;//tempLength = 0;// temp�������������ֵ������
  while(1){
    // �ж��Ƿ��Ǳ�ԭ����������򷵻أ������ж���һ����
    mpz_init_set(temp[0],a);
    mpz_init_set(c,a);
    for(i = 0 , tempLength = 1 ; i < tempNum ; ){
      mpz_mul(c,a,c);
      for(i = 0 ; i < tempLength ; i++){
        if(mpz_cmp(temp[i],c) ==0){
          break;
        }
      }
      if(i == tempLength){
        mpz_init_set(temp[tempLength++],c);
      }else {
        for(int k = 0 ; k < tempLength ; k++){
          mpz_init(temp[k]);
        }
        break;
      }
      if(tempLength == tempNum){
        mpz_init_set(g,c);
        return;
      }
    }
    mpz_add(a,a,b);
  }
}
/*
 * bits�����ɵ��������λ����2^bits
 * p�����ɵ��������
 * g������p���ظ�
 * y���ظ�g^d�η�
 * ��d��˽Կ, (p,g,y)�ǹ�Կ
 * ���룺bits
 * �������Կ(p,g,y),˽Կ(d)
 */
void elgamal_keygen(unsigned long int bits){
  random_prime(bits);
  gmp_randstate_t state;
  gmp_randinit_default(state);
  mpz_urandomm(d,state,p);
  root_nums();
  // y = (g^d)mod p;
  mpz_powm(y,g,d,p);
}
/*
 * m����Ϣ
 * p,g,y����Կ
 * ���룺��Ϣ(m),��Կ(p,g,y)
 * �������Ϣ(m)������(C1,C2)
 */
void elgamal_encrypt(){
  gmp_randstate_t state;
  gmp_randinit_default(state);
  mpz_t result;
  mpz_init(result);
  mpz_urandomm(result,state,p);// result �����ɵ������
  mpz_t K;
  mpz_init(K);
  mpz_powm(K,y,result,p);
  mpz_powm(C1,g,result,p);
  mpz_mul(C2,K,m);
  mpz_mod(C2,C2,p);
}
/*
 * ���룺����(C1,C2),˽Կ(d),��ͬѡ�������(p)
 * ���������(m)
 */
void elgamal_decrypty(){
  mpz_t K;
  mpz_init(K);
  mpz_powm(K,C1,d,p);// K = (C1^d)mod p
  // ��K��p�ϵ���Ԫ
  mpz_invert(K,K,p);
  mpz_mul(C2,C2,K);
  mpz_mod(m,C2,p);
}

int main(){
  mpz_t p,g,y,d;
  mpz_init(p);
  mpz_init(g);
  mpz_init(y);
  mpz_init(d);
  mpz_init(C1);
  mpz_init(C2);
  mpz_init(m);

  char *message = (char*)malloc(13);
  char *temp = (char*)malloc(3 * 13 + 1);
  printf("please input some message: \n");
  while(1){
    int i = 0 , j = 0 , x = 0,len = 0;
    for(i = 0,j = 0 ; i < 12 ; i++){
      scanf("%c",&message[i]);
      if(message[i] == '\n')break;
      // ����Ϣ��ʾ����λ������ASCII��
      x = message[i];
      temp[j + 2] = x % 10 + 48;
      x /= 10;
      temp[j + 1] = x % 10 + 48;
      temp[j] = x/10 + 48;
      j += 3;
      len += 3;
    }
    // ��һλ����5�������һλ��0
    temp[0] += 5;
    message[i + 1] = '\0';
    temp[j + 1] = '\0';
    mpz_init_set_str(m,temp,10);
    elgamal_keygen(128);
    elgamal_encrypt();
    gmp_printf("���ܵĽ���ǣ�(%Zd,%Zd)\n",C1,C2);
    elgamal_decrypty();
    char* r = mpz_get_str(temp,10,m);
    //  ǰ�����5������Ҫȥ��
    temp[0] -= 5;
    for(i = 0,j = 0 ; i < 12 && j < len ; i++){
      x = ((temp[j] - 48) * 10 + temp[j + 1] - 48) * 10 + temp[j + 2] - 48;
      message[i] = x;
      j += 3;
    }
    message[len + 1] = '\0';
    printf("���ܵĽ���ǣ�%s\n",message);
  }
  free(message);
  free(temp);
  mpz_clear(p);
  mpz_clear(g);
  mpz_clear(y);
  mpz_clear(d);
  mpz_clear(C1);
  mpz_clear(C2);
  mpz_clear(m);
  return 0;
}
