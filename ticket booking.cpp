#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Movie {
    string title;
    string date;
    string time;
};

struct Ticket {
    int id;
    Movie movie;
    int seat;
};

vector<Ticket> tickets;

int get_ticket_id() {
    static int id = 1;
    return id++;
}

void book_ticket() {
    Movie movie;
    cout << "Enter movie title: ";
    cin >> movie.title;
    cout << "Enter date (dd/mm/yyyy): ";
    cin >> movie.date;
    cout << "Enter time (hh:mm): ";
    cin >> movie.time;
    int seat;
    cout << "Enter seat number: ";
    cin >> seat;
    Ticket ticket;
    ticket.id = get_ticket_id();
    ticket.movie = movie;
    ticket.seat = seat;
    tickets.push_back(ticket);
    cout << "Ticket booked successfully. Your ticket ID is " << ticket.id << endl;
}

void cancel_ticket() {
    int ticket_id;
    cout << "Enter ticket ID: ";
    cin >> ticket_id;
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i].id == ticket_id) {
            tickets.erase(tickets.begin() + i);
            cout << "Ticket cancelled successfully." << endl;
            return;
        }
    }
    cout << "Ticket not found." << endl;
}

void view_tickets() {
    cout << "Tickets booked:" << endl;
    for (int i = 0; i < tickets.size(); i++) {
        cout << "Ticket ID: " << tickets[i].id << endl;
        cout << "Movie title: " << tickets[i].movie.title << endl;
        cout << "Date: " << tickets[i].movie.date << endl;
        cout << "Time: " << tickets[i].movie.time << endl;
        cout << "Seat number: " << tickets[i].seat << endl;
        cout << endl;
    }
}

int main() {
    while (true) {
        int choice;
        cout << "Menu:\n1. Book ticket\n2. Cancel ticket\n3. View tickets\n4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                book_ticket();
                break;
            case 2:
                cancel_ticket();
                break;
            case 3:
                view_tickets();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
};
