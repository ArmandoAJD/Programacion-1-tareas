// Revisor: Armando De León

Proceso Modulo
	Definir N,M Como Enteros
	Escribir "Ingrese el numero: "
	Leer N
	Escribir "Ingrese el divisor: "
	Leer M
	Si N MOD M = 0 Entonces
		Escribir M," es divisor exacto de ",N,"."
	SiNo
		Escribir "El resto de dividir ",N," por ",M," es: ",N MOD M
	FinSi
FinProceso
