// Stack_with_Lists.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Stack.h"

int main() {
    try {
        // Exemple avec des entiers
        Stack<int> intStack;
        std::cout << "Empilage d'entiers dans la pile :" << std::endl;

        intStack.Push(10);
        intStack.Push(20);
        intStack.Push(30);

        std::cout << "Contenu de la pile : ";
        intStack.PrintStack();

        std::cout << "Taille de la pile : " << intStack.get_size() << std::endl;

        std::cout << "Depilement : " << intStack.Pop() << std::endl;
        std::cout << "Contenu apres depilement : ";
        intStack.PrintStack();

        // Exemple avec des chaînes de caractères
        Stack<std::string> stringStack;
        std::cout << "\nEmpilage de chaenes de caracteres dans la pile :" << std::endl;

        stringStack.Push("Bonjour");
        stringStack.Push("Monde");
        stringStack.Push("C++");

        std::cout << "Contenu de la pile : ";
        stringStack.PrintStack();

        std::cout << "Taille de la pile : " << stringStack.get_size() << std::endl;

        std::cout << "Depilement : " << stringStack.Pop() << std::endl;
        std::cout << "Contenu après depilement : ";
        stringStack.PrintStack();
    }
    catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
