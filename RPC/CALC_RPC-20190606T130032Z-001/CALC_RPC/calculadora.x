struct args{
	float num1;
	float num2;
};

program CALCULADORA{
	version CALCULADORA_VER{
		float sumar(args) = 1;
		float restar(args) = 2;
		float multiplicar(args) = 3;
		float dividir(args) = 4;
	} = 1;
} = 0x30000001;