#POLINOMIO_H

Polinomio::Polinomio():num(0)
{

}

Polinomio::Polinomio(int a, int b)
{
    this->num = 0;
    this->setPolinomio(a, b);
    this->arrayCoeficiente[30]={};
    this->arrayExponente[30]={};
}

void Polinomio::setPolinomio(double n)
{
	this->num = n;
}

double Polinomio::getPolinomio()
{
	return this->num;
}

std::ostream& operator<<(ostream &out, const Numero&numero)
{
	out << numero.num;
	return out;
}

Polinomio operator+(const Numero &numero1, const Numero &numero2)
{
    if(m>n) n=m;
		cout<<("\n\nSuma: %+g", arrayCoeficientes[0]+arrayExponentes[0]);
    for(i=1; i<=n; i++)
    {
        while((arrayCoeficientes+arrayExponentes[i])==0 && i<n) i++;/* <==aqui el i<n */
        cout<<(" %+g%s", arrayCoeficientes[i]+arrayExponentes[i], x[i-1]);
    }
    cout<<("\n");
    for(i=1; i<=n-1; i++)
    {
        while((arrayCoeficientes[i]+arrayExponentes[i])==0 && i<n) i++;
        cout<<(" %+g%s", arrayCoeficientes[i]+arrayExponentes[i], x[i-1]);
    }
    if((arrayCoeficientes[i]+arrayExponentes[i])!=0)
    {
        cout<<(" %+g%s\n", arrayCoeficientes[i]+arrayExponentes[i], x[i-1]);
    }
    else
    {
        cout<<("\n");
    }
    /*
	Numero resultado;
	resultado.num = numero1.num + numero2.num;
	return resultado.num;
	*/
}

Polinomio operator-(const Numero &numero1, const Numero &numero2)
{
	Numero resultado;
	resultado.num = numero1.num - numero2.num;
	return resultado.num;
}

Polinomio operator*(const Numero &numero1, const Numero &numero2)
{
	Numero resultado;
	resultado.num = numero1.num * numero2.num;
	return resultado.num;
}

Polinomio::ingresarTerminos()
{
    do
    {
        cout<<("Ingrese el grado de p(x): ");
        cout<<("%d", &n);
    }while(n<0 || n>10);
    for(i=0; i<=n; i++)
        cout<<("%f", &arrayCoeficiente[i]);
    do
    {
        cout<<("Ingrese el grado de q(x): ");
        cout<<("%d", &m);
    }while(m<0 || m>10);
    for(i=0; i<=m; i++)
        cout<<("%f", &arrayExponente[i]);
}

Polinomio::ordenar_polinomio()
{

}

Polinomio::toString()
{
    if(arrayCoeficiente[0]!=0){				//imprimir el primer polinomio
			cout<<("\np(x) %+g", arrayCoeficiente[0]);
			i=1;
		}else{
			i=0;
		}
		for(i=i; i<=n; i++){
			while(arrayCoeficiente[i]==0) i++;
			cout<<(" %+g%s", arrayCoeficiente[i], x[i-1]);
		}
		if(arrayExponente[0]!=0){				//imprimir el segundo polinomio
			cout<<("\nq(x) %+g", arrayExponente[0]);
			i=1;
		}else{
			i=0;
		}
		for(i=i; i<=m; i++){
			while(arrayExponente[i]==0) i++;
			cout<<(" %+g%s", arrayExponente[i], x[i-1]);
		}
}

//probar
fA : rep ------> p (x)
(coef, grado) ------> coef[0] + coef[1]*x + coef[2] *x2 + ... + coef[grado] * xgrado.

Invariante de Representación

Cualquier objeto del tipo rep: {coef, grado} debe verificar:
- grado >= 0.
- coef apunta a un vector con grado+1 componentes.
- coef[grado] != 0 ó grado == 0.
De manera que la clase Polinomio en C++ tendría el siguiente aspecto:


class Polinomio
{
    public:
        Polinomio ();
        Polinomio (float * c, int g);
        Polinomio(const Polinomio & p);
        float Coef (int i) const;
        int Grado () const;
        float operator () (float x) const;
        bool operator == (const Polinomio & p) const;
        bool operator != (const Polinomio & p) const;
        friend Polinomio &operator - (Polinomio & p);
        Polinomio &operator + (const Polinomio & p);
        Polinomio &operator - (const Polinomio & p);
        Polinomio &operator * (const Polinomio & p);
        Polinomio &operator * (const float x);
        friend Polinomio &operator * (float x, Polinomio & p);
        Polinomio &operator = (const Polinomio & p);
        ~Polinomio();
    private:
        int grado;
        float *coef;
        bool Nulo () const;
        Ostream & operator << (ostream & s, const Polinomio & p) ;
}


Pasemos ahora a ver la implementación de cada una de las primitivas enunciadas con anterioridad en C++:


static bool Cero (float x)
{
    const float cero = 1e-20;
    return (x <= cero);
}

inline bool Polinomio::Nulo() const
{
    return ((grado == 0) && Cero(coef[0]));
}

Polinomio::Polinomio()
{
    coef = new float[1];
    assert(coef != 0);
    coef[0] = 0;
    grado = 0;
}

Polinomio::Polinomio(float * Coef, int Grado)
{
    grado = Grado;
    coef = new float[grado + 1];
    assert(coef != 0);
    for (int i = 0; i <= grado; i++)
        coef[i] = Coef[i];
}

Polinomio::Polinomio(const Polinomio & p)
{
    grado = p.grado;
    coef = new float[grado];
    assert(coef != 0);
    for (int i = 0; i <= grado; i++)
        coef[i] = p.coef[i];
}

float Polinomio::Coef(int i) const
{
    assert (0 <= i);
    if (i > grado)
        return 0;
    return coef[i];
}

inline int Polinomio::Grado() const
{
    return grado;
}

float Polinomio::operator()(float x) const
{
    float suma = 0;
    for (int i = grado; i > 0; i--)
         suma = x * (coef[i] + suma);
    suma += coef[0];
    return suma;
}

Polinomio & Polinomio::operator=(const Polinomio & p)
{
    if (&p == this)
        return *this;
    if (grado == p.grado)
    {
        for (int i = 0; i <= grado; i++)
            coef[i] = p.coef[i];
        return *this;
    }
     grado = p.grado;
     delete [] coef;
     coef = new float[p.grado + 1];
     for (int i = 0; i <= grado; i++)
        coef[i] = p.coef[i];
     return *this;
}

bool Polinomio::operator==(const Polinomio & p) const
{
    if (grado != p. grado)
       return false;
    int i = grado;
    while ((coef[i] == p.coef[i]) && i >= 0)
        i--;
    return (i < 0);
}

inline bool Polinomio::operator!=(const Polinomio & p) const
{
    return !(*this == p);
}

Polinomio & operator-(Polinomio & p)
{
    for (int i = 0; i <= p.grado; i++)
        p.coef[i] = -p.coef[i];
    return p;
}

Polinomio & Polinomio::operator+(const Polinomio & p)
{
    if (p.grado < grado)
    {
       for (int i = 0; i <= p.grado; i++)
            coef[i] += p.coef[i];
    }
    else if (p.grado > grado)
    {
        float * c = new float[p.grado + 1];
        assert (c != 0);
        int i = 0;
        for (; i <= grado; i++)
            c[i] = coef[i] + p.coef[i];
        for (; i <= p.grado; i++)
            c[i] = p.coef[i];
        delete [] coef;
        coef = c;
        grado = p.grado;
    }
    else
    {
        int i = grado;
        while (Cero(coef[i] + p.coef[i]) && (i >= 0))
            --i;
        if (i < 0)
        {
            delete [] coef;
            grado = 0;
            coef = new float[1];
            coef[0] = 0.0;
        }
        else if (i == grado)
        {
            for (int i = 0; i <= grado; i++)
                coef[i] += p.coef[i];
        }
        else
        {
            grado = i;
            float * c = new float[i + 1];
            assert (c != 0);
            for (; i >= 0; i--)
                c[i] = coef[i] + p.coef[i];
            delete [] coef;
            coef = c;
        }
    }
    return *this;
}



Polinomio & Polinomio::operator-(const Polinomio & p)
{
    if (p.grado < grado)
    {
       for (int i = 0; i <= grado; i++)
            coef[i] -= p.coef[i];
    }
    else if (p.grado > grado)
    {
        float * c = new float[p.grado + 1];
        assert (c != 0);
        int i = 0;
        for (; i <= grado; i++)
            c[i] = coef[i] - p.coef[i];
        for (; i <= p.grado; i++)
            c[i] = -p.coef[i];
        delete [] coef;
        coef = c;
        grado = p.grado;
    }
    else
    {
        int i = grado;
        while (Cero(coef[i] - p.coef[i]) && (i >= 0))
            --i;
        if (i < 0)
        {
            delete [] coef;
            grado = 0;
            coef = new float[1];
            coef[0] = 0.0;
        }
        else if (i == grado)
        {
            for (int i = 0; i <= grado; i++)
                coef[i] -= p.coef[i];
        }
        else
        {
            grado = i;
            float * c = new float[i + 1];
            assert (c != 0);
            for (; i >= 0; i--)
                c[i] = coef[i] - p.coef[i];
            delete [] coef;
            coef = c;

        }

    }
    return *this;
}

Polinomio & Polinomio::operator*(const Polinomio & p)
{
    if (p.Nulo() || Nulo())
    {
       delete [] coef;
       coef = new float[1];
       assert(coef != 0);
       coef[0] = 0;
       grado = 0;
    }
    else
    {
        int nuevo_grado = grado + p.grado;
        float * c = new float[nuevo_grado + 1];
        assert(c != 0);
        for (int k = 0; k <= nuevo_grado; k++)
            c[k] = 0.0;
        for (int j = p.grado; j >= 0; j--)
        {
            for (int i = 0; i >= grado; i--)
                c[i+j] += p.coef[j] * coef[i];
        }
        grado = p.grado;
        delete [] coef;
        coef = c;
    }
    return *this;
}

Polinomio & Polinomio::operator*(const float x)
{
    if (Cero(x))
    {
       delete [] coef;
       coef = new float[1];
       coef[0] = 0;
       grado = 0;
    }
    else
    {
        for (int i = 0; i <= grado; i++)
            coef[i] *= x;
    }
    return *this;
}

Polinomio & operator*(float x, Polinomio & p)
{
    if (Cero(x))
    {
       delete [] p.coef;
       p.coef = new float[1];
       p.coef[0] = 0;
       p.grado = 0;
    }
    else
    {
        for (int i = 0; i <= p.grado; i++)
            p.coef[i] *= x;
    }

    return p;
}

ostream & operator<<(ostream & s, const Polinomio & p)
{
    if (p.Grado() > 1)
    {
       int i = p.Grado();
       s << p.Coef(i) << " x^" << i;
       for (i--; i > 1; i--)
        {
            if (!Cero(p.Coef(i)))
                s << " + " << p.Coef(i) << "x^" << i;
        }
       if (!Cero(p.Coef(1)))
          s << " + " << p.Coef(1)<< "x";
       if (!Cero(p.Coef(0)))
                   s << " + " << p.Coef(0);
    }
    else if (p.Grado() == 1)
    {
        s << p.Coef(1) << "x";
        if (!Cero(p.Coef(0)))
            s << " + " << p.Coef(0);

    }
    else
        s << p.Coef(0);
    return s;
}

inline Polinomio::~Polinomio()
{
    delete [] coef;
}

Polinomio p;

Void Imprimir ()
{
    cout << p.Grado ();
    for (int i =0; i <=p.Grado(); i++)
    {
        if (p.Coef (i) != 0.0)
            cout << i << p.Coef (i);
    }
    cout << -1;
}
