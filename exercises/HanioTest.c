#include <stdio.h>
/**
 * ��ŵ������
 *
 * һ������������룬A��B��C��A��������64����С���ȵ�Բ�̣�������£�С�����ϡ�
 *Ҫ����64��Բ�̴�A���ƶ�C���ϣ�ÿ��ֻ���ƶ�һ��Բ�̣��ƶ����Խ���B����С�
 * �����κ�ʱ���κ����ϵ�Բ�̶����뱣�ִ������£�С�����ϡ����ƶ��Ĳ��衣
 *
 */

int getHanoiStepNum(int n);
void printHanoiMoveProcess(int n , char a , char b , char c );

int main() {

    printf("n=3�ĺ�ŵ����Ҫ %d ��\r\n" , getHanoiStepNum(3));
    printf("n=3�ĺ�ŵ���ľ��岽��\r\n" );
    printHanoiMoveProcess(3 , 'A' , 'B' , 'C');
    return 0;
}

/**
 *��ŵ���ƶ�����
 *
 * 1.��A�е������е�n-1���ƶ���B��
 * 2.��A�е�n�������ƶ���C��
 *3.��B��n-1�������ƶ���C��
 *
 * ��1���ֿ��Էֽ�Ϊ�� ��������i=n-1��
 * 1.��i-1�������ƶ���A�ƶ���C
 * 2.����i�����Ӵ�A�ƶ���B
 * 3.��i-1�����Ӵ�C�Ƶ�B
 *
 * ��3���ֿ��Էֽ�Ϊ�� ��������i=n-1��
 * 1.��i-1�������ƶ���B�ƶ���A
 * 2.����i�����Ӵ�B�ƶ���C
 * 3.��i-1�����Ӵ�A�Ƶ�C
 *
 *�����i�е�1 2 �����ŷֽ�Ϊ��������
 *
 *
 * ��1���ֿ��Էֽ�Ϊ ���Ƶ�
 *
 * @param n
 * @param a
 * @param b
 * @param c
 */
void printHanoiMoveProcess(int n , char a , char b , char c ){
    if(n==1){
        printf("%c--->%c\r\n" , a , c);
    } else{
        //---��n-1����A�ƶ���B���˲�ʵ�ֵ��Ǵ�A-->B����b��ԭ��c��λ�ã�
        printHanoiMoveProcess(n-1 , a , c , b);
        //---��A�ƶ���C
        printf("%c--->%c\r\n" , a , c);
        //---��n-1��B�ƶ���C ���˲�����ʵ�ֵ���B--C���� b��ԭ��a��λ�ã�
        printHanoiMoveProcess(n-1 , b , a , c);
    }
}

/**
 *��ŵ���ƶ�����
 *
 * @param n
 * @return
 */
int getHanoiStepNum(int n){
    int num = 0;
    if(n==1){
        num = 1;
    }else{
        num = 2* getHanoiStepNum(n-1)+1;
    }
    return num;
}
