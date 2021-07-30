/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calculadora.h"

#define SUMA 1
#define RESTA 2
#define MULTIPLICACION 3
#define DIVISION 4

void calculadora_1(char *host)
{
	CLIENT *clnt;
	float *result_1;
	args sumar_1_arg;
	float *result_2;
	args restar_1_arg;
	float *result_3;
	args multiplicar_1_arg;
	float *result_4;
	args dividir_1_arg;

	int op;
	float n1, n2;
	printf("Escoja una operación: \n");
	printf("1. Suma\n");
	printf("2. Resta\n");
	printf("3. Multiplicación\n");
	printf("4. División\n");
	scanf("%d", &op);
	printf("Ingrese el primer número: ");
	scanf("%f", &n1);
	printf("Ingrese el segundo número: ");
	scanf("%f", &n2);

#ifndef DEBUG
	clnt = clnt_create(host, CALCULADORA, CALCULADORA_VER, "udp");
	if (clnt == NULL)
	{
		clnt_pcreateerror(host);
		exit(1);
	}
#endif /* DEBUG */

	if (op == SUMA)
	{
		sumar_1_arg.num1 = n1;
		sumar_1_arg.num2 = n2;
		result_1 = sumar_1(&sumar_1_arg, clnt);
		printf("Sumar %.02f mas %.02f da %.02f\n", sumar_1_arg.num1, sumar_1_arg.num2, *result_1);
		if (result_1 == (float *)NULL)
		{
			clnt_perror(clnt, "call failed");
		}
	}
	else if (op == RESTA)
	{
		restar_1_arg.num1 = n1;
		restar_1_arg.num2 = n2;
		result_2 = restar_1(&restar_1_arg, clnt);
		printf("Restar %.02f menos %.02f da %.02f\n", restar_1_arg.num1, restar_1_arg.num2, *result_2);
		if (result_2 == (float *)NULL)
		{
			clnt_perror(clnt, "call failed");
		}
	}
	else if (op == MULTIPLICACION)
	{
		multiplicar_1_arg.num1 = n1;
		multiplicar_1_arg.num2 = n2;
		result_3 = multiplicar_1(&multiplicar_1_arg, clnt);
		printf("Sumar %.02f mas %.02f da %.02f\n", multiplicar_1_arg.num1, multiplicar_1_arg.num2, *result_3);
		if (result_3 == (float *)NULL)
		{
			clnt_perror(clnt, "call failed");
		}
	}
	else if (op == DIVISION)
	{
		dividir_1_arg.num1 = n1;
		dividir_1_arg.num2 = n2;
		// Se comprueba división por cero.
		if (dividir_1_arg.num2 == 0.0f)
		{
			printf("No se puede dividir por cero.\n");
		}
		else
		{
			result_4 = dividir_1(&dividir_1_arg, clnt);
			printf("Dividir %.02f por %.02f da %.02f\n", dividir_1_arg.num1, dividir_1_arg.num2, *result_4);
			if (result_4 == (float *)NULL)
			{
				clnt_perror(clnt, "call failed");
			}
		}
	}
	else
	{
		printf("Operación no válida.\n");
	}
#ifndef DEBUG
	clnt_destroy(clnt);
#endif /* DEBUG */
}

int main(int argc, char *argv[])
{
	char *host;

	if (argc < 2)
	{
		printf("usage: %s server_host\n", argv[0]);
		exit(1);
	}
	host = argv[1];
	calculadora_1(host);
	exit(0);
}