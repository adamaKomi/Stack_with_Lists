#pragma once
#include <stdexcept>
#include <iostream>
#include <cctype>// pour la fonction isspace()
#include <string>

using namespace std;


// structure de la liste chainée
template<typename MyType>
struct List {
    MyType val; // valeur
    List<MyType>* suiv;// pointeur vers le suivant
};

// la classe template
template <class MyType>
class Stack
{
private:
    List<MyType>* MyList; // un Noeud de la pile
public:
    Stack();
    Stack(const Stack<MyType>& stack); // Constructeur par copie
    Stack<MyType>& operator=(const Stack<MyType>& stack); // operateur d'assignation

    bool isEmpty() const;
    void clear();

    void Push(MyType object);
    MyType Pop();
    int get_size();

    void PrintStack();

    ~Stack();
};


template<class MyType>
inline Stack<MyType>::Stack()
    :MyList(nullptr)
{}


// Constructeur par copie
template<class MyType>
inline Stack<MyType>::Stack(const Stack<MyType>& stack)
    : MyList(nullptr)
{
    if (stack.MyList == nullptr) return;

    // On copie les éléments dans l'ordre inverse pour recréer la pile
    List<MyType>* current = stack.MyList;
    Stack<MyType> tmpStack;

    while (current) {
        tmpStack.Push(current->val);
        current = current->suiv;
    }

    // Réempile les éléments pour rétablir l'ordre original
    while (!tmpStack.isEmpty()) {
        this->Push(tmpStack.Pop());
    }
}

// Opérateur d'assignation
template<class MyType>
inline Stack<MyType>& Stack<MyType>::operator=(const Stack<MyType>& stack)
{
    if (this != &stack) {
        clear(); // Vide la pile actuelle

        if (stack.MyList != nullptr) {
            // On copie les éléments dans l'ordre inverse pour recréer la pile
            List<MyType>* current = stack.MyList;
            Stack<MyType> tmpStack;

            while (current) {
                tmpStack.Push(current->val);
                current = current->suiv;
            }

            // Réempile les éléments pour rétablir l'ordre original
            while (!tmpStack.isEmpty()) {
                this->Push(tmpStack.Pop());
            }
        }
    }
    return *this;
}


// verifier si la pile est vide
template<class MyType>
inline bool Stack<MyType>::isEmpty() const
{
    return (this->MyList == nullptr);
}


// pour supprimer la pile
template <typename MyType>
void Stack<MyType>::clear() {
    while (!isEmpty()) {
        Pop();
    }
}

// empiler un element
template<class MyType>
inline void Stack<MyType>::Push(MyType object)
{
    List<MyType>* n = new List<MyType>{ object, this->MyList };
    this->MyList = n;
    return;
}


// depiler un element
template<class MyType>
inline MyType Stack<MyType>::Pop()
{

    if (this->isEmpty()) {
        throw std::underflow_error("\nImpossible de dépiler : la pile est vide");
    }
    List<MyType>* tmp = MyList;
    MyType val = tmp->val;

    MyList = MyList->suiv;
    delete tmp;

    return val;
}

// claculer la taille de la pile
template<class MyType>
inline int Stack<MyType>::get_size()
{
    // creer une pile temporaire
    Stack<MyType> tmpStack = *this;

    int size = 0;

    while (!tmpStack.isEmpty())
    {
        size++;
        tmpStack.Pop();
    }
    return size;
}


// afficher une pile
template<class MyType>
inline void Stack<MyType>::PrintStack()
{
    if (this->isEmpty()) {
        std::cout << "La pile est vide" << std::endl;
        return;
    }

    // creer une pile temporaire
    Stack<MyType> tmp = *this;

    // afficher tant que la pile est non vide
    while (!tmp.isEmpty()) {
        cout << tmp.MyList->val << " ";
        tmp.Pop();
    }

    std::cout << std::endl;

}



template<class MyType>
inline Stack<MyType>::~Stack()
{
    while (!isEmpty()) {
        Pop();
    }
}