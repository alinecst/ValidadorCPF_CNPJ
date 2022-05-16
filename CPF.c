
#include<stdio.h>
#include<stdbool.h>
bool todosRepetidos(int cpf[])
{   int i;
    for(i=1; i<11; i++)
        if(cpf[0] != cpf[i])
            return false;
    return true;
}

int calculaDigito(int cpf[], int mult[], int N)
{   int soma=0, i;
    for(i=0; i<N; i++)
    {   soma = soma + cpf[i]*mult[i];
    }
    return ((soma*10) % 11)%10;
}

void imprimeRegiaoOrigem(int cpf[])
{
    if ((cpf[8]) == 0) 
        printf("A origem do CPF é: Rio Grande do Sul");
    else if ((cpf[8]) == 1)
        printf("A origem do CPF é:Distrito Federal, Goiás, Mato Grosso, Mato Grosso do Sul ou Tocantins");
    else if ((cpf[8]) == 2)
        printf("A origem do CPF é: Amazonas, Pará, Roraima, Amapá, Acre ou Rondônia");
    else if ((cpf[8]) == 3) 
        printf("A origem do CPF é: Ceará, Maranhão ou Piauí");
    else if ((cpf[8]) == 4)
        printf("A origem do CPF é: Paraíba, Pernambuco, Alagoas ou Rio Grande do Norte");
    else if ((cpf[8]) == 5)  
        printf("A origem do CPF é: Bahia ou Sergipe");
    else if ((cpf[8]) == 6) 
        printf("A origem do CPF é: Minas Gerais");
    else if ((cpf[8]) == 7)
        printf("A origem do CPF é: Rio de Janeiro ou Espírito Santo");
    else if ((cpf[8]) == 8)
        printf("A origem do CPF é: São Paulo");
    else if ((cpf[8]) == 9)
        printf("A origem do CPF é: Paraná ou Santa Catarina");
    else
        printf("Emissor inválido");
}

int main()
{
	int cpf[11];
	int m1[9]={10,9,8,7,6,5,4,3,2};
	int m2[10]={11,10,9,8,7,6,5,4,3,2};
	int i;
	printf("Entre com os 11 digitos do CPF:");
	for(i=0;i<11;i++)
	scanf("%d", &cpf[i]);

    if(calculaDigito(cpf, m1, 9) == cpf[9] &&
        calculaDigito(cpf, m2, 10) == cpf[10] &&
        !todosRepetidos(cpf))
{
        imprimeRegiaoOrigem(cpf);
	    printf("\nCPF valido.");
}
    else
	    printf("\nErro no CPF.");
	    
	return 0;
}