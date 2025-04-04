#ifndef CONFIG_H
#define CONFIG_H

class Config
{
public:
    Config(int filasTablero, int columnasTablero, int minasTablero,
           bool modoDesarrolladorTablero, int vidasTablero);

    // Getters
    int getfilasTablero() const;
    int getcolumnasTablero() const;
    int getminasTablero() const;
    bool getmodoDesarrolladorTablero() const;
    int getvidasTablero() const;

    // Setters
    bool setfilasTablero(int filas);
    bool setcolumnasTablero(int columnas);
    bool setminasTablero(int minas);
    bool setmodoDesarrolladorTablero(bool modo);
    bool setvidasTablero(int vidas);

    void menuConfiguracion();

private:
    int filasTablero;
    int columnasTablero;
    int minasTablero;
    bool modoDesarrolladorTablero;
    int vidasTablero;
};

#endif // CONFIG_H
