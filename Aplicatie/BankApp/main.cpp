#include "Bank.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int choice;
    string numarulContului, numarulContDestinatarului;
    double balantaInitiala, suma;
    vector<BankAccount> conturi;

    while (true)
    {
        cout << "Aplicatie banca" << endl;
        cout << "1. Creeaza cont" << endl;
        cout << "2. Depune" << endl;
        cout << "3. Retrage" << endl;
        cout << "4. Transfera" << endl;
        cout << "5. Afiseaza toate conturile" << endl;
        cout << "6. Iesire" << endl;
        cout << "Introdu numarul operatiunii: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Introduceti numarul contului: ";
            cin >> numarulContului;
            while (numarulContului.length() != 16)
            {
                cout << "\nNumarul contului este gresit. Numarul contului trebuie sa aiba 16 cifre." << endl;
                cout << "Introduceti numarul contului: ";
                cin >> numarulContului;
            }


            for (auto& cont : conturi)
            {
                while (cont.getNumarulContului() == numarulContului)
                {
                    cout << "\nNumarul introdus este deja folosit. Alege alt numar." << endl;
                    cout << "Introduceti numarul contului: ";
                    cin >> numarulContului;
                }

            }
            cout << "Introduceti balanta initiala: ";
            cin >> balantaInitiala;
            conturi.push_back(BankAccount(numarulContului, balantaInitiala));
            cout << "Cont bancar creat cu succes." << endl;
            break;

        case 2:
            cout << "Introduceti numarul contului: ";
            cin >> numarulContului;
            cout << "Introduceti suma de depunere: ";
            cin >> suma;
            for (auto& cont : conturi)
            {
                if (cont.getNumarulContului() == numarulContului)
                {
                    cont.depunere(suma);
                    cout << "Depunere reusita." << endl;
                    break;
                }
            }
            break;

        case 3:
            cout << "Introduceti numarul contului: ";
            cin >> numarulContului;
            cout << "Introduceti suma de retrage: ";
            cin >> suma;
            for (auto& cont : conturi)
            {
                if (cont.getNumarulContului() == numarulContului)
                {
                    cont.retragere(suma);
                    break;
                }
            }
            break;

        case 4:
        {
            cout << "Introduceti numarul contului expeditorului: ";
            cin >> numarulContului;
            cout << "Introduceti numarul contului destinatarului: ";
            cin >> numarulContDestinatarului;
            cout << "Introduceti suma de transfer: ";
            cin >> suma;
            BankAccount* contExpeditor = nullptr;
            BankAccount* contDestinatar = nullptr;

            for (auto& cont : conturi)
            {
                if (cont.getNumarulContului() == numarulContului)
                {
                    contExpeditor = &cont;
                }
                if (cont.getNumarulContului() == numarulContDestinatarului)
                {
                    contDestinatar = &cont;
                }
            }
            if (contExpeditor != nullptr && contDestinatar != nullptr)
            {
                contExpeditor->transfer(*contDestinatar, suma);
            }
            else
            {
                cout << "Numarul contului este invalid." << endl;
            }
        }
        break;
        case 5:
        {
            cout << "Toate conturile:" << endl;
            for (const auto& cont : conturi)
            {
                cout << "Numarul contului: " << cont.getNumarulContului() << endl;
                cout << "Balanta contului: " << cont.getBalanta() << endl;
                cout << endl;
            }
        }
        break;
        case 6:
        {
            cout << "O zi buna. La revedere" << endl;
            return 0;
        }
        break;
        default:
            cout << "Nu exista aceasta operatiune." << endl;
        }
        cout << endl;
    }

    return 0;
}
