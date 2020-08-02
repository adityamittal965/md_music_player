// Menu Driven Simulation of a Music Player
// Created by Aditya Mittal

/*
FUNCTIONALITIES :
L - Play Last  Song
N - Play Next Song
P - Play Previous Song
A - Add and play a new Song at current location
B - Add a new Song at the beginning of the Playlist
E - Add a new Song at the end of the Playlist
D - Display the current playlist
Q - Quit
*/

#include <iostream>
#include <cctype>
#include <string>
#include <limits>
#include <iomanip>
#include <list>

using namespace std ;

class Song{
    friend ostream &operator<<(ostream &os, const Song &s) ;
    string name{} ;
    string artist{} ;
    int rating{} ;
    
public :
    Song()
        : name{"Unknown"}{}
    
    Song(string name, string artist, int rating)
        : name{name}, artist{artist}, rating{rating}{
        } 
            
    string get_name() const{
        return name ;
    }
    
    string get_artist() const{
        return artist ;
    }
    
    int get_rating() const{
        return rating ;
    }
    
    bool operator <(const Song &rhs){
        return this->name < rhs.name ;
    }
    
    bool operator ==(const Song &rhs){
        return this->name == rhs.name ;
    }
} ;

ostream &operator <<(ostream &os, const Song &s){
    os << setw(20) << left  << s.name << setw(30) << left << s.artist << setw(2) << left << s.rating ;
    return os ;
}

// Function to Display Selection Menu
void display_menu(){
        cout << "\nF - Play First Song" << endl ;
        cout << "L - Play Last  Song" << endl ;
        cout << "N - Play Next Song" << endl ;
        cout << "P - Play Previous Song" << endl ;
        cout << "A - Add and play a new Song at current location" << endl ;
	cout << "B - Add a new Song at the beginning of the Playlist" << endl ;
	cout << "E - Add a new Song at the end of the Playlist" << endl ;
        cout << "D - Display the current playlist" << endl ;
        cout << "==================================================" << endl ;
        cout << "Enter a Selection(Q to quit): " ;
}

// Function to Play Current Song
void play_current_song(const Song &song){
    cout << "Playing :" << endl ;
    cout << song << endl ;
}


// Function to Display the Playlist
void display_playlist(const list <Song> playlist, const Song &current_song){
    list <Song> :: const_iterator it = playlist.begin() ;
    while(it != playlist.end()){
        cout << *it << endl ;
        it++ ;
    }
    cout << "Current Song : " << endl ;
    cout << current_song << endl ;
}

int main(){
    
    list <Song> playlist{
        { "God's Plan" , "Drake" , 5 } , 
        { "Never Be The Same" , "Camila Cabello" , 5 } , 
        { "Pray For Me" , "The Weekend and K.Lamar" , 4} , 
        { "The Middle" , "Zedd , Maren Morris & Grey" , 5} , 
        { "Wait" , "Maroone 5" , 4 } , 
        { "Whatever It Takes" , "Imagine Dragons" , 3 } 
    } ;
    
    list <Song> ::iterator current_song = playlist.begin() ;
    
    display_playlist(playlist, *current_song) ;
    
    char selection{} ;
    do{
        display_menu() ;
        cin >> selection ;
        
        if(toupper(selection) == 'F'){
            cout << "Playing First Song :" << endl ;
            current_song = playlist.begin() ;
            play_current_song(*current_song) ;
        }
        
        else if(toupper(selection) == 'L'){
            cout << "Playing Last Song :" << endl ;
            current_song = playlist.end() ;
            current_song-- ;
            play_current_song(*current_song) ;
        }
        
        else if(toupper(selection) == 'N'){
            cout << "Playing Next Song :" << endl ;
            if(*current_song == playlist.back()){
                cout << "Moving to start of Playlist" << endl ;
                current_song = playlist.begin() ;
            }
            else
                current_song++ ;
            play_current_song(*current_song) ;
        }
        
        else if(toupper(selection) == 'P'){
            cout << "Playing Previous Song :" << endl ;
            if(*current_song == playlist.front()){
                cout << "Moving to the end of playlist" << endl ;
                current_song = playlist.end() ;
                current_song-- ;
            }
            else
                current_song-- ;
            play_current_song(*current_song) ;
        }
        
        else if(toupper(selection) == 'A'){
            string name{} ;
            string artist{} ;
            int rating{} ;
	    getchar() ;
            cout << "Enter Song Name : " << endl ;
            getline(cin, name) ;
            cout << "Enter Artist Name" << endl ;
            getline(cin, artist) ;
            cout << "Enter Your Rating (1-5)" << endl ;
            cin >> rating ;
            cout << "Adding and Playing New Song : " << endl ;
            playlist.insert(current_song, Song(name, artist, rating)) ;
            current_song-- ;
            play_current_song(*current_song) ;
        }

	else if(toupper(selection) == 'B'){
	    string name{} ;
	    string artist{} ;
	    int rating{} ;
	    getchar() ;
	    cout << "Enter Song Name : " << endl ;
	    getline(cin, name) ;
	    cout << "Enter Artist Name" << endl ;
	    getline(cin, artist) ;
	    cout << "Enter Your Rating (1-5)" << endl ;
	    cin >> rating ;
	    cout << "Adding New Song at the beginning : " << endl ;
	    playlist.insert(playlist.begin(), Song(name, artist, rating)) ;
	}

	else if(toupper(selection) == 'E'){
            string name{} ;
            string artist{} ;
            int rating{} ;
            getchar() ;
            cout << "Enter Song Name : " << endl ;
            getline(cin, name) ;
            cout << "Enter Artist Name" << endl ;
            getline(cin, artist) ;
            cout << "Enter Your Rating (1-5)" << endl ;
            cin >> rating ;
            cout << "Adding New Song at the end : " << endl ;
            playlist.insert(playlist.end(), Song(name, artist, rating)) ;
        }

        
        else if(toupper(selection) == 'D'){
            cout << endl ;
            display_playlist(playlist, *current_song) ;
        }
        
        else if(toupper(selection) == 'Q'){
            cout << "Quitting" << endl ;
        }
        
        else{
            cout << "Invalid Choice, try again....." << endl ;
        }
    }
    while(toupper(selection) != 'Q') ;
    
    cout << "Thanks for Listening" << endl  ;
    
    return 0 ;
}
