
template<class T>
Conjunto<T>::Conjunto() {
    _raiz = nullptr;
}

template<class T>
Conjunto<T>::~Conjunto() {
 //   destruirNodos();
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
            return (a||b);
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
void Conjunto<T>::remover(const T &) {
    assert(false);
}

template<class T>
const T &Conjunto<T>::siguiente(const T &clave) {

}
/*
template <class T>
const Nodo* Conjunto<T>::siguienteNodo(const T& clave){
    Nodo* proximoProvisorio = _raiz;

    if(proximoProvisorio->valor <= clave){
        Conjunto(_raiz->der).siguienteNodo(proximoProvisorio->valor);
    }
}
 */

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
        Nodo* elemAgregado = new Nodo(clave);
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
void Conjunto<T>::destruirNodos() {
    Nodo* actual = _raiz;
    delete _raiz;
}

template<class T>
Conjunto<T>::Nodo::Nodo(const T &v) {
    valor = v;
    izq = nullptr;
    der = nullptr;
}

