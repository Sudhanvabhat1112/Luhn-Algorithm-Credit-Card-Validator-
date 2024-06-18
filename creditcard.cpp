/* lunh algorithm

I can write all of these in words but you would not understand

Example  
pin=6011000990139424
every digit from the left skipping one digit 6,1,0,0,9,1,9,2
multiply each thing by 2: 12,2,0,0,18,2,18,4
since 12 and 18 are greater than 10 add thier digits
new number is 1+8=9, 1+2=3
so new set of numbers : 3,2,0,0,9,2,9,4

ADD THESE UP TO GET 29        ---->  STEP 1

every digit from the right skipping one digit 4,4,3,0,9,0,1,0
add all of these digits : 21
add this sum to sum of step 1

answer = 21+29
if the answer divides by 10 its valid
 */
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long b;
    cout<<"Enter your credit card number(type all of it at once)\n";
    cin>>b;
    while(int(log10(b))!=15){cout<<"Your credit card must contain 16 digits and make sure to not leave spaces\n";cin>>b;}
    //log is used to count the digits 
    int a[16];
    for(int i=0;i<16;i++){
        int digit = b%10;
        b /= 10;
        a[15-i]=digit;
    }

    for(int i=0;i<16;i++){
        if(i%2==0){
            if(2*a[i]>=10){a[i]=(2*a[i]/10)+(2*a[i]%10);}
            else{a[i]=2*a[i];}
        }
    }
    int sum=0;
    for(int i=0;i<16;i++){sum+=a[i];}
    if(sum%10==0){cout<<"VALID\n";}
    else{cout<<"INVALID\n";}
}