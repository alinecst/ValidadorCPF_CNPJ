#include<stdio.h>
#include<stdbool.h>
#include<string.h>
bool todosRepetidos(int cpf[])
{   int i;
    for(i=1; i<14; i++)
        if(cpf[0] != cpf[i])
            return false;
    return true;
}

int verificador1(int cnpj[], int mult[]){
    int soma =0;
    int i;
    int dig1=0;
    for(i=0;i<12;i++){
        soma = soma + cnpj[i] * mult[i];
    }
    dig1 = soma / 11;
    printf("soma 1 %d\n",soma);
    printf("dig 1 %d\n",dig1);
    if (dig1 < 2){
        return dig1 = 0;
    } else {
        return dig1 = 11 - dig1;
    }
}

int verificador2(int cnpj[], int mult[]){
    int soma =0;
    int i;
    int dig1=0;
    for(i=0;i<13;i++){
        soma = soma + cnpj[i] * mult[i];
    }
    dig1= soma / 11;
    printf("soma 2 %d\n",soma);
    printf("dig 2 %d\n",dig1);
    if (dig1 < 2){
        return dig1 = 0;
    } else {
        return dig1 = 11 - dig1;
    }
}


int calculaDigito(int cpf[], int mult[], int N)
{   int soma=0, i;
    for(i=0; i<N; i++)
    {   soma = soma + cpf[i]*mult[i];
    }
    return ((soma*10) % 11)%10;
}

void leiaCNPJ(int cpf[])
{   char texto[30];
    fgets(texto, 30, stdin);
    int i, j=13;
    for(i=strlen(texto)-1; i>=0; i--)
    {   if(texto[i]>='0' && texto[i]<='9')
        {
            cpf[j] = texto[i] - '0';
            j--;
        }
    }
    
    while(j>=0)
    {   cpf[j] = 0;  //zero à esquerda
        j--;
    }
}

void imprimeCPF(int cpf[])
{   int i;
    printf("\n");
    for(i=0; i<14; i++)
    {   printf("%d", cpf[i]);
        if(i==1 || i==4) 
        printf(".");
        else if(i==7) 
        printf("/");
        else if (i==11) 
        printf("-");
    }
    printf("\n");
}

int main()
{
	int cnpj[13];
	int m1[13]={5,4,3,2,9,8,7,6,5,4,3,2,0};
	int m2[13]={6,5,4,3,2,9,8,7,6,5,4,3,2};
	int i;
	printf("Entre com os 14 digitos do CNPJ:");
	leiaCNPJ(cnpj);
    cnpj[12]=verificador1(cnpj,m1);
    cnpj[13]=verificador2(cnpj,m2);
    imprimeCPF(cnpj);
  	
	return 0;
}