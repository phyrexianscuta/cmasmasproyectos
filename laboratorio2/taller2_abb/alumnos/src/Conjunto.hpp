
template<class T>
Conjunto<T>::Conjunto() {
    _raiz = nullptr;
}

template<class T>
Conjunto<T>::~Conjunto() {
}

template<class T>
bool Conjunto<T>::pertenece(const T &clave) const {
    if (cardinal() == 0) {
        return false;
    } else {
        if (clave == _raiz->valor) {
            return true;
        } else {
            bool a = clave < _raiz->valor && Conjunto(_raiz->izq).pertenece(clave);
            bool b = clave > _raiz->valor && Conjunto(_raiz->der).pertenece(clave);
            return (a || b);
        }
    }
}


template<class T>
void Conjunto<T>::insertar(const T &clave) {
    bool per = pertenece(clave);
    if (!per) {
        insertarSinPertenencia(clave);
    }
}

template<class T>
void Conjunto<T>::remover(const T &clave) {
    if (_raiz != nullptr) {
        Nodo *izq = _raiz->izq;
        Nodo *der = _raiz->der;

        if (clave == _raiz->valor) {
            if (izq == nullptr && der == nullptr) {
                Nodo *padre = darPadre(_raiz->valor);
                if(padre!= nullptr){
                    if(padre->der == _raiz){
                        padre->der = nullptr;
                    } else{
                        padre->izq = nullptr;
                    }
                }

                _raiz = nullptr;

            } else if (izq == nullptr) {
                Nodo *padre = darPadre(_raiz->valor);
                if(padre != nullptr){
                    if(padre->der == _raiz){
                        padre->der = der;
                    } else{
                        padre->izq = der;
                    }
                }

                _raiz = nullptr;

            } else if (der == nullptr) {
                //el problema es que busca el valor en un subarbol ly no en el arbol entero
                Nodo *padre = darPadre(_raiz->valor);
                if(padre != nullptr){
                    if(padre->der == _raiz){
                        padre->der = der;
                    } else{
                        padre->izq = der;
                    }
                }

                _raiz = nullptr;

            } else {

            }
        } else if (_raiz->valor < clave) {
            Conjunto(der).remover(clave);
        } else {
            Conjunto(izq).remover(clave);

        }
    }
}

template<class T>
const T &Conjunto<T>::siguiente(const T &clave) {

}

template<class T>
const T &Conjunto<T>::minimo() const {
    assert(false);
}

template<class T>
const T &Conjunto<T>::maximo() const {
    assert(false);
}

template<class T>
unsigned int Conjunto<T>::cardinal() const {
    if (_raiz == nullptr) {
        return 0;
    } else {
        return (1 + Conjunto(_raiz->der).cardinal() + Conjunto(_raiz->izq).cardinal());
    }

}

template<class T>
void Conjunto<T>::mostrar(std::ostream &) const {
    assert(false);
}

template<class T>
Conjunto<T>::Conjunto(Conjunto::Nodo *abb) {

    _raiz = abb;

}

template<class T>
void Conjunto<T>::insertarSinPertenencia(const T &clave) {
    if (_raiz == nullptr) {
        Nodo *elemAgregado = new Nodo(clave);
        _raiz = elemAgregado;
    } else {
        if (clave > _raiz->valor) {
            Conjunto ladoDer = Conjunto(_raiz->der);
            ladoDer.insertar(clave);
            _raiz->der = ladoDer._raiz;


            // parte para testear x2 : x2 es  una referencia a la parte derecha del conjunto
            //Conjunto x2 = Conjunto(_raiz->der);
            //x2.insertar(9);
            //x2.cardinal();
            //fin
        } else {
            Conjunto ladoIzq = Conjunto(_raiz->izq);
            ladoIzq.insertar(clave);
            _raiz->izq = ladoIzq._raiz;
        }
    }
}

template<class T>
typename Conjunto<T>::Nodo * Conjunto<T>::darPadre(const T &clave) {
    Nodo *padre;
    if (_raiz->valor == clave) {
        padre = nullptr;
    } else {
        Nodo *der = _raiz->der;
        Nodo *izq = _raiz->izq;
        if ((der != nullptr && der->valor == clave) || (izq != nullptr && izq->valor == clave)) {
            padre = _raiz;
        } else {
            if (clave > _raiz->valor) {
                padre = Conjunto(der).darPadre(clave);
            } else {
                padre = Conjunto(izq).darPadre(clave);
            }
        }
    }
    return padre;
}

template<class T>
typename Conjunto<T>::Nodo *Conjunto<T>::darNodo(const T &clave) {
    Nodo *nodo;

    if (_raiz->valor == clave) {
        nodo = _raiz;
    } else {
        Nodo *der = _raiz->der;
        Nodo *izq = _raiz->izq;
        if (clave > _raiz->valor) {
            nodo = Conjunto(der).darNodo(clave);
        } else {
            nodo = Conjunto(izq).darNodo(clave);
        }

    }
    return nodo;
}


template<class T>
Conjunto<T>::Nodo::Nodo(const T &v) {
    valor = v;
    izq = nullptr;
    der = nullptr;
}

