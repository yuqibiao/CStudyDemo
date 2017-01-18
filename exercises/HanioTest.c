#include <stdio.h>
/**
 * 汉诺塔问题
 *
 * 一块板上有三根针，A，B，C。A针上套有64个大小不等的圆盘，大的在下，小的在上。
 *要把这64个圆盘从A针移动C针上，每次只能移动一个圆盘，移动可以借助B针进行。
 * 但在任何时候，任何针上的圆盘都必须保持大盘在下，小盘在上。求移动的步骤。
 *
 */

int getHanoiStepNum(int n);
void printHanoiMoveProcess(int n , char a , char b , char c );

int main() {

    printf("n=3的汉诺塔需要 %d 步\r\n" , getHanoiStepNum(3));
    printf("n=3的汉诺塔的具体步骤\r\n" );
    printHanoiMoveProcess(3 , 'A' , 'B' , 'C');
    return 0;
}

/**
 *汉诺塔移动过程
 *
 * 1.将A中的盘子中的n-1个移动到B上
 * 2.将A中第n个盘子移动到C上
 *3.将B中n-1个盘子移动到C上
 *
 * 第1步又可以分解为将 三步：（i=n-1）
 * 1.将i-1个盘子移动从A移动到C
 * 2.将第i个盘子从A移动到B
 * 3.将i-1个盘子从C移到B
 *
 * 第3步又可以分解为将 三步：（i=n-1）
 * 1.将i-1个盘子移动从B移动到A
 * 2.将第i个盘子从B移动到C
 * 3.将i-1个盘子从A移到C
 *
 *上面的i中的1 2 步接着分解为三个步骤
 *
 *
 * 第1步又可以分解为 类似的
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
        //---将n-1个从A移动到B（此步实现的是从A-->B所以b在原来c的位置）
        printHanoiMoveProcess(n-1 , a , c , b);
        //---从A移动到C
        printf("%c--->%c\r\n" , a , c);
        //---将n-1从B移动到C （此步最终实现的是B--C所以 b在原来a的位置）
        printHanoiMoveProcess(n-1 , b , a , c);
    }
}

/**
 *汉诺塔移动步数
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
