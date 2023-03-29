#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <boost/algorithm/string.hpp>
#include <limits>

#define TODONAME "###TODO_LIST###"
#define AMOUNTOFSPACING 20
#define AMOUNTOFLINES   30

typedef enum { e_empty, e_full, e_not_full, srvcInf } internalInf;
typedef enum { e_undefined } e_checkbox;

class ScreenList {
    friend inline std::string get_numeric(int input ) ;
public:

    ScreenList() {
        _list_size = _list.size();

        auto it = _list.begin();
        it->set_line(std::string(TODONAME), srvcInf);

        _list.push_back(OneLine());
        it = _list.end(); it--;
        it->set_line(std::string("srvcInf"), srvcInf);
    }

    void draw_screen() {
        for ( const auto & it : _list )
            std::cout << it.get_line() << '\n';
    }

    void add_line(const std::string & input ) {
        auto it = _list.begin();

        for ( ; it != _list.end() ; it++ ) {
            if ( it->get_internalInf() != e_not_full )
                continue;

            it->add_inf_in_line(input);
            break;
        }
        if ( it == _list.end() ) {
            _list.insert(--it, OneLine( get_numeric( _list.size() - 1 ) + input ));

        }
    }

    class OneLine {
    public:
        OneLine() : _line(std::string(AMOUNTOFSPACING+1, ' ')), _checkbox(e_undefined), _internalInf(e_empty) {}
        OneLine( const std::string &input ) : _line(input), _checkbox(e_undefined), _internalInf(e_full)  { }

        inline void add_inf_in_line(const std::string &input) {
            _line += input;
            _internalInf = e_full;
        }

        inline void set_line( const std::string & input, unsigned char _intInf) {
            _line = input;
            _internalInf = _intInf;
        }

        inline std::string get_line() {
            return _line;
        }
        inline std::string get_line() const {
            return _line;
        }
        inline unsigned char get_internalInf() {
            return _internalInf;
        }




    protected:

    private:
        std::string _line;
        unsigned char _checkbox;
        unsigned char _internalInf;
    };

protected:

private:

    std::list<OneLine> _list{ 1, };
    unsigned int _list_size{0};
};

inline std::string get_numeric(int input ) {
    return std::to_string(input) + '.';
}

int main()
{
    /*
        ###TODO_LIST###
        1.
        2.
        3.
        4.
        5.

        > input string

    */

    // 2. clear window
    // 3. навигация по строкам, с input string прыгнуть на №5
    ScreenList list;

//    std::cout << "\033[7;31mbold red text\033[0m\n";

    while (1) {
        list.draw_screen();

        std::string in;
        std::getline(std::cin, in);

        std::cout << "do you want add (yes/y): " << "\n " << in << " \n";

        std::string tmp;
        std::cin >> tmp;
        boost::algorithm::to_lower(tmp);
        if ( tmp == "yes" || tmp == "y" || tmp == "да" || tmp == "д" )
        {
            list.add_line(in);
        }

        int retVal = system("clear;");
        if ( retVal ) {}

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
