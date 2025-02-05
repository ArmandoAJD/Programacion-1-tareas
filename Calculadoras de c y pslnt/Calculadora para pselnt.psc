Algoritmo Calculadora
    Definir num1, num2 Como Real
    Definir operacion Como Caracter
    
    Escribir "Ingrese una operación (+, -, *, /): "
    Leer operacion
    Escribir "Ingrese dos números: "
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
                Escribir "Error: División por cero."
            FinSi
        De Otro Modo:
            Escribir "Operación no válida."
    FinSegun
FinAlgoritmo
