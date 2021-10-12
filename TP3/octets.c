#include <stdio.h>

short var_short = 17476;
char* point_Short = (char*)&var_short;

int var_int = 1145324612;
char* point_Int = (char*)&var_int;

long int var_long_int = 4919131752989213764;
char* point_Long_Int = (char*)&var_long_int;

float var_float = 44;
char* point_Float = (char*)&var_float;

double var_double = 44;
char* point_Double = (char*)&var_double;

long double var_long_double = 44;
char* point_Long_Double = (char*)&var_long_double;

int main(){
    
    for(int i=0; i<sizeof(var_short); i++){
        printf("L'octet n° %d du short est : %x\n",i+1, *(point_Short+i) );
    }
    printf("\n");
    
    for(int i=0; i<sizeof(var_int); i++){
        printf("L'octet n° %d du int est : %x\n",i+1, *(point_Int+i) );
    }
    printf("\n");
    
    for(int i=0; i<sizeof(var_long_int); i++){
        printf("L'octet n° %d du long int est : %x\n",i+1, *(point_Long_Int+i) );
    }
    printf("\n");
    
    for(int i=0; i<sizeof(var_float); i++){
        printf("L'octet n° %d du float est : %x\n",i+1, *(point_Float+i) );
    }
    printf("\n");
    
    for(int i=0; i<sizeof(var_double); i++){
        printf("L'octet n° %d du double est : %x\n",i+1, *(point_Double+i) );
    }
    printf("\n");
    
    for(int i=0; i<sizeof(var_long_double); i++){
        printf("L'octet n° %d du long double est : %x\n",i+1, *(point_Long_Double+i) );
    }
    printf("\n");
}
