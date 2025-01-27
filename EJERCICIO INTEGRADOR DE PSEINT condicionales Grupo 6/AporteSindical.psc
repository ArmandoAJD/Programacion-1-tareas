Algoritmo AporteSindical
	Escribir 'ingrese la edad del empleado:'
	Leer edad
	Escribir 'escribe el sueldo base del empleado:'
	Leer sueldo
	Si sueldo<10000 Entonces
		descuento <- sueldo*0.005
	SiNo
		Si sueldo>=10000 Y sueldo<=19999 Entonces
			descuento <- sueldo*0.01
		SiNo
			Si sueldo>=20000 Y sueldo<=29999 Entonces
				descuento <- sueldo*0.02
			SiNo
				descuento <- sueldo*0.025
			FinSi
		FinSi
	FinSi
	Si edad<=30 Entonces
		descuento <- descuento*0.2
	FinSi
	Escribir ' el aporte sindical es de: $', descuento
FinAlgoritmo
