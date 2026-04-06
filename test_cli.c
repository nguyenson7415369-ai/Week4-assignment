#include<stdio.h>
#include<string.h>
#include<cmd_line.h>

/*tao 1 bien flag 
tao 1 ham thuc hien lenh, cho flag=1
tao cmd_line_t test_table[]={tenlenh, ham _thuc_thi, test_case_name}
tao mot ham doi chieu co dau vao la dieu kien neu cmd da duoc goi thanh cong, va *testname, neu thanh cong
thi in ra success, ko thi in ra failed testname
*/
//ham thuc hien lenh tren led
int8_t led_flag,wifi_flag;
int32_t led_func(uint8_t* argv){
    (void)argv;
    led_flag=1;
    return 0;
}
int32_t wifi_func(uint8_t* argv){
    (void)argv;
    wifi_flag=1;
    return 0;
}
cmd_line_t test_table[]={
    {(int8_t*)"led",led_func,"controlling led"},
    {(int8_t*)"wifi",wifi_func,"controlling wifi"},
    {NULL,NULL,NULL}
};
int kiemtra(int condition,int flag){
    if(condition==CMD_SUCCESS){
        printf("SUCCESS \n");
    }
    else if(condition==CMD_NOT_FOUND){
        printf("LENH KHONG HOP LE \n");
    }
    else if(condition==CMD_TOO_LONG){
        printf("LENH QUA DAI\n");
    }
    else if(condition==CMD_TBL_NOT_FOUND){
        printf("BANG LENH KHONG HOP LE \n");
    }
    else{
        printf("FAILED\n");
    }
    flag=0;
}
int main(){
    led_flag=0;
    uint8_t condition=cmd_line_parser(test_table,(uint8_t*)"led on");
    uint8_t condition1=cmd_line_parser(test_table,(uint8_t*)"lkasdjklsdfajklasdfjk a");
    uint8_t condition2=cmd_line_parser(test_table,(uint8_t*)"let on");
    uint8_t condition3=cmd_line_parser(NULL,(uint8_t*)"wifi on");
    led_flag=0;
    kiemtra(condition,led_flag);
    led_flag=0;
    kiemtra(condition1,led_flag);
    led_flag=0;
    kiemtra(condition2,led_flag);
    wifi_flag=0;
    kiemtra(condition3,wifi_flag);
}
