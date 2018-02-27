#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f(x) pow(x,3)-x-1
#define t(x) 3*pow(x,2)-1 //fonsiyonun türevi
#define g(x) x-((x*x*x-x-1)/(3*x*x-1))
void yarilamafonk() {
	int i = 1;
	double a = 1;
	double b = 2;
	double FA = f(a);
	while (i <= 10) {
		double p = (a + b) / 2;
		double FP = f(p);
		if (FP == 0 || (b - a) / 2 < 1e-3) {
			
			printf("yarilamamethodu p: %f\n", p);
			break;
			}
		printf("n=%d		a=%f	b=%f	f(p)=%f\n", i, a, b, FP);
			i=i+1;
			if (FA*FP > 0) {
				a = p;
				
			}
			else b = p;
}
}
void sabitnokta() {
	int i = 1;
	double p0 = 1.5;
	double p;
	while (i <= 10) {
		p = g(p0);
		printf("n=%d	p0:%f	p=%f\n", i, p0, p);
		if (fabs(p - p0) < 1e-3) {
			printf("p=%f\n", p);
			break;
		}
		i++;
		p0 = p;




	}
}
void newtonraphson() {
	int i = 1;
	double p0 = 1.5;
	double fp0 = f(p0);
	double tp0 = t(p0);

	while (i <= 10) {
		double p = p0 -( fp0 / tp0);
		printf("n:%d	p:%f\n", i, p);
		if (fabs(p - p0) < 1e-3) {
			printf("newton method ile kok:%f", p);
			break;
		}
		i++;
		p0 = p;

	}
}
void secant() {
	int i = 2;
	double p0 = 1;
	double p1 = 1.5;
	double q0 = f(p0);
	double q1 = f(p1);
	while (i <= 10) {

		double p = p1 - q1*(p1 - p0) / (q1 - q0);
		printf("n:%d		p:%f\n", i, p);
		if (fabs(p - p1) < 1e-3) {
			printf("secanta metodu kok:%f\n", p);
			break;
		}
		i++;
		p0 = p1;
		q0 = q1;
		p1 = p;
		q1 = f(p);
	}
}
void regulafalsi() {
	int i = 2;
	double p0 = 1;
	double p1 = 1.5;
	double q0 = f(p0);
	double q1 = f(p1);
	while (i <= 10)
	{
		double p = p1 - q1*(p1 - p0) / (q1 - q0);
		printf("n:%d	p:%f\n", i, p);
		if (fabs(p - p1) < 1e-3) {
			printf("regula falsi metodu kok:%f\n", p);
			break;
		}
		i++;
		double q = f(p);
		if (q*q1 < 0) { 
			p0 = p1;
			q0 = q1;
		}
		p1 = p;
		q1 = q;





	}
}


main()
{
	printf("yarilamamedhodu\n");
	yarilamafonk();
	sabitnokta();
	printf("nepton raphson\n");
	newtonraphson();
	printf("Secant\n");
	secant();
	printf("Regula Falsi\n");
	regulafalsi();

	getchar();

}