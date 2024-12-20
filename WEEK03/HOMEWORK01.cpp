#include<iostream>
#include<string>
using namespace std;

// Base Class
class media {
private:
    int playing_sec; // last played seconds in episode

protected:
    string name;
    string author;
    int length; // media length in Seconds

public:
    void play(int time) { // play method
        int remaining_time = length - playing_sec;
        cout << "Playing " << name << " at[" << playing_sec << "] : [" << remaining_time << " sec] remaining" << endl;
        if (time > remaining_time) {
            playing_sec = 0;
        } else {
            playing_sec += time;
        }
    }

    int get_playing_sec() const {
        return playing_sec;
    }

    void set_playing_sec(int time) {
        if (time > length) playing_sec = length;
        else playing_sec = time;
    }

    void reset() {
        playing_sec = 0;
    }

    media() { // Default constructor
        name = "unknown";
        author = "";
        length = 0;
        playing_sec = 0;
    }

    media(string _name, string _author, int _length) {
        name = _name;
        author = _author;
        length = _length;
        playing_sec = 0;
    }

    media(string _name, string _author, int _length, int _playing_sec) {
        name = _name;
        author = _author;
        length = _length;
        playing_sec = _playing_sec;
    }
};

// Song Class
class song : public media {
private:
    string brand;

public:
    song() {}

    song(string _name, string _author, int _length, string _brand) 
        : media(_name, _author, _length) {
        brand = _brand;
    }

    void print_song() const {
        cout << "now we playing " << name << " of " << brand << " at " << get_playing_sec() << " sec" << endl;
    }

    void stop_song() {
        reset();
        cout << name << " has stopped" << endl;
    }
};

// Movie Class
class movie : public media {
private:
    string director;
    string main_actor;

public:
    movie() {}

    movie(string _name, string _author, int _length, int _playing_sec, string _director, string _actor) : media(_name, _author, _length, _playing_sec) {
        director = _director;
        main_actor = _actor;
    }

    movie(string _name, string _author, int _length, string _director, string _actor) : media(_name, _author, _length) {
        director = _director;
        main_actor = _actor;
    }

    void print_movie() const {
        cout << "now we playing " << name << " directed by " << director
             << " at " << get_playing_sec() << " sec" << endl;
    }
};

// Episode Class
class episode : public media {
private:
    int episode_number;
    string episode_name;

public:
    episode() {
        episode_number = -1;
        episode_name = "";
    }
    
     episode(string _name, string _author, int _length, int _playing_sec, int ep_num, string ep_name) 
    : media(_name, _author, _length, _playing_sec) {
        episode_number = ep_num;
        episode_name = ep_name;
    }

    episode(string _name, string _author, int _length, int ep_num, string ep_name) 
        : media(_name, _author, _length) {
        episode_number = ep_num;
        episode_name = ep_name;
    }


    void print_episode() const {
        cout << "now we playing " << name << " that be ep." << episode_number
             << " at " << get_playing_sec() << " sec" << endl;
    }
};

// Podcast Class
class podcast : public media {
private:
    string podcast_name;

public:
    podcast() {}

    podcast(string _name, string _author, int _length, string _podcast_name) 
        : media(_name, _author, _length) {
        podcast_name = _podcast_name;
    }

    void print_podcast() const {
        cout << "now we playing " << name << " from " << podcast_name
             << " station at " << get_playing_sec() << " sec" << endl;
    }
};

int main() {
    song s1("Som San", "sek loso", 314, "LOSO");
    song s2("Timemachine", "Pond Nipon", 328, "Rap");
    movie m1("The Disappearance of Haruhi Suzumiya", "Nagaru Tanigawa", 9707, "Tatsuya Ishihara", "Haruhi");
    episode e1("Thi da Satan : ep 3 Earth Water Wind Fire", "Kantana", 3600, 3, "Earth Water Wind Fire");
    podcast p1("PYMK EP21 Davinci The Renaissance genius", "FAROSE", 3232, "FAROSE podcast");

    p1.play(200);
    p1.print_podcast();
    p1.reset();
    p1.print_podcast();

    s1.play(50);
    s1.print_song();
    s1.stop_song();
    s1.play(50);

    cout << "1" << endl;
    movie m2("Avatar","James Cameron",9720,123,"James Cameron","Sam Worthington");
    m2.play(10);
    m2.print_movie();
    m2.reset();
    m2.print_movie();

    cout << "2" << endl;
    episode e2("Start-Up (2020) : ep 16 Scale up","Studio Dragon",4800,321,16,"Scale up");
    e2.play(10);
    e2.print_episode();
    e2.reset();
    e2.print_episode();

/* expected
    Playing PYMK EP21 Davinci The Renaissance genius at[0] : [3232 sec] remaining
    now we playing PYMK EP21 Davinci The Renaissance genius from FAROSE podcast station at 200 sec
    Playing When you started to walk, You are never be the same person anymore | Readery EP.132 at[0] : [4277 sec] remaining
    now we playing When you started to walk, You are never be the same person anymore | Readery EP.132 from THE STANDARD PODCAST station at 50 sec
    now we playing When you started to walk, You are never be the same person anymore | Readery EP.132 from THE STANDARD PODCAST station at 0 sec
    Playing Som San at[0] : [314 sec] remaining
    now we playing Som San of LOSO at 50 sec
    Som San has stopped
    Playing Som San at[0] : [314 sec] remaining
    1
    Playing Avatar at[123] : [9597 sec] remaining
    now we playing Avatar directed by James Cameron at 133 sec
    now we playing Avatar directed by James Cameron at 0 sec
    2
    Playing Start-Up (2020) : ep 16 Scale up at[321] : [4479 sec] remaining
    now we playing Start-Up (2020) : ep 16 Scale up that be ep.16 at 331 sec
    now we playing Start-Up (2020) : ep 16 Scale up that be ep.16 at 0 sec   
    */

    return 0;
}
