Algoritmo Calculadora
    Definir num1, num2 Como Real
    Definir operacion Como Caracter
    
    Escribir "Ingrese una operaci�n (+, -, *, /): "
    Leer operacion
    Escribir "Ingrese dos n�meros: "
    Leer num1, num2
    
    Segun operacion Hacer
        Caso '+':
            Escribir "Resultado: ", num1 + num2
        Caso '-':
            Escribir "Resultado: ", num1 - num2
        Caso '*':
            Escribir "Resultado: ", num1 * num2
        Caso '/':
            Si num2 <> 0 Entonces
                Escribir "Resultado: ", num1 / num2
            Sino
                Escribir "Error: Divisi�n por cero."
            FinSi
        De Otro Modo:
            Escribir "Operaci�n no v�lida."
    FinSegun
FinAlgoritmo
