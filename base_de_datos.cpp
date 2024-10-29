#include <iostream>
#include <fstream>
#include <sstream>
#include "DynamicArray_SR.hpp"
#include "LinkedList_SR.hpp"
#include "DoublyLinkedList_SR.hpp"

using namespace std;

struct Libro {
    int id;
    string title;
    string author;
    float average_rating;
    int num_page;
    int ratings_count;
    string publication_date;
    string publisher;

    friend ostream& operator<<(ostream& os, const Libro& libro) {
        os << "ID: " << libro.id << "\n"
           << "Titulo: " << libro.title << "\n"
           << "Autor: " << libro.author << "\n"
           << "Calificacion promedio: " << libro.average_rating << "\n"
           << "Numero de paginas: " << libro.num_page << "\n"
           << "Numero de calificaciones: " << libro.ratings_count << "\n"
           << "Fecha de publicacion: " << libro.publication_date << "\n"
           << "Publisher: " << libro.publisher << "\n";
        return os;
    }
};

void loadDataIntoArray(const string& filename, DynamicArray<Libro>& arr) {

    ifstream file(filename);
    string line;

    if (!file) {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
        Libro libro;

        getline(ss, temp, ',');
        libro.id = std::stoi(temp);

        getline(ss, libro.title, ',');

        getline(ss, libro.author, ',');

        getline(ss, temp, ',');
        libro.average_rating = stof(temp);

        getline(ss, temp, ',');
        libro.num_page = stoi(temp);

        getline(ss, temp, ',');
        libro.ratings_count = stoi(temp);

        getline(ss, libro.publication_date, ',');

        getline(ss, libro.publisher, ',');

        arr.push_back(libro);
    }

    file.close();
}

void loadDataIntoLinkedList(const string& filename, LinkedList<Libro>& list) {
    ifstream file(filename);
    string line;

    if (!file) {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
        Libro libro;

        getline(ss, temp, ',');
        libro.id = std::stoi(temp);

        getline(ss, libro.title, ',');

        getline(ss, libro.author, ',');

        getline(ss, temp, ',');
        libro.average_rating = stof(temp);

        getline(ss, temp, ',');
        libro.num_page = stoi(temp);

        getline(ss, temp, ',');
        libro.ratings_count = stoi(temp);

        getline(ss, libro.publication_date, ',');

        getline(ss, libro.publisher, ',');

        list.push_back(libro);
    }

    file.close();
}

void loadDataIntoDoublyLinkedList(const string& filename, DoublyLinkedList<Libro>& list) {
    ifstream file(filename);
    string line;

    if (!file) {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
        Libro libro;

        getline(ss, temp, ',');
        libro.id = std::stoi(temp);

        getline(ss, libro.title, ',');

        getline(ss, libro.author, ',');

        getline(ss, temp, ',');
        libro.average_rating = stof(temp);

        getline(ss, temp, ',');
        libro.num_page = stoi(temp);

        getline(ss, temp, ',');
        libro.ratings_count = stoi(temp);

        getline(ss, libro.publication_date, ',');

        getline(ss, libro.publisher, ',');

        list.push_back(libro);
    }

    file.close();
}

void buscarPorIDLista(const LinkedList<Libro>& list, int id) {
    Node<Libro>* current = list.getHead();

    while (current != nullptr) {
        if (current->data.id == id) {
            cout << current->data << endl;
            return;
        }
        current = current->next;
    }
    cout << "Libro con ID " << id << " no encontrado." << endl;
}

void buscarPorIDDobleLista(const DoublyLinkedList<Libro>& list, int id) {
    DoublyNode<Libro>* current = list.getHead();

    while (current != nullptr) {
        if (current->data.id == id) {
            cout << current->data << endl;
            return;
        }
        current = current->next;
    }
    cout << "Libro con ID " << id << " no encontrado." << endl;
}

void buscarPorIDDesdeElFinal(const DoublyLinkedList<Libro>& list, int id) {
    DoublyNode<Libro>* current = list.getTail();

    while (current != nullptr) {
        if (current->data.id == id) {
            cout << current->data << endl;
            return;
        }
        current = current->prev;
    }
    cout << "Libro con ID " << id << " no encontrado." << endl;
}

void buscarPorID(const DynamicArray<Libro>& arr, int id) {
    for (unsigned int i = 0; i < arr.size(); i++) {
        if (arr[i].id == id) {
            cout << arr[i] << endl;
            return;
        }
    }
    cout << "Libro con ID " << id << " no encontrado." << std::endl;
}

int main()
{
    DynamicArray<Libro> ejemplo;
    loadDataIntoArray("libros.csv", ejemplo);

    LinkedList<Libro> ejemplo1;
    loadDataIntoLinkedList("libros.csv", ejemplo1);

    DoublyLinkedList<Libro> ejemplo2;
    loadDataIntoDoublyLinkedList("libros.csv", ejemplo2);

    int id_search;
    cout << "Ingresa el ID del libro que deseas buscar: ";
    cin >> id_search;

    cout << "Información del libro (Arreglo):" << endl;
    buscarPorID(ejemplo, id_search);

    cout << "Información del libro (Lista ligada):" << endl;
    buscarPorIDLista(ejemplo1, id_search);

    cout << "Información del libro (Lista doblemente ligada desde inicio):" << endl;
    buscarPorIDDobleLista(ejemplo2, id_search);

    cout << "Información del libro (Lista doblemente ligada desde final):" << endl;
    buscarPorIDDesdeElFinal(ejemplo2, id_search);

    return 0;
};