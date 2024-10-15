/*
Yumee Chung
A01712059

ver, insertar, eliminar los empleados del candy shop
utilizando una lista doblemente encadenada
*/

template <class T> class Emplist;

template <class T> class Link{
public:
    Link(T);
    Link(T, Link<T>*, Link<T>*);
    
    T value;
    Link<T> *previous;
    Link<T> *next;

    friend class Emplist<T>;
};

template <class T>
Link<T>::Link(T val):value(val), previous(0), next(0) {}

template <class T>
Link<T>::Link(T val, Link<T>* prev, Link<T>* nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
class Emplist{
private:
    Link<T> *head;
    Link<T> *tail;
    int size;
    void clear();

public:
    Emplist();
    ~Emplist();
    int getSize() const { return size;}
    void insertion (T);
    void deleteAt(int);

    std::string toString();
};

template <class T>
Emplist<T>::Emplist():head(0),tail(0),size(0) {}

template <class T>
Emplist<T>::~Emplist(){
    clear();
}

template <class T>
void Emplist<T>::clear(){
    Link<T> *p, *q;
    p = head;
    while(p != 0){
        q = p->next;
        delete p;
        p = q;
    }
    head = 0;
    tail = 0;
    size = 0;
}

template <class T>
void Emplist<T>::insertion(T val){ //agregar empleados
    Link<T> *newLink = new Link<T>(val);
    if (head == 0){
        head = tail = newLink;
    } else{
        tail->next = newLink;
        newLink->previous = tail;
        tail = newLink;
    }
    size++;
}

template <class T>
void Emplist<T>::deleteAt(int index){
    int pos = 0;
    Link<T> *p, *q;

    p = head;

    if(index == 0){
        p = p->next;
        delete head;
        head = p;
        if (head != 0) {
            head->previous = 0;
        } else {
            tail = 0;
        }
    } else if(index == size-1){
        p = tail;
        q = p->previous;
        delete p;
        tail = q;
        if (tail != 0) {
            tail->next = 0;
        } else {
            head = 0;
        }
    }
    else{
        while(pos != index-1){
            p = p->next;
            pos++;
        }
        q = p->next;
        p->next = q->next;
        if (q->next != 0) {
            q->next->previous = p;
        } else {
            tail = p;
        }
        delete q;
    }
    size--;
}

template <class T>
std::string Emplist<T>::toString(){
    std::stringstream aux;
    int index = 0;
    Link<T> *p;

    p = head;
    while (p != 0){
        aux << index;
        aux << ". ";
        aux << p->value;
        if(p->next != 0){
            aux << "\n";
            index++;
        }
        p = p->next;
    }
    return aux.str();
}
